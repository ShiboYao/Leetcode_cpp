#include <iostream>
#include <unordered_map>
using namespace std;


class Solution {
public:
    bool confusingNumber(int N) {
        unordered_map<char,char> mp;
        mp['0'] = '0';
        mp['1'] = '1';
        mp['6'] = '9';
        mp['8'] = '8';
        mp['9'] = '6';
        string s = to_string(N);
        int i = 0, j = s.size()-1;
        bool change = false;
        while (i <= j){
            if (mp.find(s[i]) == mp.end() || mp.find(s[j]) == mp.end())
                return false;
            if (mp[s[i]] != s[j])
                change = true;
            i++;
            j--;
        }

        return change;
    }
};



int main(int argc, char** argv){
    if (argc < 2){
        cout << "specify str" << endl;
        exit(1);
    }
    int N = stoi(argv[1]);
    Solution s;
    cout << s.confusingNumber(N) << endl;

    return 0;
}
