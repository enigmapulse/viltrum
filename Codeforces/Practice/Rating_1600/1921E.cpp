#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll h, w; cin >> h >> w;
    ll xa, ya; cin >> xa >> ya;
    ll xb, yb; cin >> xb >> yb;

    if(xa >= xb) {
        cout << "Draw" << endl;
        return;
    }

    /*
    if it's alice turn and bob lies in her range then alice wins and vice versa
    so basically if they are in adjacent rows and one of them can't escape the other
    then they win but you can alway escape the other person unless you are on the same col
    as the other if the difference between the two rows is 1 then alice wins if it is 2 then 
    bob wins so goes for the same parity ones. the second case when you can't escape is 
    when their is a boundary on the side. there is 
    so here is the final idea that if they lie in each other scope then cehk the parity of
    difference in rows if one is in fov of other then it would be in the fov of the other too
    and if it's not then it it won't be of the other one too 
    actually there are only two cases of definite answer
    if they are in a straight line or just 1 shifted
    if it is two shifted then the other one can always run away
    */

    bool fov = true;
    ll xabs = abs(xa - xb); ll yabs(ya - yb);
    fov &= (yabs <= xabs);

    if(!fov) {
        cout << "Draw" << endl;
        return;
    }

    ll t = xabs/2;

    if(xabs & 1) cout << "Alice" << endl;
    else {
        cout << "Draw" << endl;
        cout << "Bob" << endl;
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