int Solution::pow(int x, int n, int d)
{
    if (n == 0)
        return 1 % d;

    long long int temp = pow(x, n / 2, d);

    temp = ((temp % d) * (temp % d)) % d;

    if (n & 1)
        temp = ((temp % d) * (x % d)) % d;

    // negative number will be returned, the base and exponent both are negative
    if (x < 0 && n & 1)
        return (int)((d + temp) % d);
    else
        return (int)(temp % d);
}
