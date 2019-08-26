#include <iostream>
#include <unordered_set>
using namespace std;


class Solution {
public:
    string removeVowels(string S) {
        unordered_set<char> set{'a', 'e', 'i', 'o', 'u'};
        int i = 0, j = 0;
        while (j < S.size()){
            while (j < S.size() && set.find(S[j]) == set.end())
                S[i++] = S[j++];
            while (j < S.size() && set.find(S[j]) != set.end())
                j++;
        }
        S = S.substr(0, i);

        return S;
    }
};



int main(int argc, char** argv){
    if (argc < 2){
        cout << "Specify string" << endl;
        exit(1);
    }
    Solution s;
    string str = argv[1];
    cout << s.removeVowels(str) << endl;

    return 0;
}
