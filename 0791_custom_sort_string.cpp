#include <iostream>
#include <unordered_map>
using namespace std;


class Solution {
public:
    string customSortString(string S, string T) {
        unordered_map<char, int> mp;
        for (int i = 0; i < T.size(); i++)
            mp[T[i]]++;
        string r = "";
        for (char c : S){
            while (mp[c]){
                r += c;
                mp[c]--;
            }
            mp.erase(c);
        }
        for (auto& i : mp){
            while (i.second > 0){
                r += i.first;
                i.second--;
            }
        }

        return r;
    }
};



int main(int argc, char** argv){
    if (argc < 3){
        cout << "specify str" << endl;
        exit(1);
    }
    string str1 = argv[1];
    string str2 = argv[2];
    Solution s;
    cout << s.customSortString(str1, str2) << endl;

    return 0;
}
