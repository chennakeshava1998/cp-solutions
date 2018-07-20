// Using Buscket Sort method - Memory Limit Exceeded
#include <bits/stdc++.h>
using namespace std;

int kthSmallestElem(vector<int> v, int k);

int kthSmallestElem(vector<int> v, int k)
{
    int min_elem = *min_element(v.begin(), v.end());
    int max_elem = *max_element(v.begin(), v.end());
    int n = v.size();
    int i;

    int partition = max(1, (max_elem - min_elem) / n);

    vector<int> cnt((max_elem - min_elem) / partition + 1, 0);

    // calculating the frequencies of buckets.
    for (int i = 0; i < v.size(); ++i)
        cnt[(v[i] - min_elem) / partition]++;

    int sum = 0;
    i = 0;
    while (i < cnt.size() && (sum + cnt[i] < k))
    {
        sum += cnt[i];
        ++i;
    }

    vector<int> temp;

    // collecting all elements belonging to the i'th bucket
    int bucket = i;

    for (i = 0; i < v.size(); ++i)
    {
        if (v[i] >= (partition * bucket + min_elem) && v[i] < (partition * (bucket + 1) + min_elem))
            temp.push_back(v[i]);
    }

    sort(temp.begin(), temp.end());

    return temp[k - sum - 1];
}

int main()
{
    vector<int> v = {2, 1, 4, 3, 2};
    int k = 3;

    // vector<int> v = {1};
    // int k = 1;

    cout << kthSmallestElem(v, k) << endl;

    return 0;
}
