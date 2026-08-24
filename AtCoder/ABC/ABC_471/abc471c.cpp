#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n); inarr(a, n);

    priority_queue<ll> left;
    priority_queue<ll, vector<ll>, greater<ll>> right;

    for (ll i = 0; i < n; i++) {
        if(a[i] > 0) right.push(a[i]);
        else left.push(a[i]);
    }

    ll tot = 0; ll curr = 0;
    while(!left.empty() && !right.empty()) {
        auto u = left.top();
        auto v = right.top();
        if(curr - u <= v - curr) {
            tot += curr - u;
            curr = u;
            left.pop();
        }
        else {
            tot += v - curr;
            curr = v;
            right.pop();
        }
    }
    
    while(!left.empty()) {
        auto u = left.top();
        tot += curr - u;
        curr = u;
        left.pop();
    }
    
    while(!right.empty()) {
        auto v = right.top();
        tot += v - curr;
        curr = v;
        right.pop();
    }

    cout << tot << endl;
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