// https://www.interviewbit.com/problems/reverse-the-string/
vector<string> splitString(string);
vector<string> splitString(string s)
{
    vector<string> v;
    int i = 0, j;
    for (i = 0; i < s.size(); ++i)
    {
        j = i;
        if (s[j] == ' ')
            continue;

        string temp;
        while (j < s.size() && s[j] != ' ')
            temp += s[j++];

        v.push_back(temp);
        i = j;
    }

    return v;
}
void Solution::reverseWords(string &A)
{
    vector<string> v = splitString(A);
    A.clear();

    reverse(v.begin(), v.end());

    for (int i = 0; i < v.size(); ++i)
    {
        A += s[i];
        if (i != (v.size() - 1))
            A += " ";
    }
}
