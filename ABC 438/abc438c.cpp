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
    vector<ll> a(n); inarr(a, n);

    list<int> lst;

    for (int x : a) {
        lst.push_back(x);

        if (lst.size() >= 4) {
            auto a = prev(lst.end());
            auto b = prev(a);
            auto c = prev(b);
            auto d = prev(c);

            if (*a == *b && *b == *c && *c == *d) {
                lst.erase(d, lst.end());  
            }
        }
    }

    cout << lst.size() << endl;
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