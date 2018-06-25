int Solution::reverse(int A)
{
    string temp = to_string(A);
    std::reverse(temp.begin(), temp.end());
    stringstream ss(temp);
    int x = 0;
    ss >> x;

    if (A < 0)
        x = -x;

    if (x >= (1 << 32) || x < -(1 << 32))
        x = 0;

    return x;
}
