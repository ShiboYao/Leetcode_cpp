#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    string simplifyPath(string path) {
        vector<string> r;
        int i = 0, j = 0, n = path.size();
        while (i < n){
            while (i < n && path[i] == '/') i++;
            if (i == n) break;
            j = i;
            while (j < n && path[j] != '/') j++;
            string t = path.substr(i,j-i);//cout << t << endl;
            if (t == ".."){
                if (!r.empty())
                    r.pop_back();
            }
            else if (t != ".")
                r.push_back(t);
            i = j;
        }
        string re = "";
        for (string i:r)
            re += '/'+i;

        return re.empty()?"/":re;
    }
};



int main(int argc, char** argv){
    if (argc < 2){
        cout << "specify path" << endl;
        exit(1);
    }
    string path = argv[1];
    Solution s;
    cout << s.simplifyPath(path) << endl;

    return 0;
}
