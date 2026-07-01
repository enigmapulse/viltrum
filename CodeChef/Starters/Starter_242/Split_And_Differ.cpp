#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n); inarr(a, n);

    vector<ll> b = {a[0]};
    for (ll i = 1; i < n; i++) {
        if(a[i] == a[i - 1]) {
            if(a[i] == 1 || a[i] == 2) {
                cout << -1 << endl;
                return;
            }
            else {
                if(i == n - 1 || (a[i + 1] != 1)) {
                    b.push_back(a[i] - 1);
                    b.push_back(1);
                    a[i] = 1;
                }
                else {
                    if(a[i] == 4) {
                        b.push_back(1);
                        b.push_back(3);
                        a[i] = 3;
                    }
                    else {
                        b.push_back(a[i] - 2);
                        b.push_back(2);
                        a[i] = 2;
                    }   
                }
            }
        }
        else b.push_back(a[i]);
    }
    
    cout << b.size() << endl;
    for(auto x : b) cout << x << " ";
    cout << endl;
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