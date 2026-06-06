#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll INF  = 1e15;
#define plb  pair<ll, bool>

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n); inarr(a, n);

    vector<ll> z = {-1};
    vector<ll> neg(n, 0), two(n, 0);
    for (ll i = 0; i < n; i++) {
        if(a[i] == 0) z.push_back(i);
    }
    z.push_back(n);

    ll mx = 0; ll l = 0, r = -1;
    for (ll s = 0; s < z.size() - 1; s++) {
        ll start = z[s];
        ll end = z[s + 1];
        if(start + 1 == end) continue;
        ll tot = 0; ll parity = 0;

        plb first_neg = {start, false}; ll ct1 = 0;
        plb last_neg = {end, false}; ll ct2 = 0;
        for (ll i = start + 1; i < end; i++) {
            if(!first_neg.second && abs(a[i]) == 2) ct1++;

            if(a[i] < 0) {
                ct2 = 0; parity++;
                if(!first_neg.second) {
                    first_neg.first = i;
                    first_neg.second = true;
                } 
                last_neg.first = i;
            }

            if(!last_neg.second && abs(a[i]) == 2) ct2++;
            if(abs(a[i]) == 2) tot++;
        }
        if(parity & 1) {
            if(mx < tot - ct1) {
                mx = tot - ct1;
                l = first_neg.first + 1, r = end - 1;
            }
            if(mx < tot - ct2){
                mx = tot - ct2;
                l = start + 1, r = last_neg.first - 1;
            }
        }
        else if(mx < tot) {
            mx = tot;
            l = start + 1, r = end - 1;
        }
    }

    cout << l << " " << n - 1 - r << endl;
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