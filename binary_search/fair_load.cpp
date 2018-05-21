// problem_statement = https://community.topcoder.com/stat?c=problem_statement&pm=1901&rd=4650

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define vl vector<ll>
#define all(v) (v).begin(),(v).end()

ll getMinLoad(vector<ll>v,ll m); // returns the max number of files to be reviwed by a worker

int main()
{
    vector<ll>v = {950, 650, 250, 250, 350, 100, 650, 150, 150, 700};
    ll m = 6;


    cout<<getMinLoad(v,m)<<"\n";
    return 0;
}

ll getMinLoad(std::vector<ll> v,ll m)
{
    ll numWorkers, i, numFiles, maxCost = *max_element(all(v));
    while(1)
    {
        numFiles = 0;
        numWorkers = 0;
        i = 0;

        while(i < v.size())
        {
            while((numFiles + v[i]) <= maxCost) // not including the '=' causes an infinite loop in some of the cases!
            {
                numFiles += v[i];
                ++i;
            }
            ++numWorkers;
            numFiles = 0;
        }

        if(numWorkers <= m) return maxCost;
        /*
        very beautiful test case - v = {1,1,1,1,100} and m = 3 or m = 5
        we are going from least possible max to higher values, so if at any stage we achieve a cost with fewer workers ==> we can do better using all the workers provided - contradiction because we are moving from lowest possible cost to higher costs OR we can't do any better even with more workers because of the skewed distribution of data in the filing cabinets!!!
        */
        ++maxCost;
    }
}
