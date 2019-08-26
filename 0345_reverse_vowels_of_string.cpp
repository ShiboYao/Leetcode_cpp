#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> set{'a', 'e', 'i', 'o', 'u'};
        int i = 0, j = s.size()-1;
        while (i < j){
            while (i < j && set.find(s[i]) == set.end())
                i++;
            while (i < j && set.find(s[j]) == set.end())
                j--;
            if (i < j)
                swap(s[i++], s[j--]);
        }

        return s;
    }
};



int main(int argc, char** argv){
    if (argc < 2){
        cout << "Specify string" << endl;
        exit(1);
    }
    string str = argv[1];
    Solution s;
    cout << s.reverseVowels(str) << endl;

    return 0;
}
