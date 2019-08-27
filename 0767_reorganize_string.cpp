#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    string reorganizeString(string S) {
        int n = S.size();
        if (n == 1)
            return S;
        vector<int> a(256, 0);
        for (auto i : S)
            a[i]++;
        int maxi = 0;
        char c;
        for (int i = 0; i < 256; i++){
            if (a[i] > maxi){
                maxi = a[i];
                c = i;
            }
        }
     
        if (n%2 != 0 && maxi > n/2+1)
            return "";
        if (n%2 == 0 && maxi > n/2)
            return "";
        
        int pos = 0;
        while (a[c]){
            S[pos] = c;
            a[c]--;
            pos += 2;
        }
        int i = 'a';
        while (pos < n){
            while (pos < n && a[i]){
                S[pos] = i;
                a[i]--;
                pos += 2;
            }
            if (a[i] == 0)
                i++;
        }
        pos = 1;
        while (pos < n){
            while (a[i]){
                S[pos] = i;
                a[i]--;
                pos += 2;
            }
            if (a[i] == 0)
                i++;
        }
            
        return S;
    }
};



int main(int argc, char** argv){
    if (argc < 2){
        cout << "Specify string" << endl;
        exit(1);
    }
    string str = argv[1];
    Solution s;
    cout << s.reorganizeString(str) << endl;

    return 0;
}
