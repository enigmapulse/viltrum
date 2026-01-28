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

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n); inarr(a, n);

    ll idx = -1;
    for(ll i = 0; i < n; ++i) {
        if(abs(a[i]) != 1) {
            idx = i;
            break;
        }
    }

    vector<ll> maxend(n), minend(n);
    vector<ll> maxstart(n), minstart(n);

    maxend[0] = minend[0] = a[0];
    for (int i = 1; i < n; i++) {
        maxend[i] = max(a[i], a[i] + maxend[i - 1]);
        minend[i] = min(a[i], a[i] + minend[i - 1]);
    }

    maxstart[n - 1] = minstart[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        maxstart[i] = max(a[i], a[i] + maxstart[i + 1]);
        minstart[i] = min(a[i], a[i] + minstart[i + 1]);
    }

    // if no anomaly
    if(idx == -1) {
        ll hi = *max_element(all(maxend));
        ll lo = *min_element(all(minend));
        cout << max(hi, 0LL) - min(lo, 0LL) + 1 << endl;
        for (ll i = min(lo, 0LL); i <= max(hi, 0LL); i++) cout << i << " ";
        cout << endl;
        return;
    }

    ll hi1 = maxend[idx] + maxstart[idx] - a[idx];
    ll lo1 = minend[idx] + minstart[idx] - a[idx];

    ll hi2 = 0, lo2 = 0;
    if(idx > 0) {
        hi2 = *max_element(maxend.begin(), maxend.begin() + idx);
        lo2 = *min_element(minend.begin(), minend.begin() + idx);
    }

    ll hi3 = 0, lo3 = 0;
    if(idx + 1 < n) {
        hi3 = *max_element(maxstart.begin() + idx + 1, maxstart.end());
        lo3 = *min_element(minstart.begin() + idx + 1, minstart.end());
    }

    set<ll> valid; valid.insert(0);
    for (ll i = lo1; i <= hi1; i++) valid.insert(i);
    for (ll i = lo2; i <= hi2; i++) valid.insert(i);
    for (ll i = lo3; i <= hi3; i++) valid.insert(i);
    
    cout << valid.size() << endl;
    for(auto e : valid) cout << e << " ";
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