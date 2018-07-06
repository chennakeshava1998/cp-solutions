// https://www.interviewbit.com/problems/palindrome-string/

int Solution::isPalindrome(string A)
{

    int i = 0;
    string s1;
    for (; i < A.size(); ++i)
    {
        if (A[i] >= 'A' && A[i] <= 'Z')
            A[i] = tolower(A[i]);

        if ((A[i] >= 'a' && A[i] <= 'z') || (A[i] >= '0' && A[i] <= '9'))
            s1 += A[i];
    }

    string s2 = s1;
    reverse(s2.begin(), s2.end());

    return (s2 == s1);
}
