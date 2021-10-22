#include <algorithm>
#include <bitset>
#include <chrono>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>


#include <cassert>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;

#define pb push_back
#define pob pop_back
#define endl "\n"

#define min(x, y) ((x) > (y) ? (y) : (x))
#define max(x, y) ((x) > (y) ? (x) : (y))
#define itoc(i) (char)(i + '0')
#define gcd(x, y) __gcd(x, y)

#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
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

namespace fastio {
    constexpr int BUFMAX = 1 << 19 ;
    char buf[BUFMAX], *p1, *p2 ;

    inline char
    gc() {
        return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, BUFMAX, stdin), p1 == p2) ? EOF : *p1++;
    }

    template <typename Tp> inline void
    in(Tp &x) {
        int f(0);
        x = 0;
        static char ch = gc() ;

        for (; ch < '0' || ch > '9'; ch = gc()) {
            f = ch == '-' || f ? 1 : 0;
        }

        for (; ch >= '0' && ch <= '9'; ch = gc()) {
            // 0 - 48
            x = x * 10 + (ch ^ 48);
        }

        x = f ? -x : x ;
    }

    template <typename T, typename ...Args> inline void
    in(T &a, Args &...args) {
        return in(a), in(args...);
    }
#undef getc
    inline void
    putc(const char ch) {
        static std::streambuf *outbuf = std::cout.rdbuf();
        outbuf -> sputc(ch);
    }
    template <typename Tp> inline void
    out(const char ch, Tp x) {
        static std::streambuf *outbuf = std::cout.rdbuf() ;
        static char stk[21];
        static int top = 0;
        x = x < 0 ? outbuf -> sputc('-'), -x : x ;

        if (!x) {
            return outbuf -> sputc('0'), outbuf -> sputc(ch), void();
        }

        while (x) {
            stk[++top] = x % 10 + '0', x /= 10 ;
        }

        while (top) {
            outbuf -> sputc(stk[top--]) ;
        }

        outbuf->sputc(ch) ;
    }

    template <typename Tp> inline void
    out(Tp x) {
        static std::streambuf *outbuf = std::cout.rdbuf() ;
        static char stk[21];
        static int top = 0;
        x = x < 0 ? outbuf -> sputc('-'), -x : x ;

        if (!x) {
            return outbuf -> sputc('0'), void();
        }

        while (x) {
            stk[++top] = x % 10 + '0', x /= 10 ;
        }

        while (top) {
            outbuf -> sputc(stk[top--]) ;
        }
    }

    template<typename T, typename ...Args> inline void
    out(const char ch, T a, Args ...args) {
        out(ch, a);
        out(ch, args...);
    }

    template<typename T, typename ...Args> inline void
    out(T a, Args ...args) {
        out(a);
        out(args...);
    }

}
using fastio::in;

const ll inf = 1e9, MOD = 1e9 + 7;

class Node {
    public:
        int degree = 0;
        int dist = -1;
        vector<Node*> adj;
        friend ostream&
        operator<<(ostream &s, const Node &n) {
            s << "degree => " << n.degree << " ";
            s << "dist=> " << n.dist << " ";
            s << "adj size=> " << n.adj.size() << " ";
            return s;
        };
};

namespace {
    inline void
    solve() {
        int n, k;
        in(n, k);
        int u, v;

        vector<Node> nodes(n, Node());
        deque<Node*> bfs;

        FOR(i, 1, n) {
            in(u, v);
            u = u - 1;
            v = v - 1;
            nodes[u].adj.push_back(&nodes[v]);
            nodes[v].adj.pb(&nodes[u]);
        }

        FR(i, n) {
            if(nodes[i].adj.size() < 2) {
                bfs.pb(&nodes[i]);
                nodes[i].dist = 0;
            }
        }

        // dist represents the number of operation needed to remove
        while(!bfs.empty()) {
            Node* first = bfs.front();
            bfs.pop_front();
            FR(i, first->adj.size()) {
                if(first->adj[i]->dist != -1) {
                    continue;
                } else {
                    first->adj[i]->degree++;

                    if(first->adj[i]->adj.size() - first->adj[i]->degree <= 1) {
                        // at most one node
                        first->adj[i]->dist = first->dist + 1;
                        bfs.push_back(first->adj[i]);
                    }
                }
            }
        }

        // init graph

        vi count_dist(n + 1, 0);
        FR(i, n) {
            count_dist[nodes[i].dist]++;
        }
        FOR(i, 1, count_dist.size()) count_dist[i] += count_dist[i - 1];


        cout << n - count_dist[k < n ? k - 1 : n - 1] << endl;

    }

};

int
main() {

#ifndef OJ_TEST
    freopen("teste/1", "r", stdin);
    freopen("teste/1.test.out", "w", stdout);
    auto start = std::chrono::high_resolution_clock::now();
#endif

    FASTIO;
    int t = 1;
    in(t);

    while (t--) {
        solve();
    }

#ifndef OJ_TEST
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    cerr << "Time spent: " << elapsed.count() * 1e-6 << " ms" << endl;
#endif
    return 0;
}
