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

    string s; cin >> s;
    vector<ll> mx;
    ll idx = 0;
    while (idx < n) {
        ll b = 0;
        while (idx + 1 < n && s[idx] == s[idx + 1]) {
            b = max(b, a[idx]);
            idx++;
        }
        b = max(b, a[idx]);
        mx.push_back(b);
        idx++;
    }
    if(s[0] == s[n - 1]) {mx[0] = max(mx[0], mx[mx.size() - 1]);
    mx.pop_back();}

    multiset<ll> ms;
    for(auto x : mx) ms.insert(x);
    
    ll val = *ms.rbegin();
    ms.erase(prev(ms.end()));
    val += *ms.rbegin();
    cout << val << endl;

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