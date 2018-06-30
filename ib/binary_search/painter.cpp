// https://www.interviewbit.com/problems/painters-partition-problem/
#define MOD 10000003
bool check(const vector<int> &board_lengths, int num_painters, int max_possible_len)
{
    int req_num_painters = 0, temp_sum = 0, i;

    if (*max_element(board_lengths.begin(), board_lengths.end()) > max_possible_len)
        return 0;

    for (i = 0; i < board_lengths.size(); ++i)
    {
        if (temp_sum + board_lengths[i] <= max_possible_len)
            temp_sum += board_lengths[i];
        else
        {
            ++req_num_painters;
            temp_sum = board_lengths[i];
        }

        if (req_num_painters >= num_painters)
            return 0;
    }

    return 1;
}

int Solution::paint(int A, int B, vector<int> &C)
{
    long long l = *min_element(C.begin(), C.end()), r = accumulate(C.begin(), C.end(), 0), mid;

    while (l < r)
    {
        mid = l + (r - l) / 2;

        if (check(C, A, mid))
            r = mid;
        else
            l = mid + 1;
    }
    return (r % MOD * B % MOD) % MOD;
}
