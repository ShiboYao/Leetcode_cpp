#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> a(26,-1);
        int n = s.size();
        for (int i = 0; i < s.size(); i++){
            int* k = &a[s[i]-'a'];
            if (*k >= 0)
                *k = -2; 
            else if (*k == -1) 
                *k = i;
        }   
        int l = n+1;
        for (int i : a){ 
            if (i >= 0)
                l = min(l,i);
        }   

        return l==(n+1)?-1:l;
    }   
};



int main(int argc, char** argv){
    if (argc < 2){
        cout << "Specify string" << endl;
        exit(1);
    }
    string str = argv[1];
    Solution s;
    cout << s.firstUniqChar(str) << endl;

    return 0;
}
