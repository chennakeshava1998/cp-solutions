int Solution::solve(vector<string> &A)
{
    vector<float> v;
    int i;

    for (i = 0; i < A.size(); ++i)
    {
        const char *p = A[i].c_str();
        v.push_back(atof(p));
    }

    sort(v.begin(), v.end());

    int j, k;
    for (i = 0; i < v.size() - 2; ++i)
    {
        j = i + 1;
        k = v.size() - 1;

        while(j < k)
        {
            double temp = v[i] + v[j] + v[k];
            if(temp > 1 && temp < 2)
                return 1;

            if(temp > 2)
                --k;

            if(temp < 1)
                ++j;
        }
    }

    return 0;
}