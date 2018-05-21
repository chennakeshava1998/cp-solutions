// uses max-suffix array preprocessing.
// can also be solved after sorting(retaining the original index), and then using this preprocessing.
// This is an O(n) solution.
#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<int>v;
	int i, j, n, x;
	cin >> n; // n is the number of integers
	while(n--)
	{
		cin >> x;
		v.push_back(x);
	}

	vector<int>leftMin(v.size()); // holds the minimum from v[0] to v[i]
	// initialise the size of leftMin vector, otherwise segmentation fault is caused.
	leftMin[0] = v[0];
	for(i=1;i<v.size();++i)
	{
		leftMin[i] = min(leftMin[i-1], v[i]);	
	}
	
	/* Debug Info:
	cout << "left min array\n";
	
	for(i=0;i<v.size();++i)
		cout << leftMin[i] << " ";
	cout << "\n";
	*/
	int  dist = -1; // maximum distance of separation

	i = v.size()-1;
	j = v.size()-1;

	while(i>=0 && j>=0)
	{
		if(v[j]>leftMin[i])  // comparing v[j] with the range-minimum-minimum within v[0]...v[i]
		{
			dist = max(dist, j - i);
			--i; // move the left pointer to the back(left) of the array
		}
		else
			--j; // move the right pointer to the back of the array
	}

	cout << dist << "\n";		

	return 0;
}
