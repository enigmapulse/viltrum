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
    ll tele, time; cin >> tele >> time;
    vector<ll> tp(tele);
    for (ll i = 0; i < tele; i++)
    {
        cin >> tp[i];
    }
    vector<ll> tm(time);
    for (ll i = 0; i < time; i++)
    {
        cin >> tm[i];
    }
    
    vector<ll> dp(n + 1, -1);
    for(auto x : tp) dp[x] = 0;
    for(auto x : tm) dp[x] = 1;


    double sump = 1, sumq = 0;
    double currp = 1, currq = 0;
    for (ll i = n - 1; i >= 2; i--) {
        currp = 0, currq = 0;
        if(dp[i] == 1) sumq++;
        else if(dp[i] == 0) continue;
        else {
            ll div = n - i;
            currp = sump / div;
            currq = sumq / div;
            sump += currp;
            sumq += currq;
        }
    }
    
    double x = sumq;
    x = x / (n - 1 - sump);
    cout << fixed << setprecision(9) << x << endl;
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