// program to test the sorting of a array of user-defined objects
#include <bits/stdc++.h>
using namespace std;

struct Student
{
    int first, last;

    Student() // default constructor
    {
        first = 0;
        last = 0;
    }

    Student(int a, int b) // parameterised constructor
    {
        first = a;
        last = b;
    }
};

bool less_than_type(const Student &a, const Student &b)
{
    return a.first < b.first;
}

int main()
{
    vector<Student> v;
    int i;
    for (i = 10; i >= 0; --i)
    {
        Student temp(i, i + 1);
        v.push_back(temp);
    }

    cout << "before sorting:\n";
    for (i = 0; i < v.size(); ++i)
        cout << v[i].first << "\t" << v[i].last << endl;

    sort(v.begin(), v.end(), less_than_type);
    cout << "after sorting:\n";

    for (i = 0; i < v.size(); ++i)
        cout << v[i].first << "\t" << v[i].last << endl;

    return 0;
}
