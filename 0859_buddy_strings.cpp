#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size()) return false;
        int n = A.size();
        bool swp = false;
        vector<char> s;
        for (int i = 0; i < n; i++){
            if (A[i] != B[i]){
                if (swp) return false;
                if (!s.empty()){
                    if (s[0] == B[i] && s[1] == A[i]){
                        s.pop_back();
                        s.pop_back();
                        swp = true;
                    }
                    else
                        return false;
                }
                else {
                    s.push_back(A[i]);
                    s.push_back(B[i]);
                }
            }
        }
        if (swp) return true;
        if (!s.empty()) return false;

        vector<int> a(26);
        for (int i = 0; i < n; i++)
            if (++a[A[i]-'a'] > 1) return true;
        
        return false;
    }
};



int main(int argc, char** argv){
    if (argc < 3){
        cout << "two strs" << endl;
        exit(1);
    }
    string s1 = argv[1], s2 = argv[2];
    Solution s;
    cout << s.buddyStrings(s1,s2) << endl;

    return 0;
}
