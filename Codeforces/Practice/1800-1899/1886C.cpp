#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    string s; cin >> s;
    ll pos; cin >> pos;

    ll curr = s.size();
    while(pos - curr > 0) {
        pos -= curr;
        curr--;
    }

    string st;
    ll rem = s.size() - curr;  

    for(auto c : s) {
        while(!st.empty() && c < st.back() && rem) {
            st.pop_back(); rem--;
        } 
        st.push_back(c);
    }

    while(rem--) st.pop_back(); 
    cout << st[pos - 1];
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