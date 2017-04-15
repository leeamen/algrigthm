#include<iostream>
#include<cmath>

using namespace std;

#if 0
#define NUMBER 7
int adj_matrix[][NUMBER] =
{
    {0,1,0,0,0,1,1},
    {1,0,0,0,0,1,0},
    {0,0,0,1,1,0,0},
    {0,0,1,0,1,0,1},
    {0,0,1,1,0,1,0},
    {1,1,0,0,1,0,0},
    {1,0,0,1,0,0,0}
};

int main()
{
    int i,j;

    for(i = 0; i < NUMBER; i++)
    {
        for(j = 0; j < NUMBER; j++)
        {
            cout<<adj_matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
#endif
#define N 3
class Index
{
public:
    Index(int a, int b)
    {
        x = a;
        y = b;
    }
    int x;
    int y;
};
Index GetIndexOF(int a, int target[][N]);
int Manhattan(int a[][N], int b[][N])
{
    int i,j,k;
    int man = 0;

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            k = a[i][j];
            if(k == 0)continue;

            Index a = GetIndexOF(k, b);
            man += abs(a.x - i);
            man += abs(a.y - j);
        }
    }
    return man;
}
Index GetIndexOF(int a, int target[][N])
{
    int i,j;
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            if(target[i][j] == a)
            {
                return Index(i, j);
            }
        }
    }
}
int main()
{
    int i,j;
    int target[][N] = {{1,2,3},{8,0,4},{7,6,5}};
    //int a [N][N] = {{2,3,0},{1,8,5},{7,4,6}};
    int a[N][N];
    while(1)
    {
        for(i = 0; i < N; i++)
        {
            for(j = 0; j < N; j++)
            {
                cin>>a[i][j];
            }
        }
        cout<<"manhattan:"<<Manhattan(a, target)<<endl;
    }

    return 0;
}
