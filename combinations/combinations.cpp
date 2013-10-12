class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.

        if(k == 0 || n < 1) {
            vector<int> inner;
            vector<vector<int>> outter;
            outter.push_back(inner);
            return outter;
        }
        
        vector<vector<int>> outter;
        for(int i=1; i< pow(2, n); i++) {
            if(this->oneNum(i) == k) {
                vector<int> inner;
                int num = i;
                int count = 1;
                while(num) {
                    if(num & 1) {
                        inner.push_back(count);
                    }
                    count++;
                    num = num >> 1;
                }
                outter.push_back(inner);
            }
        }
        return outter;
    }
    
    int oneNum(int n) {
        int count = 0;
        while(n) {
            count++;
            n = n & (n - 1);
        }
        return count;
    }
};
