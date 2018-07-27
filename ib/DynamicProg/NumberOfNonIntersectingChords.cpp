// https://www.interviewbit.com/problems/intersecting-chords-in-a-circle/
#define MOD (int)(pow(10, 9) + 7)

int Solution::chordCnt(int A)
{
    // use long long datatype for being on the safer side.
    vector<long long int> dp(A + 1);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= A; ++i)
    {
        long long sum = 0;
        for (int j = 0; j < i; ++j)
        {
            sum = (sum%MOD + (dp[j]%MOD * dp[i - j - 1]%MOD)%MOD)%MOD;
        }

        dp[i] = sum%MOD;
    }

    return (int)(dp[A]%MOD);
}
