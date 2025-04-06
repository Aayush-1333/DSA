/**
 * This is a simple implementation of a hash table using vector, list and strings.
 * They are one of the fastest data structures that can be used to quickly access any item stored in a large
 * data struture in constant time.
 * 
 * It uses arrays and linked lists which is best of both worlds:
 *    - Arrays (for access)
 *    - Linked List (for insertion and deletion)
 * 
 * In worst-case scenarios, it may go O(n) in all operations.
 */
#include <iostream>
#include <string.h>
#include <vector>
#include <list>
using namespace std;


class HashTable {
    private:
    vector<list<pair<int, string>>> table;
    int size;

    int hash_function(int key) {
        return key % size;
    }

    public:
    HashTable(int size) {
        table.resize(size);
        this -> size = size;
    }

    void insert(int key, string value) {
        int index = hash_function(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it -> first == key)
                it -> second = value;
                return;
        }
        table[index].emplace_back(key, value);
    }

    string get(int key) {
        int index = hash_function(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it -> first == key)
                return it -> second;
        }
        return "Not found";
    }

    void remove(int key) {
        int index = hash_function(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it -> first == key) {
                table[index].erase(it);
                return;
            }
        }
    }
};


int main() {
    HashTable map = HashTable(10);
    map.insert(2, "Charlie");
    map.insert(1, "Aman");
    cout << "Value at 2: " << map.get(2) << endl;
    cout << "Value at 1: " << map.get(1) << endl;

    map.insert(1, "Shavi");
    cout << "Value at 1: " << map.get(1) << endl;
    
    map.remove(1);
    cout << "Value at 1: " << map.get(1) << endl;
}
