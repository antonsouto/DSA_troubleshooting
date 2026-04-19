#include <vector>
#include <algorithm>

using namespace std;

// User function Template for C++
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Your code here
        sort(arr.begin(), arr.end());

        int left = 0;
        int right = arr.size() - 1;
        int count = 0;

        while(left < right){

            if(arr[right] + arr[left] >= target){
                right--;
            }else{
                count += (right - left);
                left++;
                // right = arr.size() - 1;
            }
        }
        
        return count;
    }
};