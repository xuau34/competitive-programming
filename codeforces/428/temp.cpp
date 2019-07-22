// God & me
// Fly ...
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 40, C = 20;

int n, k, dp[1 << C];
ll adj[maxn];
int maxc(){
	for(int i = 0; i < n; i++)
		for(int j = 0, x; j < n; j++)
			cin >> x, adj[i] |= (ll) (x || i == j) << j;
	for(int i = 1; i < (1 << max(0, n - C)); i++){
		int x = i;
		for(int j = 0; j < C; j++)
			if((i >> j) & 1)
				x &= adj[j + C] >> C;
		if(x == i)
			dp[i] = __builtin_popcount(i);
	}
	for(int i = 1; i < (1 << max(0, n - C)); i++)
		for(int j = 0; j < C; j++)
			if((i >> j) & 1)
				dp[i] = max(dp[i], dp[i ^ (1 << j)]);
	int ans = 0;
	for (int i = 0; i < (1 << min(C, n)); i++){
		int x = i, y = (1 << max(0, n - C)) - 1;
		for (int j = 0; j < min(C, n); j++)
			if ((i >> j) & 1)
				x &= adj[j] & ((1 << C) - 1), y &= adj[j] >> C;
		if (x != i)	continue;
		ans = max(ans, __builtin_popcount(i) + dp[y]);
    cout << ans << " ";
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k;
	int ans = maxc();
	long double x = (long double) k / ans;
	cout << fixed << setprecision(8) << x * x * ans * (ans - 1) / 2 << '\n';
	return 0;
}
