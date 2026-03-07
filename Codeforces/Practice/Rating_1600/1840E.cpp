#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    vector<string> st(2); cin >> st[0] >> st[1];
    ll t, q; cin >> t >> q;
    
    ll cnt = 0;
    for(ll i = 0; i < st[0].size(); ++i) cnt += (st[0][i] != st[1][i]);
    /*
    well we need a way to keep track of which strings are blocked, and considering those
    compare the strings. since blocking is done on both the arrays we can mantain a list of
    indices which differ in both. and just see if all of them are blocked or not. swapping
    doesn't have any effect on our algo? no it does since we can swap any index of one string
    with any index of another. well we will check and update our list accordingly
    which ds would be best for implementing this. also what about the timer effect where the 
    block dies out eventually? well in a way there can never be more than 5 blocked elements
    but even if it doesn't overflow we need to keep popping it if it's age is 5.
    whenever a new turn comes up I need to update the list of blocked indexes.
    */
   set<ll> blocked; ll turns = 0;

    while(q--) {
        ll ops; cin >> ops;

        turns++;
        if(*blocked.begin() == turns) blocked.erase(blocked.begin());

        if(ops == 1) {
            // blocking operation
            ll pos; cin >> pos;
            if(st[0][pos - 1] != st[1][pos - 1]) blocked.insert(turns + t);
        }
        else if(ops == 3) {
            if(blocked.size() == cnt) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else {
            ll s1, pos1, s2, pos2; cin >> s1 >> pos1 >> s2 >> pos2;
            --s1; --pos1; --s2; --pos2;

            if (st[0][pos1] != st[1][pos1]) cnt--;
            if (pos1 != pos2 && st[0][pos2] != st[1][pos2]) cnt--;

            swap(st[s1][pos1], st[s2][pos2]);

            if (st[0][pos1] != st[1][pos1]) cnt++;
            if (pos1 != pos2 && st[0][pos2] != st[1][pos2]) cnt++;
        }
    }
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