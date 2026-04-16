#include <vector>
#include <algorithm>
using namespace std;




int canAllocate(int, vector<int>);

class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        if(k > arr.size()){
            return -1;
        }
        
        // Variables para busqueda binaria sobre solucion 
        int low = *max_element(arr.begin(), arr.end());
        int high = 0;
        for(auto it = arr.begin(); it != arr.end(); it++){
            high += *it;
        }
        int mid;
        
        while(low < high){
            mid = low + (high - low)/2;
            int nEstudiantes = canAllocate(mid, arr);
            if(nEstudiantes > k){
                low = mid + 1;
            }else{
                high = mid;
            }
        }
        return low;
    }
};


int canAllocate(int mid, vector<int> array){
    int acum = 0;
    int nEstudiantes = 1;
    for(int i = 0; i < array.size(); ++i){
        acum += array[i];
        if(acum > mid){
            acum = array[i];
            nEstudiantes++;
        }
    }
    return nEstudiantes;
}