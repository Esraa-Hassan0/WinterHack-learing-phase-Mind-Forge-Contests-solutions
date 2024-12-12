#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> arr(n), sortedArr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		sortedArr[i] = arr[i];
	}

	sort(sortedArr.begin(), sortedArr.end());

	vector<ll> pref(n);
	pref[0] = arr[0]; // 5 5 2 3
	for (int i = 1; i < n; i++)
		pref[i] = arr[i] + pref[i - 1]; // 5 10 12 15

	vector<ll> sortedPref(n);
	sortedPref[0] = sortedArr[0]; // 2 3 5 5
	for (int i = 1; i < n; i++)
		sortedPref[i] = sortedArr[i] + sortedPref[i - 1]; // 2 5 10 15

	int m, t, l, r;
	cin >> m;
	while (m--)
	{
		cin >> t >> l >> r;
		--l, --r;
		if (t == 1)
			cout << pref[r] - (l > 0 ? pref[l - 1] : 0) << endl;
		else if (t == 2)
			cout << sortedPref[r] - (l > 0 ? sortedPref[l - 1] : 0) << endl;
	}
	return 0;
}