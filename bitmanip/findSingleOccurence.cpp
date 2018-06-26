int findSingleOccurence(vector<int> &v)
{
    int single;
    for (auto i = 0; i < 32; ++i)
    {
        int bit = 0;
        for (auto j = 0; j < v.size(); ++j)
        {
            if (a[j] & (1 << j))
                ++bit;
        }

        if (bit % 3)
            single |= (1 << j);
    }

    return single;
}