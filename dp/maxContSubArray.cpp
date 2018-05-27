// Kadane's Algorithm - https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

int main()
{
	ios::sync_with_stdio(false);

	ll t, n, curr_max, global_max, x;
	cin >> t;
	while(t--)
	{
		cin >> n;
		cin >> x;
		curr_max = x;
		global_max = x;

		--n; // first element has already been taken as an input
		while(n--)
		{
			cin >> x;
			curr_max = max(curr_max + x, x);
			global_max = max(global_max, curr_max);
		}

		cout << global_max << "\n";

	}

	return 0;
}