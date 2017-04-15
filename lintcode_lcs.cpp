#include<iostream>
#include<cstring>
using namespace std;

class Solution
{
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    /*
    动态规划算法
    最长公共串
    dp[i][j]:Xi位置和Yj位置的LCS长度
    1.dp[i][j] = 0, i = 0 或 j = 0
    2.dp[i][j] = dp[i - 1][j - 1] + 1, Xi = Yj
    3.dp[i][j] = max{c[i-1][j], c[i][j - 1]}

    时间复杂度O(mn)
    */
    int dp[100][100];
    void DPLCS(string x, string y)
    {
        int i,j;
        memset(dp, 0x00, sizeof(dp));

        int m = x.length();
        int n = y.length();

        for(i = 1; i <= m; i++)
        {
            for(j = 0; j <= n; j++)
            {
                if(x[i - 1] == y[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else if(dp[i - 1][j] > dp[i][j - 1])
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
    }
    int longestCommonSubsequence(string A, string B)
    {
        // write your code here
        DPLCS(A, B);
        return dp[A.length()][B.length()];
    }

};

int main()
{
    string a("abcd");
    string b("adef");
    cout<<a<<endl<<b<<endl;
    Solution s;
    int lcs_length = s.longestCommonSubsequence(a, b);
    cout<<lcs_length<<endl;
}
