#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll INF = 1e18 + 5;

using namespace std;
bool multipleTests = false;

ll sz = 0;
ll req = 0;
string l, r; 
string ans;
ll dp[20][2][2][20][10][170];

bool recur(ll idx, ll t1, ll t2, ll leadz, ll lastd, ll strength) {
    if(idx == sz) {
        return (strength >= req);
    }

    if(dp[idx][t1][t2][leadz][lastd][strength] != -1) 
        return dp[idx][t1][t2][leadz][lastd][strength];
    
    ll lo = (t1 ? l[idx] - '0' : 0ll);
    ll hi = (t2 ? r[idx] - '0' : 9ll);

    for (ll dig = lo; dig <= hi; dig++) {
        ll nidx = idx + 1;
        ll nt1 = t1 && (dig == lo);
        ll nt2 = t2 && (dig == hi);
        ll nleadz = leadz && (dig == 0ll);
        ll nstrength = strength;
        nstrength += (dig >= lastd ? dig : 0ll); 
        ll nlastd = max(lastd, dig);

        if (recur(idx + 1, nt1, nt2, nleadz, nlastd, nstrength)) {
            ans += '0' + dig;
            return dp[idx][t1][t2][leadz][lastd][strength] = 1;
        }
    }
    return dp[idx][t1][t2][leadz][lastd][strength] = 0;
}

void solve() {
    ll k; cin >> l >> r >> k;
    while(l.size() != r.size()) l = '0' + l;
    sz = l.size(); req = k;

    memset(dp, -1, sizeof(dp));
    bool flag = recur(0, 1, 1, 1, 0, 0);
    reverse(all(ans));
    if(!flag) cout << -1 << endl;
    else {
        cout << stoll(ans) << endl;
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