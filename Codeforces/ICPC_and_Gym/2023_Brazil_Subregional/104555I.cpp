#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{"; for (int i = 0; i < v.size(); ++i) { if (i) os << ", "; os << v[i]; } return os << "}";
}
template<typename... Args> void dbg_out(Args&&... args) { ((cerr << " " << args), ...) << endl; }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

bool multipleTests = false;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n); inarr(a, n);

    vector<ll> even(n, 0), odd(n, 0);
    if(a[0]) odd[0] = 1; else even[0] = 1;

    for (ll i = 1; i < n; i++) {
        if(a[i]) {
            even[i] = odd[i - 1];
            odd[i] = even[i - 1] + 1;
        }
        else {
            odd[i] = odd[i - 1];
            even[i] = even[i - 1] + 1;
        }
    }

    dbg(odd);
    dbg(even);
    
    cout << accumulate(all(odd), 0LL) << endl;
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