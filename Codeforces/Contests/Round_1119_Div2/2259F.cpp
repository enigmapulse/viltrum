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

    deque<ll> val;
    ll cnt = 0;
    ll tot = 0;
    for (ll i = n - 1; i >= 0; i--) {
        if(a[i] == 0) cnt++;
        else if(cnt) {val.push_back(cnt); tot += cnt;}
    }

    cout << tot << " ";

    ll curr = 0;
    for(auto x : s) {
        if(val.empty()) {cout << 0 << " "; continue;}
        if(x == '1') {
            tot -= val.back() - curr;
            val.pop_back();
        }
        else {
            curr++;
            tot -= val.size();
            while (!val.empty() && val.front() == curr) {
                val.pop_front();
            }
        }
        // for(auto x : val) cerr << x << " ";
        // cerr << endl;
        cout << tot << " ";
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