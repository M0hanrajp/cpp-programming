/* You take your son to the forest to see the monkeys. 
 * You know that there are a certain number there (n), but your son is too young to 
 * just appreciate the full number, he has to start counting them from 1.

As a good parent, you will sit and count with him. Given the number (n), populate an 
array with all numbers up to and including that number, but excluding zero.

For example(Input --> Output):

10 --> [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
 1 --> [1] */
#include <vector>
std::vector<int> MonkeyCount(int n) {
  std::vector<int> mc(n, 0); // create mc array with size n and initialize all elements to 0
  for(int i = 0; i < n; i++) {
    mc.at(i) = i + 1;
  }
  return mc;
}
