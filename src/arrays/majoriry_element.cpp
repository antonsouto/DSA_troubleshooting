#include <vector>
#include <algorithm>
using namespace std;



class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        int pivot = arr.size() - 2;
        while(pivot >= 0 && arr[pivot] >= arr[pivot + 1]){
            pivot--;
        }
        if(pivot < 0){
            std::reverse(arr.begin(),arr.end());
        }else{
            int maxIndex = arr.size() - 1;
            for(int i = arr.size() - 1; i > pivot; --i){
                if(arr[i] > arr[maxIndex]){
                    maxIndex = i;
                }
            }
            int indToSwap = maxIndex, provisional;
            for(int k = arr.size() -1; k > pivot; --k){
                if(arr[k] > arr[pivot]){
                    provisional = k;
                    if(arr[provisional] < arr[indToSwap]){
                        indToSwap = provisional;
                    }
                }
            }
            std::swap(arr[pivot],arr[indToSwap]);
            reverse(arr.begin() + pivot +1, arr.end());
        }
    }
};