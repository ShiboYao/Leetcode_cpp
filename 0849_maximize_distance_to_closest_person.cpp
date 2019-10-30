#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int i = 0, j = 0, n = seats.size();
        int maxi = 0;
        while (j < n){
            while (j < n && seats[j]) j++;
            i = j;
            while (j < n && !seats[j]) j++;
            maxi = max(maxi, j-i);
        }
        maxi = (maxi+1)/2;
        if (!seats[0]){
            i = 0;
            while (i < n && !seats[i])
                i++;
            maxi = max(maxi, i);
        }
        if (!seats[n-1]){
            i = n-1;
            while (i >= 0 && !seats[i])
                i--;
            maxi = max(maxi, n-1-i);
        }

        return maxi;
    }
};



int main(){
    //vector<int> a{1,0,0,0,1,0,1};
    vector<int> a{0,0,0,1};
    Solution s;
    cout << s.maxDistToClosest(a) << endl;

    return 0;
}
