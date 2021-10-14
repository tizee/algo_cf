#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include <cmath>
#include <cstdio>

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
#define FR(i, n) for (int i = 0; i < n; i++)
#define FOR(i, s, e) for (int i = s; i < e; i++)
#define RFR(i, n) for (int i = n - 1; i >= 0; i--)
#define RFOR(i, s, e) for (int i = s; i >= e; i--)

#define DBv(v) cerr << #v << " => " << v << endl;

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

const int MAXN = 4e5 + 1;

class Solution {
    private:
        int hide[MAXN];
    public:
        // WRITE YOUR SOLUTION HERE
        void
        solve() {
            int n, k;
            cin >> n >> k;
            int i = 0;

            while (i < k) {
                cin >> hide[i];
                hide[i] = n - hide[i];
                i++;
            }

            sort(hide, hide + k);

            int sum = hide[0];
            int count = 1;
            FOR(i, 1, k) {

                if (sum >= n - hide[i]) {
                    break;
                }

                sum += hide[i];
                count++;
            }
            cout << count << endl;
        }

};

int
main() {
    auto start = std::chrono::high_resolution_clock::now();

#ifndef OJ_TEST
    freopen("testc/1", "r", stdin);
    freopen("testc/1.test.out", "w", stdout);
#endif

    FASTIO;
    Solution ans;
    int t = 1;
    cin >> t;

    while (t--) {
        ans.solve();
    }

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    cerr << "Time spent: " << elapsed.count() * 1e-9 << "seconds.\n";
    return 0;
}
