/* Given a string str, reverse it and omit all non-alphabetic characters.

Example
For str = "krishan", the output should be "nahsirk".

For str = "ultr53o?n", the output should be "nortlu".

Input/Output
[input] string str
A string consists of lowercase latin letters, digits and symbols.

[output] a string */
#include <iostream>
std::string reverse_letter(const std::string &str) {
  char* res = new char[str.length()];
  int index = 0;
  for(int i = str.length() - 1; i > -1; i--) {
    if(isalpha(str[i]))
      res[index++] = str[i];
  }
  res[index] = '\0';
  return res;
}
