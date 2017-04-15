#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<list>
#include<utility>

using namespace std;

#define LEET_146_LIB 1

class LRUCache
{
private:
    typedef list<int> LRU;
    typedef unordered_map<int, pair<int, list<int>::iterator>> CACHE ;

    int _capacity;
    LRU _lru;
    CACHE _cache;

public:
    LRUCache(int capacity) : _capacity(capacity) {}

    int get(int key)
    {
        CACHE::iterator it;
        it = _cache.find(key);
        if(it == _cache.end())
        {
            return -1;
        }
        //找到
        refresh(it);
        return it->second.first;
    }

    void put(int key, int value)
    {
        CACHE::iterator it;

        //查找是否存在
        it = _cache.find(key);

        //不存在
        if(it == _cache.end())
        {
            //缓存满了,删除一个
            if(_lru.size() >= _capacity)
            {
                _cache.erase(_lru.back());
                _lru.pop_back();
            }
            _lru.push_front(key);
        }
        else
        {
            refresh(it);
        }


        //加入缓存
        _cache[key] = {value, _lru.begin()};
    }


    void refresh(CACHE::iterator it)
    {
        int key = it->first;
        _lru.erase(it->second.second);
        _lru.push_front(key);
        //更新cache中的指针
        it->second.second = _lru.begin();
    }

};

#if LEET_146_LIB != 1
int main()
{
    return 0;
}
#endif
