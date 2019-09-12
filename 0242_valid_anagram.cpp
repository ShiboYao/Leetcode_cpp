#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> a(256, 0);
        for (char i : s)
            a[i-'a']++;
        for (char i : t){
            if (a[i-'a'] == 0)
                return false;
            else
                a[i-'a']--;
        }
        for (int& i : a){
            if (i > 0)
                return false;
        }

        return true;
    }
};



int main(int argc, char** argv){
    if (argc < 3){
        cout << "Specify string s and t" << endl;
        exit(1);
    }
    string s = argv[1];
    string t = argv[2];
    Solution so;
    cout << so.isAnagram(s, t) << endl;

    return 0;
}
