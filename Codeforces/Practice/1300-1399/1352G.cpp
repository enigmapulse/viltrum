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

    if(n < 4) {cout << -1 << endl; return;}

    vector<ll> perm(n); ll curr = 5;
    deque<ll> q; 
    q.push_back(3); q.push_back(1);
    q.push_back(4); q.push_back(2);
    n -= 4;
    while(n) {
        if(curr & 1) q.push_front(curr++);
        else q.push_back(curr++);
        n--;
    }

    for(auto e : q) cout << e << " ";
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