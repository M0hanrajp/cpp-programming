#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    // code here
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0 || i == n - 1) {
                printf("* ");
            } else {
                if(j == 0)
                    printf("* ");
                else if(j == n - 1)
                    printf("* ");
                else
                    printf("  ");
            }
        }
        printf("\n");
    }
    return 0;
}
/*

10
* * * * * * * * * * 
*                 * 
*                 * 
*                 * 
*                 * 
*                 * 
*                 * 
*                 * 
*                 * 
* * * * * * * * * * 

*/
