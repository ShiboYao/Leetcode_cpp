#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int fun(string& s){
        vector<int> mp(26);
        for (char& c : s)
            mp[c-'a']++;
        for (int& i : mp)
            if (i) return i;

        return 0;
    }


    int bs(vector<int>& nums, int low, int high, int t){
        if (t < nums[0]) return 0;
        if (t >= nums.back()) return (int)nums.size();

        int mid;
        while (low < high){
            mid = (low+high)/2;
            if (t == nums[mid]) 
                low = mid+1;
            else if (t < nums[mid]){
                if (t >= nums[mid-1]) return mid;
                else high = mid-1;
            }
            else 
                low = mid+1;
        }

        return high;
    }


    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int n = words.size();
        vector<int> freq(n);
        for (int i = 0; i < n; i++)
            freq[i] = fun(words[i]);
        sort(freq.begin(), freq.end());

        int m = queries.size();
        vector<int> r(m);
        for (int i = 0; i < m; i++){
            int t = fun(queries[i]);
            r[i] = n - bs(freq,0,n-1,t);
        }

        return r;
    }
};



int main(){
    vector<string> queries{"bba","abaaaaaa","aaaaaa","bbabbabaab","aba","aa","baab","bbbbbb","aab","bbabbaabb"};
    vector<string> words{"aaabbb","aab","babbab","babbbb","b","bbbbbbbbab","a","bbbbbbbbbb","baaabbaab","aa"};
    Solution s;
    vector<int> r = s.numSmallerByFrequency(queries, words);
    for (int i : r)
        cout << i << " ";
    cout << endl;

    return 0;
}
