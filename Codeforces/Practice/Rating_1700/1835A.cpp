#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll MOD = 998244353;

ll binpow(ll base, ll exp) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

using namespace std;

bool multipleTests = true;

void solve() {
    ll a, b, c, k; cin >> a >> b >> c >> k;

    if(c < max(a, b)) {
        cout << -1 << endl;
        return;
    }
    
    ll A = binpow(10, a);
    ll B = binpow(10, b);
    ll C = binpow(10, c);

    /*
    from A = 10^a-1 to x what is the sum of choices?
    */
    auto f = [&] (ll y) {
        y = min(y, C - B / 10);
        if (y < A / 10) return 0LL;
        ll chk1 = max(A / 10 - 1, C / 10 - B / 10);
        ll chk2 = max(chk1, C - B);
        ll sm = 0;
        ll area1 = ((chk1 - A / 10 + 1) * (chk1 + A / 10 + 2 * B - C / 5)) / 2;
        ll area2 = (chk2 - chk1) * (B - B / 10);

        if(y < chk1) sm += ((y - A / 10 + 1) * (y + A / 10 + 2 * B - C / 5)) / 2;
        else if(y < chk2) {
            sm += area1;
            sm += (y - chk1) * (B - B / 10);
        }
        else {
            sm += area1 + area2;
            ll first_term = C - B / 10 - (chk2 + 1);
            ll last_term = C - B / 10 - y;
            sm += (y - chk2) * (first_term + last_term) / 2;
        }
        return sm;
    };

    if(k > f(A - 1)) {
        cout << -1 << endl;
        return;
    }

    ll lo = A / 10, hi = A - 1;
    while(lo < hi) {
        ll mid = lo + (hi - lo)/2;
        if(f(mid) >= k) hi = mid;
        else lo = mid + 1;
    }

    ll C_min = max(B / 10 + lo, C / 10); 
    ll extra = k - f(lo - 1);

    cout << lo << " + " << C_min + extra - 1 - lo << " = " << C_min + extra - 1 << endl;
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