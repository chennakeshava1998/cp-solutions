// idea = https://community.topcoder.com/stat?c=problem_statement&pm=1901&rd=4650

#include <bits/stdc++.h>
using namespace std;

bool bs(vector<int> v, int numStudents, int maxi);
int calMin(vector<int> v, int numStudents);

// perform binary search on the number of papers to be searched by a student  
int main()
{
    // input
    int numStudents, x, i, n;
    cout << "Enter the number of books\n";
    cin >> n;
    vector<int> v;

    while (n--)
    {
        cin >> x;
        v.push_back(x);
    }

    cin >> numStudents;

    // call calMin() function
    cout << calMin(v, numStudents) << endl;

    return 0;
}

int calMin(vector<int> v, int numStudents)
{
    int high = accumulate(v.begin(), v.end(), 0); // Single student must see all the papers
    int low = *max_element(v.begin(), v.end()); // One student per book
    // High and low define the search space.
    int mid, last_working_ans;

    // After the end of binary search, the last encountered mid value might not have worked. The bool values in the search space is: Y Y Y ... Y N N N .. N
    // So, instead of tracking the last correct value, we can return one more than the current value, if the current value gives a false from bs() function


    // call bs() [perform binary search]

    while (low < high)
    {
        mid = (high - low) / 2 + low; // simple (h+l)/2 may cause overflow
        // mid = (high + low) / 2;
        // cout << "high:" << high << "\t" << "low: " << low << endl;

        bool ans = bs(v, numStudents, mid);
        
        if (ans == 1)
        {
            high = mid - 1;
            last_working_ans = mid;
        }
        else
            low = mid + 1;
    }

    return last_working_ans;
}

bool bs(vector<int> v, int numStudents, int maxi)
{
    int i, runningSum = 0, reqStudents = 0;


    for (i = 0; i < v.size(); ++i)
    {
        if (reqStudents >= numStudents)
            return 0;

        if (v[i] + runningSum <= maxi)
            runningSum += v[i];
        else
        {
            runningSum = 0;
            ++reqStudents;
            --i;
        }
    }

    // cout << "maxi : " << maxi << "\treq:" << reqStudents << endl;

    return 1;
}
