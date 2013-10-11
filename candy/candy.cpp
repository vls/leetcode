/* http://oj.leetcode.com/problems/candy/ */

#include <vector>
#include <stdio.h>

using namespace std;
class Solution {
public:
    int candy(vector<int> &ratings) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int N = ratings.size();
        int* A = new int[N];
        int* V = new int[N];
        int i = 0;
        for(; i< N; i++) {
            A[i] = 1;
        }
        
        vector<int>::iterator it=ratings.begin();
        int index = 0;
        for(; it!=ratings.end(); it++, index++) {
            int cur = *it;
            V[index] = cur;
        }
        
        int startIndex = 0;
        int len = 0;
        
        while(true) {
            len = this->findLongestDanDiaoSeq(A, V, N, startIndex);
            //printf("index = %d, len = %d\n", startIndex, len);

            if(len <= 1) {
                break;
            }
        
            this->doAdjust(A, V, N, startIndex, len);
            startIndex = startIndex + len - 1;
        }
        
        int total = this->getTotal(A, N);
        delete[] A;
        delete[] V;
        return total;
    }
    
    int getTotal(int A[], int N) {
        int total = 0;
        for(int i=0;i<N;i++) {
            //printf("%d ", A[i]);
            total += A[i];
        }
        //printf("\n");
        return total;
    }
    
    int findLongestDanDiaoSeq(int A[], int V[], int N, int i) {
        int way = 0;
        int len = 1;
        for(;i < N;i++) {
            if(way == 0) {
                if(V[i] < V[i+1]) {
                    way = 1;
                }
                if(V[i] > V[i+1]) {
                    way = -1;
                }
            }
            //printf("i=%d, way=%d, len=%d\n", i, way, len);

            if(way > 0 && V[i] > V[i+1]) {
                return len;
            }
            
            if(way < 0 && V[i] < V[i+1]) {
                return len;
            }
            len++;
        }
        return len;
    }
    
    void doAdjust(int A[], int V[], int N, int start, int len) {
        int end = start + len - 1;
        if(V[start] > V[end]) {
            for(int i=end;i>=start+1;i--) {
                if(V[i-1] > V[i]) {
                    
                    A[i-1] = max(A[i] + 1, A[i-1]);
                }
            }
        }
        else if(V[start] < V[end]) {
            for(int i=start;i<=end - 1;i++) {
                if(V[i+1] > V[i]) {
                    A[i+1] = max(A[i] + 1, A[i+1]);
                }
            }
        }
    }
};

int main() {
    Solution* obj = new Solution();
    //int arr[] = {4, 2, 3, 4, 1};
    int arr[] = {2, 1};
    vector<int> v(arr, arr+sizeof(arr)/sizeof(int));

    printf("%d\n", obj->candy(v));
    return 0;
}
