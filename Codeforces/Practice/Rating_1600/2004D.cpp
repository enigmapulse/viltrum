#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    // if there is something common between two nodes then we directly jump
    // other wise situation is like this xy ... zw
    // now if there is any element ahead of xy which shares either x or y then 
    // we get to destination in two jumps
    // both of these paths have the same cost
    // if that is not the case then we would have to jump backwards
    // now we will again jump to something that shares a letter
    // we again reach in two steps but now we had a different cost
    // ohh there is another one where you have to jump after the target and then comeback
    // to the target this also has a different cost
    // so there are three cases basically
    // 1) we share an edge with target -> cost = distance
    // 2) we share an edge with anything else that is not exact copy of me call it v
    // 2a) v lies in between me and target -> cost = distance
    // 2b) v lies outside this range -> cost = distnace + 2 * nearest v
    // it never makes sense to jump to an exact copy of myself
    // since whatever I could do there I can do here too without additional cost
    // if I can jump to anything that is not me then I can definitely reach the target
    // now the issue is cost calculation in the second case
    // there is just proper implementation
    // what if I mantain a list of each node I can connect to
    // so for like xy I mantain a list of all nodes sharing x or y
    // now when I need to get to the target then I iterate over these nodes
    // well stop there, I might have to iterate over all the nodes in this case
    // and If I do this for q queries then it is definitely TLE
    // we can't mantain for each node the nearest possible neighbour 
    // since there might be a closer node to the right but a farther node leads there
    // with lesser cost (due to lying between me and target)
    // also I am assuming here that I lie on the left and my target is on the right however that
    // might not be the case
    // so actally it is best to mantain two neighbors where you could go on
    // your left and right and they are not an exact copy of you
    // and then take the min of both of these neighbors to the target
    // this is correct and fast enough
    // how to implement effectively
    // 

    ll n, q; cin >> n >> q;
    vector<string> a(n); inarr(a, n);

    auto f = [&] (ll u, ll v) {
        for(auto ch1 : a[u]) {
            for(auto ch2 : a[v]) {
                if(ch1 == ch2) return true;
            }
        }
        return false;
    };

    map<string, ll> mp1, mp2;
    vector<ll> left(n, -1), right(n, 1e12);
    for (ll i = 0; i < n; i++) {
        mp1[a[i]] = i;
        for(auto [s, idx] : mp1) {
            if(f(idx, i) && s != a[i]) left[i] = max(left[i], idx);
        }

        ll j = n - 1 - i;
        mp2[a[j]] = j;
        for(auto [s, idx] : mp2) {
            if(f(idx, j) && s != a[j]) right[j] = min(right[j], idx);
        }
    }
    
    while(q--) {
        ll u, v; cin >> u >> v;
        u--, v--;
        if(f(u, v)) {cout << abs(v - u) << endl; continue;}
        ll ans1 = 1e12; ll ans2 = 1e12;
        if(left[u] != -1) ans1 = abs(u - left[u]) + abs(left[u] - v);
        if(right[u] != -1) ans2 = abs(u - right[u]) + abs(right[u] - v);
        ll ans = min(ans1, ans2);
        if(ans == 1e12) cout << -1 << endl;
        else cout << ans << endl;
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