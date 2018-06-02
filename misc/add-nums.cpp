#include<bits/stdc++.h>
using namespace std;

int main()
{
	cout << "Enter two numbers\n";
	int a, b;
	cin >> a >> b;

	// printf returns the number of characters successfully printed to STDOUT.
	// scanf returns the number of items successfully read and assigned.

	//printf("%*c", width, string) ===> format for printing string, width number of times.
	// in the above line string cannot be empty, so force the parent printf stmt to print out in the next line
	printf("\n%d\n", printf("%*c%*c", a, ' ', b, ' '));
	return 0;
}