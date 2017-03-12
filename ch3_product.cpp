#include<cstdio>
#include<cstdlib>
#include<random>
#include<iostream>

using namespace std;

#define HIGH_OF(a, n) (((a) & (0XFFFFFFFF << (n))) >> (n))
#define LOW_OF(a, n) ((a) & (0XFFFFFFFF >> ((sizeof(a) * 8) - (n))))

#define SIGN_OF_PRODUCT(a, b) (((0x80000000 & (a)) ^ (0x80000000 & (b))) >> 31)
#define RIGHTMOVE(x, n) ((x) >> (n))
#define LEFTMOVE(x, n) ((x) << (n))
#define SIZE(n) (sizeof(n) * 8)
#define NEGATIVE(x) (~(x) + 1)
#define POSITIVE 0

inline int ABS(int x)
{
    if(x < 0)
    {
        return ~x + 1;
    }

    return x;
}
int IntProduct(int x, int y, int n);

int main(int argc, char **argv)
{
    //cout<<LEFTMOVE(0+0+16, 8/2)<<endl;
    //cout<<ABS(2)<<endl;
    //cout<<SIGN_OF_PRODUCT(1, 2)<<endl;
    cout<<IntProduct(2000, 350, 32)<<endl;
    //cout<<HIGH_OF(15, 2)<<","<<LOW_OF(15, 2)<<endl;
    return 0;
}

int IntProduct(int x, int y, int n)
{
    int a, b ,c, d;
    int x1, x3, x2;

    int sign = SIGN_OF_PRODUCT(x, y);
    x = ABS(x);
    y = ABS(y);

    if(n <= 1)
    {
        if(x == 1 && y == 1)
        {
            if(sign == POSITIVE)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }

        return 0;
    }

    a = HIGH_OF(x, n/2);
    b = LOW_OF(x, n/2);
    c = HIGH_OF(y, n/2);
    d = LOW_OF(y, n/2);

    x1 = IntProduct(a, c, n/2);
    x2 = IntProduct(b, d, n/2);
    x3 = IntProduct(b - a, c - d, n/2);

    int sum = LEFTMOVE(x1, n) + x2 + LEFTMOVE((x1 + x2 + x3), n/2);

//    printf("sign=%d,n=%d,a=%d,b=%d,c=%d,d=%d,(ac=%d,x1=%d),(bd=%d,x2=%d),"
//           "(x3=%d,b-a/c-d=%d),(LEFTMOVE(x1, n)=%d,LEFTMOVE(x3 + x1 + x2, n/2)=%d,sum=%d)\n",
//           sign, n, a, b, c, d, a*c,x1, b*d, x2,x3,(b-a)*(c-d), LEFTMOVE(x1, n),
//           LEFTMOVE(x3 + x1 + x2, n/2), sum);
    //是否是负数

    return (sign == 0)?sum:NEGATIVE(sum);
}


