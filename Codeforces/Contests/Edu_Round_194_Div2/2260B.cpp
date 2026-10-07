#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll a, b, k; cin >> a >> b >> k;

    if(a == b) {
        cout << 0 << endl;
        return;
    }

    ll tot = 0;
    tot = (k * (2 * b + k - 1))/2; 
    ll curr = b / a; 
    ll others = 0;
    ll i = 0;

    while (curr != 0) {
        ll l = 0;
        if(curr != 1) {l = (b - curr * a) / (curr - 1) + 1; l = min(l, k);}
        else l = k;
        ll people = ((l - i) * (2 * a + l + i - 1)) / 2;
        others += people * curr;
        curr--; i = l;
    }

    cout << tot - others << endl;
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