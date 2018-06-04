/*
void mergeArrays(int arr1[], int arr2[], int m, int n);
You are given the above function declaration. Assume arr1 and arr2 are two sorted arrays with m integers, and n integers respectively.  Also assume, that arr1 has the capacity to hold (m + n) integers. Create the function which stores the contents of arr1 and arr2 in arr1 in sorted order, with O(1) space and O(m + n) time complexity. No need to return arr1, just store the values in arr1.
Example:
Input arrays:
arr1 = 1, 2, 3, 6, 8, 9, -, -, -
arr2 = 5, 7, 10
Output array:
arr1 = 1, 2, 3, 5, 6, 7, 8, 9, 10
*/

#include<bits/stdc++.h>
using namespace std;

void mergeArrays(int arr1[], int arr2[], int m, int n)
{
	// start from the end of both the arrays
	long long i, j, k;

	// i, j and k are indices of arr1, arr2 and final answer respectively.
	i = m - 1;
	j = n - 1;
	k = m + n - 1;

	while(k >= 0)
	{
		if(j < 0 || arr1[i] > arr2[j])
		{
			arr1[k] = arr1[i];
			--i;
		}
		else if(i < 0 || arr1[i] <= arr2[j]) // if i<0 is not included, then arr1[i] will contain garbage values
		{
			/*
			Do not forget the equality condition; if arr1 and arr2 contain duplicate values, program will go wrong.
			2 4
			-4 -3
			-4 -3 -2 -1
			*/
			arr1[k] = arr2[j];
			--j;
		}
		--k;
	}

	for(i=0;i<m+n;++i)
		cout << arr1[i] << " ";
	cout << "\n"; 
}

int main()
{
	int m, n, i, j;
	cin >> m >> n;
	int a[m + n], b[n];
	memset(a, -1, sizeof(a));
	memset(b, -1, sizeof(b));
	
	/* inserting -1 to prevent occurence of garbage values. Garbage values will disrupt comparisons, 
	* especially since this algorithm begins from the end of arr1 (and arr2).
	*/

	for(i=0;i<m;++i)
		cin >> a[i];

	for(i=0;i<n;++i)
		cin >> b[i];

	mergeArrays(a, b, m, n);
}
