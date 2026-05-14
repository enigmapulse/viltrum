#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

vector<vector<ll>> adj;
vector<ll> soldiers;
vector<ll> depth;

void f(ll x){
    for(auto u:adj[x]){
        if(depth[u]==0){
            depth[u]=depth[x]+1;
            f(u);
        }
    }
} 

void solve() {
    ll n;
    cin>>n;
    adj.resize(n+1);
    soldiers.resize(n+1);
    depth.assign(n+1,0);
    for(ll i = 2;i<=n;i++) cin>>soldiers[i];
    for(ll i = 1;i<n;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    depth[1]=1;
    f(1);
    map<ll,ll> mp;
    for(ll i = 2;i<=n;i++){
        mp[depth[i]]+=soldiers[i];
    }
    ll mx = 0,val = 0;
    for(auto p:mp){
        if(p.second>mx){
            mx = p.second;
            val = p.first;
        }
    }
    cout<<mx<<" "<<val-1<<endl;
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