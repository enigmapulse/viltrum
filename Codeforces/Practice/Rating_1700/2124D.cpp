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
    vector<ll> a(n); inarr(a, n);

    vector<ll> b = a, c; sort(all(b)); ll cnt = 0;
    set<ll> removable; ll idx = k; ll neg = b[k - 1];
    while(idx < n && b[idx] == b[idx - 1]) idx++; 
    cnt = idx - k + 1;
    for (ll i = idx; i < n; i++) removable.insert(b[i]);
    for (ll i = 0; i < n; i++) {
        if(removable.find(a[i]) == removable.end()) c.push_back(a[i]);
    }

    ll l = 0, r = c.size() - 1;
    while(l < r) {
        if(c[l] == c[r]) {l++; r--;}
        else {
            if(c[l] == neg && cnt) {l++; cnt--;}
            else if(c[r] == neg && cnt) {r--; cnt--;}
            else {
                cout << "NO" << endl;
                return;
            }
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