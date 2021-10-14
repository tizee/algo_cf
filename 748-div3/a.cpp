#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <chrono>

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <climits>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

#define endl "\n"
#define min(x, y) ((x) > (y) ? (y) : (x))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define itoc(i) (char)(i + '0')
#define pb push_back
#define pob pop_back

#define FASTIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ALL(a) a.begin(), a.end()
#define FR(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, s, e) for (ll i = s; i < e; i++)
#define RFR(i, n) for (ll i = n - 1; i >= 0; i--)
#define RFOR(i, s, e) for (ll i = s; i >= e; i--)

#define DBall(a)                                                               \
  cerr << #a << " => ";                                                        \
  for (auto &i : a) {                                                          \
    cerr << i << " ";                                                          \
  }                                                                            \
  cerr << endl;
#define DBrange(a, k, n)                                                       \
  cerr << #a << " => ";                                                        \
  for (int i = k; i < n; i++) {                                                \
    cerr << a[i] << " ";                                                       \
  }                                                                            \
  cerr << endl;

const ll inf = 1e9, MOD = 1e9 + 7;

class Solution {
    private:
    public:
        // WRITE YOUR SOLUTION HERE
        void
        solve() {
            int a, b, c;
            cin >> a >> b >> c;
            cout << max(0, max(b, c) - a + 1) << " ";
            cout << max(0, max(a, c) - b + 1) << " ";
            cout << max(0, max(a, b) - c + 1) << endl;
        }
};

int
main() {

#ifndef OJ_TEST
    freopen("testa/1", "r", stdin);
    freopen("testa/1.test.out", "w", stdout);
    auto start = std::chrono::high_resolution_clock::now();
#endif

    FASTIO;
    Solution ans;
    int t = 1;
    cin >> t;

    while (t--) {
        ans.solve();
    }

#ifndef OJ_TEST
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    cerr << "Time spent: " << elapsed.count() * 1e-6 << " ms" << endl;
#endif
    return 0;
}
