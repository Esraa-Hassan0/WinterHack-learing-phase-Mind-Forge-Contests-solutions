#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
	int t = 1;
	ll N, Q, X;
	// cin >> t;
	while (t--)
	{
		cin >> N;
		vector<int> worms(N), piles(N + 1, 0);
		for (int i{}; i < N; i++)
			cin >> worms[i];
		piles[0] = 0;
		piles[1] = worms[0];
		for (int i{2}; i <= N; i++)
			piles[i] = piles[i - 1] + worms[i - 1];
		cin >> Q;
		while (Q--)
		{
			cin >> X;
			cout << (lower_bound(piles.begin(), piles.end(), X) - piles.begin()) << endl;
		}
	}
	return 0;
}