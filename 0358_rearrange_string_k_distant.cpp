#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


struct comp{
    bool operator() (const pair<char,int>& i, const pair<char,int>& j){
        return (i.second > j.second);
    }
};


class Solution {
public:
    string rearrangeString(string s, int k) {
        if (k == 0)
            return s;
        unordered_map<char, int> mp; 
        for (char& c : s)
            mp[c]++;
        vector<pair<char, int>> order(mp.begin(), mp.end());
        sort(order.begin(), order.end(), comp());
        
        string r = ""; 
        int l = s.size();
        while (!order.empty()){
            int n = order.size();
            if (n < min(k, l))
                return ""; 
            for (int i = 0; i < k; i++){
                char c = order[i].first;
                r += c;
                order[i].second--;
                if (--l == 0)
                    return r;
            }
            stable_sort(order.begin(), order.end(), comp());
            while (order.back().second == 0)
                order.pop_back();
        }

        return r;
    }   
};

int main(int argc, char** argv){
    if (argc < 3){
        cout << "specify string and k" << endl;
        exit(0);
    }
    string str = argv[1];
    int k = argv[2][0] - '0';
    Solution s;
    cout << s.rearrangeString(str, k) << endl;

    return 0;
}
