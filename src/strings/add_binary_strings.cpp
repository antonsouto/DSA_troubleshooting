#include <string>
#include <vector>
using namespace std;



// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
        int carry = 0;
        int sum = 0;
        
        int maxSize = max (s1.size(), s2.size());
        if(s1.size() < s2.size()){
            s1.insert(0, maxSize - s1.size(), '0');
        }else{
            s2.insert(0, maxSize - s2.size(), '0');
        }
        
        string solution(maxSize, '0');
        
        for(int i = maxSize - 1; i >= 0;  --i){
            int bit1 = s1[i] - '0';
            int bit2 = s2[i] - '0';
            sum = bit1 + bit2 + carry;
            
            solution[i] = sum % 2 + '0';
            carry = sum / 2;
        }
        
        if(carry){
            solution.insert(solution.begin(), 1, '1');
        }
        
        auto pos = solution.find_first_not_of('0');
        if(pos != string::npos){
            return solution.substr(pos);
        }else{
            return "0";
        }
    }
};