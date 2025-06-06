#include <string>
class Solution {
  public:
    std::string isVowel(char c) {
        // code here
        switch(c) {
            case 'a': 
            case 'A': return "YES"; break;
            case 'e': 
            case 'E': return "YES"; break;
            case 'i': 
            case 'I': return "YES"; break;
            case 'o': 
            case 'O': return "YES"; break;
            case 'u': 
            case 'U': return "YES"; break;
            default : return  "NO"; break;
        }
    }
};
