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
    vector<ll> a(n); inarr(a, n);

    if(n == 1){
        cout << 0 << endl;
        return;
    }

    auto chk = [&] (ll x) {
        vector<ll> score(n + 1, 0);
        for (ll i = 1; i <= n; i++) {
            if(score[i - 1] > a[i - 1]) score[i] = score[i - 1] - 1;
            else if(score[i - 1] < a[i - 1]) score[i] = score[i - 1] + 1;
            else score[i] = score[i - 1];
        }
        
        vector<ll> reql(n + 1, 0), reqr(n + 1, 0);
        reql[n] = x, reqr[n] = x;
        for (ll i = n - 1; i >= 0; i--) {
            reql[i] = reql[i + 1]; reqr[i] = reqr[i + 1];
            if(a[i] > reqr[i]) {reql[i]--; reqr[i]--;}
            else if (a[i] < reql[i]) {reqr[i]++; reql[i]++;}
            else {reql[i]--; reqr[i]++;} 
        }
        for (ll i = n - 1; i >= 0; i--) {
            reql[i] = min(reql[i], reql[i + 1]);
            reqr[i] = max(reqr[i], reqr[i + 1]);
        }

        for (ll i = 0; i < n; i++) {
            if(score[i] >= reql[i + 1] && score[i] <= reqr[i + 1]) return true;
        }
        return false;
    };

    ll lo = 0, hi = n + 1;
    while(lo < hi) {
        ll mid = lo + (hi - lo + 1)/2;
        if(chk(mid)) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << endl;
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