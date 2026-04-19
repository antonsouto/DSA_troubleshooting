#include <vector>
using namespace std;

class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        // Code Here
        int i = 0;
        int count = 0;
        while(i < arr.size() - 2){
            int left = i + 1;
            int right = arr.size() - 1;
            int complement = target - arr[i];
            
            while(left < right){
                if(arr[left] + arr[right] == complement){
                    int auxLeft = 1;
                    int auxRight = 1;
                    if(arr[left] != arr[right]){
                        while(arr[right] == arr[right - auxRight]){
                            auxRight++;
                        }
                        while(arr[left] == arr[left + auxLeft]){
                            auxLeft++;
                        }
                        count += (auxLeft*auxRight);
                        left += auxLeft;
                        right -= auxRight;
                    }else if(arr[left] == arr[right]){
                        int n = right - left + 1;
                        count += (n * (n-1)/2);
                        break;
                    }
                }else if(arr[left] + arr[right] > complement){
                    right--;
                }else{
                    left++;
                    //right = arr.size() - 1; 
                }
            }
            i++;
        }
        return count;
    }
};