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
    vector<int> a; inarr(a, n);

    vector<int> z ={-1};
    vector<int> neg(n, 0), two(n, 0);
    for (ll i = 0; i < n; i++) {
        if(a[i] == 0) a.push_back(i);
        if(a[i] < 0) neg[i] = 1;
        if(abs(a[i]) == 2) two[i] = 1;
        if(i != 0) {
            neg[i] += neg[i - 1];
            two[i] += two[i - 1];
        }
    }
    z.push_back(n);

    ll mx = -1e15, l = n, r = 0;
    for (ll i = 0; i < z.size() - 1; i++) {
        ll left = z[i], right = z[i + 1];
        if(left == right - 1) continue;
        bool chk = ((neg[right - 1] - (left > -1 ? neg[left] : 0)) & 1);
        if(!chk) {
            ll numof2 = two[right - 1] - two[left + 1];
            if(numof2 > mx) {
                mx = numof2;
                l = left + 1;
                r = n - right + 1;
            }
        }
        else {
            auto choice1 = lower_bound(all(neg), (left > -1 ? neg[left] : 0) + 1);
            auto choice2 = upper_bound(all(neg), neg[right - 1] - 1);
            if(choice1 != neg.end() && *choice1 < right - 1 && !((neg[right - 1] - (*choice1 > -1 ? neg[*choice1] : 0)) & 1)) {
                ll numof2 = two[right - 1] - two[*choice1];
                if(numof2 > mx) {
                    mx = numof2;
                    l = *choice1 + 1;
                    r = n - right + 1;
                }
            }
            if(choice2 != neg.end() && *choice1 < right - 1) {
                ll numof2 = two[right - 1] - two[*choice1];
                if(numof2 > mx) {
                    mx = numof2;
                    l = *choice1 + 1;
                    r = n - right + 1;
                }
            }
        }
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