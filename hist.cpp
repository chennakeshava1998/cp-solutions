    // problem - http://www.spoj.com/problems/HISTOGRA/
    // explanation - https://www.geeksforgeeks.org/largest-rectangle-under-histogram/
     
    #include<bits/stdc++.h>
    using namespace std;
     
    int main()
    {
    	long long int x, n;
    	cin >> n;
    	while(n != 0)
    	{
    		vector<long long>v;
     
    		while(n--)
    		{
    			cin >> x;
    			v.push_back(x);
    		}
     
    		stack<long long int>s; 
    		/* push only indices into the stack; 
    		* 1. No need to again search for the index within the input array. index of top element of stack is required to find the area 
    		* 2. If identical values are present in the array, confusions can be avoided
    		*/
     
    		long long int i = 0, l = v.size(), max_area = 0, tmp_area, top;
    		// use l instead of v.size(), not much of gains here anyway, because v.size() takes constant time. 
    		while(i < l)
    		{
    			if(s.empty() || v[s.top()] < v[i]) // v[s.top()] not pnly s.top() =====> Silly mistake, we are pushing indices. 
    				s.push(i++); // push i and later increment it! (i gets incremented only at this point.)
    			else
    			{
    				top = s.top();
    				s.pop();
     
    				// calculation of current area:
    				if(s.empty())
    					tmp_area = v[top] * i;
    				else
    					tmp_area = v[top] * (i - s.top() - 1);
     
    				if(max_area < tmp_area)
    					max_area = tmp_area;
     
    				// cout << "tmp_area = " << tmp_area << " i = " << i << "\n";
    			}
    		}
     
    		// cout << "\npopping the remaining elements of the stack:\n\n";
     
    		while(!s.empty())
    		{
    			top = s.top();
    			s.pop();
     
    			// calculation of current area:
    			if(s.empty())
    				tmp_area = v[top] * i;
    			else
    				tmp_area = v[top] * (i - s.top() - 1);
     
    			if(max_area < tmp_area)
    				max_area = tmp_area;
     
    			// cout << "tmp_area = " << tmp_area << " i = " << i << "\n";
    			// i = top;
    		}
     
    		cout << max_area << "\n";
     
    		cin >> n;
    		v.clear();
    	}
     
    	return 0;
    } 
