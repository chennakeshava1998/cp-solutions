// https://practice.geeksforgeeks.org/problems/save-gotham/0
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000001
using namespace std;

ll func(const vector<ll> &v);

int main()
{
	ll t, n, x;
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

		cout << func(v) << "\n";
	}

}

ll func(const vector<ll> &v)
{
	int n = v.size(), i ,j;
	stack<ll>s; // holds the elements for which nextGreater() hasn't yet been found. 
	// The elements in the stack are in the same order as given in the input(ascending as seen from the top of stack.

	ll sum = 0; // accumulator variable

	for(i=0;i<n;++i)
	{
		if(s.empty())
			s.push(v[i]);
		else if(s.top() < v[i])
		{
			// v[i] is the nextGreater for the element at the top of stack.
			sum = (sum + v[i]%mod)%mod; 
			s.pop(); // nextGreater for this element has been added to sum.

			while(s.empty() == 0 && s.top() < v[i]) // v[i] is nextGreater for all such elements.
			{
				/* 
				* Example case:
				* 6 5 4 3 10 ....
				* This while loop is encountered when 10 is compared with other elements.
				*/
				sum = (sum + v[i]%mod)%mod;
				s.pop();
			}

			s.push(v[i]); // we still need to find nextGreater() for v[i] itself.
		}
		else
			s.push(v[i]);
	}

	/* there is no need to empty the stack and add all the remaining elements, because:
	 * if nextGreater(elem) is found, elem is removed from the stack. 
	 * so if nextGreater(elem) is not found, then the elements remain on the stack.
	 * there is no need to empty the stack and add them up.
	*/
	return sum;
}

/*
* Testcases:
1
9
112 133 161 311 122 512 1212 0 19212
*/

/*
* Some observations:
* If nextGreater(v[i]) is found (for an element at position i in the input vector),
* then it does not necesarily mean that, nextGreater has been found for all the previous elements.
* Ex: 10 2 4 
* here, nextGreater(2) = 4, but nextGreater(10) doesn't exist. 
*/