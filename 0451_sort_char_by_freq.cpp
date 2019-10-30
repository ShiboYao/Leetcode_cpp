#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    static bool comp(pair<char,int>& a, pair<char,int>& b){
        return a.second>b.second;
    }


    string frequencySort(string s) {
        vector<int> mp(256);
        for (char& c : s)
            mp[c]++;
        vector<pair<char,int>> m;
        for (int i = 0; i < 256; i++){
            if (mp[i] > 0)
                m.push_back(make_pair(i, mp[i]));
        }
        sort(m.begin(), m.end(), comp);
        string r = "";
        for (auto i : m){
            while (i.second){
                r += i.first;
                i.second--;
            }
        }

        return r;
    }
};



int main(int argc, char** argv){
    if (argc < 2){
        cout << "specify str" << endl;
        exit(1);
    }
    string str = argv[1];
    Solution s;
    cout << s.frequencySort(str) << endl;

    return 0;
}
