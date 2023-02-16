#include<iostream>
using namespace std;
void iskset(int n, int k)
{
    int x = (1<<(k-1));        // left shift 1 (k-1) times
    if ((n&x) != 0 ){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
}

int main()
{
    int n, k;
    cin>>n;
    cin>>k;
    iskset(n,k);
    return 0;
}

// another implementation would be to bring x right shift for k-1 bits
