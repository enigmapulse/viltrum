#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll INF = 1e15;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n); inarr(a, n);
    
    multiset<ll> left, curr, right;
    for (ll i = 0; i < n; i++) {
        if(i < k) curr.insert(a[i]);
        else right.insert(a[i]);
    }

    for (ll i = 0; i < n - k + 1; i++) {
        ll mx = *(prev(curr.end()));
        ll mn = *(curr.begin());
        bool chk1 = (left.empty() || *(prev(left.end())) <= mn);
        bool chk2 = (right.empty() || *(right.begin()) >= mx);
        if(chk1 && chk2) {
            cout << "Yes" << endl;
            // cerr << i << endl;
            return;
        }
        curr.erase(curr.find(a[i]));
        left.insert(a[i]);
        if(!right.empty()) {
            right.erase(right.find(a[i + k]));
            curr.insert(a[i + k]);
        }
    }
    cout << "No" << endl;
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