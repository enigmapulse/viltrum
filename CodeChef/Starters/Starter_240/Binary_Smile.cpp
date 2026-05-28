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
    string A, B; cin >> A >> B;
    ll ops = 0;
    vector<ll> idx1, idx2;
    for (ll i = 0; i < n; i++) {
        if(A[i] == '1') idx1.push_back(i);
        if(B[i] == '1') idx2.push_back(i);
    }
    
    if(idx1.size() != idx2.size()) cout << -1 << endl;
    else {
        ll t = idx1.size();
        for (ll i = 0; i < t; i++) {
            if(idx1[i] != idx2[i]) ops++;
        }
        cout << ops << endl;
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