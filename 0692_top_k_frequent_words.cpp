#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;


class comparator{
public:
    bool operator()(const pair<string, int> a, const pair<string, int> b){
        if (a.second > b.second)
            return true;
        else if (a.second < b.second)
            return false;
        else {
            if (a.first.compare(b.first) < 0)
                return true;
            else 
                return false;
        }
    }
};


class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (string& str : words)
            mp[str]++;
        priority_queue<pair<string, int>, vector<pair<string, int>>, comparator> pq;
        for (auto& iter : mp){
            pq.push(make_pair(iter.first, iter.second));
            if (pq.size() > k)
                pq.pop();
        }
        vector<string> r;
        for (int i = 0; i < k ; i++){
            r.push_back(pq.top().first);
            pq.pop();
        }
        reverse(r.begin(), r.end());

        return r;
    }
};



int main(){
    vector<string> words{"i", "love", "leetcode", "i", "love", "coding"};
    int k = 2;
    Solution s;
    vector<string> r = s.topKFrequent(words, k);
    for (string& str : r)
        cout << str << endl;

    return 0;
}
