#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 1; _i <= (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define pll pair<ll, ll>
const ll INF = 1e17;

using namespace std;

bool multipleTests = false;

struct twoHeaps {
    ll lsz, rsz;
    ll lsm = 0, rsm = 0;
    priority_queue<ll> left; // maxHeap for left half
    priority_queue<ll, vector<ll>, greater<>> right; // minHeap for right half
    
    twoHeaps() {
        lsz = rsz = 0;
        left.push(-INF);
        right.push(INF);
    }

    void balance() {
        while (rsz != lsz && rsz != lsz + 1) {
            if(rsz > lsz) {
                lsm += right.top();
                rsm -= right.top();
                left.push(right.top());
                right.pop();
                lsz++; rsz--;
            }
            else {
                rsm += left.top();
                lsm -= left.top();
                right.push(left.top());
                left.pop();
                lsz--; rsz++;
            }
        }
    }

    void insert(ll val) {
        if(val <= left.top()) {
            left.push(val); 
            lsz++; lsm += val;
        }
        else {
            right.push(val); 
            rsz++;
            rsm += val;
        }
        balance();
    }

    ll median() {
        if(rsz >= lsz) return right.top();
        else return left.top();
    }

    ll cost() {
        ll med = median();
        ll cost = 0;
        cost += rsm - med * rsz;
        cost += med * lsz - lsm;
        return cost;
    }
};

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n + 1); inarr(a, n);

    vector<vector<ll>> dp(k + 1, vector<ll> (n + 1, INF));
    dp[0][0] = 0;

    for (ll cuts = 1; cuts <= k; cuts++) {
        for (ll idx = 1; idx <= n; idx++) {
            twoHeaps hp; hp.insert(a[idx]);
            for (ll prev = idx - 1; prev >= 0; prev--) {
                dp[cuts][idx] = min(dp[cuts][idx], hp.cost() + dp[cuts - 1][prev]);
                hp.insert(a[prev] + idx - prev);
            }
        }
    }
    cout << dp[k][n] << endl;
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