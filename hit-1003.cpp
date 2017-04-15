#include <iostream>
#include<queue>

using namespace std;

#define HIT_1003_LIB 1

struct Farmer{
    int price;
    int amount;
    Farmer(int a, int b):price(a),amount(b){}
};

struct cmp{
    bool operator()(Farmer &a, Farmer &b)
    {
        return a.price >= b.price;
    }
};


#if HIT_1003_LIB < 1
int main()
{
    int N, M;
    int price, amount;
    priority_queue<Farmer, vector<Farmer>, cmp> q;

    while(std::cin>>N>>M)
    {
        for(int i = 0; i < M; i++)
        {
            std::cin>>price>>amount;
            q.push(Farmer(price, amount));
        }


        int least_money = 0;

//        std::cout<<"N is:"<<N<<endl;


//        while(!q.empty())
//        {
//            Farmer f = q.top();
//            std::cout<<f.price<<","<<f.amount<<endl;
//            q.pop();
//        }

        while(N > 0 && !q.empty())
        {
            Farmer f = q.top();
            if(N >= f.amount)
            {
                N -= f.amount;
                least_money += f.amount * f.price;
                q.pop();
            }
            else if(N < f.amount)
            {
                least_money += N * f.price;
                q.pop();
                N = 0;
            }
        }

        std::cout<<least_money<<endl;


    }
    return 0;
}

#endif
