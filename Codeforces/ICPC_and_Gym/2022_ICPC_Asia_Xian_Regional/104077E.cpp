#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {

    function<ll(ll)> f = [&] (ll x) {
        if(x == 0) return 0LL;
        else if(x % 3 == 0) return 1LL + f(x/3);
        else return 1LL + f(x - 1);
    };

    ll l, r; cin >> l >> r;
    if(l == r) cout << f(l) + 1 << endl;
    else {
        vector<ll> v;
        ll curr = r;
        while(curr){
            ll val = 1;
            while(val*3<=curr){
                val*=3;
            }
            curr-=val;
            v.push_back(val);
        }
        ll mx = f(r);
        curr = 0;
        for(ll i = 0;i<v.size();i++){
            curr+=v[i];
            if(curr-1>=l) mx = max(mx,f(curr-1));
        }
        cout<<mx+1<<endl;
    }
    // for (ll i = 0; i < 200; i++) {
    //     cout << i << " : " << f(i) << endl;
    // }
    
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