#include <cstddef>
#include <iostream>
#include <string>

int main(void) {
    std::string greeting = "Hello!";
    std::cout << greeting; //prints Hello! without newline

    // string concatenation
    // The + operator can be used between strings to add them together to make a new string. This is called concatenation:
    std::string firstName = "C";
    std::string lastName = "++";
    // method 1,
    std::cout << '\n' + greeting + " " << firstName + lastName << std::endl; // prints C++ with new line
    // method 2 using append
    std::cout << greeting.append(" " + firstName + lastName) << std::endl;
                                //^-------- a whole string
    /* Hello! C++
     * Hello! C++ */

    // string length can use either length or size
    // size is an alias of length
    std::string result = greeting.append(" I'm learning " + firstName + lastName);
    std::cout << "The length() of \"" << result + "\" is " << result.length() << std::endl;
    std::cout << "The size() of \"" << result + "\" is " << result.size() << std::endl;
    /* The length() of "Hello! C++ I'm learning C++" is 27 (we did greeting.append() hence previous string is present)
     * The size() of "Hello! C++ I'm learning C++" is 27
     */

    // accessing string elements
    std::cout << "element 0: " << greeting[0] << " element 1: " << greeting[1] << std::endl;
    // at() function that can be used to access characters in a string, by providing an index 0 based
    std::cout << "element 2: " << greeting.at(2) << " element 3: " << greeting.at(3) << std::endl;
    // last character, will be + due to above statements
    std::cout << "Last element : " << greeting.at(greeting.length() - 1) << std::endl;
    /* element 0: H element 1: e
     * element 2: l element 3: l
     * Last element : +
     */

    // user input, uncomment what is required to execute
    std::string userName;
    //std::cout << "Enter full your name ";
    //  you would expect the program to print "John Doe", but it only prints "John".
    //std::cin >> userName;std::cout << userName + '\n';
    // In order to overcome this use getline(), 
    std::cout << "Enter full your name ";
    getline(std::cin, userName);std::cout << userName + "\n";

    char sentence[] = "I'm learning C++ and I'm 30% done";
    std::cout << sentence << std::endl;

    return 0;
}

/* Note
* why std::string can be used without "string" header file
* Some libc++ or libstdc++ implementations (like GCC, Clang) might include <string> internally from <iostream> or other headers.
* VIMP: It's always good practice to include the <string> to perform string operations.
* https://stackoverflow.com/questions/33349833/can-stdstring-be-used-without-include-string/33349897
* C style strings and C++ style strings
* https://stackoverflow.com/questions/3454900/whats-the-difference-between-c-strings-and-c-strings
* https://embeddedartistry.com/blog/2017/07/26/stdstring-vs-c-strings/
* If you try to add a number to a string then there is an error, the types cannot be different.
* You can change characters by accessing separate characters and assigning new character.
*/

// What happens when you dont declare "using namespace std;
// more clues can be found in
/* https://stackoverflow.com/questions/70375007/what-is-using-namespacestd-in-c
* https://stackoverflow.com/questions/1452721/whats-the-problem-with-using-namespace-std */
/* 8_strings.cpp: In function ‘int main()’:
8_strings.cpp:5:5: error: ‘string’ was not declared in this scope
    5 |     string greeting = "Hello !\n";
      |     ^~~~~~
8_strings.cpp:5:5: note: suggested alternatives:
In file included from /usr/include/c++/11/iosfwd:39,
                 from /usr/include/c++/11/ios:38,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from 8_strings.cpp:1:
/usr/include/c++/11/bits/stringfwd.h:79:33: note:   ‘std::string’
   79 |   typedef basic_string<char>    string;
      |                                 ^~~~~~
In file included from /usr/include/c++/11/bits/locale_classes.h:40,
                 from /usr/include/c++/11/bits/ios_base.h:41,
                 from /usr/include/c++/11/ios:42,
                 from /usr/include/c++/11/ostream:38,
                 from /usr/include/c++/11/iostream:39,
                 from 8_strings.cpp:1:
/usr/include/c++/11/string:67:11: note:   ‘std::pmr::string’
   67 |     using string    = basic_string<char>;
      |           ^~~~~~
8_strings.cpp:6:18: error: ‘greeting’ was not declared in this scope
    6 |     std::cout << greeting;
      |                  ^~~~~~~~ */


// Error if you want to add string literals
/* 8_strings.cpp: In function ‘int main()’:
8_strings.cpp:20:46: error: invalid operands of types ‘const char [2]’ and ‘const char [13]’ to binary ‘operator+’
   20 |     std::string result = greeting.append(" " + "I'm learning" + " " + firstName + lastName);
      |                                          ~~~ ^ ~~~~~~~~~~~~~~
      |                                          |     |
      |                                          |     const char [13]
      |                                          const char [2] */
/* - "text" is of type const char* (C-style string), not std::string.
- " " + "I'm learning" tries to add two const char* pointers — which makes no sense. It’s like doing pointer arithmetic.
- You can only use + between std::string and either another std::string or a C-string. */

/* Escape character	Result	        Description
\'	                 '	            Single quote
\"	                 "	            Double quote
\\	                 \	            Backslash */
