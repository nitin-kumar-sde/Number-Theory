#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

// prime factorise
map<ll, int> get_prime_factors(ll k) {
    map<ll, int> factors;
    for (ll i = 2; i * i <= k; ++i) {
        while (k % i == 0) {
            ++factors[i];
            k /= i;
        }
    }
    if (k > 1) factors[k]++;
    return factors;
}

// counts power of prime in a given num
int count_prime_power(int x, int p) {
    int cnt = 0;
    while (x % p == 0) {
        ++cnt;
        x /= p;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll k;
    cin >> n >> k;

    vector<int> a(n+1,0);
    for (int i=1;i<=n;i++) cin >> a[i];

    map<ll, int> k_factors = get_prime_factors(k);
    int primes_count = k_factors.size();

    vector<vector<int>> prefix(primes_count, vector<int>(n + 1, 0));
    vector<ll> primes;

    for (auto &[p, e] : k_factors) primes.push_back(p);

    for (int i = 1; i <=n; ++i) {
        int idx = 0;
        for (auto p : primes) {
            int cnt = count_prime_power(a[i], p);
            prefix[idx][i] = prefix[idx][i-1] + cnt;
            ++idx;
        }
    }

    ll total = 0;
    for (int l = 1; l <=n; ++l) {
        int low = l, high = n, r = n+1;
        while (low <= high) {
            int mid = (low + high) / 2;
            bool valid = true;
            int idx = 0;
            for (auto &[p, e] : k_factors) {

                int cnt = prefix[idx][mid] - prefix[idx][l-1];

                if (cnt < e) {
                    valid = false;
                    break;
                }
                ++idx;
            }
            if (valid) {
                r = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        total += n + 1  - r;
    }

    cout << total << endl;
    return 0;
}
