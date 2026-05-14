#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll N; cin >> N;
    vector<ll> a(N); inarr(a, N);
    map<ll, ll> A;
    for(auto x : a) A[x]++;
    vector<ll> F(N + 1);


    for(int i = 0; i<N; ++i)
        F[i] = A[i];
    for(int i = 0;i < 21; ++i) for(int mask = 0; mask<N; ++mask){
        if(mask & (1<<i))
            F[mask] += F[mask^(1<<i)];
    }

    for(auto y : F) cout << y << " ";
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