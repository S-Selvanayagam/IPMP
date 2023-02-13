#include<iostream>
#include<vector>
using namespace std;
int log2(int m)
{
    int res =0;
    while(m)
    {
        m = m>>1;
        res++;
    }
    return res-1;
}

vector<int> swapno(int a, int b)
{
    a^=b;
    b^=a;
    a^=b;
    return {a,b};
}

bool checkpowerof2(int n)
{
    return (n!=0) && ((n & (n-1)) ==0);         // if its a power of 2, doing & on n and n-1 we get 0
}

int xor_sum(int n) {
    switch (n & 3) {
        case 0: return n;
        case 1: return 1;
        case 2: return n + 1;
        case 3: return 0;
    }
}

int main()
{
    cout<<"Enter first num"<<endl;int n; cin>>n;
    cout<<"Enter second num"<<endl;int m; cin >>m;
    vector<int> v = swapno(n,m);
    cout<<"Swapped Order : "<<v[0]<<v[1]<<endl;;
    int a = log2(n);
    cout<<"Log 2 value is "<<a<<endl;
    if(checkpowerof2(n)) cout<<"Yes, it is a power of 2";
    else cout<<"nope not a power of 2";
    return 0;
}