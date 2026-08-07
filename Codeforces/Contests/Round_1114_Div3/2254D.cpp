#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll INF = 1e18;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    vector<ll> b(n); inarr(b, n);

    // freq of b array
    map<ll, ll> cnt;
    for(auto x : b) cnt[x]++;

    if(cnt[0] == 0) {
        cout << -1 << endl;
        return;
    }

    // a array val for the corresponding b array value
    map<ll, ll> val; ll prev = 0;

    for(auto it = cnt.begin(); it != cnt.end(); it++) {
        auto ut = next(it);
        if(ut == cnt.end()) {
            val[it -> first] = prev + 1;
            break;
        }
        ll curr = ut -> first - it -> first;
        if(curr % (it -> second) != 0) {
            cout << -1 << endl;
            return;
        }
        curr = curr / (it -> second);
        val[it -> first] = curr;
        prev = curr;
    }

    ll mx = 0;
    for(auto [num, asgn] : val) {
        if(mx >= asgn) {
            cout << -1 << endl;
            return;
        }
        mx = max(mx, asgn);
    }

    for (ll i = 0; i < n; i++) {
        cout << val[b[i]] << " ";
    }
    cout << endl;
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