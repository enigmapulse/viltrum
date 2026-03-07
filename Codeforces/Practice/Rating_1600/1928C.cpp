#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

vector<ll> divisors(ll n) {
    vector<ll> ret;
    for (ll i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ret.push_back(i);
            if(i * i != n) ret.push_back(n / i);
        }
    }
    sort(all(ret));
    return ret;
}

bool multipleTests = true;

void solve() {
    ll n, x; cin >> n >> x;

    set<ll> valid;
    for(auto f1 : divisors(n - x)) {
        if(f1 >= 2*x - 2 && f1 % 2 == 0) valid.insert(f1);
    }

    for(auto f2 : divisors(n + x - 2)) {
        if(f2 >= 2*x - 2 && f2 % 2 == 0) valid.insert(f2);
    }

    cout << valid.size() << endl;
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