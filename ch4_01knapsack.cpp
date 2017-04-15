#include<iostream>
using namespace std;

#define CH4_01KNAPSACK_LIB 1

#define N 500
static int dp[N][N];

void Knapsack(int weights[], int values[], int n, int total_weights)
{
  int i, j;
  //1. dp(n, j) = 0, 0 <= j < weights[n]
  for(j = 0; j < min(weights[n-1], total_weights); j++)
  {
    dp[n][j] = 0;
  }

  //2. dp(n, j) = values[n], total_weights >= j >= weights[n]
  for(j = weights[n - 1]; j <= total_weights; j++)
  {
    dp[n][j] = values[n-1];
  }

  //
  for(i = n - 1; i >= 1; i--)
  {
    for(j = 0; j < min(total_weights,weights[i - 1]) ; j++)
    {
      dp[i][j] = dp[i + 1][j];
    }
    for(j = weights[i - 1]; j <= total_weights; j++)
    {
      dp[i][j] = max(dp[i + 1][j], dp[i+1][j-weights[i-1]]+values[i-1]);
    }
  }
}

//构造有化解，打印
void PrintOpimal(int i, int c, int weights[], int n)
{
  if(i > n || c <= 0) return;

  if(dp[i][c] == dp[i+1][c])
  {
    PrintOpimal(i + 1, c, weights, n);
  }
  else
  {
    cout<<i<<",";
    PrintOpimal(i+1, c - weights[i - 1], weights, n);
  }
}

#if CH4_01KNAPSACK_LIB < 1
int main()
{
  /*
  物品的重量和价值
  总重量total_weights
  求如何装背包使得总价值最大
  每一个物品只能选择装入或者不装入
  */
  int weights[] = {1,2,5,4,5};
  int values[] = {2,1,4,3,2};
  int total_weights = 5;
  int n = sizeof(weights)/sizeof(int);
  cout<<"weights:";
  for(int i = 0; i < n; cout<<weights[i++]);
  cout<<endl<<"values:";
  for(int i = 0; i < n; cout<<values[i++]);
  cout<<endl<<"total weights:"<<total_weights<<endl;

  Knapsack(weights, values, n, total_weights);
  cout<<"max values:"<<dp[1][total_weights]<<endl;
  cout<<"optimal:";
  PrintOpimal(1, total_weights, weights, n);
  cout<<endl;
  return 0;
}
#endif


