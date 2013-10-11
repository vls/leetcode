#include <stdio.h>
#include <limits.h>

class Solution {
public:
    int atoi(const char *str) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        char* start = NULL;
        char* end = NULL;
        char* ptr;
        bool flag_valid = false;
        for(ptr=(char*)str; ptr != '\0'; ptr++) {
            char c = *ptr;
            if(c == ' ' && !flag_valid) {
                continue;
            }
            
            if (!(!flag_valid && (c == '+' || c == '-') || (c <= '9' && c >= '0'))) {
                break;
            }
            
            if(NULL == start) {
                start = ptr;
                flag_valid = true;
            }
            end = ptr;
        }
        
        if(!flag_valid) {
            return 0;
        }
        
        int total = 0;
        char sign = '+';
        if(*start == '+' || *start == '-') {
            sign = *start;
            start++;
        }
        
        int max_before_multiply = INT_MAX / 10;
        for(ptr=start;ptr<=end;ptr++) {
            total += *ptr - '0';

            
            if(total < 0 || (ptr != end && total > max_before_multiply)) {
                if(sign == '+') return INT_MAX;
                if(sign == '-') return INT_MIN;
            }
            if(ptr != end) {
                total *= 10;
                if(total < 0) {
                    if(sign == '+') return INT_MAX;
                    if(sign == '-') return INT_MIN;
                }
            }
        }
        
        if(sign == '-') {
            total *= -1;
        }
        
        return total;
        
        
    }
};
int main() {
    Solution* obj = new Solution();

    printf("%d\n", obj->atoi(" 10522545459"));
    return 0;
}
