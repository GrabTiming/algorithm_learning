#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll MOD = 998244353;

ll modpow(ll a, ll e) {
    ll r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int X1, X2, X3;
    cin >> X1 >> X2 >> X3;

    int N = X1 + X2 + X3;

    vector<ll> fact(N + 1), invfact(N + 1);
    fact[0] = 1;
    for (int i = 1; i <= N; i++) fact[i] = fact[i - 1] * i % MOD;

    invfact[N] = modpow(fact[N], MOD - 2);
    for (int i = N; i >= 1; i--) invfact[i - 1] = invfact[i] * i % MOD;

    auto C = [&](int n, int r) -> ll {
        if (r < 0 || r > n) return 0;
        return fact[n] * invfact[r] % MOD * invfact[n - r] % MOD;
    };

    auto ways_composition = [&](int total, int parts) -> ll {
        // positive integer composition: total split into parts positive pieces
        if (parts <= 0) return 0;
        if (total < parts) return 0;
        return C(total - 1, parts - 1);
    };

    int n = X1 + X3;
    ll ans = 0;

    // k = number of transitions between 1 and 3 in the skeleton.
    // Since both X1 and X3 are positive, k starts from 1.
    int maxK = min({X2, n - 1, 2 * min(X1, X3)});
    // The 2 * min bound is loose but safe; invalid cases are also filtered by C/composition.

    for (int k = 1; k <= min(X2, n - 1); k++) {
        ll skeletonWays = 0;

        if (k % 2 == 1) {
            int p = (k + 1) / 2;
            skeletonWays = 2LL
                * ways_composition(X1, p) % MOD
                * ways_composition(X3, p) % MOD;
        } else {
            int half = k / 2;

            // start and end with 1
            ll case1 = ways_composition(X1, half + 1)
                     * ways_composition(X3, half) % MOD;

            // start and end with 3
            ll case2 = ways_composition(X1, half)
                     * ways_composition(X3, half + 1) % MOD;

            skeletonWays = (case1 + case2) % MOD;
        }

        ll placeTwos = C(X2 - k + n, n);
        ans = (ans + skeletonWays * placeTwos) % MOD;
    }

    cout << ans << '\n';
    return 0;
}