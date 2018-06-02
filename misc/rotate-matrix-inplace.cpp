// https://www.geeksforgeeks.org/inplace-rotate-square-matrix-by-90-degrees/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t, n, x, i, j;
	cin >> t;

	while(t--)
	{
		cin >> n;
		int v[n][n];
		
		for(i=0;i<n;++i)
		{
			for(j=0;j<n;++j)
				cin >> v[i][j];
		}


		for(i=0;i<n/2;++i)
		{
			for(j=i;j<n-i-1;++j)
			{
				int temp = v[i][j];

				v[i][j] = v[j][n-i-1];

				v[j][n-i-1] = v[n-i-1][n-j-1];

				v[n-i-1][n-j-1] = v[n-j-1][i];

				v[n-j-1][i] = temp;

			}
		}

		for(i=0;i<n;++i)
		{
			for(j=0;j<n;++j)
				cout << v[i][j] << " ";
		}

		cout << "\n";
	}

	return 0;
}