#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define OO 2e18
#define MaxSize 1000000
vector<int>Prime,LPF(1000001);
void Linear_Sieve_Of_Eratosthenes(ll N)
{
	vector<bool>Is_Prime(N + 1, 1);//Initially Assuming all numbers to be primes
	LPF[1]=1;
	Is_Prime[0] = Is_Prime[1] = 0;//0 and 1 are NOT primes
	for (int i{ 2 }; i <= N; i++)
	{
		if (Is_Prime[i])
		{
			Prime.push_back(i);
			LPF[i] = i;//The least prime factor of a prime number is itself
		}
		for (int j{}; j < (int)Prime.size() and i * Prime[j] <= N and Prime[j] <= LPF[i]; j++)
		{
			Is_Prime[i * Prime[j]] = 0;//Crossing out all the multiples of prime numbers
			LPF[i * Prime[j]] = Prime[j];
		}
	}
}
 
ll Num_Of_Prime_Factors(ll N)
{
	int cnt{};
	while(N!=1)
	{
		if(LPF[N/LPF[N]]!=LPF[N])
		{
			cnt++;
		}
		N/=LPF[N];
	}
	return cnt;
	
	
 
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	Linear_Sieve_Of_Eratosthenes(1000001);
	ll N;
	cin>>N;
	int cnt{};
	for(int i{1};i<=N;i++)
	{
		if(Num_Of_Prime_Factors(i)==2)
		cnt++;
	}
	cout<<cnt;
	return 0;
}