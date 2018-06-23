vector<int> prime;
void func()
{
    if (!prime.empty())
        return;
    vector<bool> v(pow(10, 7) + 1, 1);
    v[0] = 0;
    v[1] = 0;
    int i, j;

    // creation of prime numbers
    for (auto i = 2; i < v.size(); ++i)
    {
        if (v[i])
        {
            for (j = 2 * i; j < v.size(); j += i)
                v[j] = 0;
        }
    }

    for (auto i = 0; i < v.size(); ++i)
    {
        if (v[i])
            prime.push_back(i);
    }
}

bool is_prime(int n)
{
    if (n <= 1)
        return 0;

    for (auto i = 2; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

vector<int> Solution::primesum(int A)
{
    func();
    // finding the two primes:
    vector<int> ans;
    for (auto i = 0; i < prime.size(); ++i)
    {
        if (is_prime(A - prime[i]))
        {
            ans.push_back(prime[i]);
            ans.push_back(A - prime[i]);
            return ans;
        }
    }

    // this case really does not arise - Goldbach's Conjecture
    return ans;
}
