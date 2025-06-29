// #include <iostream> is a header file library that lets us work with input and output objects, such as cout
#include <iostream>
// using namespace std means that we can use names for objects and variables from the standard library.
using namespace std;

// main function
int main(void) {
    // cout (pronounced "see-out") is an object used together with the insertion operator (<<) to output/print text.
    cout << "Hello, World!\n";
    // The using namespace std line can be omitted and replaced with the std keyword, followed by the :: operator for some objects:
    std::cout << "Hello, World!\n";
    // The cout object, together with the << operator, is used to output values and print text.
    cout << "Hello, "
            "I'm learning cpp\n";
    // end
    return 0;
    /* Output if errors are fixed
        Hello, World!
        Hello, World!
        Hello, I'm learning cpp
    */
}

// blank line. C++ ignores white space. But we use it to make the code more readable.
// C++ is case-sensitive: "cout" and "Cout" has different meaning.
// Every C++ statement ends with a semicolon ;.
// What happens if you omit "using namespace std" $ g++ -Wall -g helloworld.cpp
/* helloworld.cpp: In function ‘int main()’:
helloworld.cpp:9:5: error: ‘cout’ was not declared in this scope; did you mean ‘std::cout’?
    9 |     cout << "Hello, World!\n";
      |     ^~~~
      |     std::cout
In file included from helloworld.cpp:2:
/usr/include/c++/11/iostream:61:18: note: ‘std::cout’ declared here
   61 |   extern ostream cout;          /// Linked to standard output
      |                  ^~~~ */

/* Note
* https://stackoverflow.com/questions/70375007/what-is-using-namespacestd-in-c
* https://stackoverflow.com/questions/1452721/whats-the-problem-with-using-namespace-std
*/
