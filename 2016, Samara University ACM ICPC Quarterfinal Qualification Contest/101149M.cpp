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
    vector<ll> a(n+1);
    for(ll i = 1; i <= n; i++) a[i] = -1;

    ll last = -1; 
    while(count(all(a), -1) != 1) {
        last = -1;
        for(ll i = 1; i <= n;i++){
            if(a[i] == -1 && last == -1) last = i;
            else if(a[i] == -1) {
                cout << "? " << last << " " << i << endl << flush;
                char ch; cin >> ch;
                if(ch == '>') a[i] = last;
                else a[last] = i;
                last = -1;
            }
        }
    }

    ll winner = 0;
    for (ll i = 1; i <= n; i++) {
        if(a[i] == -1) winner = i;
    }
    
    vector<ll> v;
    for (ll i = 1; i <= n; i++) {
        if(a[i] == winner) v.push_back(i);
    }
    
    ll mx = 0; last = v[0];
    for (ll i = 1; i < v.size(); i++) {
        cout << "? " << last << " " << v[i] << endl << flush;
        char ch; cin >> ch;
        if(ch == '<') last = v[i];
    }
    
    cout << "! " << last << endl << flush;
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