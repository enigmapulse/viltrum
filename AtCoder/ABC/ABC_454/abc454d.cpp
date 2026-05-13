#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    string s, t; cin >> s >> t;
    
    string b1, b2;
    for(auto ch : s) {
        b1.push_back(ch);
        if(b1.size() >= 4) {
            if(b1.substr(b1.size() - 4) == "(xx)") {
                b1.erase(b1.size() - 4, 4);
                b1 += "xx";
            }
        }
    }

    for(auto ch : t) {
        b2.push_back(ch);
        if(b2.size() >= 4) {
            if(b2.substr(b2.size() - 4) == "(xx)") {
                b2.erase(b2.size() - 4, 4);
                b2 += "xx";
            }
        }
    }
    

    // cerr << b1 << endl;
    // cerr << b2 << endl;
    // cerr << endl;
    if(b1 == b2) cout << "Yes" << endl;
    else cout << "No" << endl;
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