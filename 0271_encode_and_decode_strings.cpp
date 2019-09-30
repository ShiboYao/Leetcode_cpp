#include <iostream>
#include <vector>
using namespace std;


class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string r = "";
        for (string s : strs)
            r += to_string(s.size()) + '#' + s;

        return r;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> r;
        int i = 0;
        while (i < s.size()){
            int j = i;
            while (s[j] != '#')
                j++;
            int l = stoi(s.substr(i, j-i));
            j++;
            r.push_back(s.substr(j, l));
            i = j + l;
        }

        return r;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));



int main(int argc, char** argv){
    if (argc < 2){
        cout << "specify strs" << endl;
        exit(1);
    }
    vector<string> strs;
    for (int i = 1; i < argc; i++)
        strs.push_back(argv[i]);
    Codec codec;
    vector<string> r = codec.decode(codec.encode(strs));
    for (string s : r)
        cout << s << endl;

    return 0;
}
