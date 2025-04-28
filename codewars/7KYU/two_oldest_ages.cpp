/* The two oldest ages function/method needs to be completed. It should take an array of numbers 
 * as its argument and return the two highest numbers within the array. The returned value should 
 * be an array in the format [second oldest age,  oldest age].

The order of the numbers passed in could be any order. The array will always include at least 2 items. 
If there are two or more oldest age, then return both of them in array format.

For example (Input --> Output):

[1, 2, 10, 8] --> [8, 10]
[1, 5, 87, 45, 8, 8] --> [45, 87]
[1, 3, 10, 0]) --> [3, 10] */
#include <vector>
#include <array>

std::array<int, 2> two_oldest_ages(std::vector<int> ages) {
  int a = 0, b = 0;
  // after 2 iterations largest two elements are placed at the end of vector ages
  for(unsigned long i = 0; i < 2; i++) {
    for(unsigned long j = 1; j < ages.size() - i; j++) {
      if(ages[j] < ages[j - 1])
        std::swap(ages[j], ages[j - 1]);
    }
  }
  a = ages[ages.size() - 2];
  b = ages[ages.size() - 1];
  return {a, b};
}
