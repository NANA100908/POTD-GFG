// solution:

class Solution {
  public:
    /*You are requried to complete this method */
    long long max_Books(int arr[], int n, int k) {
        // Your code here
        long long ans =0;
        long long sum =0;
        for(int i=0;i<n;i++){
            if(arr[i]>k){
                ans = max(ans, sum);
                sum=0;
            }
            else{
                sum = sum +arr[i];
            }
        }
        ans = max(ans, sum);
        return ans;
    }
};
