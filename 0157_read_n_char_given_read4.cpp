// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int count = 0;
        while (n > 0){
            int i = min(read4(buf), n);
            count += i;
            if (i < 4) return count;
            n -= i;
            buf += i;
        }
        
        return count;
    }
};
