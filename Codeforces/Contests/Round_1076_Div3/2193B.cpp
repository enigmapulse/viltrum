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
    ll diff = -1;
    for (ll i = 0; i < n; i++) {
        if(a[i] != n - i) {
            diff = i; break;
        }
    }

    if(diff == -1) {
        for (ll i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }

    ll mx = 0; ll idx = 0;
    if(diff != -1) {
        for (ll i = diff; i < n; i++) {
            if(a[i] > mx) {mx = a[i]; idx = i;}
        }
    }

    while(diff <= idx) {
        swap(a[diff], a[idx]);
        diff++; idx--;
    }
    
    for (ll i = 0; i < n; i++)
    {
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