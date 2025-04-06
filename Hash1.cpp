#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

class HashTable {
    int BUCKET;  
    vector<list<pair<int, string>>> table; 

public:
    HashTable(int size); 
    int hashFunction(int x) {
        return (x % BUCKET);
    }
    void add(int key, const string &value);
    string find(int key);
    void display();
};
HashTable::HashTable(int size) {
    this->BUCKET = size;
    table.resize(BUCKET);
}
void HashTable::add(int key, const string &value) {
    int index = hashFunction(key);
    table[index].push_back({key, value});
}
string HashTable::find(int key) {
    int index = hashFunction(key);
    for (auto &x : table[index]) {
        if (x.first == key)
            return x.second;
    }
    return "-";
}
void HashTable::display() {
    for (int i = 0; i < BUCKET; i++) {
        if (table[i].empty()) {
            cout << "(-1,-) ";
        } else {
            for (auto &x : table[i]) {
                cout << "(" << x.first << "," << x.second << ") ";
            }
        }
        cout << endl;
    }
}
int main() {
    HashTable h(17);
    char command;
    int key;
    string value;

    while (true) {
        cin >> command;
        if (command == 'e') {
            break;
        } else if (command == 'a') {
            cin >> key >> value;
            h.add(key, value);
        } else if (command == 'p') {
            h.display();
        } else if (command == 's') {
            cin >> key;
            cout << h.find(key) << endl;
        }
    }
    return 0;
}
