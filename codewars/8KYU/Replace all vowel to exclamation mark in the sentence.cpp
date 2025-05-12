/* Description:
Replace all vowel to exclamation mark in the sentence. aeiouAEIOU is vowel.

Examples
"Hi!" --> "H!!"
"!Hi! Hi!" --> "!H!! H!!"
"aeiou" --> "!!!!!"
"ABCDE" --> "!BCD!" */

#include <iostream>
using namespace std;

string replace(const string &s) {
  char *res = new char[s.length()];
  int index = 0;
  for(unsigned long i = 0; i < s.length(); i++) {
    switch(s[i]) {
        case 'a': 
        case 'A': res[index++] = '!'; break;
        case 'e': 
        case 'E': res[index++] = '!'; break;
        case 'i': 
        case 'I': res[index++] = '!'; break;
        case 'o': 
        case 'O': res[index++] = '!'; break;
        case 'u': 
        case 'U': res[index++] = '!'; break;
        default : res[index++] = s[i];break;
    }
  }
  res[index] = '\0';
  return res; //coding and coding....
}
