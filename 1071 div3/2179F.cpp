#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve1() {
    ll n, m; cin >> n >> m;
    vector<vector<ll>> adj(n + 1);
    for (ll i = 0; i < m; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<ll> dist(n + 1, -1); dist[1] = 0;
    queue<ll> q; q.push(1);
    while(!q.empty()) {
        ll u = q.front(); q.pop();
        for(auto child : adj[u]) {
            if(dist[child] == -1) {
                dist[child] = dist[u] + 1;
                q.push(child);
            }
        }
    }

    string col(n, ' ');
    for (ll i = 0; i < n; i++) {
        ll x = dist[i + 1];
        if(x % 3 == 0) col[i] = 'r';
        else if(x % 3 == 1) col[i] = 'g';
        else col[i] = 'b';
    }
    
    cout << col << endl;
}

void solve2() {
    ll q; cin >> q;
    while(q--) {
        ll n; cin >> n;
        string s; cin >> s;
        set<ll> t;
        for(auto ch : s) {
            if(ch == 'r') t.insert(0);
            if(ch == 'g') t.insert(1);
            if(ch == 'b') t.insert(2);
        }

        if(t.size() == 1) {
            cout << 1 << endl;
            continue;
        }

        ll chosen = 0;
        for(ll i = 0; i < 3; ++i) {
            if(t.find(i) == t.end()) {chosen = (i + 2) % 3; break;}
        }
        char x;
        if(chosen == 0) x = 'r';
        else if(chosen == 1) x = 'g';
        else x=  'b';

        for (ll i = 0; i < s.size(); i++) {
            if(s[i] == x) {
                cout << i + 1 << endl;
                break;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string c; cin >> c;
    int T = 1;
    if (multipleTests)
        cin >> T;
    while (T--) {
        if(c == "first") solve1();
        else solve2();
    }
    return 0;
}