#include<iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_multiset tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>

#define yes cout << "Yes" << endl
#define no cout << "No" << endl
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
#define INF (ll)(4e18)

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
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



void solve() {
    ll n;
    cin>>n;
    vll val(n+1,0);
    ll cur=0;
    f2(j,0,log2(n)+1){
        ll cnt0 =0,cnt1=0;
        f2(i,1,n+1){
            if(val[i]==cur){
                cout<<"? "<<i<<' '<<j<<endl;
                ll ans;
                in(ans);
                val[i]+=ans<<j;
                if(ans) cnt1++;
                else cnt0++;
            }
        }
        if(cnt0 > cnt1){
            cur+=1<<j;
        }
    }
    cout<<"! "<<cur<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

//    #ifndef ONLINE_JUDGE
//        freopen("check.txt", "w", stderr);
//    #endif

    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}