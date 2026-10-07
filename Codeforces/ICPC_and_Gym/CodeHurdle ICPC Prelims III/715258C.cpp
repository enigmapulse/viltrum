#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

const ll MAXN = 1000005;
ll spf[MAXN];

void sieve() {
    spf[1] = 1LL;
    for (ll i = 2; i < MAXN; i++) spf[i] = i;
    for (ll i = 4; i < MAXN; i += 2) spf[i] = 2;
    for (ll i = 3; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i)
                if (spf[j] == j) spf[j] = i;
        }
    }
}

vector<ll> getFactorization(ll n) {
    vector<ll> ret;
    while (n != 1) {
        ret.push_back(spf[n]);
        n /= spf[n];
    }
    return ret;
}

const ll MOD=1000000007;

void solve() {
    ll n,k;
    cin>>n>>k;
    map<ll,ll> mp;
    for(int i=0;i<n;i++){
        ll x;
        cin>>x;
        while(x>1){
            ll p=spf[x];
            while(x%p==0) x/=p,mp[p]++;
        }
    }
    
    vector<pair<ll,ll>> v;
    for(auto [p,ct]:mp){
        v.push_back({ct,p});
    }
    
    sort(all(v));
    
    
    ll ans=1;
    for(int i=0;i<v.size();i++){
        
        auto [ct,p]=v[i];
        ll mx=min(k,ct);
        // cout<<mx<<endl;
        v[i].first-=mx;
        k-=mx;
        ans*=(v[i].first+1);
        ans%=MOD;
    }

    cout<<ans<<endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    int T = 1;
    if (multipleTests)
        cin >> T;
    while (T--)
        solve();
    return 0;
}