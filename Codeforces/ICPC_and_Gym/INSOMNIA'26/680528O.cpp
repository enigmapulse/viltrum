#include <bits/stdc++.h>

#include <utility>
using namespace std;
#define ull unsigned long long
#define ll long long
#define endl '\n'
#define O(x) cout<<(x)<<endl
#define all(v) v.begin(),v.end()
#define M_PI		3.14159265358979323846
// #define max(a,b) (((a>b)?(a):(b)))
// #define min(a,b) (((a<b)?(a):(b)))
#define MOD 1000000007
#define double long double
//
ll mod_pow_ll(ll base, ll exponent) {
    ll result = 1;
    base %= MOD;
    while (exponent > 0) {
        if (exponent & 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exponent >>= 1;
    }
    return result;
}

// long long pow_ll(long long base, long long exp) {
//     const long long INF = LLONG_MAX;
//     __int128 result = 1;
//     __int128 b = base;
//
//     while (exp > 0) {
//         if (exp & 1) {
//             result *= b;
//             if (result > INF) return INF;
//         }
//         exp >>= 1;
//         if (exp) {
//             b *= b;
//             if (b > INF) b = INF;
//         }
//     }
//     return (long long)result;
// }


// fast exponentiation
long long modpow(long long a, long long e) {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

// factorials + inverse factorials
vector<long long> fact, invfact;

void build_factorials(int n) {
    fact.resize(n + 1);
    invfact.resize(n + 1);

    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i-1] * i % MOD;

    // inverse factorial using Fermat: x^{-1} = x^{MOD-2}
    invfact[n] = modpow(fact[n], MOD - 2);
    for (int i = n; i > 0; i--)
        invfact[i-1] = invfact[i] * i % MOD;
}

// compute n! / (a! * b! * c! ...) mod MOD
long long divide_factorials(long long n, vector<long long> denom) {
    long long res = fact[n];
    for (long long x : denom) {
        res = res * invfact[x] % MOD;
    }
    return res;
}

// Function to add an edge between two vertices

void addEdge(vector<vector<ll>>& adj, ll u, ll v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void displayAdjList(vector<vector<ll>>& adj) {
    for (ll i = 0; i < adj.size(); i++) {
        cout << i << ": ";
        for (ll j : adj[i]) {
            cout << j << " ";
        }
        cout << endl;
    }
}


const int MAXP = 10000000; // 1e7
vector<ll> primes;

void build_primes() {
    vector<bool> is_composite(MAXP + 1, false);
    for (int i = 2; i * i <= MAXP; ++i) {
        if (!is_composite[i]) {
            for (int j = i * i; j <= MAXP; j += i)
                is_composite[j] = true;
        }
    }
    for (int i = 2; i <= MAXP; ++i)
        if (!is_composite[i])
            primes.push_back(i);
}

// returns distinct prime factors of x
set<ll> get_factors_fast(ll x) {
    set<ll> s;
    // s.insert(1);
    for (int p : primes) {
        if (1LL * p * p > x) break;
        if (x % p == 0) {
            while (x % p == 0) {
                x /= p;
            }
            s.insert(p);
        }
    }
    if (x > 1) s.insert(x); // x is now 1 or a prime > sqrt(original x)
    return s;
}

bool isPowerOf2(long long x) {
    return x > 0 && (x & (x - 1)) == 0;
}

long long intSqrt(long long x) {
    long long r = floor(sqrtl(x));   // safe approximation
    if (r * r == x) return r;
    if ((r + 1) * (r + 1) == x) return r + 1;
    return -1; // not a perfect square
}

bool isPerfectSquare(long long x) {
    if (x < 0) return false;
    long long r = floor(sqrtl(x));     // long double sqrt
    return r * r == x || (r + 1) * (r + 1) == x;
}

bool isPrime(ll n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (ll i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

ll nCr(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
}



void solve() {
    ll n;
    cin>>n;
    ll a[n];
    for(ll i = 0;i<n;i++) cin>>a[i];
    ll pre[n],suf[n];
    pre[0] = a[0];
    suf[n-1] = a[n-1];
    for(ll i = 1;i<n;i++) pre[i] = __gcd(a[i],pre[i-1]);
    for(ll i = n-2;i>=0;i--) suf[i] = __gcd(suf[i+1],a[i]);

    bool marked[n];
    marked[0] = true;
    marked[n-2]=true;

    for(ll i = 0;i<n-1;i++){
        if(pre[i]==1){                
            marked[i] = true;
        }
    }

    for(ll i = 0;i<n-1;i++){
        if(suf[i+1]==1){
            marked[i] = true;
        }
    }

    for(ll j = 0;j<n-1;j++){
        if(__gcd(pre[j],suf[j+1])==min(pre[j],suf[j+1])){
            marked[j] = true;
        }
    }

    for(ll j = 0;j<n-2;j++){
        if(pre[j]==suf[j+2]) marked[j+1] = true;
    }

    for(ll i =1;i<n;i++){
        if(pre[i]!=pre[i-1]){
            ll b[n];
            for(ll j=0;j<n;j++) b[j] = a[j];
            b[i] = pre[i-1];
            ll pre1[n];
            pre1[0]=b[0];
            for(ll j = 1;j<n;j++){
                pre1[j] = __gcd(b[j],pre1[j-1]);
            }
            ll suf1[n];
            suf1[n-1]=b[n-1];
            for(ll j = n-2;j>=0;j--){
                suf1[j] = __gcd(b[j],suf1[j+1]);
            }
            for(ll j = 0;j<n-1;j++){
                if(pre1[j]==suf1[j+1]) {
                    marked[j] = true;
                    // if(j==3) cout<<pre1[j]<<" "<<suf1[j]<<endl;
                }
            }
        }
    }

    for(ll i =n-2;i>=0;i--){
        if(suf[i]!=suf[i+1]){
            ll b[n];
            for(ll j=0;j<n;j++) b[j] = a[j];
            b[i] = suf[i+1];
            ll suf1[n];
            suf1[n-1]=b[n-1];
            for(ll j = n-2;j>=0;j--){
                suf1[j] = __gcd(b[j],suf1[j+1]);
            }
            ll pre1[n];
            pre1[0]=b[0];
            for(ll j = 1;j<n;j++){
                pre1[j] = __gcd(b[j],pre1[j-1]);
            }
            for(ll j = 0;j<n-1;j++){
                if(suf1[j+1]==pre1[j]){
                    marked[j] = true;
                    // if(j==3) cout<<pre1[j]<<" "<<suf1[j]<<endl;
                }
            }
        }
    }

    ll cnt = 0;
    marked[n-1] = false;
    for(ll i = 0;i<n;i++) if(marked[i]){
        // cout<<i<<" ";
        cnt++;
    }
    // cout<<endl;
    cout<<cnt<<endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ull tt=1;
    // build_factorials(200007);
    // build_primes();
    cin>>tt;
    while(tt--) solve();
}