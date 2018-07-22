// to test pass-by-ref concept.
#include<bits/stdc++.h>
using namespace std;

void test_func(vector<int>&);

void test_func(vector<int>& v)
{
    swap(v[0], v[1]);
}

int main()
{
    vector<int>v = {1, 2};
    cout << "before swapping: " << v[0] << "\t" << v[1]<<endl;

    test_func(v);
    cout << "after swapping: " << v[0] << "\t" << v[1]<<endl;


    return 0;
}