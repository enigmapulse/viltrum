#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n; cin >> n;
    ll f = 1, s = 2, cnt = 0;
    while(f <= n) {
        while(s <= n) {
            cout << "? " << f << " " << s << endl << flush;
            string output; cin >> output;
            if(output == "No") break;
            else s++;
        }
        cnt += s - f - 1;
        f++; s = max(s, f + 1);
    }

    cout << "! " << cnt << endl << flush;
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