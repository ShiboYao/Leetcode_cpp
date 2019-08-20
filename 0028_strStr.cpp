#include <iostream>
using namespace std;


class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;
        int i = 0, j = 0;
        int size = haystack.size(), size2 = needle.size();
        while (i < size){
            while (i < size && haystack[i] != needle[j])
                i++;
            int k = i;
            while (k < size && j < size2 && haystack[k] == needle[j]){
                k++;
                j++;
            }
            if (j == size2)
                return i;
            else {
                j = 0;
                i++;
                while (i < k && haystack[i] != needle[j])
                    i++;
            }
        }

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
