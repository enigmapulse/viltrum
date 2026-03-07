#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    // the given condition basically says that if a < b then c must be less than both of them
    // ensuring that the chain of LDS is broken by only two elements at max
    // so for a given range we can choose all the elements in it - the number of such increasing duos

    ll n; cin >> n;
    vector<ll> a(n); inarr(a, n);

    ll contri = 0;
    for (ll i = 0; i < n - 1; i++) {
        if(a[i] < a[i + 1]) contri += (i + 1) * (n - i - 1);    
    }
     
    ll tot = (n*(n + 1)*(n + 2))/6;
    cout << tot - contri << endl;

    // lot of interesting dp soln too
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