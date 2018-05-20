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

	vector<int>leftMin; // holds the minimum from v[0] to v[i]
	leftMin[0] = v[0];
	for(i=1;i<v.size();++i)
	{
		leftMin[i] = min(leftMin[i-1], v[i]);	
	}
	cout << "left min array\n";
	
	for(i=0;i<v.size();++i)
		cout << leftMin[i] << " ";
	cout << "\n";
	int  dist = -1;

	i = v.size()-1;
	j = v.size()-1;

	while(i>=0 && j>=0)
	{
		if(v[j]>leftMin[i])
		{
			dist = max(dist, j - i);
			--i; // move the left pointer backwards
		}
		else
			--j;
	}

	cout << dist << "\n";		

	return 0;
}