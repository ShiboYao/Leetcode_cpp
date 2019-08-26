#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size()-1;
        while (i < j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};



int main(){
    vector<char> a{'h','e','l','l','o'};
    Solution s;
    s.reverseString(a);
    for (char& i : a)
        cout << i << " ";
    cout << endl;

    return 0;
}
