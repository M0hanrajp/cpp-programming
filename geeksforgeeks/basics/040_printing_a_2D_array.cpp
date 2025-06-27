/* Function to take input for 2D array elements
 * Note : Mention matrix in argument also.
 * N : size of matrix
 */
#include <iostream>
using namespace std;
void twoDimensional(/*Your Parameter here*/int **arr, int N) {

    // Loop to iterate through matrix
    // and print all the matrix elements row wise
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
