#include <iostream>
using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 0 || s.size() == 1)
            return s;
        int a, b, i = 0, mark, size = s.size();
        int maxlen = 1;
        while (2*(size-i) > maxlen){
            a = b = i;
            while (b+1 < size && s[b] == s[b+1])
                b++;
            i = b+1; //instead of i++; faster
            while (a > 0 && b+1 < size && s[a-1] == s[b+1]){
                a--;
                b++;
            }
            if (b-a+1 > maxlen){
                mark = a;
                maxlen = b-a+1;
            }
        }

        return s.substr(mark, maxlen);
    }
};



int main(int argc, char** argv){
    if (argc < 2){
        cout << "Specify input string!" << endl;
        exit(1);
    }
    string s = argv[1];
    cout << s << endl;
    Solution so;
    string substr = so.longestPalindrome(s);
    cout << substr << endl;

    return 0;
}
