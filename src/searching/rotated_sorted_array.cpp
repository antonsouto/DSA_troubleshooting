#include <vector>
using namespace std;


class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // Code Here
        int low = 0;
        int high =arr.size()-1;
        
        while(low <= high){
            int m = low + (high - low)/2;
            if(arr[m] == key){
                return m;
            }
            if(arr[m] >= arr[low]){
                // Izquierda es la parte ordenada
                if(key <= arr[m] && key >= arr[low]){
                    high = m - 1;
                }else{
                    low = m + 1;
                }
                
            }else{
                // Derecha es la parte ordenada
                if(key >= arr[m] && key <= arr[high]){
                    low = m + 1;
                }else{
                    high = m - 1;
                }
            }
        }
        return -1;
    }
};