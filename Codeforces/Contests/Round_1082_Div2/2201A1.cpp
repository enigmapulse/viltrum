#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    ll n; cin >> n;
    vector<ll> a(n); inarr(a, n);

    stack<ll> st; st.push(a[n - 1]);
	for (ll i = n - 2; i >= 0; i--) {
		st.push(a[i]);
		while(true) {
			ll x = st.top();
			st.pop(); ll y = st.top();
			if(x == y - 1) {
				st.pop();
				st.push(x);
				if(st.size() == 1) break;
			}
			else {
				st.push(x);
				break;
			}
		}
	}
	
	cout << st.size() << endl;
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