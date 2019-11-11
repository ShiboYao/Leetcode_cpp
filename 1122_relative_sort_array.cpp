#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> mp;
        for (int& i : arr2)
            mp[i] = 0;
        for (int& i : arr1){
            if (mp.find(i) != mp.end())
                mp[i]++;
        }
        int i = 0, m = arr2.size(), n = arr1.size();
        vector<int> r(n);
        for (int k = 0; k < m; k++){
            while (mp[arr2[k]] > 0){
                r[i++] = arr2[k];
                mp[arr2[k]]--;
            }
        }
        int j = i;
        for (int k = 0; k < n; k++){
            if (mp.find(arr1[k]) == mp.end())
                r[i++] = arr1[k];
        }
        sort(r.begin()+j,r.end());
        
        return r;
    }
};



int main(){
    //vector<int> a{2,3,1,3,2,4,6,7,9,2,19}, b{2,1,4,3,9,6};
    vector<int> a{28,6,22,8,44,17}, b{22,28,8,6};
    Solution s;
    vector<int> c = s.relativeSortArray(a,b);
    for (int i : c)
        cout << i << " ";
    cout << endl;

    return 0;
}
