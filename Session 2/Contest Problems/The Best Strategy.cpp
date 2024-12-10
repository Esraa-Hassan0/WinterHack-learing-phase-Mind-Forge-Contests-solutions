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
	ll N;
	cin >> t;
	while (t--)
	{
		cin >> N;
		vector<ll> P(N);
		for (int i{}; i < N; i++)
			cin >> P[i];
		const int PERIOD = 300;
		ll currentTime{}, penalty{}, cnt{};
		sort(P.begin(), P.end());
		vector<ll> pref(N, 0);
		pref[0] = P[0];
		for (int i{1}; i < N; i++)
			pref[i] = pref[i - 1] + P[i];
		for (int i{}; i < N; i++)
		{
			if (currentTime + P[i] > PERIOD)
				break;
			cnt++;
			penalty += pref[i];
			currentTime += P[i];
		}
		cout << cnt << " " << penalty << endl;
	}
	return 0;
}