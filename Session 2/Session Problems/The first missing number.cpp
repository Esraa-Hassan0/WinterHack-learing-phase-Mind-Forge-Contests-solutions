#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
// https://codeforces.com/group/c3FDl9EUi9/contest/262795/problem/D
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif // !ONLINE_JUDGE

	int N, M, X;
	cin >> N >> M;
	vector<int> freq(2 * M + 1);
	while (N--)
	{
		cin >> X;
		freq[X + M]++;
	}
	for (int i{0}; i <= M; i++)
	{
		if (freq[i] == 0)
		{
			cout << i - M;
			return 0;
		}
	}
	return 0;
}