// Solution

class Solution {
  public:
    long long max_sum(int a[], int n) { // n=4 , a[] = {1,2,3,5}
        // Your code here
        long long sum =0, R0=0; // sum=0, R0 =0
        for(int i=0;i<n;i++){ 
            sum += a[i];  // sum = 11
            R0 += (1LL*i*a[i]);  // R0=23
        }
        
        long long max=R0; // max = 23
        long long Ri = R0;  // Ri = 23
        for(int i=0;i<n-1;i++){
            long long Rip1 = Ri + sum - (1LL*n*a[n-i-1]);
            if(Rip1 > max) max = Rip1;
            Ri = Rip1;
        }
        return max;
    }
};

/* For loop Run:
1st run   // max = 23 , Ri = 23 , i =0
Rip1 = 23+11 - (4*5) = 14
Rip1>max ? = false
Ri = 14

2nd Run // max = 23, Ri = 14, i=1
Rip1 = 14+11 -(4*3) = 13
Rip1> max ? = false
Ri = 13

3rd Run // max = 23, Ri = 13, i=2
Rip1 = 13+11 -(4*2) = 16
Rip1> max ? = false
Ri = 16

4th Run // max=23, Ri = 16, i =3
Rip1 = 16+11-(4*1) = 23
Rip1> max ? = false
Ri = 23

Loop end 

max = 23 --- Answer
*/

// Time Complexity = O(N)
// Space Complexity = O(1)
