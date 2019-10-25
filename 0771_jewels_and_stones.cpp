#include <iostream>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> s;
        for (char& c : J)
            s.insert(c);
        int sum = 0;
        for (char& c : S)
            sum += s.find(c)!=s.end();

        return sum;
    }
};



int main(int argc, char** argv){
    if (argc < 3){
        cout << "specify jewels and stones" << endl;
        exit(1);
    }
    string jewels = argv[1], stones = argv[2];
    Solution s;
    cout << s.numJewelsInStones(jewels, stones) << endl;

    return 0;
}
