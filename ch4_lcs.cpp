#include<iostream>
#include<string>
#include<cstring>

using namespace std;

#define CH4_LCS_LIB 1

#define N 1000
//dp[i][j] 是Xi和Yj LCS长度
static int dp[N][N];
typedef enum
{
    UP = 1,
    LEFT,
    UPLEFT
} Direction;
Direction flag[N][N];


/*
动态规划算法
最长公共串
dp[i][j]:Xi位置和Yj位置的LCS长度
1.dp[i][j] = 0, i = 0 或 j = 0
2.dp[i][j] = dp[i - 1][j - 1] + 1, Xi = Yj
3.dp[i][j] = max{c[i-1][j], c[i][j - 1]}

时间复杂度O(mn)
*/
void DPLCS(string x, string y)
{
    int i, j;

    memset(dp, 0x00, sizeof(dp));
    memset(flag, 0x00, sizeof(flag));
    int m = x.length();
    int n = y.length();

    for(i = 1; i <= m; i++)
    {
        for(j = 1; j <= n; j++)
        {
            //2.dp[i][j] = dp[i - 1][j - 1] + 1, Xi = Yj
            if(x[i - 1] == y[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                //设置标志
                flag[i][j] = UPLEFT;
            }
            //3.dp[i][j] = max{c[i-1][j], c[i][j - 1]}
            else if(dp[i - 1][j] >= dp[i][j - 1])
            {
                dp[i][j] = dp[i - 1][j];
                flag[i][j] = UP;
            }
            else
            {
                dp[i][j] = dp[i][j - 1];
                flag[i][j] = LEFT;
            }
        }
    }
}
//打印出来最长公共字符串
void PrintDPLCS(string &x, int i, int j)
{
    if(i == 0 || j == 0)
    {
        return;
    }

    if(flag[i][j] == UPLEFT)
    {
        PrintDPLCS(x, i - 1, j - 1);
        cout<<x[i-1];
    }
    else if(flag[i][j] == LEFT)
    {
        PrintDPLCS(x, i, j - 1);
    }
    else
    {
        PrintDPLCS(x, i - 1, j);
    }
}

void PrintArray(int width, int height)
{
    int i, j;
    for(i = 0; i <= width; i++)
    {
        for(j = 0; j <= height; j++)
        {
            cout<<" "<<flag[i][j];
        }
        cout<<endl;
    }
}


/*
普通分治算法
时间复杂度2的min(m,n)指数
*/
string NaiveLCS(string x, string y)
{
    int m = x.length();
    int n = y.length();

    //cout<<"m:"<<m<<",n:"<<n<<endl;
    if(m == 0 || n == 0)
    {
        return string("");
    }

    //最后一个字符相同
    if(x[m - 1] == y[n - 1])
    {
        return NaiveLCS(x.substr(0, m - 1), y.substr(0, n - 1)) + x[m - 1];
    }
    //否则，结尾不同
    else
    {
        string z1 = NaiveLCS(x.substr(0, m - 1), y);
        string z2 = NaiveLCS(x, y.substr(0, n - 1));

        return z1.length() > z2.length()?z1:z2;
    }
}


#if CH4_LCS_LIB < 1
int main()
{
    string x,y;
    cin>>x>>y;
    //普通的分治算法
    cout<<"x:"<<x<<endl<<"y:"<<y<<endl;
    cout<<"naive fenzhi lcs method:"<<NaiveLCS(x, y)<<endl;

    //动态规划算法
    DPLCS(x, y);
    PrintArray(x.length(), y.length());

    cout<<"dp LCS:";
    PrintDPLCS(x, x.length(), y.length());
    cout<<endl;
    return 0;
}
#endif
