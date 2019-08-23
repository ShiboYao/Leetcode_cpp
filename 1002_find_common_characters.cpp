#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

/*
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        unordered_map<char, int> mp;
        for (char& b : A[0])
            mp[b]++;
        for (int i = 1; i < A.size(); i++){
            unordered_map<char, int> mp2;
            for (char& b : A[i]){
                if (mp[b] > 0)
                    mp2[b]++;
            }
            for (auto& m : mp){
                m.second = min(m.second, mp2[m.first]);
            }
        }

        vector<string> r;
        for (auto m : mp){
            while (m.second > 0){
                r.push_back(string(1, m.first));
                m.second--;
            }
        }

        return r;
    }
};
*/
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> m(26, 0);
        for (char& b : A[0])
            m[b - 'a']++;
        for (int i = 1; i < A.size(); i++){
            vector<int> m2(26, 0);
            for (char& b : A[i])
                m2[b - 'a']++;
            for (int j = 0; j < 26; j++)
                m[j] = min(m[j], m2[j]);
        }
        vector<string> r;
        for (int i = 0; i < 26; i++){
            while (m[i] > 0){
                r.push_back(string(1, 'a'+i));
                m[i]--;
            }
        }

        return r;
    }
};


int main(int argc, char** argv){
    if (argc < 3){
        cout << "Specify at least two strings" << endl;
        exit(1);
    }
    vector<string> A;
    for (int i = 1; i < argc; i++)
        A.push_back(argv[i]);

    Solution s;
    vector<string> a = s.commonChars(A);
    for (string& i : a)
        cout << i << " ";
    cout << endl;

    return 0;
}
