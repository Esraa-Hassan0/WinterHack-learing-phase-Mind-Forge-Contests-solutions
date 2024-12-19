// https: // codeforces.com/contest/96/problem/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"

bool Equal_amount(ll N)
{
	int cnt_4{}, cnt_7{};
	while (N)
	{
		cnt_4 += (N % 10 == 4);
		cnt_7 += (N % 10 == 7);
		N /= 10;
	}
	return (cnt_4 == cnt_7);
}

vector<ll> Lucky_numbers;
void Generate_Lucky_Numbers(ll N)
{
	/*
	Starting from 0, We can build ALL lucky numbers
	At each digit, we have ONLY 2 choices:
	1. Make it 4
	2. Make it 7
	because lucky numbers contain ONLY 4's and 7's
	*/

	// if (N > 1e18) // It's efficient until 10^18
	if (N > 1e10)
		return;
	if (N) // If it's NOT 0, then it's A lucky number
	{
		if (Equal_amount(N))
			Lucky_numbers.push_back(N);
	}

	Generate_Lucky_Numbers(N * 10 + 4); // Make it 4
	Generate_Lucky_Numbers(N * 10 + 7); // Make it 7
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("Output.txt", "w", stdout);
#endif //! ONLINE_JUDGE

	Generate_Lucky_Numbers(0); // It's extremely fast, It's O(2^18)

	// It generates Lucky numbers UNSORTED, so we need to sort them first
	sort(Lucky_numbers.begin(), Lucky_numbers.end());

	int t = 1, N;
	ll X;
	// cin >> t;
	while (t--)
	{
		cin >> N;
		cout << *lower_bound(Lucky_numbers.begin(), Lucky_numbers.end(), N);
	}
	return 0;
}