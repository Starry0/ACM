#include <bits/stdc++.h>
using namespace std;

class LFUCache {
public:
    LFUCache(int capacity) {
        _cap = capacity;
    }
    
    int get(int key) {
        auto it = _map.find(key);
        if(it == _map.end()) return -1;
        int value = it->second->value;
        update_freq(it->second);
        return value;
    }
    
    void put(int key, int value) {
        auto it = _map.find(key);
        if(it != _map.end()) {
            it->second->value = value;
            update_freq(it->second);
        } else {
            if(_size >= _cap) {
                auto old_list =  _freq_map.begin();
                _map.erase(old_list->begin()->key);
                old_list.pop_front();
            }
        }
    }
private:
    struct LFUNode{
        int key;
        int value;
        int freq;
        LFUNode(int k, int v, int f):key(k),value(v),freq(f){}
    };
    void update_freq(list<LFUNode>::iterator it) {
        int freq = it->freq, key = it->key, value = it->value;
        _freq_map[freq].erase(it);
        _freq_map[freq+1].push_back(LFUNode(key, value, freq));
        _map[key] = _freq_map[freq+1].end();
        _map[key]--;
    }
    int _cap;
    int _size;
    unordered_map<int, list<LFUNode>::iterator> _map;
    map<int, list<LFUNode>> _freq_map;
};


 
void test() {
	LFUCache* cache = new LFUCache(2);
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