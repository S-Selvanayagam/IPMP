// GFG Water Overflow

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    double waterOverflow(int K, int R, int C) {
        double p[100][100] = {0};
        p[0][0] = K;
        for(int i=1; i<100; i++)
        {
            for(int j=0; j<=i; j++)
            {
                double x = (p[i-1][j] -1)/2;
                if(x>0)
                {
                    p[i][j] +=x;
                    p[i][j+1] +=x;
                }
            }
        }
        if (p[R-1][C-1] >=1) return 1.0;
        return p[R-1][C-1];
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int K,R,C;
        
        cin>>K>>R>>C;

        Solution ob;
        cout << fixed << setprecision(6)<< ob.waterOverflow(K,R,C) << endl;
    }
    return 0;
}
