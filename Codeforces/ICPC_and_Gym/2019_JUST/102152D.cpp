#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

string dp[11][11][11][11];
bool vis[11][11][11][11];
string dfs(int pos, int a, int b, int c) {
    if (pos == 10) {
        if (a == 0 && b == 0 && c == 0) return "";
        return "#"; 
    }
    if (vis[pos][a][b][c]) return dp[pos][a][b][c];
    vis[pos][a][b][c] = true;
    string best = "";
    for (int mask = 0; mask < 8; mask++) {
        int x = (mask >> 0) & 1;
        int y = (mask >> 1) & 1;
        int z = (mask >> 2) & 1;

        if (x > a || y > b || z > c) continue;

        char cur = char('0' + (x ^ y ^ z));
        string rest = dfs(pos + 1, a - x, b - y, c - z);
        string cand = cur + rest;

        if (cand != "#" && (best == "" || cand > best)) best = cand;
    }
    return dp[pos][a][b][c] = best;
}

void solve() {
    string a, b, c; cin >> a >> b >> c;

    ll cnta = 0, cntb = 0, cntc = 0;
    for (ll i = 0; i < 10; i++) {
        cnta += (a[i] == '1');
        cntb += (b[i] == '1');
        cntc += (c[i] == '1');
    }

    cout << dfs(0, cnta, cntb, cntc) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    if (multipleTests)
        cin >> T;
    while (T--) {
        memset(vis, 0, sizeof(vis));
        solve();
    }
    return 0;
}