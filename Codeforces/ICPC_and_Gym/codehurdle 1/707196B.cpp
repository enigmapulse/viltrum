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
    vector<ll> M(n); inarr(M, n);
    vector<ll> V(n); inarr(V, n);
    vector<ll> C(n); inarr(C, n);

    auto chk = [&] (ll cost) {
        ll idx = 0;
        while(idx < n) {
            ll curr = 0, instbl = 0, sz = 0;
            while(idx < n) {
                instbl += curr * V[idx];
                curr += M[idx];
                if(instbl + C[idx] <= cost) {
                    idx++; sz++;
                }
                else break;
            }
            if(sz == 0) return false;
        }
        return true;
    };

    ll lo = 
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