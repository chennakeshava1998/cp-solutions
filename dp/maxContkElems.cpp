// Kadane's Algorithm - https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

int main()
{
	ios::sync_with_stdio(false);

	ll t, n, curr_max, global_max, x, i, j, k;
	cin >> t;
	while(t--)
	{
		cin >> n;
		vector<ll>v;
		while(n--)
		{
			cin >> x;
			v.pb(x);
		}

		cin >> k;

		vector<ll>prefixArray(v.size()); 
		// prefixArray is useful to calculate the sum of previous k-elements in O(1) time.
		prefixArray[0] = v[0];

		for(i=1;i<v.size();++i)
			prefixArray[i] = prefixArray[i-1] + v[i];

		curr_max = prefixArray[k-1]; // sum of first k-elements
		global_max = curr_max;

		for(i=k;i<v.size();++i)
		{
			curr_max = max(curr_max + v[i], prefixArray[i] - prefixArray[i-k]/* fresh sum of last k-elements */);
			global_max = max(global_max, curr_max);
		}

		cout << global_max << "\n";
	}

	return 0;
}