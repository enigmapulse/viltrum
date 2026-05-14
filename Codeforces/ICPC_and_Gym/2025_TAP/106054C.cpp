#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 1; _i <= (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n; cin >> n;
    vector<ll> perm(n + 1); inarr(perm, n);
    ll mx = 0;
    // for(ll j=0;j<3;j++){
        map<ll,ll> mp;
        for(ll i = 1;i<n+1;i++){
            ll idx = (i)%n;
            if(idx==0) idx = n;
            ll val = perm[idx]-i;
            if(val<0) val+=n;
            mp[val]++;
        }
        ll res = n;
        // for(auto p:mp){
        //     cout<<p.first<<" "<<p.second<<endl;
        // }
        for(auto p:mp){
            if(p.second>1){
                ll val = (p.second-1)*p.second;
                res+=val;
            }
        }
        mx = max(mx,res);
    // }
    cout<<mx<<endl;
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