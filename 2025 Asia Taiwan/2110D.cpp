#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define input_vec_v vector<long long>v(n);for(int i = 0; i < n; i++){cin >> v[i];}
#define input_n long long n;cin>>n;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long MaX(long long a,long long b){return b>a?b:a;}
long long MiN(long long a,long long b){return b<a?b:a;}



void solve() {
    ll n, m; cin >> n >> m;
    vector<ll> w(n+1);
    for(ll i = 1; i <= n; i++) cin >> w[i];
    vector<pair<pair<ll, ll>,ll>> v;
    for(ll i = 1; i <= m; i++){
        ll x, y, z; cin >> x >> y >> z;
        v.push_back({{x, y}, z});
    }
    sort(all(v));

    auto chk = [&] (ll x) {
        vector<ll> bat(n + 1, -1); bat[1] = 0;

        for(ll i = 0; i < m; i++){
            ll ut = v[i].ff.ff;
            ll vt = v[i].ff.ss;
            ll e = v[i].ss;
            if(bat[ut] != -1 && min(bat[ut] + w[ut], x) >= e) {
                bat[vt] = max(bat[vt], min(bat[ut] + w[ut], x));
            }
        }

        return (bat[n] >= 0);
    };

    ll lo = 1, hi = 1e12;
    while(lo < hi) {
        ll mid = lo + (hi - lo)/2;
        if(chk(mid)) hi = mid;
        else lo = mid + 1;
    }

    if(lo == 1e12) cout << -1 << endl;
    else cout << lo << endl;
}


int main(){
    fastio;
    long long t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}