// https://www.codewars.com/kata/515de9ae9dcfc28eb6000001/cpp
#include <vector>
#include <string>
std::vector<std::string> solution(const std::string &s) {
  std::vector<std::string> res;
  char tmp[3] = {};
  int idx = 0;
  for(int i = 0; s[i] != '\0'; i++) {
    tmp[idx++] = s[i];
    if(idx == 2) {
      res.push_back(tmp);
      idx = 0;
    }  
  }
  if(idx == 1) {
    tmp[idx++] = '_';
    res.push_back(tmp);
    idx = 0;
  }   
  return res; // Your code here
}
