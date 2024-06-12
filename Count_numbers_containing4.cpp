// solution

class Solution {
  public:
    int countNumberswith4(int n) {
        // code here
        int count=0;
        for(int i =1;i<=n;i++){
            int num = i;
            while(num>0){
                if(num%10 == 4){
                    count++;
                    break;
                }
                num = num/10;
            }
        }
        return count;
    }
};

//Time Complexity: O(NlogN)
// Space Complexity: O(1)
