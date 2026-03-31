class MyHashMap {
public:
    vector<list<pair<int,int>>> b;

    MyHashMap() {
        b.resize(1000);
    }

    int h(int key) {
        return key % 1000;
    }

    void put(int key, int value) {
        int i = h(key);
        for (auto &p : b[i])
            if (p.first == key) {
                p.second = value;
                return;
            }
        b[i].push_back({key, value});
    }

    int get(int key) {
        int i = h(key);
        for (auto &p : b[i])
            if (p.first == key)
                return p.second;
        return -1;
    }

    void remove(int key) {
        int i = h(key);
        for (auto it = b[i].begin(); it != b[i].end(); it++)
            if (it->first == key) {
                b[i].erase(it);
                return;
            }
    }
};
/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */