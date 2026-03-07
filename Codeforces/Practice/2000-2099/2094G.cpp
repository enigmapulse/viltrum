#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll q; cin >> q;
    deque<ll> d;
    ll pref = 0, suff = 0, sum = 0; ll dir = 1;
    while(q--) {
        ll ops; cin >> ops;
        ll n = d.size();
        switch (ops)
        {
        case 1:
            if(dir) {
                d.push_front(d.back()); d.pop_back();
                pref += sum - n*(d.front());
                suff -= sum - n*(d.front());
                cout << pref << endl;
            }
            else {
                d.push_back(d.front()); d.pop_front();
                pref += sum - n*(d.back());
                suff -= sum - n*(d.back());
                cout << pref << endl;
            }
            
            break;
        
        case 2:
            swap(pref, suff); dir = dir ^ 1;
            cout << pref << endl;
            break;

        case 3:
            ll k; cin >> k;
            if(dir) d.push_back(k);
            else d.push_front(k);
            pref += k*(n + 1);
            sum += k;
            suff += sum;
            cout << pref << endl;    
        }
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