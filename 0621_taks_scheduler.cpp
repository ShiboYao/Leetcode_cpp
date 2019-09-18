#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26);
        for (char& c : tasks)
            mp[c-'A']++;
        int highfreq = 0, count = 0;
        for (int&m : mp){
            if (m > highfreq){
                highfreq = m;
                count = 1;
            }
            else if (m == highfreq)
                count++;
        }

        return max(int(tasks.size()), (highfreq-1) * (n+1) + count);
    }
};



int main(int argc, char** argv){
    if (argc < 2){
        cout << "specify str as tasks" << endl;
        exit(1);
    }
    vector<char> tasks;
    string str = argv[1];
    for (char& c : str)
        tasks.push_back(c);
    Solution s;
    int n = 2;
    cout << s.leastInterval(tasks, n) << endl;

    return 0;
}
