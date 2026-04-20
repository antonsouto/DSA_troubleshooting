#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        int left = 0;
        int right = arr.size() - 1;
        int count = 0;
        
        while(left < right){
            // complement = target - arr[left];
            if(arr[left] + arr[right] < target){
                left++;
            }else if(arr[left] + arr[right] > target){
                right--;
            }else{
                if(arr[left] == arr[right]){
                    int n = right - left + 1;
                    count += (n * (n - 1) ) / 2;
                    break;
                }else{
                    int nLeft = 0;
                    int nRight = 0;
                    int elemLeft = arr[left];
                    int elemRight = arr[right];
                    
                    while(arr[left] == elemLeft && left <= right){
                        left++;
                        nLeft++;
                    }
                    while(arr[right] == elemRight && left <= right){
                        nRight++;
                        right--;
                    }
                    
                    count += nLeft*nRight ;
                }
            }
        }
        return count;
    }
};