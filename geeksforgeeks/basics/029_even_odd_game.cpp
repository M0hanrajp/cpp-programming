/* In a given number of apples,
 * you always choose first, then your friend,
 * given number of apples return the string who wins ?
 */
#include <string>

std::string utility(int n) {
    // write your code here
    return n % 2 != 0 ? "You" : "Friend";
}
