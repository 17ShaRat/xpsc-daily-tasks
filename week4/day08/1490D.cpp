/* 
 * You didn’t come into this world. 
 * You came out of it, like a wave from the ocean.
 * You are not a stranger here.” 
				– Alan Watts
									 */
#include <algorithm>
#include <array>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdint>
#include <complex>
#include <cmath>
#include <chrono>
#include <ctime>
#include <cassert>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <string>
#include <random>
using namespace std;
using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using pll = pair<ll, ll>;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)(x).size()
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (a)-1; i >= b; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define nl putchar('\n')
#define putc(c) putchar(c)
#define ins insert
#define sci(x) scanf("%d", &x)
#define sci2(a,b) scanf("%d %d", &a, &b)
#define sci3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sci4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define pri(x) printf("%d ", x)
#define prin(x) printf("%d\n", x)
#define scl(x) scanf("%lld", &x)
#define scl2(a,b) scanf("%lld %lld", &a, &b)
#define scl3(a,b,c) scanf("%lld %lld %lld", &a, &b, &c)
#define prl(x) printf("%lld ", x)
#define prln(x) printf("%lld\n", x)
#define scs(s) scanf("%s", s)
#define scs2(s1, s2) scanf("%s %s", s1, s2)
#define RET return

const int N = 200;
int num[N];
vi g[N];
vi level;
void add(int par, int l, int r) {
	if(l > r) RET;
	int mi, mx = -1;
	for(int i = l; i <= r; i++) {
		if(num[i] > mx) {
			mx = num[i];
			mi = i;
		}
	}
	g[par].pb(mx);
	add(mx, l, mi-1);
	add(mx, mi+1, r);
}
void dfs(int src) {
	trav(v, g[src]) {
			level[v] = level[src]+1;
			dfs(v);
	}
}

void solve() {
	int n;
	sci(n);
	level.clear();
	level.resize(n+1, -1);
	int mi, root = -1;
	F0R(i, n) {
		g[i].clear();
		sci(num[i]);
		if(num[i] > root) {
			mi = i;
			root = num[i];
		}
	}
	add(root, 0, mi-1);
	add(root, mi+1, n-1);
	level[root] = 0;
	dfs(root);
	F0R(i, n) {
		printf("%d ",
				level[num[i]]);
	}
	nl;
}


int main(void) {
	/* freopen("input.txt", "r", stdin); */
	/* freopen("output.txt", "w", stdout); */
		int t;
		scanf("%d", &t);
		for (int i = 1; i <= t; i++) {
			/* printf("Case %d: ", i); */
	
			solve();
			
			/* printf("%lld\n", (ll) solve()); */
	
			/* if (solve()) { */
			/* 	printf("YES\n"); */
			/* } else { */
			/* 		printf("NO\n"); */
			/* } */
		}
	 
	RET 0;
}

