class Solution {
public:
    int maxSubArray_On(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int i;
        int max_sum = A[0];
        for(i=1;i<n;i++) {
            max_sum = max(max_sum, A[i]);
        }
        
        if(max_sum < 0) {
            return max_sum;
        }
        
    
        int value;
        max_sum = A[0];
        int sum = 0;
        for(i=0;i<n;i++) {
            sum += A[i];
            sum = max(0, sum);
            max_sum = max(sum, max_sum);
        }
        
        return max_sum;
    }


    int maxSubArray_brute_force(int A[], int n) {
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
