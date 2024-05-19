// Solution:

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        // Complete the function
        // finding the smallest element index that is close to K in array 
        int index1 = lower_bound(arr, arr+n, k)-arr;
        // finding the nearest largest element index that is close to K in array
        int index2 = upper_bound(arr, arr+n, k)-arr;
         // if both indices are same then reduces index1 by 1
        if(index1==index2)index1--;
         // checking with smaller index element
        if(abs(arr[index1]-k)>abs(arr[index2]-k)){
            return arr[index2];
        }
        // checking with next larger index element
        else if(abs(arr[index1]-k)<abs(arr[index2]-k)){
            return arr[index1];
        }
        // if both are same the returning the largest value
        return arr[index2];
    } 
};
