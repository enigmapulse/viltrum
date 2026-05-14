#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

vector<ll> primes;
const int MAXP = 200000;
bool is_prime[MAXP];

void precompute() {
    fill(is_prime + 2, is_prime + MAXP, true);
    for (int p = 2; p * p < MAXP; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i < MAXP; i += p)
                is_prime[i] = false;
        }
    }
    for (int p = 2; p < MAXP; p++) {
        if (is_prime[p]) {
            primes.push_back(p);
        }
    }
}

void solve() {
    ll n; cin >> n;
    for (int i = 0; i < n; i++) {
        cout << primes[i] * primes[i + 1] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    precompute();
    
    int T = 1;
    if (multipleTests)
        cin >> T;
    while (T--)
        solve();
    return 0;
}