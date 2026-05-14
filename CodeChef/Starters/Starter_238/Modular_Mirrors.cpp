#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, m; cin >> n >> m;
    if(n % 3 != 2) {
        cout << -1 << endl;
        return;
    }

    ll sz = 0; ll flip = 0;
    while(sz < n - 2) {
        if(!flip) {
            cout << "1 1 0 ";
            sz += 3;
            flip = flip ^ 1;
        } 
        else {
            cout << m - 1 << " ";
            cout << m - 1 << " ";
            cout << 0 << " ";
            sz += 3;
            flip = flip ^ 1;
        }
    }

    if(!flip) {
        cout << "1 1";
        sz += 2;
        flip = flip ^ 1;
    } 
    else {
        cout << m - 1 << " ";
        cout << m - 1 << " ";
        sz += 2;
        flip = flip ^ 1;
    }
    cout << endl;
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