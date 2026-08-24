#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;
void print128(__int128_t n) {
    if (n < 0) {
        cout << '-';
        n = -n;
    }
    string s;
    do {
        s += (char)('0' + n % 10);
        n /= 10;
    } while (n);
    reverse(s.begin(), s.end());
    cout << s << endl;
}


bool multipleTests = false;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n); inarr(a, n);

    map<ll, ll> mp; 
    mp[a[n - 1]] = 1;
    ll sm = a[n-1]; 
    
    __int128_t ans = 0;
    for (ll i = n - 2; i >= 0; i--) {
        ans += sm - (n - i - 1) * a[i];
        ll val = a[i];
        ans +=  mp[val-1] - mp[val+1];
        mp[val]++;
        sm += val;
    }
    print128(ans);
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