// https://www.geeksforgeeks.org/count-different-numbers-can-generated-digits-sum-equal-n/
#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long
#define mod 1000000007
ll func(ll n);
ll dp[100000]; // global array is useful if multiple test cases are used

int main()
{
	memset(dp, 0, 100000); // if dp array is initliazed to any other value like -1, then re-initialise the array with '0' before line-33.
	dp[0] = 0;
	dp[1] = 2;
	ll n;
	cin >> n;
	cout << func(n) << "\n";

	return 0;
}

ll func(ll n)
{
	if(dp[n]!=0) 
		return dp[n];
	// proceed only if dp[n] == -1, because this is a bottom-up approach, if dp[n] != -1, then dp[i] != -1 for all 1<i<n
	ll i;
	int j;

	for(i=2;i<=n;++i)
	{
		for(j=1;j<=3;++j)
		{
			if(i == j)
				dp[i] += 1; // the j-digit itself can only be used.
			else if(j == 1) // this condition is else-if and not only if: dp[1] has already been initialized
				dp[i] += (dp[i - j] * 2); // 1 is represented by '1' and '4'
			else if(i>j)
				dp[i] += dp[i - j];

			if(dp[i]>=mod)
				dp[i] = dp[i]%mod;
		}
	}

	return dp[n];
}