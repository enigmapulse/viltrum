#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
ll MAXN (1e6 + 1);

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, m; cin >> n >> m;
    vector<ll> a(n), b(m); inarr(a, n); inarr(b, m);
    
    sort(all(a)); 
    a.erase(unique(all(a)), a.end());

    MAXN = n + m + 1;
    vector<ll> div(MAXN, 0);
    for(auto x : a) {
        for (ll i = x; i < MAXN; i += x) div[i]++;
    }

    ll Alice = 0, Bob = 0, Both = 0;
    for (ll j = 0; j < m; j++) {
        if(div[b[j]] == a.size()) Alice++;
        else if(div[b[j]] == 0) Bob++;
        else Both++;
    }
    
    if(Both & 1) {
        if(Alice >= Bob) cout << "Alice" << endl;
        else cout << "Bob" << endl;
    }
    else {
        if(Alice > Bob) cout << "Alice" << endl;
        else cout << "Bob" << endl;
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