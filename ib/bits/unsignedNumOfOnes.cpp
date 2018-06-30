// https://www.interviewbit.com/problems/number-of-1-bits/
int Solution::numSetBits(unsigned int A)
{
    // Solution-1:
    // __builtin_popcount : int
    // __builtin_popcountl : long int
    // __builtin_popcountll : long long
    // Most efficient answer:
    // return __builtin_popcountll((long long)A);

    // Solution-2:
    // Traverse all the 32 bits, and check which of them is 1

    // Solution-3:
    // x & (x - 1) will only unset the last set bit!! All the other bits remain unaffected ==> IMP
    /* ===================================================================*/
    // O (Number of Ones): Really beatiful answers!
    int cnt = 0;
    while (A)
    {
        ++cnt;
        A = A & (A - 1);
    }

    return cnt;
}
