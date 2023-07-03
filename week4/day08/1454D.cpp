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
const int N = 1e5 + 100;
vb num(N, 1);
vl primes;
void gen_prime() {
	num[2] = 1;
	num[0] = num[1] = 0;
	FOR(i, 2, N) {
		if(num[i]) {
			primes.pb(i);
			for(int j = 2; j*i < N; j++) 
				num[j*i] = 0;
		}
	}
}
void solve() {
	ll n;
	scl(n);
	bool found = 0;
	int cnt = 0;
	ll div = 1;
	vpii divs;
	ll tmp = n;
	trav(prime, primes) {
		cnt = 0;
		n = tmp;
		if(prime == n) {
			printf("1\n%lld\n", prime);
			RET;
		}
		while(n % prime == 0) {
			cnt++;
			n /= prime;
			found = 1;
		}
		if(cnt) {
			divs.pb({cnt, prime});
		}
	}
	if(!found) {
		printf("1\n");
		printf("%lld\n", n);
		RET;
	}
	sort(all(divs));
	cnt = divs.back().fi;
	div = divs.back().se;
	printf("%d\n", cnt);
	cnt--;
	ll done = 1;
	F0R(i, cnt) {
		printf("%lld ", div);
		done *= div;
	}
	printf("%lld\n", tmp/done);
}
int main(void) {
	/* freopen("input.txt", "r", stdin); */
	/* freopen("output.txt", "w", stdout); */
		int t;
		scanf("%d", &t);
		gen_prime();
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

