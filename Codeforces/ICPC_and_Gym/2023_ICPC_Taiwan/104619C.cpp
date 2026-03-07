#include<iostream>
#include <bits/stdc++.h>
#include <numeric>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds; 
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_multiset tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>


#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define f1(i, a, b) for (int i = a; i < b; i++)
#define f2(i, a, b) for (ll i = a; i < b; i++)
#define fr1(i, a, b) for (int i = a; i >= b; i--)
#define fr2(i, a, b) for (ll i = a; i >= b; i--)
#define in(x) cin >> x
#define out(x) cout << x
#define pb push_back
#define make make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define vi vector<int>
#define vll vector<ll>
#define vstr vector<string>
#define vvll vector<vector<ll>>
#define vvi vector<vector<int>>
#define MOD (ll)(998244353)
#define INF (ll)(1e17+7)

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" = "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

long long power(long long x,ll y){   
    x%=MOD;
    long long res = 1;
 
    while (y > 0) 
    {
        if (y & 1)
            res = (res * x)%MOD ;
 
        y = y >> 1;
        x = (x * x)%MOD ;
    }
    return res%MOD;
}

// long long nCr(ll n, ll r) {
//     if(n<r){
//         return 0;
//     }
//     if(r > n - r) r = n - r; // because C(n, r) == C(n, n - r)
//     long long ans = 1;
//     ll i;
 
//     for(i = 1; i <= r; i++) {
//         ans *= n - r + i;
//         ans /= i;
//     }
 
//     return ans;
// }




ll add(ll x, ll y) {
     x += y;
     if (x >= MOD) x -= MOD;
     if (x < 0) x += MOD;
     return x;
}
 
ll mul(ll x, ll y) {
    return x * y % MOD;
}

ll divide(ll x, ll y) {
    return mul(x, power(y, MOD - 2));
}

// bool cmp(pair<string,ll> a, pair<string,ll> b) {
//     if (a.first != b.first)
//         return a.first < b.first;   // primary key
//     return a.second > b.second;     // secondary key
// }

ll lcm(ll a, ll b) {
    return (a / __gcd(a, b)) * b;
}

const ll N=1e4;
vll fact(N);  

ll nCr(ll n,ll r){
    return divide(fact[n],mul(fact[r],fact[n-r]));
}


ll binexp(int a,int b){
    ll ans=1;
    while(b>0){
        if(b&1){
            ans=(ans*a);
        }
        a=(a*a);
        b>>=1;
    }
    return ans;
}


void solve() {
    string s; cin >> s; ll b; cin >> b;

    ll curr = 0, pow = 0, ans = 0, last=s.size(),prev=s.size();
    for (ll i = s.size() - 1; i >= 0; i--) {
        ll contr = (s[i] - '0') * binexp(10, pow++);
        if (curr + contr > b) {
            if(last==prev){
                cout<<"NO WAY"<<endl;
                return;
            }
            if(curr>b){
                cout<<"NO WAY"<<endl;
                return;
            }
            prev=last;
            ans++; b = curr;
            curr = (s[i] - '0') *binexp(10,last-i-1); pow = last-i;
        }
        else curr += contr;
            debug(contr);

        if(s[i]!='0') last=i;
    }

    if(curr>b){
        cout<<"NO WAY"<<endl;
        return;
    }
    
    cout << ans << endl;
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("check.txt", "w", stderr);
    #endif
    fact[0]=1;
    f2(i,1,N) fact[i]=mul(fact[i-1],i);
    
    

    int t=1;
    // cin >>t;
    while (t--) {
        
        solve();
        
        
    }
    return 0;
    
}