#include <iostream>
using namespace std;


class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(tx >= sx && ty >= sy){
            if(tx > ty){
                if(sy == ty) return (tx - sx) % ty == 0;
                tx %= ty;
            }else{
                if(sx == tx) return (ty - sy) % tx == 0;
                ty %= tx;
            }
        }

        return false;
    }
};



int main(){
    Solution s;
    cout << s.reachingPoints(1,1,2,2) << endl;

    return 0;
}
