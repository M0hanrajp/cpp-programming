// single line comments
/*
 * Mulit line comments
 *
 */
#include <iostream>

int main(void) {
    // You can also use another << operator and place the \n character after the text, like this:
    std::cout << 3 << "\n";
    // Two \n characters after each other will create a blank line:
    std::cout << 4 * 3 << "\nInserting blankline\n\n";
    // Another way to insert a new line, is with the endl manipulator:
    std::cout << 3 * 3 << std::endl;
    std::cout << 5 % 2 << std::endl;
    return 0;
}
/* 
\t	Creates a horizontal tab	
\\	Inserts a backslash character (\)	
\"	Inserts a double quote character */
