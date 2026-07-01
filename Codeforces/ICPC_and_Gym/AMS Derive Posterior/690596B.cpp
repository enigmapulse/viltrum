#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define inarr(a, n) for (int _i = 0; _i < (n); _i++) cin >> (a)[_i];
#define invec(v) for (auto &_x : (v)) cin >> _x;

using namespace std;

bool multipleTests = true;

void solve() {
    char k1; ll w1; char c1; bool r1; cin >> k1 >> w1 >> c1 >> r1;
    char k2; ll w2; char c2; bool r2; cin >> k2 >> w2 >> c2 >> r2;
    struct loaf {
        char kind;
        ll weight;
        char crust;
        bool sourdough;

    };
    
    auto is_unusable = [&] (loaf& a) {
        if(a.crust == 'X') return true;
        if(a.kind == 'B') return (a.weight < 150);
        else return (a.weight < 100);
    };

    loaf A(k1, w1, c1, r1);
    loaf B(k2, w2, c2, r2);
    if(is_unusable(A) && is_unusable(B)) {
        cout << "DRAW" << endl;
        return;
    }
    if(is_unusable(A)) {
        cout << "CRUMB" << endl;
        return;
    }
    if(is_unusable(B)) {
        cout << "CRAM" << endl;
        return;
    }

    if(A.kind != B.kind) {
        if(A.crust == 'S' && A.kind == 'B' && B.crust == 'C' && B.kind == 'D') {
            cout << "CRUMB" << endl;
            return;
        }
        if(B.crust == 'S' && B.kind == 'B' && A.crust == 'C' && A.kind == 'D') {
            cout << "CRAM" << endl;
            return;
        }
        if(A.kind == 'B') {
            cout << "CRAM" << endl;
            return;
        }
        if(B.kind == 'B') {
            cout << "CRUMB" << endl;
            return;
        }
    }

    if(A.weight > B.weight) {
        cout << "CRAM" << endl;
        return;
    }
    else if(A.weight < B.weight) {
        cout << "CRUMB" << endl;
        return;
    }
    else {
        if(A.crust == 'C' && B.crust == 'S') {
            cout << "CRAM" << endl;
            return;
        }
        else if(A.crust == 'S' && B.crust == 'C') {
            cout << "CRUMB" << endl;
            return;
        }
        else {
            if(A.sourdough && !B.sourdough) {
                cout << "CRAM" << endl;
                return;
            }
            else if(!A.sourdough && B.sourdough) {
                cout << "CRUMB" << endl;
                return;
            }
            else {
                cout << "DRAW" << endl;
                return;
            }
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