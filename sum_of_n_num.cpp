#include <bits/stdc++.h>
using  namespace  std;
#define SUM_OF_N_NUM_LIB 1


#define mod 1000000007
template<class T> void read(T&num) {
    char CH; bool F=false;
    for(CH=getchar();CH<'0'||CH>'9';F= CH=='-',CH=getchar());
    for(num=0;CH>='0'&&CH<='9';num=num*10+CH-'0',CH=getchar());
    F && (num=-num);
}
const int N=5e4+10;

int  dp[N][351], n;

#if SUM_OF_N_NUM_LIB < 1
int  main(){
  read(n);
  dp[0][0] = 1;
  for(int i = 1; i < 350 ; i++){//i个数
    for(int j = 0; j <= n ; j++){//组成j
      if(j - i >= 0){
        dp[j][i] = (dp[j - i][i] + dp[j - i][i - 1]) % mod;
      }
    }
  }
  int ans = 0;
  for(int i = 1; i < 350; i++)
    ans = (ans + dp[n][i]) % mod;
  printf("%d\n", ans);
  return 0;
}

#endif
