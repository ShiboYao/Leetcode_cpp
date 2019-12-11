#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> mp;
        unordered_set<string> st;
        int i = 0, j = 0, k = 0, m = pattern.size(), n = str.size();
        while (i < m && j < n){
            while (j < n && str[j] != ' ') j++;
            string s = str.substr(k, j-k);
            if (mp.find(pattern[i]) == mp.end()){
                if (st.find(s) != st.end())
                    return false;
                else{
                    mp[pattern[i]] = s;
                    st.insert(s);
                }
            }
            else if (mp[pattern[i]] != s)
                return false;
            k = ++j;
            i++;
        }

        return (i >= m && j >= n);
    }
};



int main(int argc, char** argv){
    if (argc < 3){
        cout << "specify s1 and s2" << endl;
        exit(1);
    }
    string s1 = argv[1], s2 = argv[2];
    Solution s;
    cout << s.wordPattern(s1, s2) << endl;

    return 0;
}
