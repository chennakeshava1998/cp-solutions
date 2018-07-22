// the names of header files are case sensitive, ie. Including a few spaces near the '/' does not compile!
#include <bits/stdc++.h>
using namespace std;

// vector<int>v;
int quicksort(vector<int> &v, int start, int end, int k);
int partition(vector<int> &v, int start, int end);

// int partition(vector < int > & v, int start, int end) {
//     int i = start + 1, j = end, pivot = start;

//     // The below loop cannot be an if stmt. It has to continue until i and j cross-over each other.
//     while (i < j) {
//         while (i < v.size() && v[i] <= v[pivot])
//             ++i;

//         while (j >= 0 && v[j] > v[pivot])
//             --j;

//         if (i < j) {
//             cout << "Swapping: " << i << "\t" << j << endl;
//             swap(v[i], v[j]);

//         }
//     }

//     swap(v[j], v[pivot]);
//     cout << "Swapping: pivot " << pivot << "\t" << j << "\n\n";

//     return j;
// }

int quicksort(vector<int> &v, int start, int end, int k)
{
    if (start < end)
    {
        int pivot = partition(v, start, end);

        if (pivot == (k - 1))
            return v[pivot];
        else if (pivot < (k - 1))
            return quicksort(v, pivot + 1, end, k);
        else
            return quicksort(v, start, pivot, k);
    }
}

int partition(vector<int> &v, int start, int end)
{
    int i = start - 1;
    int pivot = v[end];
    int j;

    for (j = start; j <= end - 1; ++j)
    {
        if (v[j] <= pivot)
        {
            ++i;
            swap(v[i], v[j]);
        }
    }

    swap(v[i + 1], v[end]);

    return (i + 1);
}

int main()
{
    vector<int> v = {
        94, 87, 100, 11, 23, 98, 17, 35, 43, 66, 34, 53, 72, 80, 5, 34, 64, 71, 9, 16, 41, 66, 96};
    int k = 19;

    // vector<int> v = {2, 1, 4, 3, 2};
    // int k = 3;

    cout << quicksort(v, 0, v.size() - 1, k) << endl;

    return 0;
}