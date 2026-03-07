#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, p; cin >> n >> p;
    /*
    well if I am starting from 1 it makes sense for me to kump to farthest
    point I can get because it is more plausible to get to n earlier using
    that. also as a side note f(A) is nothing but the shortest distance.
    so in a way keep doing i + a[i] until you surpass n. the number of steps
    it takes to do that is the f(A) value. now we need to sum this for all
    so for each f(A) i need to find out the number of possible A arrays
    which would have made it possible. so say I wanna get there in 1 step
    1 + a[1] >= n so a[1] >= n - 1 so two choices for a[1] and no restriction
    on others so this gives 2*(n - 1)! quite a big number
    let's move on now in two steps so j + a[j] >= n where j is 1 + a[1]
    this is dofficult since now we are dealing with cyclic behaviour. this
    also highlights that going to the farthest node might not always be optimal
    out of all the nodes you can go to there is this factor of i added which
    led me to believe that going to farthest node must be optimal to reach to n
    quickly but some other value might have the sum of i + a[i] higher than the 
    last value. always choosing the max a[i] one would also not work. so this is
    complicated. so I need the max among i + a[i] at any node i you can always go
    to i + 1 provided it exists ofc. so the upper bound on f(A) for any array is
    n. but how do we count the number of arrays for a fixed f(A)? 
    let's start with 2 only. so I need the max from 2 + a[2] to 1 + a[1] + a[1 + a[1]] 
    to be greater than equal to n. how the hell am I supposed to get that
    just thinking there might be another way of counting this instead of asking how
    many arrays with f(A) we can also ask how many arrays with f(A) >= k. summing those
    would automatically count f(A) multiple times since they woudl overcounted exactly 
    f(A) times. 
    chk(1) = n! all arrays take >= 1 step to reach n
    chk(2) = n! - 2*(n - 1)! we calculated earler so came in handy
    chk(3) idk how to calculate
    */
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