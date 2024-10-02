//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:
    int capacity;
    std::unordered_map<int, std::list<pair<int, int>>::iterator> cache;
    std::list<pair<int, int>> list;

    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) : capacity(cap) {}

    int GET(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) {
            return -1; // Key not found
        }

        // Move the key-value pair to the front of the list to mark it as recently used
        list.splice(list.begin(), list, it->second);

        return it->second->second; // Return the value
    }

    void SET(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            // Key already exists, update the value and move to the front
            it->second->second = value;
            list.splice(list.begin(), list, it->second);
            return;
        }

        // Key doesn't exist, add it to the front of the list and cache
        list.push_front({key, value});
        cache[key] = list.begin();

        // If the cache is full, remove the least recently used item
        if (list.size() > capacity) {
            auto last = list.back();
            list.pop_back();
            cache.erase(last.first);
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends