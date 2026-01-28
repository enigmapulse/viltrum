#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    /*
    since the final array is decreasing and our required array is increasing
    they can only intersect at one point so I can before doing op2 gain at max
    1 point. if my original array gives me 1 or more point it is always wise to
    take it right there. otherwise I might continue with it before flushing it.
    well on a sidenote my last ops should be flush one (trivial) 
    if my starting array were all zeros then I would keep doing op1 until I get one point 
    after which I would flush. but I would get 1 point in the firs op itself since a[1] = 1
    ok great so if my starting array is zero or it gives me > 0 points both cases are done
    what if my og array is not zero and it doesn't even give me points? is it wise to 
    just flush it in the first attempt and go ahead and try other options or should I stick
    with it. the fact that my og array didn't give me any points proves that it must be
    ascending in order. otherwise it would have intersected with the required array somewhere
    and it would have to be below that req line since the max lim is n but if it were then the
    first element would be less than 1. but wait clearly there exists array which don't give 
    points. there is a flaw with my reasoning. I am assuming it would intersect as if it's a 
    continuous valued path but it isn't. there is discreteness so this last arg doesn't hold
    but the above ideas were fine the formed array can't have more than 1 intersection and
    the strategy is correct for empty and point giving arrays. but it is really a turns wasting
    effort to try getting a point from the og array . because it might take more than 1 turns
    to even get it valid. and just doing that a[1] = 1 strategy would be better there is just a 
    edge case when number of turns is 2 where keeping the og array might be useful none other
    okay I just ealized my entire idea was fluke. there can be ways to get more than 1 point 
    from the og array (not if we start from 0 array though). so I guess just bruteforcing and
    checking at each step the score we get if we flush our og array now might be a way to solve
    my logic btw failed for this case as the og array need not be decreasing after doing the ops
    so there might be more than 1 interaction. I guess a hard upper limit would be doing it n 
    times. but no that is not true what if some elements are 4 steps behind their index
    repeating two ops in that case for n = 2 might actually do the trick. actualyy I might
    store how many turns would it take for each a[i] in og array to actually be considered but 
    that's complicated since it would be unafected for some turns and a lot if ifs and buts
    I am really lost here. I thought of simulating but stopped thinking if d is much larger
    than n then it might be arrive at the good array in more than n steps and I had no idea
    how many steps I think it can be more than n. but wait I can for guarantee get 1 point
    for two turns so I need to simulate only for 2*n turns because the og array can not provide
    me with more than n valid i. 
    */

    ll n, k, d; cin >> n >> k >> d;
    vector<ll> a(n); inarr(a, n);
    vector<ll> v(k); inarr(v, k);

    auto chk = [&] () {
        ll cnt = 0;
        for (ll i = 0; i < n; i++) {
            cnt += (a[i] == i + 1);
        }
        return cnt;
    };
    
    ll og_points = chk();

    if(d == 1) {
        cout << og_points << endl;
        return;
    }
    
    ll ans = og_points;
    for (ll i = 0; i < min(d, 2*n); i++) {
        ll rem = d - i - 1;
        ans = max(ans, og_points + rem / 2);

        ll idx = i % k;
        for (ll j = 0; j < v[idx]; j++) a[j]++;
        og_points = chk();
    }
    
    cout << ans << endl;
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