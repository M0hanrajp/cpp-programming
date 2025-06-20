/* https://www.codewars.com/kata/57ecf6efc7fe13eb070000e1/cpp#:~:text=The%20Office%20I%20%2D%20Outed */
#include <string>
#include <map>
std::string outed(const std::map<std::string, int> &meet, const std::string &boss){
  float score = 0, numColleagues = 0;
  for(auto& p : meet) {
    if(p.first == boss)
      score += (2 * p.second);
    else
      score += p.second;
    numColleagues++;
  }
  return ((score / numColleagues) <= 5.0 ? "Get Out Now!" : "Nice Work Champ!" );
}

