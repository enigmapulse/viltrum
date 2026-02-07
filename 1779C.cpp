#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define pll pair<ll, ll>

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n); inarr(a, n);

    if(n == 1) {
        cout << 0 << endl;
        return;
    }

    ll cnt = 0,cnt1=0; 
    if(a[k - 1] > 0) {a[k - 1] *= -1; cnt1++;}

    vector<ll> pre(n, 0); pre[0] = a[0];
    for(ll i = 1; i < n; i++) pre[i] = pre[i - 1] + a[i];

    ll target = pre[k - 1];

    set<ll> s; ll curr = 0;
    bool flag = false;
    ll num = target;
    do {
        flag = false;
        s.clear();
        curr=0;
        cnt=0;
        for (ll i = 0; i < k; i++) {
            s.insert(a[i]); curr += a[i];
            if(curr < target) {
                auto it = s.begin();
                ll val = (-1) * (*it);
                s.erase(it); s.insert(val);
                curr += 2 * val;
                target += 2*val;
                cnt++;
            }
            if(curr<target){
                flag = true;
                num = min(target,curr);
            }
        }

        ll diff = target - num;

        while(diff>0){
            auto it = s.end();
            it--;
            diff-=2*(*it);
            target-=2*(*it);
            s.erase(it);
            cnt1++;
        }
        
    } while(flag);
    
    s.clear(); curr = 0;
    for (ll i = k; i < n; i++) {
        s.insert(a[i]); curr += a[i];
        if(curr < 0) {
            auto it = s.begin();
            ll val = (-1) * (*it);
            s.erase(it); s.insert(val);
            curr += 2 * val;
            cnt++;
        }
    }

    cout << cnt+cnt1 << endl;
    
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