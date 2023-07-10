/* 
 * You didn’t come into this world. 
 * You came out of it, like a wave from the ocean.
 * You are not a stranger here. 
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
typedef vector<bool> vb;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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

void solve() {
	int n;
	sci(n);
	vpii a(n);
	F0R(i, n) {
		int x;
		sci(x);
		a[i].fi = x;
		a[i].se = i+1;
	}
	sort(all(a));
	vector<pii> ans2;
	vector<pii> ans1;
	int Left = 0, Right = 0;
	F0R(i, n-1) {
		Left += a[i].fi;
		ans1.pb(a[i]);
	}
	ans2.pb(a[n-1]);
	Right = a[n-1].fi;
	if(Left <= Right) {
		printf("%d\n", Left);
		F0R(i, n-1) {
			F0R(j, a[i].fi) printf("%d %d\n", a[i].se, a[n-1].se);
		}
		RET;
	}
	int diff = Left - Right;
	diff = (diff + 1) / 2;
	int i = 0;
	while(Right < Left) {
		if(i >= ans1.size()) break;
		/* printf("diff = %d\n", diff); */
		int taken = min(diff, ans1[i].fi);
		/* printf("taken = %d\n", taken); */
		Right += taken;
		Left -= taken;
		diff -= taken;
		ans1[i].fi -= taken;
		ans2.pb({taken, ans1[i].se});
		i++;
	}
	/* printf("Right = %d, Left = %d\n", Right, Left); */
	/* printf("ans1 size = %d, ans2 = %d\n", sz(ans1), sz(ans2)); */
	printf("%d\n", (Left+Right)/2);

		int l = 0, r = 0;
		/* assert(ans1[l].se != ans2[r].se); */
	while(l < sz(ans1) && r < sz(ans2)) {
		while(l < sz(ans1) && ans1[l].fi <= 0) l++;
		while(r < sz(ans2) && ans2[r].fi <= 0) r++;
		/* printf("l = %d, r  = %d\n", l, r); */
		while(l < sz(ans1) && ans1[l].fi > 0 && r < sz(ans2) && ans2[r].fi > 0) {
			printf("%d %d\n", ans1[l].se, ans2[r].se);
			ans1[l].fi--, ans2[r].fi--;
		}
	}
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

