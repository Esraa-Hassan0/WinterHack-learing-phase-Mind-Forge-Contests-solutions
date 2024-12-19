#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

vector<int> Prime;

void Sieve_Of_Eratosthenes(int N)
{
	vector<bool> Is_Prime(N + 1, 1); // Initially Assuming all numbers to be primes
	Is_Prime[0] = Is_Prime[1] = 0;	 // 0 and 1 are NOT primes
	for (int i{2}; i <= N; i++)
	{
		if (Is_Prime[i])
		{
			Prime.push_back(i);
			for (int j{2 * i}; j <= N; j += i)
				Is_Prime[j] = 0;
		}
	}
}

bool check(int N)
{
	--N; // Subtract 1
	for (int a : Prime)
	{
		int pos_a = lower_bound(Prime.begin(), Prime.end(), a) - Prime.begin();
		if (binary_search(Prime.begin(), Prime.end(), N - a) == false)
			continue;
		int pos_b = lower_bound(Prime.begin(), Prime.end(), N - a) - Prime.begin();
		if (pos_b - pos_a == 1) // If they are neighboring
			return true;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE
	Sieve_Of_Eratosthenes(10001);
	int t = 1, K, N;
	// cin >> t;
	while (t--)
	{
		cin >> N >> K;
		int pos = lower_bound(Prime.begin(), Prime.end(), N) - Prime.begin();
		bool one = (binary_search(Prime.begin(), Prime.end(), N) == false); // If N itself is NOT a prime we iterate to the greatest prime < N
		int cnt{};
		for (int i{}; i <= pos - one; i++)
		{
			if (check(Prime[i]))
				cnt++;
		}
		if (cnt >= K)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}