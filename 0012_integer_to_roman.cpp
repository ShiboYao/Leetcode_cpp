#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution {
private:
    unordered_map<int, string> mp;

public:
    string intToRoman(int num) {
        mp[1] = "I";
        mp[4] = "VI";
        mp[5] = "V";
        mp[9] = "XI";
        mp[10] = "X";
        mp[40] = "LX";
        mp[50] = "L";
        mp[90] = "CX";
        mp[100] = "C";
        mp[400] = "DC";
        mp[500] = "D";
        mp[900] = "MC";
        mp[1000] = "M";
        int digit = 1;
        string r = "";
        while (num){
            int t = num%10;
            num /= 10;
            string c = mp[digit];
            while (t != 0 && t != 1 && t != 4 && t != 5 && t != 9){
                r += c;
                t--;
            }
            if (t != 0)
                r += mp[t*digit];
            digit *= 10;
        }
        reverse(r.begin(), r.end());

        return r;
    }
};



int main(int argc, char** argv){
    if (argc < 2){
        cout << "specify str" << endl;
        exit(1);
    }
    string str = argv[1];
    int n = stoi(str);
    Solution s;
    cout << s.intToRoman(n) << endl;

    return 0;
}
