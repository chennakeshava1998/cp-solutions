// https://practice.geeksforgeeks.org/problems/search-in-a-matrix/0
// Time Complexity: O(log(n * log(m) ) )
// n = # of rows; m = # of columns


#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t, n, m, i, j, x;
	cin >> t;

	while(t--)
	{
		cin >> n >> m;
		vector<vector<int> > v(n, vector<int>(m));

		for(i=0;i<n;++i)
		{
			for(j=0;j<m;++j)
				cin >> v[i][j];
		}

		cin >> x;
		// performig binary_search on the first-col

		int low = 0, high = n - 1, flag = 0;

		while(high >= low)
		{
			int mid = high - (high - low)/2; // avoid overflow due to (l + h)/2

			if(v[mid][0] == x)
			{
				cout << "1\n";
				flag = 1;
				break;
			}

			if(v[mid][0] > x) // no point of doing bs, if all the other elements in the row are higher.
			{
				high = mid - 1;
				continue;
			}

			// perform binary search on the row of mid
			if(binary_search(v[mid].begin(), v[mid].end(), x))
			{
				// x is found in the 'mid' row
				cout << "1\n";
				flag = 1;
				break;
			}
			
			low = mid + 1;
		}

		if(!flag)
			cout << "0\n";
	}


	return 0;
}