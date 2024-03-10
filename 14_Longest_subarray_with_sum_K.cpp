// Basically we have to find the longest subarray that has the sum as 'K' from the giver array
#include <bits/stdc++.h>
using namespace std;
//O(n^2)
// int getLongestSubarray(vector<int>& a, long long k) {
//     int n = a.size(); // size of the array.
//     int maxLen = 0;
//    for(int i = 0 ; i<n ; i++){
//     int sum = 0 ;
//     for(int j =i ; j<n ; j++){
//       sum +=a[j];
//       if(sum==k)
//       {
//         maxLen= max(maxLen,j-i+1);
//       }
//     }
//    }
//    return maxLen;
// }
// int getLongestSubarray(vector<int>& a, long long k) {
//     int n = a.size(); // size of the array.
//      long long sum = 0 ;
//      int maxLen=0;  
//      unordered_map<long long,int>prefixSum;
//      for(int i = 0 ; i<n;i++){
//         sum+=a[i];
//         if(prefixSum.find(sum-k)!=prefixSum.end())
//           maxLen = max(maxLen,i-prefixSum[sum-k]);
//         // prefixSum[sum]=i;
//         // there is still one edge case with this one that is 
//         // if we get zeros in the array then it might function as they
//         // are supposed to so we'll us this if statement to make that
//         // edge case solvable
//         if(prefixSum.find(sum)==prefixSum.end())
//         prefixSum[sum]=i;
//      }
//      return maxLen;
// }

//optimal approach
int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size(); // size of the array.
    int i =0,j=1;
    long long sum=(long long)a[0];
    int maxLen=0;
   while(j<=n){
    sum+=a[j];
    while(sum>k && i<=j){ 
        //i<=j is added because if a singular number greater than k exists in the giver array then 'i' will become greater than j which will be hider with the algorithm ( just think it through once you'll get it)
        sum-=a[i];
        i++;
    }
    if(sum==k)
    maxLen=max(maxLen,j-i+1);
    j++;
   }
    return maxLen;
    
}

int main()
{
    vector<int> a = {-13, 0, 6, 15, 16, 2, 15, -12, 17, -16, 0, -3, 19, -3, 2, -9, -6};
    // {1,2,0,0, 3, 5, 1, 9};
    long long k = 15;
    int len = getLongestSubarray(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    return 0;
}