#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int n = words.size();
        int p1 = -n, p2 = -n, mini = n;
        for (int i = 0; i < n; i++){
            if (words[i] == word1){
                p1 = i;
                mini = min(mini, p1-p2);
            }
            else if (words[i] == word2){
                p2 = i;
                mini = min(mini, p2-p1);
            }
        }

        return mini;
    }
};



int main(){
    vector<string> words{"practice", "makes", "perfect", "coding", "makes"};
    string w1 = "coding", w2 = "practice";
    Solution s;
    cout << s.shortestDistance(words, w1, w2) << endl;

    return 0;
}
