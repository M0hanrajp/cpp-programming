#include <map>
#include <string>

std::string boredom(const std::map<std::string, std::string> &staff){
  int cs = 0;
  for(auto& p : staff) {
    if(p.second == "accounts")
      cs +=  1;
    if(p.second == "finance")
      cs +=  2;
    if(p.second == "canteen")
      cs += 10;
    if(p.second == "regulation")
      cs +=  3;
    if(p.second == "trading")
      cs +=  6;
    if(p.second == "IS")
      cs +=  8;
    if(p.second == "change")
      cs +=  6;
    if(p.second == "retail")
      cs +=  5;
    if(p.second == "cleaning")
      cs +=  4;
    if(p.second == "pissing about")
      cs +=  25;
  }
  return (cs <= 80) ? "kill me now" :
         (cs > 80 && cs < 100) ? "i can handle this" : "party time!!";
}
