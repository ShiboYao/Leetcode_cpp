#include <iostream>
#include <unordered_map>
using namespace std;


class Solution {
private:
    unordered_map<char,int> mp;
public:
    int romanToInt(string s) {
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        int i = 0, num = 0, end = s.size()-1;
        while (i < end){
            if (s[i] == 'I' && (s[i+1] == 'V' || s[i+1] == 'X'))
                num += mp[s[i+1]] - mp[s[i++]];
            else if (s[i] == 'X' && (s[i+1] == 'L' || s[i+1] == 'C'))
                num += mp[s[i+1]] - mp[s[i++]];
            else if (s[i] == 'C' && (s[i+1] == 'D' || s[i+1] == 'M'))
                num += mp[s[i+1]] - mp[s[i++]];
            else
                num += mp[s[i]];
            i++;
        }
        if (i == end)
            num += mp[s[i]];

        return num;
    }
};



int main(int argc, char** argv){
    if (argc < 2){
        cout << "specify string" << endl;
        exit(1);
    }
    Solution s;
    string str = argv[1];
    cout << s.romanToInt(str) << endl;

    return 0;
}
