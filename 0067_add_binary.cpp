#include <iostream>
using namespace std;


class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1, j = b.size()-1;
        int carry = 0;
        string r;
        while (i >= 0 && j >= 0){
            int t = a[i] + b[j] + carry - '0' - '0';
            if (t == 0)
                r.insert(0, 1, '0');
            else if (t == 1){
                r.insert(0, 1, '1');
                carry = 0;
            }
            else if (t == 2){
                r.insert(0, 1, '0');
                carry = 1;
            }
            else 
                r.insert(0, 1, '1');
            i--;
            j--;
        }
        while (i >= 0){
            int t = a[i] + carry - '0';
            if (t == 0)
                r.insert(0, 1, '0');
            else if (t == 1){
                r.insert(0, 1, '1');
                carry = 0;
            }
            else
                r.insert(0, 1, '0');
            i--;
        }
        while (j >= 0){
            int t = b[j] + carry - '0';
            if (t == 0)
                r.insert(0, 1, '0');
            else if (t == 1){
                r.insert(0, 1, '1');
                carry = 0;
            }
            else 
                r.insert(0, 1, '0');
            j--;
        }
        if (carry)
            r.insert(0, 1, '1');

        return r;
    }
};



int main(int argc, char** argv){
    if (argc < 3){
        cout << "specify 2 strings" << endl;
        exit(1);
    }

    string str1 = argv[1];
    string str2 = argv[2];

    Solution s;
    string str = s.addBinary(str1, str2);
    cout << str << endl;

    return 0;
}
