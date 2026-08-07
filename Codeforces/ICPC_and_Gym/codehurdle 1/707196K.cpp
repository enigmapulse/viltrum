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
template<typename T>
using ordered_set1 = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;

using ordered_pair_set = ordered_set1<pair<ll,ll>>;
using ordered_pair_multiset = ordered_set1<pair<pair<ll,ll>,ll>>;

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
    ll l,r,k;
    cin>>l>>r>>k;
    
    string s = to_string(l);
    vll pre(s.size());
    ll prev=s[0]-'0';
    pre[0]=prev;
    f2(i,1,s.size()){
        ll d=s[i]-'0';
        pre[i]=pre[i-1];
        if(d>=prev){
            pre[i]+=d;
            prev=d;
        }
    }
    ll rem = k;

    for(ll i = s.length()-1;i>=0;i--){
        if(rem==0) break;
        rem-=(i==0?0:pre[i-1]);
        // rem-=ext;
        ll mx = min((9ll-(s[i]-'0')),rem);
        s[i]+=mx;
        rem-=mx;
        // debug(rem);
    }
    while(rem>0){
        ll mn=min(9ll,rem);
        char ch='0'+mn;
        s=ch+s;
        rem-=mn;
    }
    ll num = 0;
    for(auto x:s){
        num*=10;
        num+=(x-'0');
    }
    if(num>r || rem>0){
        cout<<"-1"<<endl;
    }
    else{
        cout<<num<<endl;
    }
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