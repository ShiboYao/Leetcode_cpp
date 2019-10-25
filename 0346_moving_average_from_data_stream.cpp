#include <iostream>
#include <queue>
using namespace std;


class MovingAverage {
    double sum = 0;
    int k;
    queue<int> q;

public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        k = size;
    }

    double next(int val) {
        if (q.size() == k){
            sum -= q.front();
            q.pop();
        }
        sum += val;
        q.push(val);

        return sum/q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */



 int main(){
     MovingAverage* obj = new MovingAverage(3);
     cout << obj->next(1) << endl;
     cout << obj->next(10) << endl;
     cout << obj->next(3) << endl;
     cout << obj->next(5) << endl;

     return 0;
 }
