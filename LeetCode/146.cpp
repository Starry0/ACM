#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        _cap = capacity;
    }
    
    int get(int key) {
        auto it = _mp.find(key);
        if(it == _mp.end()) return -1;
        int value = it->second->second;
        _list.erase(it->second);
        _list.push_front(make_pair(key, value));
        _mp[key] = _list.begin();
        return value;
    }
    
    void put(int key, int value) {
<<<<<<< HEAD
        auto it = _mp.find(key);
        if(it != _mp.end()) {
        	_list.erase(it->second);
        	_list.push_front(make_pair(key, value));
        	_mp[key] = _list.begin();
        } else {
        	if(_list.size() >= _cap) {
        		int old_key = _list.back().first;
        		_list.pop_back();
        		_mp.erase(old_key);
        	}
        	_list.push_front(make_pair(key, value));
        	_mp[key] = _list.begin();
        }
=======
		auto it = _mp.find(key);
		if(it != _mp.end()) {
			_list.erase(it->second);
		}
		_list.push_front(make_pair(key, value));
		_mp[key] = _list.begin();
		if(_list.size() > _cap) {
		   int key = _list.back().first;
		   _list.pop_back();
		   _mp.erase(key);
		}
>>>>>>> 5eb63f73609acabccc5e780d632a2151158f888d
    }
private:
	int _cap;
	list<pair<int,int> > _list;
	unordered_map<int, list<pair<int,int>>::iterator> _mp;
};


 
void test() {
	LRUCache* cache = new LRUCache(2);
	cache->put(1, 1);
	cache->put(2, 2);
	cout << cache->get(1) << endl;       // 返回  1
	cache->put(3, 3);    // 该操作会使得密钥 2 作废
	cout << cache->get(2) << endl;       // 返回 -1 (未找到)
	cache->put(4, 4);    // 该操作会使得密钥 1 作废
	cout << cache->get(1) << endl;      // 返回 -1 (未找到)
	cout << cache->get(3) << endl;       // 返回  3
	cout << cache->get(4) << endl;       // 返回  4
}
int main() {
	test();

	return 0;
}