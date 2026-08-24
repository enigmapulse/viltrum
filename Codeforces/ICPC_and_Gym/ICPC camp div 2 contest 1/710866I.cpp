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

    vector<double> ans(n);
    ll tot = (n * (n - 1)) / 2;
    ll mx = *max_element(all(a));

    for (ll i = 0; i < n; i++) {
        if(mx == a[i]) {
            ans[i] = 1;
            continue;
        }
        double prev = 0;
        ll j = i;
        while(a[j] <= a[i]) {
            prev++;
            j--;
            j = (j + n) % n;
        }
        double nxt = 0;
        j = i;
        while(a[j] <= a[i]) {
            nxt++;
            j++;
            j = (j + n) % n;
        }
        ans[i] = (nxt * prev) / tot;
    }
    
    for (ll i = 0; i < n; i++)
    {
        cout << fixed << setprecision(12) << ans[i] << endl;
    }
    
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