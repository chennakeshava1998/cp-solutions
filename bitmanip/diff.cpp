/*
	https://www.geeksforgeeks.org/sum-of-bit-differences-among-all-pairs/
*/

#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define ll long long

int main()
{
	ll t, n, x;
	cin >> t;
	while(t--)
	{
		ll i, j;
		cin >> n;
		int cnt[32] = {0}; // count of numbers where the i'th bit is 1
		// integer datatype takes 32 bits or 4 bytes 
		for(j=0;j<n;++j)
		{
			cin >> x;
			for(i=0;i<32;++i)
			{
				if(x & (1<<i)) // if i'th bit in x equals 1
					++cnt[i];
			}
		}

		ll ans = 0;
		for(i=0;i<32;++i)
		{
			// cnt[i] = # of elements with i'th bit = 1 (1-set)
			// n - cnt[i] = # of elements with i'th bit = 0 (the remaining elements) (0-set)
			// the bit difference of (a, b) = the bit difference of (b, a). Hence, multiply by 2.
			// choose 1 elements from 1-set and 1 element from 0-set ===> (cnt[i] choose 1 * (n - cnt[i]) choose 1 )
			ans = ans + 2 * (cnt[i] * (n - cnt[i]));
		}

		cout << ans << "\n";
	}

}