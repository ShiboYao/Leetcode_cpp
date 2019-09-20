#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
using namespace std;


class RandomizedCollection {
    unordered_map<int, unordered_set<int>> mp;
    vector<int> a;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        if (mp.find(val) == mp.end())
            mp[val] = unordered_set<int>{};
        mp[val].insert(a.size());
        a.push_back(val);
        return mp[val].size() == 1;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (mp.find(val) == mp.end())
            return false;
        int i = *(mp[val].begin());//cant use pointer as it's being modified
        mp[val].erase(i);
        a[i] = a.back();
        mp[a.back()].insert(i);//insert first
        mp[a.back()].erase(a.size()-1);//otherwise could erase from empty
        a.pop_back();
        if (mp[val].empty())
            mp.erase(val);
        return true;
    }

    /** Get a random element from the collection. */
    int getRandom() {
        srand(time(NULL));
        return a[rand()%a.size()]; 
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */



int main(){
    RandomizedCollection* obj = new RandomizedCollection();
    obj->insert(1);
    obj->insert(1);
    obj->insert(2);
    cout << obj->getRandom() << endl;
    obj->remove(1);
    cout << obj->getRandom() << endl;

    return 0;
}
