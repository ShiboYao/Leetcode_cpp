#include <iostream>
using namespace std;


class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;
        int i = 0, j = 0, index = 0;
        int size = haystack.size(), size2 = needle.size();
        while (i < size && j < size2){
            if (haystack[i] == needle[j]){
                i++;
                j++;
            }
            else {
                index++;
                i = index;
                j = 0;
            }
        }
        if (j == size2)
            return index;

        return -1;
    }
};


int main(int argc, char** argv){
    if (argc < 3){
        cout << "Specify a string and a needle" << endl;
        exit(1);
    }
    string str = argv[1];
    string needle = argv[2];
    Solution s;
    int p = s.strStr(str, needle);
    cout << p << endl;

    return 0;
}
