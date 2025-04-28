/* Compare two strings by comparing the sum of their values (ASCII character code).

For comparing treat all letters as UpperCase
null/NULL/Nil/None should be treated as empty strings
If the string contains other characters than letters, treat the whole string as it would be empty
Your method should return true, if the strings are equal and false if they are not equal.

Examples:
"AD", "BC"  -> equal
"AD", "DD"  -> not equal
"gf", "FG"  -> equal
"zz1", ""   -> equal (both are considered empty)
"ZzZz", "ffPFF" -> equal
"kl", "lz"  -> not equal
null, ""    -> equal */
#include <iostream>
bool checkEmpty(std::string input) {
  for (int c : input) {
    if(toupper(c) > 64 && toupper(c) < 91)
      continue;
    else
      return true;
  }
  return false;
}

bool compare(std::string s1, std::string s2) {
  int sone = 0, stwo = 0;
  std::cout << "s1:" << s1 << '\n';
  std::cout << "s2:" << s2 << '\n';
  if(!checkEmpty(s1) && !checkEmpty(s2)) {
    for(int c : s1) {
      sone += toupper(c);
    }
    for(int c : s2) {
      stwo += toupper(c);
    } 
  }
  std::cout << "s1:" << sone << '\n';
  std::cout << "s2:" << stwo << '\n';
  return sone == stwo;
}
