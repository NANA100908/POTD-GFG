// Solution

class Solution {
  public:
    // l and r are input array
    // maxx : maximum in r[]
    // n: size of array
    // arr[] : declared globally with size equal to maximum in l[] and r[]
    // Function to find the maximum occurred integer in all ranges.
    int maxOccured(int n, int l[], int r[], int maxx) { 
        vector<int> freq(maxx+2, 0);
        
        for(int i=0;i<n;i++){
            freq[l[i]]++;
            if(r[i]+1 <=maxx)
                freq[r[i]+1] --;
        }
        
        int max_occ = freq[0];
        int res =0;
        
        for(int i =1;i<maxx+1;i++){
            freq[i]+=freq[i-1];
            if(freq[i] > max_occ) {
                max_occ = freq[i];
                res =i;
            }
        }
        return res;
        // Your code here
    }
};

/*Dry Run:
n=5, l[] ={1,5,9,13,21} , r[] ={15,8,12,20,30} , maxx=30

now freq = {0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,0,0}
    
1st loop 
i=0  ,freq[1] =1 ,freq[16]=-1
i=1 , freq[5] = 1 ,freq[9]=-1
i=2 , freq[9]=0 , freq[13]=-1
i=3 , freq[13]=0 ,freq[21]=-1
i=4 , freq[21]=0

now freq = {0,1,0,0,0,1,0,0,0,0,
            0,0,0,0,0,0,-1,0,0,0,
            0,0,0,0,0,0,0,0,0,0}

now max_occ = 0 , res =0
2nd loop
freq = {0,1,1,1,1,2,2,2,2,2,
        2,2,2,2,2,1,1,1,1,1,
        1,1,1,1,1,1,1,1,1,1}
        
max_occ = 2 , res = 5
*/

// Time Complexity: O(n+maxx)
// space Complexity: O(maxx)
