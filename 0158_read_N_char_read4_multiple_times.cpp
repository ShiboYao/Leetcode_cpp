// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    char buffer[4];
    int i4 = 0, len = 0;
    
    int read(char *buf, int n) {
        int i = 0;
        while (i < n){
            while (i < n && i4 < len)
                buf[i++] = buffer[i4++];
            if (i == n) break;
            len = read4(buffer);
            i4 = 0;
            if (len == 0) break;
        }
        
        return i;
    }
};
