#include<iostream>
using namespace std;
int reversebits(int num)
{
    unsigned int rev =0;
    for(int i=0; i<32;i++)
    {
        rev = (rev << 1) | (num & 1);
        num >>= 1;
    }
    return rev;
}
int main()
{
    int n; cin>>n; 
    int ans = reversebits(n);
    cout<<ans;
    return 0;
}
/* 
    011010
    
*/