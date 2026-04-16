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
            int right = arr.size() - 1;
            int complement = target - arr[i];
            
            while(left < right){
                if(arr[left] + arr[right] == complement){
                    count++;
                    int aux=1;
                    while((arr[right] == arr[right -aux]) && (left) != (right -aux))
                    { 
                        count++;
                        aux++;
                    }
                    left++;
                }else if((arr[left] + arr[right] > complement) ){
                    right--;
                }else{
                    left++;
                    right=arr.size() - 1;
                }
            }
            i++;
        }
        return count;
    }
};