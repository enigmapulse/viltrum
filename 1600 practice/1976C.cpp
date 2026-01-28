#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll p, t; cin >> p >> t; // required programmers and testers
    vector<ll> ps(p + t + 1), ts(p + t + 1); // skill set
    inarr(ps, p + t + 1); inarr(ts, p + t + 1);

    ll idx = -1; // where does jobs first exhaust
    ll job = 0; // whose job exhausts first
    ll cntp = 0, cntt = 0;
    for (ll i = 0; i < p + t + 1; i++) {
        if(ps[i] > ts[i]) {
            if(cntp < p) cntp++;
            else {idx = i; job = 1; break;}
        }
        if(ps[i] < ts[i]) {
            if(cntt < t) cntt++;
            else {idx = i; break;}
        }
    }
     
    ll tot = 0;
    for (ll i = 0; i < p + t + 1; i++) {
        if (i < idx) {
            tot += max(ps[i], ts[i]); 
        } else if (job) {
            tot += ts[i]; 
        } else {
            tot += ps[i];
        }
    }
    
    for (ll i = 0; i < p + t + 1; i++) {
        ll curr = tot;
        // if I remove the ith one
        if(idx >= i) {
            // if current one was a programmer
            if(ps[i] > ts[i]) {
                // and programmer's job was filled first
                if(job) {
                    // then ew have a chance to fill up one more prrgammer
                    curr += ps[idx] - ts[idx] - ps[i];
                }
                else {
                    // testers were filled first then there is nothing much to do
                    curr -= ps[i];
                }
            }
            else {
                if(job) curr -= ts[i];
                else curr += ts[idx] - ps[idx] - ts[i]; 
            }
        }
        else {
            // we are not working merit based now
            // just filling the vacancies so removing nothing happens
            if(job) curr -= ts[i];
            else curr -= ps[i];
        }

        cout << curr << " ";
    }
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