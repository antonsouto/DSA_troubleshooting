#include <vector>
using namespace std;



class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        
        int n = arr.size();
        int *low = &arr[0];
        int *mid = &arr[0];
        int *high = &arr[n - 1];
    
        while(mid <= high){
            if(*mid == 0){
                int temp = *mid;
                *mid = *low;
                *low = temp;
                mid++;
                low++;
            }else if(*mid == 1){
                mid++;
            }else if(*mid == 2){
                int temp = *mid;
                *mid = *high;
                *high = temp;
                high--;
            }
        }
    }
};