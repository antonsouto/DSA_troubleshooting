#include <vector>
using namespace std;



class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here

        // Asigno el máximo a mi variable que almacena el máximo
        int max = arr[0];
        int max2 = arr[1]; // Asigno la variable max2 a la misma, que luego verificaré para devolver -1
        
        for(int iter = 0; iter<arr.size(); iter++){
            if(arr[iter] > max){
                max2 = max;
                max = arr[iter];
            }else if(arr[iter] > max2 && arr[iter] != max){
                max2 = arr[iter];
            }
        }
        
        if(max<max2){ // Control de v de tamaño 2 con pos 1 mayor que pos 0
            int aux = max;
            max = max2;
            max2 = aux;
        }
        if(max == max2){return -1;}
        return max2;
    }
};