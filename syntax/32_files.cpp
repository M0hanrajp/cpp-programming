/* The fstream library allows us to work with files.
 * ofstream	Creates and writes to files
 * ifstream	Reads from files
 * fstream	A combination of ofstream and ifstream: creates, reads, and writes to files
 */
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>

int main(void) {
    // Create and Write To a File
    std::ofstream fp("fdir/example.txt");
    // fp.open("fdir/example.txt"); >> This alone does not create the file, it only opens it
    fp.write("Trying to learn C++ file operations\n", 36);
    fp << "Writing some more characters\n";
    fp.close();
    // reading from file
    std::ifstream fp_open("fdir/example.txt");
    std::string readTxt;
    while (std::getline(fp_open, readTxt)) {
        std::cout << readTxt << std::endl;
    }
    fp_open.close();
    return 0;
}

/* Note
 * ofstream -> creates file if not present automatically
 * fstream -> does not create the file if not present.
 * if a file has been opened from ofstream then it is not capable of reading
 * use ifstream or fstream
 * before reading a file, the file which was written to must be closed as the file to which
 * is being written to might be still in buffer and not written to the file completely 
 */
