#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> a(m); inarr(a, m);
    vector<ll> x(n), y(n), z(n);
    for (ll i = 0; i < n; i++) cin >> x[i] >> y[i] >> z[i];
    
    ll sm = accumulate(all(y), 0LL);
    if(sm > k) {cout << 0 << endl; return;}
    k -= sm;

    // for each gift I have try satisfying the max z[i] guy with it
    // but what if I have 2 beauty gift and there is a guy with  only req of 1 
    // but has the highest z[i] so I will iterate the gifts in ascending order
    // for each gift find the max cost guy I can satisfy with it
    // and erase it this ensures that for the current gift no gift before it could have 
    // satidfied it so it takes care of the problem above
    // after I am done with beauty gifting all we need to do is iterate over the
    // remaning z[i] and see how many of them we can support with our cost

    sort(all(a));
    ll cnt = 0;
    struct F {
        ll beauty, cost;
        bool operator<(const F& other) const {
            return beauty < other.beauty;
        }
    };

    vector<F> f;
    for (ll i = 0; i < n; i++) {
        f.push_back({x[i], z[i] - y[i]});
    }
    sort(all(f)); // increasig order of beauty req
    priority_queue<ll> cost; // for storing the cost of all the valid elem till now
    ll idx = 0;
    for(auto box : a) {
        // so I need to store all the values with beauty less 
        // than or equal to this box value as these will eb valid values
        // for future boxes too
        while(idx < n && f[idx].beauty <= box) {cost.push(f[idx].cost); ++idx;}

        // use the current box for the most expensive one you can use it for
        if(!cost.empty()) {cost.pop(); ++cnt;}
    }

    // after we are done with gifts now the money thing
    for (ll i = idx; i < n; i++) cost.push(f[i].cost); // push the remaining ones
    
    vector<ll> q;
    while(!cost.empty()) {
        q.push_back(cost.top()); cost.pop();
    }

    while(k && !q.empty()) {
        ll min_cost = q.back();
        if(k - min_cost >= 0) {++cnt; k -= min_cost; q.pop_back();}
        else break;
    }

    cout << cnt << endl;
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