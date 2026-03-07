import os
import re
import shutil
import requests

# Pointing exactly to your new structured practice folder
PRACTICE_DIR = "./Codeforces/Practice"


def fetch_cf_ratings():
    print("Fetching problem ratings from Codeforces API...")
    try:
        # Fetch the entire problemset
        response = requests.get("https://codeforces.com/api/problemset.problems")
        data = response.json()

        ratings = {}
        if data["status"] == "OK":
            for prob in data["result"]["problems"]:
                if "rating" in prob:
                    # Construct the key exactly as it appears in the filename (e.g., 1497 + C1)
                    key = f"{prob['contestId']}{prob['index']}"
                    ratings[key] = prob["rating"]
            print(
                f"✅ Successfully loaded {len(ratings)} rated problems from Codeforces."
            )
            return ratings
        else:
            print("❌ API Error:", data.get("comment", "Unknown error"))
            return {}
    except Exception as e:
        print(
            "❌ Failed to connect to Codeforces API. Check your internet connection.", e
        )
        return {}


def reorganize_by_rating():
    ratings_db = fetch_cf_ratings()
    if not ratings_db:
        print("Aborting reorganization due to API failure.")
        return

    moved_count = 0

    # Walk through the current Practice directory
    for root, dirs, files in os.walk(PRACTICE_DIR):
        for file in files:
            if not file.endswith(".cpp"):
                continue

            # Match files like "1497C1.cpp", "1722E.cpp"
            # Group 1 captures the digits (contest ID), Group 2 captures the letter/number (index)
            match = re.match(r"^(\d{3,4})([A-Z][0-9]?)\.cpp$", file, re.IGNORECASE)
            if match:
                # Reconstruct the key to safely match the API dictionary
                problem_id = f"{match.group(1)}{match.group(2).upper()}"
                rating = ratings_db.get(problem_id)

                if rating:
                    folder_name = f"Rating_{rating}"
                else:
                    folder_name = "Unrated"

                target_folder = os.path.join(PRACTICE_DIR, folder_name)
                if not os.path.exists(target_folder):
                    os.makedirs(target_folder)

                old_path = os.path.join(root, file)
                new_path = os.path.join(target_folder, file)

                if old_path != new_path:
                    shutil.move(old_path, new_path)
                    print(f"Moved {file} -> {folder_name}/")
                    moved_count += 1

    # Clean up empty folders (e.g., 1300-1399, 1400-1499) left behind
    for dirpath, dirnames, filenames in os.walk(PRACTICE_DIR, topdown=False):
        if not os.listdir(dirpath):
            os.rmdir(dirpath)

    print(
        f"\n🎉 Done! Successfully categorized {moved_count} practice files by their official difficulty rating."
    )


if __name__ == "__main__":
    if not os.path.exists(PRACTICE_DIR):
        print(
            f"❌ Error: Could not find the directory '{PRACTICE_DIR}'. Make sure you run this script from the root of your repo."
        )
    else:
        reorganize_by_rating()
