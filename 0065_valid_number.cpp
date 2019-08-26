#include <iostream>
#include <cctype>
using namespace std;


class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        if (n == 0)
            return false;

        int i = 0;
        while (isspace(s[i]))
            i++;
        if (s[i] == '+' || s[i] == '-')
            i++;

        int count = 0;
        while (isdigit(s[i])){
            i++;
            count++;
        }
        if (s[i] == '.')
            i++;
        while (isdigit(s[i])){
            i++;
            count++;
        }
        if (count == 0)
            return false;

        if (s[i] == 'e'){
            i++;
            if (s[i] == '+' || s[i] == '-')
                i++;
            if (!isdigit(s[i]))
                return false;
            while (isdigit(s[i]))
                i++;
        }
        while (isspace(s[i]))
            i++;

        return s[i]=='\0';
    }
};


int main(int argc, char** argv){
    if (argc < 2){
        cout << "Specify string" << endl;
        exit(1);
    }
    string str = argv[1];
    Solution s;
    cout << s.isNumber(str) << endl;

    return 0;
}
