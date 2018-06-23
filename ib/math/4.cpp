int Solution::isPalindrome(int A)
{
    if (A < 0)
        return 0;
    string temp = to_string(A);
    string rev = reverse(temp.begin(), temp.end());

    return temp == rev;
}
