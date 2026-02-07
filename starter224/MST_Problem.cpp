#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n, k; cin >> n >> k;

    if(k < (n * (n - 1)) / 2 || k > ((n - 1) * ((n - 1) * (n - 1) + 1)) / 2) {
        cout << -1 << endl;
        return;
    }

    vector<ll> a(n - 1); iota(all(a), 1);
    ll curr = (n * (n - 1)) / 2, idx = n - 2;
    ll mx_diff = ((n - 2) * (n - 1)) / 2;
    while(curr < k) {
        ll req = k - curr;
        if(req >= mx_diff) {
            a[idx] += mx_diff;
            idx--; curr += mx_diff;
        }
        else {
            a[idx] += req;
            break;
        }
    }

    // so till now I was thinkning that I just need to create a MST but here
    // the weights have to be minimied too

    for(auto y : a) cout << y << " ";
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

/*
so if it were just spanning tree the problem were straightforward we would choose n - 1 values from 1 to n*(n - 1)/2 and all of them would have to sum to k
the case when it wouldn't be possible were also straightforward. now the issue is given all the ways to choose the edge weights could there be one where 
the MST is the one we are choosing to be. there is another thing that 1 and 2 would always be in the MST but we can skip 3. the question can be also thought 
like what are the possible values which can be achieved by ensuring the min ones. now in 3 nodes the only k possible is 3. in the case of 4 the only possible
ones are 6 and 7 which occur when 1, 2 and 3 are in a straight line and the other one when they form a cycle so the next one is 4. there is one more thing
that this graph is a complete graph that is each node is connected with all the other vertices. now here is the idea starting from 1 now if 1 must be connected
to some vertes using 1 edge weight since no other path can provide a shorter path. how can I see which one I can keep and which one not based on my previous 
choices, 

fact 1 : if all the weights before me have been included in the mst then to skip the current one I just need to keep two edges x, curr - x side by side and be done
with it. there are multiple ways to do it but what is true is that we can always do it

so it seems like after I include k vertices there is a limit to the number of edges I can disclude. like after 1, 2 I can only disclude 1 edge of weight 3 then
I will have to take it in the mst. after taking 3 edges of weight 1 , 2, 3 I can skip 4, 5, 6 then after taking 4 weights of 1, 2, 3, 4 I can skip till 10. so 
basically if I take k edges then I can skip up to k C 2 edges then I would have to start taking again let's see after taking this does the pattern follow 
so this seems like coincidence basically when i add two edges e1 and e2 side by side I can choose to remove any edge e >= e1 + e2. if I have three edges e1, e2 and e3
in that case I can choose to remove three edges of lenght greater than >= e1 + e2, >= e2 + e3 and of >= e1 + e2 + e3 so a better way to frame my obs is that

fact 2 : after including e1 to ek edges we can choose to remove k C 2 pairs from the set where each pair is basically sum of weights from ei to ej for all i = 1 to k
and j = i + 1 to k

so I can after some manipulation mantain a set of values that I am capable of removing, I think my above algo of choosing the smallest weights and then trying to
fit in is kind of on the right track so by the above method of finding the n - 1 weight to sum to k I am basically doing is take some prefix and some suffix
of the allowed weights and choose them in my mst if I am able to form a mst using it then it is good otherwise it is not possible to do it using any other 
choice of weights. 

so on trying to create the matrix I can see I will have to choose some k then fill the upper traingle above it now what about after it? can I argue and say for sure
a prefix and a suufix is the best way of creating one mst. I am getting intuition but can't prove it rigourously. 

there is one more thing my entire idea is based on creating chains when contructing the mst I am not even thinking about a tree like MST yet. 
well there is this other thing too that the largest weight if it is in my chosen set then it is never chosen in the mst since any other edge would provide a better
alternative than what it is. 
*/