/*http://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order*/

class Solution {
public:
    string getPermutation(int n, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        char* arr = new char[n];
        for(int i=0;i<n;i++) {
            arr[i] = '1' + i;
        }
        
        int count = 1;
        while (count < k) {
            this->do_perm(arr, n);
            count++;
        }
        return string(arr);
    }
    
    void do_perm(char* arr, int n) {
        int k,l;
        for(k=n-2;k>=0;k--) {
            if(arr[k] < arr[k+1]) {
                break;
            }
        }
        
        for(l=n-1;l>=0;l--) {
            if(arr[k] < arr[l]) {
                break;
            }
        }
        
        char tmp = arr[k];
        arr[k] = arr[l];
        arr[l] = tmp;
        
        this->reverse(arr, k+1, n);
    }
    
    void reverse(char* arr, int start, int n) {
        if(n - start <= 1) {
            return;
        }
        
        int end = n - 1;
        while(start < end) {
            char tmp = arr[start];
            arr[start] = arr[end];
            arr[end] = tmp;
            start++;
            end--;
        }
    }
};
