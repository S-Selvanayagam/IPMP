// GFG
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
        int x; unsigned int c=1;
        while(n)
        {
            if(n&1 != 0) return c;
            c++;
            n = n>>1;
        }
        // Your code here
        return 0;
    }
};


int main()
{
    int t;
    cin>>t; // testcases
    while(t--)
    {
        int n;
        cin>>n; //input n
        Solution ob;
        printf("%u\n", ob.getFirstSetBit(n)); // function to get answer
    }
	return 0;
}

