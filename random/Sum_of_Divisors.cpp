#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll MOD = 1e9 + 7;

using namespace std;

bool multipleTests = false;

void solve() {
    ll n; cin >> n;

    ll cnt = (n * (n + 1)) / 2; cnt = cnt % MOD;
    for (ll i = 1; i <= (n / 2); i++) {
        cnt += (((n / i) - 1) * i) % MOD;
        cnt = cnt % MOD;
    }

    /*
    1 2 3 4 5
    1 1 1 1 1
    _ 2 _ 2 _
    _ _ 3 _ _
    _ _ _ 4 _ 
    _ _ _ _ 5

    1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20
1   1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1  1 done
2   _  2  _  2  _  2  _  2  _  2  _  2  _  2  _  2  _  2  _  2 done
3   _  _  3  _  _  3  _  _  3  _  _  3  _  _  3  _  _  3  _  _ done
4   _  _  _  4  _  _  _  4  _  _  _  4  _  _  _  4  _  _  _  4
5   _  _  _  _  5  _  _  _  _  5  _  _  _  _  5  _  _  _  _  5
6   _  _  _  _  _  6  _  _  _  _  _  6  _  _  _  _  _  6  _  _ not done
7   _  _  _  _  _  _  7  _  _  _  _  _  _  7  _  _  _  _  _  _
8   _  _  _  _  _  _  _  8  _  _  _  _  _  _  _  8  _  _  _  _
9   _  _  _  _  _  _  _  _  9  _  _  _  _  _  _  _  _  9  _  _
10  _  _  _  _  _  _  _  _  _ 10  _  _  _  _  _  _  _  _  _ 10 done
11  _  _  _  _  _  _  _  _  _  _ 11  _  _  _  _  _  _  _  _  _
12  _  _  _  _  _  _  _  _  _  _  _ 12  _  _  _  _  _  _  _  _
13  _  _  _  _  _  _  _  _  _  _  _  _ 13  _  _  _  _  _  _  _
14  _  _  _  _  _  _  _  _  _  _  _  _  _ 14  _  _  _  _  _  _
15  _  _  _  _  _  _  _  _  _  _  _  _  _  _ 15  _  _  _  _  _
16  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _ 16  _  _  _  _
17  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _ 17  _  _  _
18  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _ 18  _  _
19  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _ 19  _
20  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _  _ 20 done

    */
    
    cout << cnt % MOD << endl;
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