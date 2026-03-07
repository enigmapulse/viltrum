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
    vector<ll> a(n), b(n); 
    inarr(a, n); inarr(b, n);

    // w/o any ops we have a pattern 
    // a1 b2 a3 b4 a5 ... call it c
    // b1 a2 b3 a4 b5 ... call it d
    vector<ll> c(n), d(n);
    for (ll i = 0; i < n; i++) {
        if(i & 1) {
            c[i] = b[i];
            d[i] = a[i];
        }
        else {
            c[i] = a[i];
            d[i] = b[i];
        }
    }
    
    // these are the values where we can choose an index i
    // and make all the elements before them the same

    // this can be solved in O(n) by taking the max of min of both idx of a number k form 1 to n
    map<ll, ll> mp1, mp2;
    for (ll i = 0; i < n; i++) {
        mp1[c[i]] = i; mp2[d[i]] = i;
    }
    
    ll ans = -1;
    for (ll i = 1; i <= n; i++) {
        if(mp1.find(i) != mp1.end() && mp2.find(i) != mp2.end()) ans = max(ans, min(mp1[i], mp2[i]));
    }
    
    // now when we remove something from the array
    // we have to check for both the arrays whether
    // an element is valid if freq greater than 2 and copies are not present consecutively
    // we then take the max of min idx of such valid elements for both the arrays c and d
    vector<ll> valid(n + 1, false);
    map<ll, vector<ll>> mp3, mp4;
    for (ll i = 0; i < n; i++) {
        mp3[c[i]].push_back(i);
        mp4[d[i]].push_back(i);
    }
    
    for (ll i = 1; i <= n; i++) {
        if(mp3.find(i) != mp3.end() && mp3[i].size() >= 2) {
            // we will take the min of the last 2 idxs provided
            // that the difference between those two is greater than 1
            ll cnt = -1;
            ll second = mp3[i].back();
            for (ll j = 0; j < mp3[i].size() - 1; j++) {
                ll first = mp3[i][j];
                if(second - first > 1) cnt = first;
            }
            ans = max(ans, cnt);
        }

        if(mp4.find(i) != mp4.end() && mp4[i].size() >= 2) {
            // we will take the min of the last 2 idxs provided
            // that the difference between those two is greater than 1
            ll cnt = -1;
            ll second = mp4[i].back();
            for (ll j = 0; j < mp4[i].size() - 1; j++) {
                ll first = mp4[i][j];
                if(second - first > 1) cnt = first;
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans + 1 << endl;
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