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

    vector<ll> start, end;
    ll last = -1;
    for (ll i = 0; i < n; i++) {
        if(a[i] == 1) {
            start.push_back(i);
            end.push_back(i);
        }
        else if(a[i] == -1) {
            start.push_back(i);
            last = i;
        }
    }

    ll mx = 0;
    ll l = -1, r = -1;
    for(auto x : start) {
        auto it = upper_bound(all(end), x);
        if(it == end.end()) {
            if(last == -1) continue;
            ll curr = last - x;
            if(curr > mx) {
                mx = curr;
                l = x; r = last;
            }
            continue;
        }
        ll cur = *it - x;
        if(cur > mx) {
            mx = cur;
            l = x; r = *it;
        }
    }

    if(l == -1) {
        for(auto x : a) {
            if(x == -1) cout << 1 << " ";
            else cout << x << " ";
        }
        cout << endl;
    }
    else {
        a[l] = 1; a[r] = 1;
        for(auto x : a) {
            if(x == -1) cout << 0 << " ";
            else cout << x << " ";
        }
        cout << endl;
    }

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