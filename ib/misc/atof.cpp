// program to test the functionality of atof() function
// atof(): https://www.ibm.com/support/knowledgecenter/en/ssw_ibm_i_71/rtref/itof.htm
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a = "14.294";
    // string.c_str() will convert the string to the type const char*
    const char *p = a.c_str();
    float x = atof(p);

    

    cout << x + 1 << endl;

    return 0;
}