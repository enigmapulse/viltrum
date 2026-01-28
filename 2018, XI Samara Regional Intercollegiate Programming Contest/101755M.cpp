// #include<iostream>
// #include <bits/stdc++.h>
// #include <numeric>
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace std;
// using namespace __gnu_pbds; 
// #define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
// #define ordered_multiset tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>


// #define yes cout << "YES" << endl
// #define no cout << "NO" << endl
// #define f1(i, a, b) for (int i = a; i < b; i++)
// #define f2(i, a, b) for (ll i = a; i < b; i++)
// #define fr1(i, a, b) for (int i = a; i >= b; i--)
// #define fr2(i, a, b) for (ll i = a; i >= b; i--)
// #define in(x) cin >> x
// #define out(x) cout << x
// #define pb push_back
// #define make make_pair
// #define F first
// #define S second
// #define all(x) x.begin(), x.end()
// #define allr(x) x.rbegin(), x.rend()
// #define vi vector<int>
// #define vll vector<ll>
// #define vstr vector<string>
// #define vvll vector<vector<ll>>
// #define vvi vector<vector<int>>
// #define MOD (ll)(1e9+7)
// #define INF (ll)(1e17+7)

// typedef long long ll;
// typedef unsigned long long ull;
// typedef long double lld;

// #ifndef ONLINE_JUDGE
// #define debug(x) cerr << #x <<" = "; _print(x); cerr << endl;
// #else
// #define debug(x)
// #endif

// void _print(ll t) {cerr << t;}
// void _print(int t) {cerr << t;}
// void _print(string t) {cerr << t;}
// void _print(char t) {cerr << t;}
// void _print(lld t) {cerr << t;}
// void _print(double t) {cerr << t;}
// void _print(ull t) {cerr << t;}

// template <class T, class V> void _print(pair <T, V> p);
// template <class T> void _print(vector <T> v);
// template <class T> void _print(set <T> v);
// template <class T, class V> void _print(map <T, V> v);
// template <class T> void _print(multiset <T> v);
// template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
// template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
// template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

// long long power(long long x,ll y){   
//     x%=MOD;
//     long long res = 1;
 
//     while (y > 0) 
//     {
//         if (y & 1)
//             res = (res * x)%MOD ;
 
//         y = y >> 1;
//         x = (x * x)%MOD ;
//     }
//     return res%MOD;
// }

// // long long nCr(ll n, ll r) {
// //     if(n<r){
// //         return 0;
// //     }
// //     if(r > n - r) r = n - r; // because C(n, r) == C(n, n - r)
// //     long long ans = 1;
// //     ll i;
 
// //     for(i = 1; i <= r; i++) {
// //         ans *= n - r + i;
// //         ans /= i;
// //     }
 
// //     return ans;
// // }




// ll add(ll x, ll y) {
//      x += y;
//      if (x >= MOD) x -= MOD;
//      if (x < 0) x += MOD;
//      return x;
// }
 
// ll mul(ll x, ll y) {
//     return x * y % MOD;
// }

// ll divide(ll x, ll y) {
//     return mul(x, power(y, MOD - 2));
// }

// // bool cmp(pair<string,ll> a, pair<string,ll> b) {
// //     if (a.first != b.first)
// //         return a.first < b.first;   // primary key
// //     return a.second > b.second;     // secondary key
// // }

// ll lcm(ll a, ll b) {
//     return (a / __gcd(a, b)) * b;
// }

// const ll N=2e5+5;
// vll fact(N);  

// ll nCr(ll n,ll r){
//     return divide(fact[n],mul(fact[r],fact[n-r]));
// }


// ll binexp(int a,int b){
//     ll ans=1;
//     while(b>0){
//         if(b&1){
//             ans=(ans*a);
//         }
//         a=(a*a);
//         b>>=1;
//     }
//     return ans;
// }


// struct DSU {
//     vector<ll> parent;
//     vector<ll> size;
//     // vll ct;

//     DSU(ll n) {
//         parent.resize(n + 1);
//         size.assign(n + 1, 1);
//         // ct.assign(n+1,0);
//         iota(all(parent), 0);
//     }

//     ll find(ll v) {
//         if (v == parent[v]) return v;
//         return parent[v] = find(parent[v]);
//     }

//     bool unite(ll a, ll b) {
//         a = find(a);
//         b = find(b);
//         if (a != b) {
//             if (size[a] < size[b]) swap(a, b);
//             parent[b] = a;
//             size[a] += size[b];
//             // ct[a]+=ct[b];
//             return true;
//         }
//         return false;
//     }
// };


// const int MAXN = 1005;
// bitset<MAXN> successor_mask[MAXN];

// void solve(){
//     ll n;
//     cin>>n;
    
//     // vector<set<ll>> child(n+1);
//     vector<vector<pair<ll,ll>>> parent(n+1);
//     vll sz(n + 1);
//     f2(i,1,n+1){
//         cin>>sz[i];
//         f2(j,0,sz[i]){
//             ll x;
//             in(x);
//             successor_mask[i].set(x);
//             parent[x].pb({sz[i],i});
//         }
//     }

//     vvll adj(n + 1);
//     vll degree(n + 1, 0); 
//     ll root = -1;

