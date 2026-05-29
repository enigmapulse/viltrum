#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;
#define plc pair<ll, char>

using namespace std;

bool multipleTests = true;

void solve() {
    string s; cin >> s;
    ll n = s.size();

    vector<ll> cnt(26, 0);
    for (ll i = 0; i < n; i++) {
        cnt[s[i] - 'a']++;
    }
    set<plc, greater<plc>> t;
    for (ll i = 0; i < 26; i++) {
        t.insert({cnt[i], char('a' + i)});
    }

    string cand;
    while(true) {
        auto it = t.begin();
        auto ut = next(it);
        
        if(it -> first != 0 && ut -> first != 0) {
            cand += it -> second;
            cand += ut -> second;
            auto v1 = *it, v2 = *ut;
            v1.first--; v2.first--;
            t.erase(it); t.erase(ut);
            t.insert(v1); t.insert(v2);
        }
        else if(it -> first == 1) {
            cand += it -> second;
            break;
        }
        else if(it -> first > 1) {
            cout << "No" << endl;
            return;
        }
        else break;
    }

    cout << "Yes" << endl;
    cout << cand << endl;
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