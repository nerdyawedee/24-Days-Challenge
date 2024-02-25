class LRUCache {
public:
    map<int, int> tk;
    unordered_map<int, int> kv, kt;
    int sz, time = 0;
    LRUCache(int capacity) { sz = capacity; }

    int get(int key) {
        if (kv.find(key) == kv.end())
            return -1;
        tk.erase(kt[key]);
        tk[++time] = key;
        kt[key] = time;
        return kv[key];
    }

    void put(int key, int value) {
        if (kv.find(key) != kv.end()) {
            kv[key] = value;
            tk.erase(kt[key]);
            kt[key] = ++time;
            tk[time] = key;
        } else if (sz == 0) {
            auto it = tk.begin();
            kv.erase(it->second);
            kt.erase(it->second);
            tk.erase(it->first);
            kv[key] = value;
            tk[++time] = key;
            kt[key] = time;
        } else {
            kv[key] = value;
            tk[++time] = key;
            kt[key] = time;
            sz--;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
