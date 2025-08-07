#include <vector>
using namespace std;
vector<vector<int>> transpose(int a[][M], int n) {
    // Code here
    vector<vector<int>> tpose(n, vector<int>(n, 0));
    /* creates a 2D vector with n * n elements
     * assigns them default value of 0
     */
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            tpose[i][j] = a[j][i];
        }
    }
    return tpose;
}
