#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

struct r{
    ll x;
    ll y;
    ll z;
};

void solve() {
    ll n;
    cin>>n;
    vector<r> q,w;
    ll mx = 1e10,idx = -1;
    for(ll i  = 0; i< n;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        r t = {a,b,c};
        q.push_back(t);
        w.push_back(t);
    }

    auto cmp  = [&] ( r a,r b){
        ll cnt = 0;
        if(a.x>b.x) cnt++;
        if(a.y>b.y) cnt++;
        if(a.z>b.z) cnt++;
        return cnt<2;
    };

    sort(all(q),cmp);
    bool flag = true;

    for(ll i = 1;i<n;i++){
        if(!(cmp(q[0],q[i]))) flag = false;
    }

    if(flag){
        cout<<1<<endl;
        for(ll i =0;i<n;i++){
            if(q[0].x == w[i].x &&  q[0].y == w[i].y && q[0].z == w[i].z) cout<<i+1<<endl;
        }
        return;
    }
    cout<<0<<endl;
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