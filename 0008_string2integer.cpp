#include <iostream>
#include <climits>
using namespace std;


class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        while (i < str.size() && str[i] == ' ')
            i++;
        if (str[i] != '-' && str[i] != '+' && (str[i] < '0' || str[i] > '9'))
            return 0;
        bool sign = false;
        if (str[i] == '-')
            sign = true;
        if (str[i] == '-' || str[i] == '+'){
            i++;
            if (str[i] < '0' || str[i] > '9')
                return 0;
        }
        unsigned result = 0;
        int lim = INT_MAX/10;
        while (i < str.size() && str[i] >= '0' && str[i] <= '9'){
            if (result > lim){
                if (sign)
                    return INT_MIN;
                else
                    return INT_MAX;
            }
            result *= 10;
            result = result + str[i] - '0';
            i++;
        }
        if (sign && result > INT_MAX)
            return INT_MIN;
        if (!sign && result >= INT_MAX)
            return INT_MAX;

        return sign?-(signed)result:result;
    }
};



int main(int argc, char** argv){
    if (argc < 2){
        cout << "Specify string!" << endl;
        exit(1);
    }
    string str = argv[1];
    Solution s;
    int num = s.myAtoi(str);
    cout << num << endl;

    return 0;
}
