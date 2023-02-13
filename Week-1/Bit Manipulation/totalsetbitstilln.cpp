// GFG -> O(logn) implementation
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    unsigned int getLeftmostBit(int n)
    {
        int m = 0;
        while (n > 1) {
            n = n >> 1;
            m++;
        }
        return m;
    }
    
    unsigned int getNextLeftmostBit(int n, int m)
    {
        unsigned int temp = 1 << m;
        while (n < temp) {
            temp = temp >> 1;
            m--;
        }
        return m;
    }
    
    signed int _countSetBits(unsigned int n, int m)
    {
        if (n == 0)
            return 0;
        m = getNextLeftmostBit(n, m);
        if (n == (1 << (m + 1)) - 1)
            return (m + 1) * (1 << m);
        n = n - (1 << m);
        return (n + 1) + countSetBits(n) + m * (1 << (m - 1));
    }
    
    unsigned int countSetBits(unsigned int n)
    {
         int m = getLeftmostBit(n);
         return _countSetBits(n, m);
    }
    
};

int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}

