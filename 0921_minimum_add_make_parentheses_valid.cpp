#include <iostream>
using namespace std;


class Solution {
public:
    int minAddToMakeValid(string S) {
        int count = 0, l = 0;
        for (char& c : S){
            if (c == '(')
                l++;
            else {
                if (l == 0)
                    count++;
                else 
                    l--;
            }
        }
        count += l;

        return count;
    }
};



int main(int argc, char** argv){
    if (argc < 2){
        cout << "specify string" << endl;
        exit(1);
    }
    string str = argv[1];
    Solution s;
    cout << str << endl;
    cout << s.minAddToMakeValid(str) << endl;

    return 0;
}
