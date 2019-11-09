#include <iostream>
using namespace std;


class Solution {
public:
    int shortestWay(string source, string target) {
        int i = 0, j = 0, count = 0, m = source.size(), n = target.size();
        while (i < n){
            while (j < m && target[i] != source[j])
                j++;
            if (j == m){
                j = 0;
                count++;
            }
            else {
                i++;
                j++;
            }
            if (count > i)
                return -1;
        }

        return count+1;
    }
};



int main(int argc, char** argv){
    if (argc < 3){
        cout << "specify str1 and str2" << endl;
        exit(1);
    }
    string s1 = argv[1], s2 = argv[2];
    Solution s;
    cout << s.shortestWay(s1, s2) << endl;

    return 0;
}
