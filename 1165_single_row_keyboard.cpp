#include <iostream>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int calculateTime(string keyboard, string word) {
        unordered_map<char,int> mp;
        for (int i = 0; i < 26; i++)
            mp[keyboard[i]] = i;
        int sum = mp[word[0]], n = word.size();
        for (int i = 1; i < n; i++)
            sum += abs(mp[word[i]]-mp[word[i-1]]);

        return sum;
    }
};



int main(int argc, char** argv){
    if (argc < 3){
        cout << "specify key and word" << endl;
        exit(1);
    }
    string key = argv[1], word = argv[2];
    Solution s;
    cout << s.calculateTime(key, word) << endl;

    return 0;
}
