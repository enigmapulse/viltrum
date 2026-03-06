#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;
/*
so there are choices for me whether I wanna take this or not
if I take it and it is greater than my curr value then my curr values decreases by 1
otherwise no change in curr value
I need to find out max how many I can take
so once I start reducing my curr value it doesn't make sense to stop in between and switch to the
previous method of going after those which are strictly less since in that case I would have done it
with the previous value itself so basically for each i I need to check if till this prefix I followed
taking stuff less than me only and afterwards stuff greater than me only then how many I can make and
which i would provide max
my strategy is till some prefix play safe and then aggressivelt rake whatever you can
i need to know for each i if I started playing aggressive from right here then how far I can go
but now the thing is that it keeps on reducing the threshold
that is once something comes above k next I need to see when next comes above k - 1 
and so on and so forth but how do I calculate this
so my work now is that from rach index i I wanna know how far I can go if I started from k and
reduce it if something larger comes and keep it as it is otherwise how long before k becomes 0
the problem is that the value of k keeps on changing so only counting how many are less or more than it is
not suff
I need to somehow find out the 
*/
void solve() {
    ll n, k; cin >> n >> k;
    vector<ll> a(n); inarr(a, n);

    ll tmp = k;
    vector<ll> suff(n + 1, 0);
    for (ll i = n - 1; i >= 0; i--) {
        suff[i] = suff[i + 1] + (a[i] > tmp);
        tmp--;
    }
    
    ll chosen = -1;
    ll ans = min(k, suff[0]), curr = 0;
    for (ll i = 0; i < n; i++) {
        curr += (a[i] <= k);
        if(ans < curr + min(suff[i + 1], k)) {
            chosen = i;
            ans = curr + min(suff[i + 1], k);
        }
    }
    
    for (ll i = 0; i <= chosen; i++) {
        if(a[i] <= k) cout << "1";
        else cout << "0";
    }
    for (ll i = chosen + 1; i < n; i++) {
        if(a[i] > k && k != 0) {cout << "1"; k--;}
        else cout << "0";
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