/* Structures
*
* Structures (also called structs) are a way to group several related variables into one place. 
* Each variable in the structure is known as a member of the structure.
* Unlike an array, a structure can contain many different data types (int, string, bool, etc.).
* Syntax of the structure
    struct {             // Structure declaration
      int myNum;         // Member (int variable)
      string myString;   // Member (string variable)
    } myStructure;       // Structure variable
* use myStructure.field_memeber to access members.
*/
#include <iostream>
#include <string>

int main(void) {
    struct programming {
        int languages;
        std::string languageName[3];
    } studentInfo[2];
    
    // assinging value
    studentInfo[0].languages = 2;
    studentInfo[0].languageName[0] = "C";
    studentInfo[0].languageName[1] = "C++";
    studentInfo[0].languageName[2] = "Go";

    std::cout << "Student A is aware of " << studentInfo[0].languages << "programming languages\n";
    std::cout << "He is proficient in : " << studentInfo[0].languageName[0] + ", "  + 
                                             studentInfo[0].languageName[1] + " & " +
                                             studentInfo[0].languageName[2] + '\n';

    return 0;
}
