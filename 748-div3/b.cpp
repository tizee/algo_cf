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
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        // 50 75 25 100
        cout << find25s(s) << endl;
    }

    int
    find25s(string &s) {
        // 05 00 57 52
        int steps = INT_MAX;
        int first0 = 0, first5 = 0;
        int n = s.size();
        // state
        // 0 -> 5 or 0 -> 0
        int i = 0, state = 0;

        while (i < n) {
            if (state==0&&s[i] == '0') {
                state = 1;
                first0=i;
                i++;
            } else if (state == 0) {
                i++;
            } else if (state == 1 && (s[i] == '5' || s[i] == '0')) {
                // no leading zero
                steps = min(i - first0 - 1 + first0, steps);
                break;
            } else {
                i++;
            }
        }

        // 5 -> 7 or 5 -> 2
        i=0,state=0;
        while (i < n) {
            if (state==0&&s[i] == '5') {
                state = 1;
                first5=i;
                i++;
            } else if (state == 0) {
                i++;
            } else if (state == 1 && (s[i] == '7' || s[i] == '2')) {
                // no leading zero
                steps = min(i - first5 - 1 + first5, steps);
                break;
            } else {
                i++;
            }
        }

        return steps;
    }
};

/* #define OJ_TEST */

int
main() {
    auto start = std::chrono::high_resolution_clock::now();

#ifndef OJ_TEST
    freopen("testb/1", "r", stdin);
    freopen("testb/1.test.out", "w+", stdout);
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
