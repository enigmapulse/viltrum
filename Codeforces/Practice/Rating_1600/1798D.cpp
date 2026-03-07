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
    ll mx = *max_element(all(a));
    ll mn = *min_element(all(a));

    if(n == 1 || mx == mn) {
        cout << "No" << endl;
        return;
    }

   vector<ll> pos, neg;
   for (ll i = 0; i < n; i++) {
    if(a[i] >= 0) pos.push_back(a[i]);
    else neg.push_back(a[i]);
   }
   
   sort(all(pos), greater<ll>()); sort(all(neg));
   vector<ll> ans; ll curr = 0;
   auto it = pos.begin(), ut = neg.begin();
    while(true) {
        bool done = false;
        if (curr > 0) {
            if(ut != neg.end() && curr + *ut > mn) {
                ans.push_back(*ut); curr += *ut; ++ut; done = true;
            } else if(it != pos.end() && curr + *it <= mx) {
                ans.push_back(*it); curr += *it; ++it; done = true;
            }
        } else {
            if(it != pos.end() && curr + *it <= mx) {
                ans.push_back(*it); curr += *it; ++it; done = true;
            } else if(ut != neg.end() && curr + *ut > mn) {
                ans.push_back(*ut); curr += *ut; ++ut; done = true;
            }
        }

        if(!done) break;
    }

   if(ans.size() == n) {
        cout << "Yes" << endl;
        for(auto e : ans) cout << e << " ";
        cout << endl;
   }
   else cout << "No" << endl;
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