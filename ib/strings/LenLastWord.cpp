// https://www.interviewbit.com/problems/length-of-last-word/

int Solution::lengthOfLastWord(const string A)
{
    string s = A;
    reverse(s.begin(), s.end());
    int i = 0;
    while (s[i] == ' ' && i < s.size())
        ++i;

    if (i == s.size())
        return 0;

    int start = i;

    for (; i < s.size(); ++i)
        if (s[i] == ' ')
            break;

    return i - start;
}
