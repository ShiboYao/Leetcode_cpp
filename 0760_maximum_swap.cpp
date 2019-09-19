#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        vector<int> mp(10);
        for (char& c : s)
            mp[c-'0']++;
        while (mp.back() == 0)
            mp.pop_back();
        int n = s.size();
        int l = n-1, r;
        for (int i = 0; i < n; i++){
            mp[s[i]-'0']--;
            if (s[i] != mp.size()-1+'0' && mp.back() != 0){
                l = i;
                break;
            }
            while (mp.back() == 0)
                mp.pop_back();
        }
        if (l == n-1) return num;
        
        r = n-1;
        while (s[r] != mp.size()-1+'0')
            r--;
        swap(s[l], s[r]);
        
        return stoi(s);
    }
};



int main(int argc, char** argv){
    if (argc < 2){
        cout << "specify num" << endl;
        exit(0);
    }
    string str = argv[1];
    int num = stoi(str);
    Solution s;
    cout << s.maximumSwap(num) << endl;

    return 0;
}
