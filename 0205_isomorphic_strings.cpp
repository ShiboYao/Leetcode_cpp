#include <iostream>
#include <unordered_map>
using namespace std;


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m = s.size(), n = t.size();
        if (m != n) return false;
        unordered_map<char, char> mp;
        unordered_map<char, char> mp2;
        for (int i = 0; i < n; i++){
            if (mp.find(s[i]) == mp.end())
                mp[s[i]] = t[i];
            if (mp[s[i]] != t[i])
                return false;
            if (mp2.find(t[i]) == mp2.end())
                mp2[t[i]] = s[i];
            else if (mp2[t[i]] != s[i])
                return false;
        }

        return true;
    }
};



int main(int argc, char** argv){
    if (argc < 3){
        cout << "specify two strs" << endl;
        exit(1);
    }
    Solution so;
    string s = argv[1], t = argv[2];
    cout << so.isIsomorphic(s, t) << endl;

    return 0;
}
