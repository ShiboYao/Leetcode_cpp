#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int low = 0, high = 20000, mid;
        while (low <= high){
            mid = (low+high)/2;
            int t = reader.get(mid);
            if (t == target) return mid;
            else if (t > target) high = mid-1;
            else low = mid+1;
        }

        return -1;
    }
};

