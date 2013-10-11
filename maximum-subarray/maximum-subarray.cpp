class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.

        int i;
        int j;
        

        int max_value = INT_MIN;
        int value;
        for(j=0;j<n;j++) {
            value = 0;
            for(i=j;i<n;i++) {
                value += A[i];
                if(value > max_value) {
                    max_value = value;
                }
            }
        }
        
        return max_value;
    }
};
