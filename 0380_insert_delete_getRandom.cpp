#include <iostream>
#include <unordered_set>
#include <ctime>
using namespace std;


class RandomizedSet {
    unordered_set<int> mp;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (mp.find(val) == mp.end()){
            mp.insert(val);
            return true;
        }
        return false;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (mp.find(val) != mp.end()){
            mp.erase(val);
            return true;
        }
        return false;
    }

    /** Get a random element from the set. */
    int getRandom() {
        srand(time(NULL)); //on leetcode need to remove this line
        int r = rand() % mp.size();
        for (auto i : mp){
            if (r-- == 0)
                return i;
        }
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */



int main(){
    RandomizedSet* obj = new RandomizedSet();
    cout << obj->insert(1) << endl;
    cout << obj->insert(10) << endl;
    cout << obj->insert(20) << endl;
    cout << obj->getRandom() << endl;

    return 0;
}
