// https://www.codewars.com/kata/57ee24e17b45eff6d6000164/cpp
#include <string>
std::string cat_mouse(std::string x) {
  return x.find("m") < 5 ? "Caught!" : "Escaped!";
}
