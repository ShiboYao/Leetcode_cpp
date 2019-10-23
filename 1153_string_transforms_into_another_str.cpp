#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;


class Solution {
public:
    bool canConvert(string str1, string str2) {
        if (str1 == str2) return true;
        unordered_map<char,char> mp;
        for (int i = 0; i < str1.size(); i++){
            if (mp.find(str1[i]) == mp.end())
                mp[str1[i]] = str2[i];
            if (mp[str1[i]] != str2[i])
                return false;
        }
        set<char> s;
        for (char& c : str2)
            s.insert(c);
        
        return s.size() < 26;
    }
};



int main(int argc, char** argv){
    if (argc < 3){
        cout << "specify str1 and str2" << endl;
        exit(1);
    }
    string str1 = argv[1], str2 = argv[2];
    Solution s;
    cout << s.canConvert(str1, str2) << endl;

    return 0;
}
