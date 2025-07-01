#include <iostream>
#include <vector>
// runtime error, takes more time
using namespace std;

void printVect(vector<int> &num) {
    for (int n : num) {
        std::cout << n << " ";
    }
    cout << endl;
}

int main(void) {
    std::vector<int> numbers = {215, 28303, 25668, 24700};
    int k = 3;
/*     for(unsigned long i = 0; i < numbers.size(); i++) {
        if(k) {
            cout << "[DBG]: n[i]: " << numbers[i] << " n[i + 1] " << numbers[i + 1] << " i = " << i << endl;
            if(numbers[i] < numbers[i + 1]) {
                numbers.erase(numbers.begin() + i);
                i -= 1;
                k--;
            }
            printVect(numbers);
        }
    } */
    int i = 0;
    while(k) {
        cout << "[DBG]: n[i]: " << numbers[i] << " n[i + 1] " << numbers[i + 1] << " i = " << i << endl;
        if(i == numbers.size())
            break;
        if(numbers[i] < numbers[i + 1]) {
            numbers.erase(numbers.begin() + i);
            i = 0;
            k--;
            printVect(numbers);
            continue;
        }
        i++;
    }
    printVect(numbers);
    return 0;
}
