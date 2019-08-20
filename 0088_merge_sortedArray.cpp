#include <iostream>
#include <vector>
using namespace std;

/*
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (!n)
            return;
        if (!m){
            for (int i = 0; i < n; i++)
                nums1[i] = nums2[i];
            return;
        }
        int i = 0, j = 0, k = j;
        while (i < m && j < n){ 
            while (i < m && nums1[i] <= nums2[j])
                i++;
            while (j < n && nums2[j] < nums1[i])
                j++;
            nums1.insert(nums1.begin()+i, nums2.begin()+k, nums2.begin()+j);
            i = i + j - k;
            m = m + j - k;
            k = j;
        }
        if (j < n){
            for (int i = 0; i < n-j; i++)
                nums1[m+i] = nums2[j+i];
        }
        nums1.resize(m+n-j);
    }   
};
*/


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (!n)
            return;
        if (!m){
            for (int i = 0; i < n; i++)
                nums1[i] = nums2[i];
            return;
        }
        int p = m + n - 1, i = m - 1, j = n - 1;
        while (i>=0 && j>=0){
            while (i >= 0 && nums1[i] >= nums2[j])
                nums1[p--] = nums1[i--];
            while (j >= 0 && i >= 0 && nums1[i] < nums2[j])
                nums1[p--] = nums2[j--];
        }
        while (j >= 0)
            nums1[p--] = nums2[j--];
    }
};



int main(){
    vector<int> a{2,0};
    vector<int> b{1};
    int m = 1, n = 1;
    Solution s;
    s.merge(a, m, b, n);
    for (int& i : a)
        cout << i << " ";
    cout << endl;

    return 0;
}
