#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<list>
#include<utility>

using namespace std;

#define LEET_42_LIB 0

class Solution
{
public:
    int trap(vector<int>& height)
    {
        int l = 0, r = height.size()-1, level = 0, water = 0;
        while (l < r)
        {
            int lower = height[height[l] < height[r] ? l++ : r--];
            level = max(level, lower);
            water += level - lower;
            cout<<"lower:"<<lower<<",level:"<<level<<",water:"<<water<<endl;
        }
        return water;
    }
};

class Solution3
{
public:
    int trap(vector<int>& height)
    {
        int i, water = 0;
        int n = height.size();

        if(n <= 2)
        {
            return 0;
        }
        //找到最高的位置
        int max_height = 0;
        int max_idx = 0;
        for(i = 0; i < n; i++)
        {
            if(height[i] > max_height)
            {
                max_height = height[i];
                max_idx = i;
            }
        }

        //两侧向中间靠拢逐渐计算水量
        int local_max_height = height[0];
        for(i = 0; i < max_idx; i++)
        {
            if(local_max_height < height[i])
            {
                local_max_height = height[i];
            }
            else
            {
                water += local_max_height - height[i];
            }
        }
        local_max_height = height[n-1];
        for(i = n - 1; i > max_idx; i--)
        {
            if(local_max_height < height[i])
            {
                local_max_height = height[i];
            }
            else
            {
                water += local_max_height - height[i];
            }
        }

        return water;
    }
};
#if LEET_42_LIB != 1
int main()
{
    int n[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> height(n, n + sizeof(n)/sizeof(int));
    Solution3 s;
    auto water = s.trap(height);
    cout<<water<<endl;

    return 0;
}
#endif
