#include <vector>
using namespace std;




class Solution {
  public:
    int peakElement(vector<int> &arr) {
        // code here
        int high = arr.size() - 1;
        int low = 0;
        while(low < high){
            int m = low + (high - low)/2;
            if(arr[m] < arr[m + 1]){
                low = m + 1;
            }else{
                high = m;
            }
        }
        
        return low;
    }
};
