// std::Vector::swap - Member function, constant complexity. More efficient implementation than crude implementation.

/* Library Function:
vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B)
{
    // Enough space needs to be allocated for the answer array, causes seg faults otherwise.
    vector<int>ans(max(A.size(), B.size()));

    auto it = set_intersection(A.begin(), A.begin()+A.size(), B.begin(), B.begin()+B.size(), ans.begin());
    ans.resize(it-ans.begin());
    return ans;

}
*/

vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B)
{
    int i = 0, j = 0;
    vector<int> ans;

    while (i < A.size() && j < B.size())
    {
        if (A[i] > B[j])
            ++j;
        else if (A[i] < B[j])
            ++i;
        else if (A[i] == B[j])
        {
            ans.push_back(A[i]);
            // Both the indices must be incremented, otherwise this could lead to double counting.
            ++i; 
            ++j;
        }
    }

    return ans;
}
