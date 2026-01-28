#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
const ll MOD = 1e9 + 7;

using namespace std;

template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{"; for (int i = 0; i < v.size(); ++i) { if (i) os << ", "; os << v[i]; } return os << "}";
}
template<typename... Args> void dbg_out(Args&&... args) { ((cerr << " " << args), ...) << endl; }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

bool multipleTests = true;

void solve() {
    // so basically for a given l and r if I construct a map of freq (of prefix sum)
    // then for each such range I can say that the answer is the sum of
    // fC2 where f is the frequency of 0
    // this is O(n^3) very bad
    // so say if in a range I have equal number of zeros and ones then 
    // for how many l rs would it be counted
    // it will be counted for ls starting from 0 to left index of range
    // and from right to n - 1 so product of these two
    // so if I find a range which has equal prefix sums -> that range has equal 0s and 1s
    // I multiply it with the weightage of that range based on the indices
    // if pre[a] = pre[b] then a...b - 1 is a valid range of course a < b
    // then I need to add to the answer a * (n - 1 - b) a, b are 0 based indices
    // so why not mantain a sum of all indices of elements having same prefix sum
    
    string s; cin >> s;

    vector<ll> pre(s.size() + 1, 0); 
    for (ll i = 1; i <= s.size(); i++) {
        pre[i] = pre[i - 1] + (s[i - 1] == '1' ? 1 : -1);
    }

    dbg(pre);
    
    ll ans = 0;
    map<ll, ll> mp;
    for (ll i = 0; i <= s.size(); i++) {
        ll x = pre[i];
        ans += mp[x] * (s.size() - i + 1);
        ans = ans % MOD;
        mp[x] += i + 1;
    } 

    cout << ans % MOD << endl;
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