// https://www.geeksforgeeks.org/add-two-numbers-without-using-arithmetic-operators/
// FIXME:  The single-line recursive stmt(Line-43) is working fine
// But if all the stmts are written out separately : Lines - 27, 30, 37, 39; Wrong outputs?
// Can't seem to find the reason.
#include<bits/stdc++.h>
using namespace std;

int add(int a, int b);

/*
Iterative version of the add function:

int add(int a, int b)
{
	while(b != 0)
	{
		int carry = a & b;
		a = a ^ b;
		// b = (a & b) << 1;  Don't do this - the value of a has already been modified in the prev line!!
		// Use a separate variable carry to preserve a&b, using old value of a. 
		b = carry << 1;
	}

	return a;
}

*/


int main()
{
	int a, b;

	cin >> a >> b;

	cout << add(a, b) << endl;

	return 0;
}

// Recursive version of add function:
int add(int a, int b)
{
	if(b == 0)
		return a;


	// XOR of two numbers gives their sum, at positions where BOTH their bits are NOT SET.

	// VERY IMP: carry must be calculated before the value of a is modified to a new value.
	// So, carry = a&b; must be written before a = a^b; VERY IMP!! 
	int carry = a & b;
	a = a ^ b;

	// To account for the cases where both the bits are high, a & b is considered.

	// Since carry bits are again added to their LHS-neighbours. 
	// So all bits of carry are left-shifted by 1 bit position
	// In line 25, the XOR(effective-sum) is being stored into a. 
	// So, the effective carry for the next iteration is stored in b
	
	b = carry << 1;

	return add(a, b);



	// all of the above can be compactly written as :
	// return add(a^b, (a&b) << 1);
	// But this might reduce readability
}	
