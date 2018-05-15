// https://practice.geeksforgeeks.org/problems/search-in-a-matrix/0
// Time Complexity: O(log(n) * log(m) )
// n = # of rows; m = # of columns

/*
 * This solution does not work because I am only performing binary-search(BS) on the first column elements,
 * and then trying to use them as indexes for the second-level BS on that particular row.
 * All the rows and columns are sorted, but that does not imply a correlation between the elements of rows and cols
 * An counter-example:

 1
 3 3
 1 1 5
 2 3 7
 4 6 8
 5 (element to be searched)
 
 this code will perform BS only the first column and conclude that 5 is not present. This is a mistake.
 * 
 */

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