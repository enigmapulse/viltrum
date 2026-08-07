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

    set<ll> chosen;
    for (ll i = 0; i < n; i++) {
        if(a[i] == a[n - 1 - i]) continue;
        else {
            if(abs(a[i] - a[n - 1 - i]) != 2) {
                cout << "No" << endl;
                return;
            }
            ll mn = min(a[i], a[n - 1 - i]);
            chosen.insert(mn);
        }
    }

    if(chosen.size() < 2) {
        cout << "Yes" << endl;
        return;
    }
    
    if(chosen.size() > 2) {
        cout << "No" << endl;
        return;
    } 
    else {
        auto val1 = *chosen.begin();
        auto val2 = *chosen.rbegin();
        if(val2 != val1 + 1) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
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