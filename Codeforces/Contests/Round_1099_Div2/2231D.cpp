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
    string s; cin >> s;
    vector<ll> a(n), c(n); inarr(a, n); inarr(c, n);

    set<ll, greater<ll>> empty_idx; ll curr = 0;
    for (ll i = 0; i < n; i++) {
        if(s[i] == '0') empty_idx.insert(i);
        else curr += a[i];

        if(i == 0 || c[i] > c[i - 1]) {
            if(s[i] == '0') a[i] = c[i] - curr;
            else {
                if(empty_idx.empty()) {
                    if(c[i] != curr){
                        cout << "No" << endl;
                        return;
                    }  
                    else continue;
                }

                auto it = empty_idx.begin();
                a[*it] += c[i] - curr;
                empty_idx.erase(it);
            }
            curr = c[i];
            empty_idx.clear();
        }
        else if(c[i] == c[i - 1] && curr > c[i]) {
            if(empty_idx.empty()) {
                cout << "No" << endl;
                return;
            }
            auto it = empty_idx.begin();
            a[*it] += c[i] - curr;
            curr = c[i];
        }
    }

    ll cur = 0, mx = -2e18; 
    for (ll i = 0; i < n; i++) {
        cur += a[i];
        mx = max(mx, cur);
        if (mx != c[i]) {
            cout << "No" << endl;
            return;
        }
    }
    
    cout << "Yes" << endl;
    for (ll i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
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