// User functiom template for C++
#include <iostream>
#include <cctype>

using namespace std;

class Solution {
  public:
    int BasicDataType(string s) {
      // code here
      // Check for character
      if(s.length() == 1) {
          if(!(s[0] > 47 && s[0] < 58)) {
              return sizeof(char);
          }
      }
      // check for integer
      size_t check = s.find(".");
      if(check == std::string::npos) {
          return sizeof(int);
      // check for float and double
      } else {
          int precision = 0;
          for(int i = check + 1; s[i] != '\0'; i++) {
              if(s[i]) {
                  precision++;
              }
          }
          return precision < 6 ? sizeof(float) : 
                                 sizeof(double);
      }
    }
};
