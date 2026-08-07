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
    vector<ll> b, c;
    ll buf1 = 0, buf2 = 0;
    for (ll i = 0; i < n; i++) {
        if(i & 1) if(a[i] != 0) b.push_back(a[i]); else buf1++;
        else if(a[i] != 0) c.push_back(a[i]); else buf2++;
    }
    reverse(all(b)); reverse(all(c));
    
    vector<ll> res(n);
    ll idx = 0;
    while (!b.empty() && !c.empty()) {
        ll f = b.back();
        ll s = c.back();
        if(idx & 1) {
            if(f <= s) {
                b.pop_back();
                res[idx] = f;
            }
            else {
                if(buf1) {res[idx] = 0; buf1--;}
                else {
                    cout << "NO" << endl;
                    return;
                }
            }
            idx++;
        }
        else {
            if(s <= f) {
                c.pop_back();
                res[idx] = s;
            }
            else {
                if(buf2) {res[idx] = 0; buf2--;}
                else {
                    cout << "NO" << endl;
                    return;
                }
            }
            idx++;
        }
    }

    while(!b.empty()) {
        res[idx] = b.back();
        b.pop_back();
        idx++;
    }

    while(!c.empty()) {
        res[idx] = c.back();
        c.pop_back();
        idx++;
    }

    vector<ll> fin;
    for (ll i = 0; i < n; i++) {
        if(res[i] != 0) fin.push_back(res[i]);
    }
    vector<ll> sorted = fin; sort(all(sorted));
    if(fin == sorted) {
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