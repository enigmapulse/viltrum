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
    vector<ll> b(n); inarr(b, n); 

    ll cnt = 0;
    for (ll i = 1; i < n - 1; i++) {
        ll g1 = gcd(a[i], a[i - 1]);
        ll g2 = gcd(a[i], a[i + 1]);
        ll m = lcm(g1, g2);
        if(m < a[i]) cnt++;
        else if(m != a[i] && m <= b[i]) cnt++;
        else if(m == a[i]){
            //sochte
        }
    }
    
    if(gcd(a[0], a[1]) <= b[0] && gcd(a[0], a[1]) != a[0]) cnt++;
    if(gcd(a[n - 1], a[n - 2]) && gcd(a[n - 1], a[n - 2]) != a[n - 1]) cnt++;

    cout << cnt << endl;
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