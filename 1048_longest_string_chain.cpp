#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    bool chain(string& a, string& b){
        int i = 0, m = a.size();
        while (i < m && a[i] == b[i])
            i++;
        while (i < m && a[i] == b[i+1])
            i++;

        return i==m;
    }


    static bool comp(string& a, string& b){
        return a.size() < b.size();
    }


    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        int n = words.size(), i = 0, j = 0;
        vector<int> dp(n, 1);
        while (i < n){
            while (j < i && words[j].size()+1 < words[i].size())
                j++;
            int k = j, maxi = 0;
            while (k < i && words[k].size()+1 == words[i].size()){
                if (chain(words[k],words[i]))
                    maxi = max(maxi, dp[k]);
                k++;
            }
            dp[i++] += maxi;
        }
        int m = 1;
        for (int& p : dp)
            m = max(m, p);
      
        return m;
    }
};



int main(){
    vector<string> a{"ksqvsyq","ks","kss","czvh","zczpzvdhx","zczpzvh","zczpzvhx","zcpzvh","zczvh","gr","grukmj","ksqvsq","gruj","kssq","ksqsq","grukkmj","grukj","zczpzfvdhx","gru"};
    Solution s;
    cout << s.longestStrChain(a) << endl;

    return 0;
}
