#include <vector>
using namespace std;



int LowIndexBS(const vector<int>& arr, const int &target);
int HighIndexBS(const vector<int>& arr, const int &target);

class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        bool noEncontrado = false;
        if(arr.empty()){
            return 0;
        }else if(arr.size() == 1){
            return(arr[0] == target ? 1 : 0);
        }else{
            int high = HighIndexBS(arr,target);
            int low = LowIndexBS(arr,target);
            if(low == -1 || high == -1){
                return 0;
            }else{
                return (high - low + 1);
            }
        }
    }
};

int LowIndexBS(const vector<int>& arr, const int &target){
    if(arr.empty()){
        return -1;
    }else if(arr.size() == 1){
        return(arr[0] == target ? 0 : -1);
    }
    bool encontrado = false;
    int n = arr.size();
    int menor = 0;
    int high = n -1;
    int low = 0;
    while(low <= high){
        int m = low + (high - low)/2;
        if(arr[m] == target){
           menor = m;
           high = m - 1;
           encontrado = true;
        }else if(arr[m] < target){
            low = m + 1;
        }else if(arr[m] > target){
            high = m - 1;
        }
    }
    return encontrado ? menor : -1;
}

int HighIndexBS(const vector<int>& arr, const int &target){
    if(arr.empty()){
        return -1;
    }else if(arr.size() == 1){
        return(arr[0] == target ? 0 : -1);
    }
    bool encontrado = false;
    int n = arr.size();
    int mayor = 0;
    int high = n -1;
    int low = 0;
    while(low <= high){
        int m = low + (high - low)/2;
        if(arr[m] == target){
           mayor = m;
           low = m + 1;
           encontrado = true;
        }else if(arr[m] < target){
            low = m + 1;
        }else if(arr[m] > target){
            high = m - 1;
        }
    }
    return encontrado ? mayor : -1;
}
// Version con subarrays que no es binary search pero es divide and conquer
// int LowIndexBS(const vector<int> &arr, const int &target, int offset  = 0){
//     int low = 0;
//     int high = arr.size() - 1;
//     int m = (low + high)/2;
//     int posible = - 1;
//     if(arr.empty()){
//         return -1;
//     }else if(arr.size() == 1){
//         return(arr[0] == target ? offset : -1);
//     }
//     if(arr[m] == target){
//         // Busco mas a la izquierda
//         vector<int> left(arr.begin(), arr.begin() + m);
//         int candidate = LowIndexBS(left, target, offset);
//         if(candidate >=  0){return candidate;}
//         // Si fall , este mid es el valido, ajustado con offset
//         return offset + m;
//     }
//     else if(arr[m] > target){
//         vector<int> left(arr.begin(), arr.begin() + m); 
//         return posibleLowIndexBS(left, target, offset);
//     }
//     else if(arr[m] < target){
//         vector<int> right(arr.begin() + m + 1, arr.end()); 
//         return LowIndexBS(right, target, offset + m + 1);
//     }
//     return -1;
// }