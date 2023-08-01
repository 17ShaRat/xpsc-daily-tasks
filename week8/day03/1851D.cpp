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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC target("popcnt")
using namespace std;
using namespace __gnu_pbds;
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
int n;
bool missing_from_left(vector<long long> a) {
	vector<int> occur(n+1);
	for(int i = 0; i < n - 2; i++) {
		if(a[i+1] - a[i] > n) RET 0;
		occur[a[i+1]-a[i]]++;
		if(occur[a[i+1]-a[i]] > 1) RET 0;
	}
	int sum = 0;
	int cnt = 0;
	for(int i = 1; i <= n; i++) {
		if(!occur[i]) {
			cnt++;
			sum += i;
		}
	}
	if(cnt > 2) RET 0;
	RET sum == a.front();
}
bool missing_from_right(vector<long long> a) {
	if(a.front() > n) return false;
	vector<int> occur(n+1);
	occur[a.front()]++;
	for(int i = 0; i < n - 2; i++) {
		if(a[i+1] - a[i] > n) return false;
		occur[a[i+1]-a[i]]++;
		if(occur[a[i+1]-a[i]]> 1) return false;
	}
	int cnt = 0;
	int sum = 0;
	for(int i = 1; i <= n; i++) {
		if(!occur[i]) {
			cnt++;
			sum += i;
		}
	}
	/* printf("Missing from right : "); */
	/* printf("cnt = %d, sum = %d\n", cnt, sum); */
	if(cnt > 1) RET 0;
	ll mx = (ll) n * (n+1) / 2;
	if(a.back() + sum > mx) return false;
	return true;
}
bool missing_from_middle(vector<long long> a) {
	if(a.front() > n) RET 0;
	ll mx = (ll) n * (n+1) / 2;
	if(a.back() != mx) RET 0;
	int sum = 0;
	vector<int> occur(n+1);
	int tmp = 0;
	occur[a.front()] = 1;
	int target = -1;
	int twice = 0;
	int val = 0;
	for(int i = 0; i < n - 2; i++) {
		int diff = a[i+1] - a[i];
		if(diff > n) {
			tmp++;
			target = diff;
			continue;
		}
		occur[diff]++;
		if(occur[diff] > 1) {
			twice++;
			val = diff;
		}
		if(twice > 1) return false;
		if(tmp > 1) return false;
	}
	if(tmp == 1 && twice == 1) return false;
	for(int i = 1; i <= n; i++) {
		if(!occur[i]) {
			sum += i;
		}
	}
	if(tmp) {
		if(sum == target) return true;
	}
	if(twice) if(sum == val) return true;
	return false;
}
bool solve() {
	scanf("%d", &n);
	vl a(n-1);
	for(int i = 0; i < n-1; i++) scanf("%lld", &a[i]);
	if(missing_from_left(a)) return true;
	if(missing_from_right(a)) return true;
	if(missing_from_middle(a)) return true;
	return 0;
}
int main(void) {
	/* freopen("input.txt", "r", stdin); */
	/* freopen("output.txt", "w", stdout); */
		int t;
		scanf("%d", &t);
		for (int i = 1; i <= t; i++) {
			/* printf("Case %d: ", i); */
	
			/* solve(); */
			
			/* printf("%lld\n", (ll) solve()); */
	
			if (solve()) {
				printf("YES\n");
			} else {
					printf("NO\n");
			}
		}
	 
	RET 0;
}

