// solution

class Solution {
  public:
    string binaryNextNumber(string s) { // let s = '1110'
        // code here.
        int i = s.size()-1; // i = 4-1  = 3
        while(i>=0 && s[i]!='0'){ // s[i]=0 therefore, while lop will not execute
            s[i]='0'; 
            i--;
        }
        if(i<0)s='1'+s; // will not execute
        else s[i]='1'; // s[3]= '1' -- string='1111'
        reverse(s.begin(), s.end()); // s= '1111'
        while(true){  
            int n = s.size(); // n = 4
            if(s[n-1]=='0') s.pop_back(); // not 
            else break; 
        }
        reverse(s.begin(), s.end()); // s = '1111'
        return s; // s='1111'
    }
};

// time complexity = O(N)
