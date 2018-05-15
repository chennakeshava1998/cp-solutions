// explanation - https://www.geeksforgeeks.org/search-in-row-wise-and-column-wise-sorted-matrix/
// O(m + n)
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

		int p = 0, q = m - 1, flag = 0; // starting from the top right corner

		while(p < n && q >= 0)
		{
			if(v[p][q] == x)
			{
				flag = 1;
				break;
			}

			if(v[p][q] < x)
				++p;
			else
				--q;
		}

		flag?(cout<<"1\n"):(cout<<"0\n");
	}
	return 0;
}