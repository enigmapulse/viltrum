#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

const int MAXN = 10000005;
const int MAXS = 20000005; 

static int divsum[MAXN];
vector<int> mp; 

void build() {
    for (int i = 1; i < MAXN; ++i) {
        for (int j = i; j < MAXN; j += i) {
            divsum[j] += i;
        }
    }

    mp.assign(MAXS, -1);
    for (int i = 0; i < MAXN; ++i) {
        int s = divsum[i];
        if (s >= 0 && s < MAXS && mp[s] == -1) {
            mp[s] = i;
        }
    }
}

void solve() {
    int n; cin >> n;
    if (n < 0 || n >= MAXS || mp[n] == -1) cout << -1 << '\n';
    else cout << mp[n] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    build();
    if (multipleTests)
        cin >> T;
    while (T--)
        solve();
    return 0;
}
