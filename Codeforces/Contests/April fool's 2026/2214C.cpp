#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    int n; cin >> n;
    vector<string> answers(9);
    answers[1] = "walk";
    answers[2] = "no";
    answers[3] = "no";
    answers[4] = "no";
    answers[5] = "yes";
    answers[6] = "yes";
    answers[7] = "sdrawkcab";
    answers[8] = "8";
    cout << answers[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    if (multipleTests)
        cin >> T;
    while (T--)
        solve();
    return 0;
}