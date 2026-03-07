#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

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
    // well clearly once I start removing 0s then after that there is no point in
    // stopping mid removal. so before starting that what I can do is try removing the ones
    // we calculate the mex without 1 removal, when all the ones are removed then it would be 1
    // so in and all I have two choices r
    // 1> remove all 1s then remove all 0s
    // 2> remove all 0s
    // whichever gives me a smaller value we will do that
    // wait a second why stop at 1 only
    // we could also do another case 3> remove all 2 then remove all 1 then remove all 0
    // see one thing is clear if you set out to remove a number then it doesn't make sense
    // to take a half measure. like leavinf half 2s and wiping out the rest like it can never be 
    // optimal. so we need to decide at each step whether or not to rempve this particular element
    // or not, i guess this could be done using some other ways too but dp would be really nice
    // n is only till 5000 so this is my cue to try dp. so in a way we are on a graph after 
    // removing a partiular element we move to a new node with a new mex and the cost of the 
    // operation is the mex * the number of elements we decide to remove. so how do we build
    // this graph or maybe model it as a dp
    // so say we model it as this dp[u] that is the min cost of getting to the mex u
    // this is the first time i am able to visualize the states in the form of a graph 
    // with the problem being finding the minimum distance from a node to another node
    // but not able to write the dp comfortably

    ll n; cin >> n;
    vector<ll> a(n); inarr(a, n);

    ll mex = 0; map<ll, ll> mp;
    for(auto elem : a) mp[elem]++;
    for(ll i = 0; i <= n; ++i) if(mp[i] == 0) {mex = i; break;}
    
    vector<ll> dp(mex + 1, 1e12); dp[mex] = 0;
    for (ll i = mex; i >= 0; i--) {
        for (ll j = i - 1; j >= 0; j--) {
            dp[j] = min(dp[j], dp[i] + i * (mp[j] - 1) + j);
        }
    }

    dbg(dp);
     
    cout << dp[0] << endl;
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