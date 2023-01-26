#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    int i;
    int lower = 0, upper = 7, count = 1;
 
    // Use current time as
    // seed for random generator
    srand(time(0));
    for (i = 0; i < count; i++) {
        int num = (rand() %(upper - lower + 1)) + lower;
        printf("%d ", num);
    }
}