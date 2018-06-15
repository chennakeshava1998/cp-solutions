/*
Editorial:

InterviewBit logo

    Practice
    Referrals
    Contests New

    2185
    50
    Chenna

    Programming Arrays Set Matrix Zeros 

Set Matrix Zeros

Given an m x n matrix of 0s and 1s, if an element is 0, set its entire row and column to 0.

Do it in place.

Example

Given array A as

1 0 1
1 1 1 
1 1 1

On returning, the array A should be :

0 0 0
1 0 1
1 0 1

Note that this will be evaluated on the extra memory used. Try to minimize the space and time complexity.
Seen this question in a real interview before
Notes
All Notes

00 : 42 : 48
Current Possible Score: 132
Max Score: 300

Saved code at 13:45:51

    Compilation
    Correctness
    Efficiency
    Memory Limit Exceeded. Your submission didn't complete in the allocated memory limit.

    In actual interview it is expected to write the most optimal solution at the first attempt. Please be careful, you might not get a second chance in front of a real Interviewer.
    Partially Correct Answer.
    You got 99/300 points!

Hints

    Hint 1
    Solution Approach
    Complete Solution


Similar Problems

    MAXSPPROD
    Merge Intervals

18741 successful submissions.
Asked In:

    Oracle
    Amazon

Discussion

This thread is for people who have not yet solved the problem. Please do not post solutions here.


    V
    vandana_13 about 20 hours ago
    What is the time limit of question?0 Reply
    S
    shubham_2781 3 days ago
    Code works on other compilers0 Reply
    A
    abhishek-vispute 10 days ago
    My code works fine on all test cases i give but on submit it shows *** Error in `3 Reply
    S
    shivam-sharma_396 27 days ago
    Loop not functioning0 Reply
    A
    amber-saxena about 1 month ago
    My code runs for all test cases except for this. But this test case give correct answer when run as a custom input0 Reply
    P
    pranshu_upadhaya about 1 month ago
    Is there a bug? A case that gives correct output in "test using custom input" giv1 Reply
    S
    ShubhamRathi about 2 months ago
    Getting the correct output in the terminal but not in InterviewBit0 Reply
    S
    santosh_kumar_326 5 months ago
    Java8 arrray support for solving the problem0 Reply
    Y
    yashveer-rana 5 months ago
    Why is return type void?1 Reply
    G
    guest_user_251 over 2 years ago
    One useful comment: assume r0 Reply
    G
    guest_user_251 almost 3 years ago
    There will be only 1 zero in the entire Matrix?2 Reply
    G
    guest_user_251 almost 3 years ago
    Is it a boolean matrix?0 Reply
    A
    anshumansingh about 3 years ago
    Unexpected result ? Put debug statements to see what's going wrong. How to use th3 Reply
    A
    anshumansingh about 3 years ago
    Hi, It's giving "Time Limit Exceeded. Your submission didn't complete in the all3 Reply
    A
    anshumansingh about 3 years ago
    What is the memory limit for the question?3 Reply
    A
    anshumansingh about 3 years ago
    Does the input matrix have only one element with value '0'?1 Reply
    G
    guest_user_251 about 3 years ago
    Return type is void. Should I print the matrix?0 Reply


    Blog About Us FAQ Contact Us Terms Privacy Policy 

    System Design Interview Questions Google Interview Questions Facebook Interview Questions Amazon Interview Questions Microsoft Interview Questions 

    Like Us Follow Us Email 

Got suggestions ? We would love to hear your feedback.
Loved InterviewBit ? Write us a testimonial.
Access Hint

Small explanation :

We use the first row and column in the matrix to store what we need to store in step 2. The trick is in using the first row and column to store the information.
Then we need to know whether or not to set the first row and column to zeroes. So, we use two boolean to store that information.

Detailed explanation :

So, you have 2 additional variables ( lets say R and C ). Firstly convince yourself that if in the original array, if any of the value in the first row was 0, the whole row will be 0. So R stores just that information ( whether any of the value in the row was 0 ). Now, if R = 0, your job is simple. In the end, mark every element in the first row as 0. If R = 1, then leave the row as it is ( with each cell storing whether their corresponding column has any zeroes ).
Things work very similarily for columns.

Let me demonstrate using an example.
Lets say the array was

[ 
1 1 1
0 1 1
1 0 1
]

Now, R = 1 as everything in row 1 = 1. C = 0, as second element in first column is 0.
Now, using first row and first column to store value about their respective columns and rows ( For the first row, column i stores if all the value in column i are 1. For the first column, row i stores if all the values in row i are 1. We leave 0,0 unassigned )

[
X 0 1
0 . .
0 . .
] 

is what you get.

Now, for any entry which is not in first row or first column, entry (r,c) is 1, if its corresponding column entry in first row is 1 and corresponding row entry in first column is 1.

[
0 0 1
0 0 0 
0 0 0 
]


*/
void Solution::setZeroes(vector<vector<int>> &A)
{
    // finalising the first column
    for (int i = 0; i < A.size(); ++i)
    {
        bool ans = A[i][0];

        if (!ans)
            continue;

        for (int j = 1; j < A[i].size(); ++j)
            ans &= A[i][j];

        A[i][0] = ans;
    }

    // finalising the first row:
    for (int j = 0; j < A[0].size(); ++j)
    {
        bool ans = A[0][j];
        if (!ans)
            continue;

        for (int i = 1; i < A.size(); ++i)
            ans &= A[i][j];

        A[0][j] = ans;
    }

    // (r, c) == 1 iff the A[r][0] & A[0][c] == 1

    for (int i = A.size() - 1; i >= 0; --i)
    {
        for (int j = A[0].size() - 1; j >= 0; --j)
            A[i][j] = A[i][0] & A[0][j];
    }
}

