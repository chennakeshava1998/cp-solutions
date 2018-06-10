// This program tests why iterators of a set cannot be subtracted, like those of a vector. This is probably because set is implemented as a Tree, which is not a linear data structure.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> s;

    for (int i = 0; i < 100; ++i)
        s.insert(i);

    // This throws an error: s.end() - s.begin() 
    // That's probably because set is implemented as a tree, unlike a vector.
    // distance[first, last] : DO NOT INVERT FIRST AND LAST PARAMS

    // Time Complexity of distance() : Constant for a random access data structure. Linear for other types of data structures.
    cout << distance(s.begin(), s.end()) << endl;

    return 0;
}