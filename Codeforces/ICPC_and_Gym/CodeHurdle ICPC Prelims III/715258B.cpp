#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n); inarr(a, n);

    auto chk = [&] (ll x) {

        ll cnt = 0;
        stack<ll> st;
        for (ll i = 0; i < n; i++) {
            while(!st.empty() && st.top() + x <= a[i]) {
                cnt++; st.pop();
            }
            st.push(a[i]);
        }
        return (cnt >= k);
    };

    if(!chk(1)) {
        cout << -1 << endl;
        return;
    }

    ll lo = 1, hi = 1e10;
    while (lo < hi)  {
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