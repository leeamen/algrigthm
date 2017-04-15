#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>

#define LEET_1_LIB 1
using namespace std;

class Solution
{
public:
    vector<int> target_vector;
    vector<int> twoSum(vector<int>& nums, int target)
    {
        //两层遍历
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                if(nums[i] + nums[j] == target)
                {
                    target_vector.push_back(i);
                    target_vector.push_back(j);
                    return target_vector;
                }
            }
        }
        return target_vector;
    }


};

class Solution2
{
public:
    vector<int> result_vector;
    unordered_map<int, int> hashmap;
    vector<int> twoSum(vector<int>& nums, int target)
    {
        for(int i = 0; i < nums.size(); i++)
        {
            int rest = target - nums[i];
            //在hashmap中查找剩余的部分
            if(hashmap.find(rest) != hashmap.end())
            {
                result_vector.push_back(hashmap[rest]);
                result_vector.push_back(i);
                break;
            }

            //保存当前的值得索引到hashmap
            hashmap[nums[i]] = i;
        }
        return result_vector;
    }
};


#if LEET_1_LIB != 1
int main()
{
    int n[] = {-1,-2,-3,-4,-5};
    int target = -8;
    vector<int> nums(n, n + 5);
    Solution s ;
    vector<int>result;
    result = s.twoSum(nums, target);
    //cout<<result.size()<<endl;
    for(int i = 0; i < result.size(); i++)
    {
        cout<<result[i]<<endl;
    }
    return 0;
}
#endif
