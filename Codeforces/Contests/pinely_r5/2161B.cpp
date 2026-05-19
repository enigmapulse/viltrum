#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

struct DSU {
    vector<ll> parent;
    vector<ll> size;

    DSU(ll n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        iota(all(parent), 0);
    }

    ll find(ll v) {
        if (v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }

    bool unite(ll a, ll b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            return true;
        }
        return false;
    }
};

void solve() {
    ll n; cin >> n;
    vector<string> a(n); inarr(a, n);

    set<ll> s, t;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            if(a[i][j] == '#') {
                s.insert((i + j) %  3);
                t.insert((i - j + 4) % 3);
            }
        }
    }
    
    if(s.size() <= 2 || t.size() <= 2) {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
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