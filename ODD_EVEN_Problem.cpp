// solution:

class Solution {
  public:
    string oddEven(string s) {
        // code here
        int x = 0, y=0;
        unordered_map<char, int> m;
        for(int i=0;i<s.size();i++)
            m[s[i]]++;
        
        for(auto it:m){
            if((it.first - 'a'+1)%2==0 && it.second%2==0)
                x++;
            if((it.first - 'a'+1)%2==1 && it.second%2==1)
                y++;
        }
        return ((x+y)%2)?"ODD":"EVEN";
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
