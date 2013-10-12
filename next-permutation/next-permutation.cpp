class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int k = -1, l;
        int size = num.size();
        int i;
        for(i=size-2;i>=0;i--) {
            if(num[i] < num[i+1]) {
                k = i;
                break;
            }
        }
        
        if(k == -1) {
            this->reverse(num, 0);
            return;
        }
        
        for(i=size-1;i>=0;i--) {
            if(num[k] < num[i]) {
                l = i;
                break;
            }
        }
        
        int tmp = num[k];
        num[k] = num[l];
        num[l] = tmp;
        
        this->reverse(num, k+1);
        
    }
    
    void reverse(vector<int> &num, int start) {
        int n = num.size();
        
        int end = n - 1;
        while(start < end) {
            int tmp = num[start];
            num[start] = num[end];
            num[end] = tmp;
            start++;
            end--;
        }
    }
};
