#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution {
public:
string getHint(string secret, string guess){
        vector<int> s(10), g(10);
        int a = 0, b = 0;
        for (int i = 0; i < guess.size(); i++){
            if (secret[i] == guess[i])
                a++;
            else{
                s[secret[i]-'0']++;
                g[guess[i]-'0']++;
            }
        }
        for (int i = 0; i < 10; i++)
            b += min(s[i],g[i]);

        return to_string(a)+"A"+to_string(b)+"B";
    }
};


/*
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,unordered_set<int>> mp;
        for (int i = 0; i < secret.size(); i++){
            if (mp.find(secret[i]) == mp.end())
                mp[secret[i]] = unordered_set<int>{};
            mp[secret[i]].insert(i);
        }
        int a = 0, b = 0;
        for (int i = 0; i < guess.size(); i++){
            if (mp[guess[i]].find(i) != mp[guess[i]].end()){
                a++;
                mp[guess[i]].erase(i);
                guess[i] = 'n';
            }
        }
        unordered_map<char,int> m;
        for (auto i : mp)
            m[i.first] = i.second.size();
        for (int i = 0; i < guess.size(); i++){
            if (m[guess[i]] > 0){
                m[guess[i]]--;
                b++;
            }
        }
        
        return to_string(a)+"A"+to_string(b)+"B";
    }
};
*/


int main(int argc, char** argv){
    if (argc < 3){
        cout << "specify true and guess" << endl;
        exit(1);
    }
    string str1 = argv[1], str2 = argv[2];
    Solution s;
    cout << s.getHint(str1, str2) << endl;

    return 0;
}
