#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> r;
        if (s.empty())
            return r;
        unordered_map<char, int> mp;
        for (auto a : p)
            mp[a]++;
        int i = 0, j = 0, count = p.size();
        while (i < s.size()){
            if (mp[s[i]] > 0){
                mp[s[i]]--;
                count--;
                i++;
            }
            else {
                mp[s[j]]++;
                j++;
                count++;
            }
            while (count == 0){
                r.push_back(j);
                mp[s[j]]++;
                j++;
                count++;
            }
        }

        return r;
    }
};



int main(int argc, char** argv){
    if (argc < 3){
        cout << "Specify string andb pattern" << endl;
        exit(1);
    }
    string s = argv[1];
    string p = argv[2];
    Solution so;
    vector<int> r = so.findAnagrams(s, p);
    for (int& i : r)
        cout << i << " ";
    cout << endl;

    return 0;
}
