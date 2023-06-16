/* ########################### *
 * # Welcome to the Internet # *
 * #   Have a look around    # *
 * ########################### */
#include <algorithm>
#include <array>
#include <cassert>
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

#ifdef LOCAL 
				#define eprintf(...) {fprintf(stderr, __VA_ARGS__); fflush(stderr); }
#else 
				#define eprintf(...) 42 
#endif

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
typedef vector<pil> vpii;
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
#define ins insert
#define sci(x) scanf("%d", &x)
#define sci2(a,b) scanf("%d %d", &a, &b)
#define sci3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define pri(x) printf("%d ", x)
#define prin(x) printf("%d\n", x)
#define scl(x) scanf("%lld", &x)
#define scl2(a,b) scanf("%lld %lld", &a, &b)
#define scl3(a,b,c) scanf("%lld %lld %lld", &a, &b, &c)
#define prl(x) printf("%lld ", x)
#define prln(x) printf("%lld\n", x)
#define scs(s) scanf("%s", s)
#define RET return
#define RET0 return 0
unordered_map<long long, int> hsh;
int lenOfLongSubarr(int A[], int N, int K) {
	long long sum = 0;
	int best = 0;
	for(int i = 0; i < N; i++) {
		sum += A[i];
		if(sum == K) best = max(best, i+1);
		if(hsh.find(sum) == hsh.end()) hsh.insert({sum, i});
		if(hsh.find(sum-K) != hsh.end()) {
			int l = hsh[sum-K];
			best = max(best, i - l + 1);
		}
	}
	return best;
}


int main(int argc, char **argv) {
	/* startTime = clock(); */
	/* freopen("input.txt", "r", stdin); */
	/* freopen("output.txt", "w", stdout); */
	 
	return 0;
}


