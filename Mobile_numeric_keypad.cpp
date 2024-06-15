// solution

class Solution {
  public:
    long long getCount(int n) {
        // Your code goes here
        vector<long long int> dp (10, 1);
        for(int i =1;i<n;i++){
            vector<long long int> temp (10, 0);
            temp[0] = dp[0]+dp[8];
            temp[1] = dp[1]+dp[2]+dp[4];
            temp[2] = dp[1]+dp[2]+dp[3]+dp[5];
            temp[3] = dp[2]+dp[3]+dp[6];
            temp[4] = dp[1]+dp[4]+dp[5]+dp[7];
            temp[5] = dp[2]+dp[4]+dp[5]+dp[6]+dp[8];
            temp[6] = dp[3]+dp[5]+dp[6]+dp[9];
            temp[7] = dp[4]+dp[7]+dp[8];
            temp[8] = dp[0]+dp[5]+dp[7]+dp[8]+dp[9];
            temp[9] = dp[6]+dp[8]+dp[9];
            dp = temp;
        }
        long long int sum =0;
        for(int i =0;i<10;i++){
            sum += dp[i];
        }
        
        return sum;
    }
};


/* Explanation / Simulation:
n = 3;
dp = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
      0  1  2  3  4  5  6  7  8  9

for i = 1----> 1<3 -----> condition true 
temp = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
        0  1  2  3  4  5  6  7  8  9

temp[0] = dp[0]+dp[8];  ----> 2
temp[1] = dp[1]+dp[2]+dp[4];  ----->3
temp[2] = dp[1]+dp[2]+dp[3]+dp[5]; ----->4
temp[3] = dp[2]+dp[3]+dp[6]; ---->3
temp[4] = dp[1]+dp[4]+dp[5]+dp[7]; ---->4
temp[5] = dp[2]+dp[4]+dp[5]+dp[6]+dp[8]; ---->5
temp[6] = dp[3]+dp[5]+dp[6]+dp[9]; ---->4
temp[7] = dp[4]+dp[7]+dp[8]; ---->3
temp[8] = dp[0]+dp[5]+dp[7]+dp[8]+dp[9]; ---->5
temp[9] = dp[6]+dp[8]+dp[9]; ---->4

temp = {2, 3, 4, 3, 4, 5, 4, 3, 5, 3}
        0  1  2  3  4  5  6  7  8  9


dp = temp;  ---->therefore dp= {2, 3, 4, 3, 4, 5, 4, 3, 5, 3}
                                0  1  2  3  4  5  6  7  8  9

for i = 2----> 2<3 -----> condition true 
temp = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
        0  1  2  3  4  5  6  7  8  9

temp[0] = dp[0]+dp[8]; ----> 7
temp[1] = dp[1]+dp[2]+dp[4]; ---->11
temp[2] = dp[1]+dp[2]+dp[3]+dp[5]; ----->15
temp[3] = dp[2]+dp[3]+dp[6]; ---->11
temp[4] = dp[1]+dp[4]+dp[5]+dp[7]; ---->15
temp[5] = dp[2]+dp[4]+dp[5]+dp[6]+dp[8]; ---->22
temp[6] = dp[3]+dp[5]+dp[6]+dp[9]; ---->15
temp[7] = dp[4]+dp[7]+dp[8]; ---->12
temp[8] = dp[0]+dp[5]+dp[7]+dp[8]+dp[9]; ---->18
temp[9] = dp[6]+dp[8]+dp[9]; ---->12

temp = {7, 11, 15, 11, 15, 22, 15, 12, 18, 12}
        0   1   2   3  4    5   6   7   8   9


dp = temp;  ---->therefore dp= {7, 11, 15, 11, 15, 22, 15, 12, 18, 12}
                                0   1   2   3  4    5   6   7   8   9
                                
for i = 3----> 3!<3 -----> condition false -----> loop stops

sum = 0;

After FOR loop
sum = 7+11+15+11+15+22+15+12+18+12 --------> 138 

sum = 138 -------> Answer/Output
*/

// Time Complexity - O(N);
// Space Complexity - O(1);
