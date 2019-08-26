#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int partition(vector<int>& key, vector<int>& freq, int low, int high){
        int i = low, j = low;
        while (j < high){
            if (freq[j] >= freq[high]){
                swap(freq[i], freq[j]);
                swap(key[i++], key[j]);
            }
            j++;
        }
        swap(freq[i], freq[high]);
        swap(key[i], key[high]);
        
        return i;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int& n : nums)
            mp[n]++;
        vector<int> key;
        vector<int> freq;
        for (auto m : mp){
            key.push_back(m.first);
            freq.push_back(m.second);
        }        
        int low = 0, high = freq.size()-1;
        k--;
        while (1){
            int p = partition(key, freq, low, high);
            if (p == k)
                break;
            else if (p > k)
                high = p-1;
            else
                low = p+1;
        }
        vector<int> r;
        while (k>=0)
            r.push_back(key[k--]);

        return r;
    }
};



int main(){
    vector<int> a{1,1,1,2,2,3};
    int k = 2;
    Solution s;
    vector<int> r = s.topKFrequent(a, k);
    for (int& i : r)
        cout << i << " ";
    cout << endl;

    return 0;
}
