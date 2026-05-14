#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n), b(n); inarr(a, n); inarr(b, n);

    for (ll i = 0; i < n - k; i++) {
        if(a[i] != a[i + k]) {
            if((b[i] != -1 && b[i] != a[i]) || (b[i + k] != -1 && b[i + k] != a[i + k])) {
                cout << "NO" << endl;
                return;
            }
            b[i] = a[i];
            b[i + k] = a[i + k];
        }
        else {
            if(b[i] != -1 && b[i + k] != -1 && b[i] != b[i + k]) {
                cout << "NO" << endl;
                return;
            }
            else if(b[i] != -1) b[i + k] = b[i];
            else b[i] = b[i + k];
        }
    }

    for (ll i = n - 1; i >= k; i--) {
        if(a[i] == a[i - k]) {
            if(b[i] != -1 && b[i - k] != -1 && b[i] != b[i - k]) {
                cout << "NO" << endl;
                return;
            }
            else if(b[i] != -1) b[i - k] = b[i];
            else b[i] = b[i - k];
        }
    }
    
    map<ll, ll> mp;
    for (ll i = 0; i < k; i++) {
        mp[a[i]]++;
        if(b[i] != -1) mp[b[i]]--;
    }
    
    for(auto [val, f] : mp) {
        if(f < 0) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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