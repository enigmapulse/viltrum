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

    vector<ll> idx; ll i = n - 1; ll cnt = 0;
    while(i >= 0) {
        if(cnt & 1) {
            if(a[i] < 0) {idx.push_back(i); cnt++;}
        }
        else if (a[i] > 0) {idx.push_back(i); cnt++;}
        while(i >= 0 && a[i] > 0 && (cnt & 1)) i--;
        while(i >= 0 && a[i] < 0 && !(cnt & 1)) i--;
    }

    
    cout << idx.size() << endl;
    for (ll i = 0; i < idx.size(); i++)
    {
        cout << idx[i] + 1 << " ";
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