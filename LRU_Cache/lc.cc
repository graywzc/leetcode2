/*
 Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
*/

class LRUCache{
public:

    LRUCache(int capacity)
    :_cap(capacity>0?capacity:0)
    {
    }
    
    int get(int key) {
        if(_m.find(key)!=_m.end())        
        {
            List::iterator it = _m.find(key)->second;
            int val = it->second;
            _l.erase(it);
            _l.push_back(Pair(key,val));
            _m[key] = --_l.end();
            return val;
        }
        else
        {
            return -1; 
        }
    }
    
    void set(int key, int value) {
        if(_m.find(key)!=_m.end())        
        {
            List::iterator it = _m.find(key)->second; 
            _l.erase(it);
            _l.push_back(Pair(key,value));
            _m[key] = --_l.end();
        }
        else
        {
            _l.push_back(Pair(key,value)); 
            _m[key] = --_l.end();
            if(_l.size()>_cap)
            {
                int k = _l.begin()->first; 
                _l.erase(_l.begin());
                _m.erase(k);
            }
        }
    }

private:
    typedef pair<int,int> Pair;
    typedef list<Pair> List;
    typedef unordered_map<int,List::iterator> Map;
    int _cap;
    Map _m;
    List _l;

};
