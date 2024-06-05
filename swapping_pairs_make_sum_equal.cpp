// solution

class Solution {

  public:
    int findSwapValues(int A[], int n, int B[], int m) { // n=6 , m=4, a[]= {4,1,2,1,1,2} , b[] ={3,6,3,3}        // Your code goes here
       int sum1=0,sum2=0; // sum1 =0, sum2 =0
       for(int i=0;i<n;i++) sum1 += A[i]; // sum1 = 4+1+2+1+1+2 = 11
       for(int i=0;i<m;i++) sum2 += B[i]; // sum2 = 3+6+3+3 = 15
       sort(A,A+n); // a[] = {1,1,1,2,2,4}
       sort(B,B+m); // b[] = {3,3,3,6}
       int i=0,j=0; //i=0,j=0
       while(i<n && j<m){  // 1st run = 11-4+3 == 15+4-3 -- 10 != 16  fail if case ; 11-4+3>15+4-3 -- 10!>16 not run ; so j =1;
           if(sum1-A[i]+B[j]==sum2+A[i]-B[j]) return 1; 
           else if(sum1-A[i]+B[j]>sum2+A[i]-B[j]) i++;
           else j++;
       }
       return -1;
    }
};

/* 1st run
11-1+3 == 15+1-3 -- 13 != 13  return 1;
*/

// Time Complexity: O(n log n + m log m)
