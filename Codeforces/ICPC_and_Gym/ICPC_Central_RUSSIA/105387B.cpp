#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n, m, k; cin >> n >> m >> k;
    map<ll, vector<ll>> row, col;
    for (ll i = 0; i < k; i++) {
        ll r, c; cin >> r >> c;
        row[r].push_back(c); 
        col[c].push_back(r);
    }
    
    ll cr = 0, cc = 0, kill = 0;

    // checking for the row
    for(auto &[r, vals] : row) {
        sort(all(vals));
        ll cand_kill = 0, candr = 0, candc = 0;
        for(ll i = 0; i < vals.size(); ++i) {
            if(i == 0) {
                if(vals[0] != 1 && vals.size() > cand_kill) {
                    candr = r; candc = 1;
                    cand_kill = vals.size();
                }
                continue;
            }
            if(vals[i] - vals[i - 1] > 1 && max(i, (ll)vals.size() - i) > cand_kill) {
                candr = r; candc = vals[i] - 1;
                cand_kill = max(i, (ll)vals.size() - i);
            }
        }
        if(vals.back() != m && vals.size() > cand_kill) {
            candr = r; candc = m;
            cand_kill = vals.size();
        }

        if(cand_kill > kill) {
            kill = cand_kill;
            cr = candr; cc = candc;
        }
    }

    // checking for the col
    for(auto &[c, vals] : col) {
        sort(all(vals));
        ll cand_kill = 0, candr = 0, candc = 0;
        for(ll i = 0; i < vals.size(); ++i) {
            if(i == 0) {
                if(vals[0] != 1 && vals.size() > cand_kill) {
                    candr = 1; candc = c;
                    cand_kill = vals.size();
                }
                continue;
            }
            if(vals[i] - vals[i - 1] > 1 && max(i, (ll)vals.size() - i) > cand_kill) {
                candr = vals[i] - 1; candc = c;
                cand_kill = max(i, (ll)vals.size() - i);
            }
        }
        if(vals.back() != n && vals.size() > cand_kill) {
            candr = n; candc = c;
            cand_kill = vals.size();
        }
        if(cand_kill > kill) {
            kill = cand_kill;
            cr = candr; cc = candc;
        }
    }

    cout << kill << endl;
    cout << cr << " " << cc << endl;
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