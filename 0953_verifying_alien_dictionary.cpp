#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    bool strcmp(string& a, string& b, unordered_map<char, int>& mp){
        int m = a.size(), n = b.size();
        int k = min(m, n);
        int i = 0;
        while (i < k && a[i] == b[i])
            i++;
        if (i == k)
            return m > n;
        
        return mp[a[i]] > mp[b[i]];
    }

    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> mp;
        for (int i = 0; i < order.size(); i++)
            mp[order[i]] = i;
        for (int i = 1; i < words.size(); i++){
            if (strcmp(words[i-1], words[i], mp))
                return false;
        }

        return true;
    }
};



int main(){
    vector<string> words{"apple", "app"};
    //vector<string> words{"hello", "leetcode"};
    string order = "abcdefghijklmnopqrstuvwxyz";
    Solution s;
    cout << s.isAlienSorted(words, order) << endl;

    return 0;
}
