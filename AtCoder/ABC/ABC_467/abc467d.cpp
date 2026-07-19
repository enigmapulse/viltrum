#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll px, py, qx, qy, rx, ry, sx, sy; 
    cin >> px >> py >> qx >> qy >> rx >> ry >> sx >> sy;
    ll val1 = (qy - py) * (sx - rx);
    ll val2 = (sy - ry) * (qx - px);
    if(val1 != val2) {
        cout << "Yes" << endl;
        return;
    } 
    if(px + qx == rx + sx && py + qy == ry + sy) {
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
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