/*
 * The bloody photocopier is broken... Just as you were sneaking around the office to print off your favourite binary code!
 * Instead of copying the original, it reverses it: '1' becomes '0' and vice versa.
 * Given a string of binary, return the version the photocopier gives you as a string.
*/
#include <iostream>

std::string broken(const std::string& inp) {
  char* res = new char[inp.length() + 1];
  int index = 0;
  for(unsigned long i = 0; i < inp.length() ; i++) {
    switch(inp[i]) {
        case '1': res[index++] = '0'; break;
        case '0': res[index++] = '1'; break;
        default : break;
    }
  }
  res[index] = '\0';
  return res;
}
