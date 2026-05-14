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
    vector<ll> d(n); inarr(d, n);
    sort(all(d));
    ll pos1 = d[n - 1];
    ll pos2 = d[1] * d[n - 1];

    if(n==1 && d[0]==1){
        cout<<"*"<<endl;
        return;
    }
    bool flag = false;
    for(ll i = 0;i<n;i++){
        if(pos1%d[i]!=0){
            flag = true;
            break;
        }
    }
    if(!flag){
        ll missing = 0;
        set<ll> s;
        for(ll i = 0;i<n;i++) s.insert(d[i]);
        for(auto p:s){
            ll val = pos1/p;
            if(s.find(val)==s.end()){
                missing = val;
                cout<<pos1<<" "<<missing<<endl;
                return;
            }
        }
        ll val = sqrt(pos1);
        if(s.find(val)==s.end() && val*val==pos1){
            cout<<pos1<<" "<<val<<endl;
            return;
        }
    }
    cout<<pos2<<" "<<pos2<<endl;
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