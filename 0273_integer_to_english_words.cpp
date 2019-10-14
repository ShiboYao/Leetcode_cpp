#include <iostream>
#include <vector>
using namespace std;


class Solution {
private:
    vector<string> word{"Billion","Million","Thousand","Hundred","Ninety","Eighty","Seventy","Sixty","Fifty","Forty","Thirty","Twenty","Nineteen","Eighteen","Seventeen","Sixteen","Fifteen","Fourteen","Thirteen","Twelve","Eleven","Ten","Nine","Eight","Seven","Six","Five","Four","Three","Two","One"};
    vector<int> nums{1000000000,1000000,1000,100,90,80,70,60,50,40,30,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
public:
    string numberToWords(int num) {
        for (int i = 0; i < word.size(); i++){
            if (num/nums[i] > 0){
                int a = num/nums[i], b = num%nums[i];
                return ((i<4?numberToWords(a)+" ":"")+word[i]+(b?" "+numberToWords(b):""));
            }
        }

        return "Zero";
    }
};



int main(int argc, char** argv){
    if (argc < 2){
        cout << "specify num" << endl;
        exit(1);
    }
    int num = stoi(argv[1]);
    Solution s;
    cout << s.numberToWords(num) << endl;

    return 0;
}
