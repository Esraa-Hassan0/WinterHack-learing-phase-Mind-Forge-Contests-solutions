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
	int t = 1, K;
	vector<int> Hate3s;
	for (int i{1}; i <= 1000007; i++)
	{
		if (i % 3 != 0 && i % 10 != 3)
			Hate3s.push_back(i);
	}
	cin >> t;
	while (t--)
	{
		cin >> K;
		cout << Hate3s[K - 1] << endl;
	}
	return 0;
}