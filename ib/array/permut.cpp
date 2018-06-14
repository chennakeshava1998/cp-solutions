// https://www.iarcs.org.in/inoi/online-study-material/topics/permutations.php
void Solution::nextPermutation(vector<int> &A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    // identify the first i, such that A[i] < A[i+1]. Everything to the right of i is sorted in desending order.

    int i = A.size() - 2;
    for (; i >= 0; --i)
    {
        if (A[i] < A[i + 1])
            break;
    }

    if (i == -1)
    {
        // the array is sorted in descending order. Hence display in ascending order.
        
        sort(A.begin(), A.end());
        // for (int i = A.size() - 1; i >= 0; --i)
        //     cout << A[i] << " ";
        // cout << endl;

        return;
    }

    // auto it = upper_bound(A.begin() + i + 1, A.end(), A[i]);
    auto it = upper_bound(A.end() - 1, A.begin() + i, A[i]);
    
    // swap(*it, A[i]);
    int temp = A[i];
    A[i] = *it;
    *it = temp;
    
    


    // reverse the part of the vector tp thr right of index-i

    // copy(A.rbegin(), A.begin() + i, A.begin() + i + 1);

    reverse(A.begin() + i + 1, A.end());

    for (i = 0; i < A.size(); ++i)
        cout << A[i] << " ";
    cout << endl;
}



/*
 *** Error in `./solution': corrupted size vs. prev_size: 0x000000000061c0e0 ***
Aborted
Your submission encountered runtime error for the following input:

A : [ 444, 994, 508, 72, 125, 299, 181, 238, 354, 223, 691, 249, 838, 890, 758, 675, 424, 199, 201, 788, 609, 582, 979, 259, 901, 371, 766, 759, 983, 728, 220, 16, 158, 822, 515, 488, 846, 321, 908, 469, 84, 460, 961, 285, 417, 142, 952, 626, 916, 247, 116, 975, 202, 734, 128, 312, 499, 274, 213, 208, 472, 265, 315, 335, 205, 784, 708, 681, 160, 448, 365, 165, 190, 693, 606, 226, 351, 241, 526, 311, 164, 98, 422, 363, 103, 747, 507, 669, 153, 856, 701, 319, 695, 52 ]

The expected output for this testcase is:
444 994 508 72 125 299 181 238 354 223 691 249 838 890 758 675 424 199 201 788 609 582 979 259 901 371 766 759 983 728 220 16 158 822 515 488 846 321 908 469 84 460 961 285 417 142 952 626 916 247 116 975 202 734 128 312 499 274 213 208 472 265 315 335 205 784 708 681 160 448 365 165 190 693 606 226 351 241 526 311 164 98 422 363 103 747 507 669 153 856 701 695 52 319 
*/
