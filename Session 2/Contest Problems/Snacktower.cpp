#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define OO 2e18

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int N;
	cin >> N;
	int *fallen{new int[N + 1]{0}}; // To mark the fallen snakes; 0 means NOT fallen yet and 1 means it has ALREADY fallen
	int next_to_print = N;			// Stores the size of the following snake to print
	int j{next_to_print};
	for (int i{}; i < N; i++)
	{
		int x;
		cin >> x;
		fallen[x] = 1;		// Mark as fallen
		for (; j >= 1; j--) // Didn't put an initialization statement in order to continue on values of j which represents the next_to_print snake's size
		{
			if (fallen[j])
				cout << j << " ";
			else // breaks when the next_to_print snake's size is NOT marked as fallen
				break;
		}
		cout << endl;
	}
	delete[] fallen;
	return 0;
}