#include <vector>
#include <algorithm>
using namespace std;



class Solution {
  public:
    
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        vector<vector<int>> solucion;
        // Code here
        // arr[[1,2],[6,8],[3,5]]
        
        sort(arr.begin(), arr.end(), [] (const vector<int> &a, const vector<int> &b) -> bool{
            if(a[0] != b[0]){
                return a[0] < b[0];
            }else{
                return a[1] < b[1];
            }
        });
        
        //arr[[1,4],[3,5],[6,8]]
        vector<vector<int>> tem; // Intervalos fusionados hasta el momento [1,4]
        tem.push_back(arr[0]);
        
        //int it = 0;
        
        for(int i = 0; i < arr.size()-1; ++i){
            vector<int> include;
            if(tem.back()[1] >= arr[i+1][0]){
                include.push_back(tem.back()[0]);
                include.push_back(max(tem.back()[1], arr[i+1][1]));
                //solucion.push_back(include); // Esto no lo puedes hacer porque si el siguiente solapa cagaste
                tem.pop_back(); //Quito el ultimo solape
                tem.push_back(include); //Meto el definitivo temporal [[1,5]]
                //include.pop_back(); //Esto tiene que estar vacío en cada bucle, no se si hace falta realmente, ya tu me dices y lo quito si en cada iteración se reinicia por la posicion en la que se declara
            }else{
                //solucion.push_back(arr[i]);
                tem.push_back(arr[i + 1]);
                //it++;
            }
        }
        
        return tem;
    }
};