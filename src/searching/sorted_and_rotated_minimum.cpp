#include <vector>
using namespace std;




class Solution {
  public:
    int findMin(vector<int>& arr) {
        // complete the function here
        int low = 0;
        int high = arr.size() - 1;

        while(low < high){
            int m = low + (high - low)/2;
            if(arr[m] > arr[high]){
                low = m + 1;
            }else{
                high = m;
            }
        }
        
        return arr[low];
        
    }
};