#include <stdio.h>

int solve() {
	int x;
	scanf("%d", &x);
	if(x <= 10) return 1;
	return 0;
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		if(solve()) puts("YES");
		else puts("NO");
	}
	return 0;
}
