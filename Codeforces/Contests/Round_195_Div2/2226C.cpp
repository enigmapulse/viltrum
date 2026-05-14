#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n); inarr(a, n);

    auto chk = [&] (ll x) {
        multiset<ll> ms(all(a));
        for (ll i = x - 1; i >= 0; i--) {
            auto it = ms.find(i);
            if(it != ms.end()) ms.erase(it);
            else {
                it = ms.lower_bound(2 * i + 1);
                if(it == ms.end()) return false;
                else ms.erase(it);
            }
        }
        return true;
    };

    ll lo = 1, hi = n;
    while(lo < hi) {
        ll mid = lo + (hi - lo + 1)/2;
        if(chk(mid)) lo = mid;
        else hi = mid - 1;
    }

    cout << lo << endl;
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