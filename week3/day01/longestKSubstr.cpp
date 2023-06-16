/* Problem statement: Given a string you need to print the size of the longest possible substring that has exactly K unique characters. If there is no possible substring then print -1. */ 
/* link: https://practice.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1 */
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
/* This problem can be solved using sliding window technique. We will increase our window/substring size while size is less than or equal to K. If size is equal to K we will take the maximum size.
 * Sliding window technique basically finds the longest substring size
 * which ends at the rth index. */ 

int longestKSubStr(string s, int k) {
	/* How many times each letter has found in the current substring */
	vector<int> alpha(26, 0);
	int cnt = 0; // number of unique chars in the current substring
	/* maximum size of the substring that has exactly k unique chars */							 
	int best = -1;
	/* left and right index of the current subarray */
	int l = 0, r = 0;
	while(r < s.size()) {
		alpha[s[r]-'a']++;
		if(alpha[s[r]-'a'] == 1) 
			cnt++;
		while(cnt > k) {
			alpha[s[l] - 'a']--;
			if(alpha[s[l] - 'a'] == 0) cnt--;
			l++;
		}
		if(cnt == k) {
			best = max(best, r - l + 1);
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