//     for(int i = 1; i <= n; i++){
//         sort(all(parent[i]));

//         for(size_t k = 0; k + 1 < parent[i].size(); k++){
//             if(parent[i][k].first == parent[i][k+1].first){
//                 no; return;
//             }
//         }

//         if(parent[i].empty()){
//             if(root != -1){ 
//                 no; return;
//             }
//             root = i;
//         } else {
//             int p = parent[i][0].second;
//             adj[p].pb(i);
            
            
//             if((successor_mask[i] & successor_mask[p]) != successor_mask[i]){
//                 no; return;
//             }
//         }
//     }

//     if(root == -1){ 
//         no; return;
//     }

    
//     vll vis(n + 1, 0);
//     vll q;
//     q.pb(root);
//     vis[root] = 1;
    
//     int head = 0;
//     while(head < q.size()){
//         int u = q[head++];
//         for(int v : adj[u]){
//             if(vis[v]){ 
//                 no; return;
//             }
//             vis[v] = 1;
//             q.pb(v);
//         }
//     }

    
//     if(q.size() != n){
//         no; return;
//     }

   
//     reverse(all(q)); 
//     vll subtree_size(n + 1, 0);

//     for(int u : q){
//         int computed_succ_count = 0;
//         for(int v : adj[u]){
//             computed_succ_count += (1 + subtree_size[v]);
//         }
//         subtree_size[u] = computed_succ_count;

//         if(subtree_size[u] != sz[u]){
//             no; return;
//         }
//     }

//     yes;
//     for(int i = 1; i <= n; i++){
//         for(int child : adj[i]){
//             cout << i << " " << child << "\n";
//         }
//     }
    
// }





// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);

//     #ifndef ONLINE_JUDGE
//         freopen("check.txt", "w", stderr);
//     #endif
//     fact[0]=1;
//     f2(i,1,N) fact[i]=mul(fact[i-1],i);
    

    
//     int t=1;
//     // cin >>t;
//     while (t--) {
        
//         solve();
        
        
//     }
//     return 0;
    
// }




#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define endl '\n'
#define O(x) cout<<(x)<<endl
#define all(v) v.begin(),v.end()
#define lcm(a,b) ((a*b)/(gcd(a,b)))
#define M_PI        3.14159265358979323846
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
vector<int> primes;

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
        if(s.size()>=2) return s;
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
    string a,b,c;
    cin >> a >> b >> c;
    string s;
    ll n = a.length();
    ll cnt1 = 0,cnt2=0,cnt3=0;
    ll imp = 0;
    for (ll i = 0; i < n; i++) {
        if(a[i]==b[i] && b[i]==c[i]) {
            s+=a[i];
        }
        else if(a[i]==c[i]) {
            s+=a[i];
            cnt1++;
        }
        else if(b[i]==c[i]) {
            s+=b[i];
            cnt2++;
        }
        else if(a[i]==b[i]) {
            s+=b[i];
            cnt3++;
        }
        else {
            imp++;
            s+=a[i];
        }
    }
    // cout<<cnt<<endl;
    if(cnt1+cnt2+cnt3>3){
        cout<<"Impossible"<<endl;
        return;
    }

    if(imp){
        if(cnt1+cnt2+cnt3>1 || imp>1){
            cout<<"Impossible"<<endl;
            return;
        }
        if(cnt1+cnt2+cnt3==1){
            ll ar=-1;
            for (ll i = 0; i < n; i++){
                if(a[i]==b[i] && b[i]==c[i]) {
                    // s+=a[i];
                }
                else if(a[i]==c[i]) {
                    // s+=a[i];
                    ar=2;
                    // cnt++;
                }
                else if(b[i]==c[i]) {
                    // s+=b[i];
                    ar=1;
                    // cnt++;
                }
                else if(a[i]==b[i]) {
                    // s+=b[i];
                    ar=3;
                    // cnt++;
                }
                
            }
            for (ll i = 0; i < n; i++){
                if(a[i]!=b[i] && a[i]!=c[i] && b[i]!=c[i]){
                    if(ar==1){
                        s[i]=a[i];
                    }else if(ar==2){
                        s[i]=b[i];
                    }else s[i]=c[i];
                }
            }
            cout<<s<<endl;
        }
        else{
            cout<<"Ambiguous"<<endl;
            return;
        }
    }
    if(cnt1==3 ||cnt2==3||cnt3==3){
        cout<<"Impossible"<<endl;
        return;
    }
    if(cnt1==2 && cnt2+cnt3==0){
        cout<<"Ambiguous"<<endl;
        return;
    }
    if(cnt2==2 && cnt1+cnt3==0){
        cout<<"Ambiguous"<<endl;
        return;
    }
    if(cnt3==2 && cnt2+cnt1==0){
        cout<<"Ambiguous"<<endl;
        return;
    }
    if(cnt1>1 ||cnt2>1||cnt3>1){
        cout<<"Impossible"<<endl;
        return;
    }
    if(cnt1+cnt2+cnt3<=2) {    
        cout<<"Ambiguous"<<endl;
    }
    else {
        cout<<s<<endl;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ull t=1;
    // build_factorials(20000);
    // build_primes();
    // cin>>t;
    while(t--) solve();
}