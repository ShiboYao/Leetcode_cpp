#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
   int findkth(vector<int>::iterator a, int n1, vector<int>::iterator b, int n2, int k){
        if (n1 > n2)
            return findkth(b, n2, a, n1, k);
        if (n1 == 0)
            return *(b+k-1);
        if (k == 1)
            return min(*a, *b);

        int i = min(k/2, n1), j = k-i;
        if (a[i-1] < b[j-1])
            return findkth(a+i, n1-i, b, n2, k-i);
        else if (a[i-1] > b[j-1])
            return findkth(a, n1, b+j, n2-j, k-j);
        else
            return a[i-1];
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int total = n1+n2;
        vector<int>::iterator a = nums1.begin();
        vector<int>::iterator b = nums2.begin();
        
        if (total%2 != 0)
            return findkth(a, n1, b, n2, total/2+1);
        else
            return (findkth(a, n1, b, n2, total/2) + findkth(a, n1, b, n2, total/2+1))/2.0;
    }
};



int main(){
    vector<int> a{1,2};
    vector<int> b{3,4};
    Solution s;
    double r = s.findMedianSortedArrays(a, b);
    cout << r << endl;

    return 0;
}
