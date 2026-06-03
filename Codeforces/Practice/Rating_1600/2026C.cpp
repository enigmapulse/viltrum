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
    string s; cin >> s;

    ll cost = 0;
    vector<ll> taken(n, 1);
    for (ll i = 0; i < n - 1; i++) {
        if(s[i] == '0') {
            taken[i + 1] += taken[i];
            taken[i] = 0;
        }
        else {
            if(taken[i] == 1) {
                taken[i + 1] += taken[i];
                taken[i] = 0;
            }
            else {
                taken[i + 1] += taken[i] - 2;
                taken[i] = 2;
            }
        }
    }
    ll discount = 0;
    for (ll i = 0; i < n; i++) {
        if(taken[i] >= 2) discount += i + 1;
    }
    
    cout << (n * (n + 1)) / 2 - discount << endl;
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