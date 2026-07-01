#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll r, c; cin >> r >> c;
    ll folds; cin >> folds;
    
    struct fold {
        char dir;
        ll k;
    };
    vector<fold> ops(folds);
    for (ll i = 0; i < folds; i++) {
        fold op;
        cin >> op.dir >> op.k;
        ops[i] = op;
    }
    
    vector<vector<char>> crease(2*r, vector<char> (2*c));
    ll cx=1, cy=1;
    for (ll i = 0; i < folds; i++) {
        if(ops[i].dir == 'T') cx += ops[i].k;
        if(ops[i].dir == 'L') cy += ops[i].k;
    }
    
    // cs, cy now store the final position of the 1 cross 1 grid
    // problem is that I didn't consider that the crease could have come from a larger folding
    crease[2*cx - 1][2*cy - 1] = '.';
    cx = 2*cx - 1, cy = 2*cy - 1;
    ll l = 1, w = 1;
    auto f = [&] (ll idx) {
        if(ops[idx].dir == 'T') {
            for (ll i = 0; i < 2*l - 1; i++)  {
                crease[cx - 1][cy + i] = 'V';
            }
            for (ll i = 0; i < 2*ops[idx].k - 1; i++) {
                for (ll j = 0; j < 2*l - 1; j++) {
                    if(crease[cx + i][cy + j] == '.') crease[cx - 2 - i][cy + j] = '.';
                    else if(crease[cx + i][cy + j] == 'V') crease[cx - 2 - i][cy + j] = 'M';
                    else if(crease[cx + i][cy + j] == 'M') crease[cx - 2 - i][cy + j] = 'V';
                }
            }
            w += ops[idx].k;
            cx = cx - 2 * ops[idx].k;
        }
        if(ops[idx].dir == 'B') {
            for (ll i = 0; i < 2*l - 1; i++)  {
                crease[cx + 2*w - 1][cy + i] = 'V';
            }
            for (ll i = 0; i < 2*ops[idx].k - 1; i++) {
                for (ll j = 0; j < 2*l - 1; j++) {
                    if(crease[cx + 2*w - 2 - i][cy + j] == '.') crease[cx + 2*w + i][cy + j] = '.';
                    else if(crease[cx + 2*w - 2 - i][cy + j] == 'V') crease[cx + 2*w + i][cy + j] = 'M';
                    else if(crease[cx + 2*w - 2 - i][cy + j] == 'M') crease[cx + 2*w + i][cy + j] = 'V';
                }
            }
            w += ops[idx].k;
        }
        if(ops[idx].dir == 'L') {
            for (ll i = 0; i < 2*w - 1; i++)  {
                crease[cx + i][cy - 1] = 'V';
            }
            for (ll j = 0; j < 2*ops[idx].k - 1; j++) {
                for (ll i = 0; i < 2*w - 1; i++) {
                    if(crease[cx + i][cy + j] == '.') crease[cx + i][cy - j - 2] = '.';
                    else if(crease[cx + i][cy + j] == 'V') crease[cx + i][cy - j - 2] = 'M';
                    else if(crease[cx + i][cy + j] == 'M') crease[cx + i][cy - j - 2] = 'V';
                }
            }
            l += ops[idx].k;
            cy = cy - 2 * ops[idx].k;
        }
        if(ops[idx].dir == 'R') {
            for (ll i = 0; i < 2*w - 1; i++)  {
                crease[cx + i][cy + 2*l - 1] = 'V';
            }
            for (ll j = 0; j < 2*ops[idx].k - 1; j++) {
                for (ll i = 0; i < 2*w - 1; i++) {
                    if(crease[cx + i][cy + 2*l - 2 - j] == '.') crease[cx + i][cy + 2*l + j] = '.';
                    else if(crease[cx + i][cy + 2*l - 2 - j] == 'V') crease[cx + i][cy + 2*l + j] = 'M';
                    else if(crease[cx + i][cy + 2*l - 2 - j] == 'M') crease[cx + i][cy + 2*l + j] = 'V';
                }
            }
            l += ops[idx].k;
        }
    };

    for (ll i = folds - 1; i >= 0; i--) {
        f(i);
    }
    for (ll i = 1; i <= 2*r - 1; i++) {
        for (ll j = 1; j <= 2*c - 1; j++) {
            if(i % 2 == 0 && j % 2 == 0) cout << '+';
            else cout << crease[i][j];
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