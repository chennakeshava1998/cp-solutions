int Solution::gcd(int A, int B)
{
    if (A > B)
        swap(A, B);

    if (A == 0)
        return B;

    return gcd(B % A, A);
}
