#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

// Calculates (x * y) % m using 128-bit integer to prevent overflow
ull mul(ull x, ull y, ull m) {
    return (__int128)x * y % m;
}

// Calculates (x - y) % m handling negative results
ull sub(ull x, ull y, ull m) {
    // If x < y, we wrap around by adding m
    return (x >= y) ? (x - y) : (x - y + m);
}

// Returns {V_n, V_{n+1}}
// Based on recurrence: V_0=2, V_1=a, V_n = a*V_{n-1} - V_{n-2}
pair<ull, ull> fast_doubling(ull n, ull a, ull m) {
    if (n == 0) return {2 % m, a % m};

    // Recursively calculate for n / 2
    // p.first is V_k, p.second is V_{k+1}
    pair<ull, ull> p = fast_doubling(n >> 1, a, m);
    ull vk = p.first;
    ull vk1 = p.second;

    // Apply doubling formulas:
    // V_{2k} = V_k^2 - 2
    ull v2k = sub(mul(vk, vk, m), 2 % m, m);
    
    // V_{2k+1} = V_k * V_{k+1} - a
    ull v2k1 = sub(mul(vk, vk1, m), a % m, m);

    // If n was even (2k), we need {V_2k, V_{2k+1}}
    if ((n & 1) == 0) {
        return {v2k, v2k1};
    }
    
    // If n was odd (2k+1), we need {V_{2k+1}, V_{2k+2}}
    // V_{2k+2} can be derived from V_{k+1}: V_{2k+2} = V_{k+1}^2 - 2
    ull v2k2 = sub(mul(vk1, vk1, m), 2 % m, m);
    return {v2k1, v2k2};
}

void solve() {
    ull a, b, m; 
    cin >> a >> b >> m;

    if (m == 1) {
        cout << 0 << endl;
        return;
    }

    // Returns the pair {V_b, V_{b+1}}, we only need V_b
    cout << fast_doubling(b, a, m).first << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}