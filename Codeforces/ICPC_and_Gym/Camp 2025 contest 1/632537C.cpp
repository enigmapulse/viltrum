#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, a, b; cin >> n >> a >> b;
    
    vector<double> p(n + 1, 0), sm(n + 1, 0);
    
    for (ll i = 1; i <= n; i++) {
        if(a == 0) {
            double sum = 1;
            sum += (sm[i - 1] - (i > b ? sm[i - b - 1] : 0));
            p[i] = (sum / b) + 1;
        }
        else {
            double sum = 0;
            ll cnt = (b - a + 1);
            if(i >= a) sum += (sm[i - a] - (i > b ? sm[i - b - 1] : 0));
            p[i] = (sum / cnt) + 1;
        }
        sm[i] = p[i];
        sm[i] += sm[i - 1];
    }
    cout << fixed << setprecision(5) << p[n] << endl;

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