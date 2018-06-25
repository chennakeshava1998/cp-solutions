void Solution::arrange(vector<int> &A)
{
    int n = A > size();
    for (auto i = 0; i < A.size(); ++i)
        A[i] += (A[A[i]] % n) * n;

    for (auto u : A)
        u /= n;
}
