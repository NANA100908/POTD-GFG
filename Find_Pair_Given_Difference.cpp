// Solution:

class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
        // code here
        unordered_map<int, int> mpp;
        for(int i=0;i<n;i++){
            int target1 = arr[i]-x;
            int target2 = arr[i]+x;
            
            if(mpp.find(target1) != mpp.end() || mpp.find(target2)!= mpp.end()){
                return 1;
            }
            mpp[arr[i]]++;
        }
        return -1;
    }
};

// Logic Used: 
// 1. An unordered map mpp is created to store the elements of the array arr as keys and their counts as values.
// 2. The code then iterates over the array arr. For each element arr[i], it calculates two target values: target1 and target2, which are arr[i]-x and arr[i]+x respectively.
// 3. It checks if either target1 or target2 exists in the map mpp. If either exists, it means there is a pair in the array whose difference is x, and the function returns 1.
// 4. If no such pair is found after checking all elements, the function returns -1.

// Time Complexity: O(N)
// Space Complexity: O(N)
