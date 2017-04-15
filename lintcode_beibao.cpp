#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
#define N 500

class Solution
{
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A & V: Given n items with size A[i] and value V[i]
     * @return: The maximum value
     */
    int dp[N][N];

    void BeibaoDP(int m, vector<int> A, vector<int> V)
    {
        int i,j;
        int n = A.size();

        for(j = 0; j < min(A[n - 1], m); j++)
        {
            dp[n][j] = 0;
        }
        for(j = A[n - 1]; j <= m; j++)
        {
            dp[n][j] = V[n - 1];
        }

        for(i = n - 1; i >= 1; i--)
        {
            for(j = 0; j < min(m, A[i - 1]); j++)
            {
                dp[i][j] = dp[i + 1][j];
            }
            for(j = A[i - 1]; j <= m; j++)
            {
                dp[i][j] = max(dp[i+1][j], dp[i + 1][j - A[i - 1]] + V[i - 1]);
            }
        }
    }

    int backPackII(int m, vector<int> A, vector<int> V)
    {
        // write your code here
        memset(dp, 0x00, sizeof(dp));
        BeibaoDP(m, A, V);
        return dp[1][m];
    }
};


int main()
{
    Solution s;
    int m = 5;
    int a[] = {1,2,3,1,1};
    int v[] = {1,4,2,4,6};
    int n = 5;
    vector<int>A(a, a + n);
    vector<int>V(v, v + n);
    cout<<s.backPackII(m, A, V)<<endl;
    return 0;
}
