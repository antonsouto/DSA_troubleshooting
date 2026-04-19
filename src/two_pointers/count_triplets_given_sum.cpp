#include <vector>
using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& arr, int target) {
        // Code Here
        int i = 0;
        int count = 0;
        while(i < arr.size() - 2){
            int left = i + 1;
            int right = left +1;
            int complement = target - arr[i];
            
            while(right < arr.size()){
                if(arr[left] + arr[right] == complement){
                    count++;
                    int aux=1;
                    while((arr[right] == arr[right + aux]) && arr.size() > (right + aux))
                    { 
                        count++;
                        aux++;
                    }
                    left++;
                    right=left +1;
                }else if((arr[left] + arr[right] < complement) ){
                    right++;
                }else{
                    left++;
                    right=left +1;
                }
            }
            i++;
        }
        return count;
    }
};