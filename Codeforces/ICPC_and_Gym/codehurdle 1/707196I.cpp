#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 1; _i <= (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll INF = 1e17;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n,k; cin>>n>>k;
    vector<ll> a(n + 1); inarr(a, n);

    vector<ll> cnt(n + 1, 0);
    for (ll i = 1; i <= n; i++) {
        if(a[i] == -1) cnt[i]++;
        cnt[i] += cnt[i - 1];
    }

    vector<vector<ll>> dp(n + 1, vector<ll> (k + 1, -INF));
    dp[0][0] = 0;

    for (ll ops = 0; ops <= k; ops++) {
        for (ll i = 1; i <= n; i++) {
            ll diff = 0;
            if(a[i] == 1){
                if(ops==0){
                    if(cnt[i-1]&1) diff--;
                    else diff++;
                }else{
                    if((cnt[i-1]^ops)%2==1) diff--;
                    else diff++;
                }
            }
            dp[i][ops] = max(dp[i - 1][ops] + diff, dp[i][ops]);
            diff = 0;
            if(a[i] == -1){
                if(ops==0){
                    if(cnt[i-1]&1) diff--;
                    else diff++;
                }else{
                    if((cnt[i-1]^ops)%2==0) diff--;
                    else diff++;
                }
            }
            if(ops) dp[i][ops] = max(dp[i - 1][ops - 1] + diff, dp[i][ops]);
        }
        // cerr << dp[1][ops] << endl;
    }

    
    ll ans = -INF;
    for (ll i = k; i >= 0; i -= 2) {
        ans = max(ans, dp[n][i]);
    }

    vector<vector<ll>> dp1(n + 1, vector<ll> (k + 1, INF));
    dp1[0][0] = 0;

    for (ll ops = 0; ops <= k; ops++) {
        for (ll i = 1; i <= n; i++) {
            ll diff = 0;
            if(a[i] == 1){
                if(ops==0){
                    if(cnt[i-1]&1) diff--;
                    else diff++;
                }else{
                    if((cnt[i-1]^ops)%2==1) diff--;
                    else diff++;
                }
            }
            dp1[i][ops] = min(dp1[i - 1][ops] + diff, dp1[i][ops]);
            diff = 0;
            if(a[i] == -1){
                if(ops==0){
                    if(cnt[i-1]&1) diff--;
                    else diff++;
                }else{
                    if((cnt[i-1]^ops)%2==0) diff--;
                    else diff++;
                }
            }
            if(ops) dp1[i][ops] = min(dp1[i - 1][ops - 1] + diff, dp1[i][ops]);
        }
        // cerr << dp[1][ops] << endl;
    }

    
    ll ans1= INF;
    for (ll i = k; i >= 0; i -= 2) {
        ans1 = min(ans1, dp1[n][i]);
    }
    cout << max(ans,-ans1) << endl;
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