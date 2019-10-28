#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(), i = 0, j = 0;
        while (i < n){
            chars[j++] = chars[i];
            int k = i;
            while (i < n && chars[k] == chars[i])
                i++;
            if (i-k > 1){
                string t = to_string(i-k);
                for (char& c : t)
                    chars[j++] = c;
            }
        }
        chars.resize(j);

        return j;
    }
};



int main(int argc, char** argv){
    if (argc < 2){
        cout << "specify str" << endl;
        exit(1);
    }
    string str = argv[1];
    vector<char> a;
    for (char& c : str)
        a.push_back(c);
    Solution s;
    cout << s.compress(a) << endl;

    return 0;
}
