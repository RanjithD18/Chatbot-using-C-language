#include <ctype.h>
#include <stdio.h>
 
int main()
{
    int j = 0;
    char str[100]="SBJKKSB'";
    while (str[j]) {
        str[j] = tolower(str[j]);
        j++;
    }
    for (int i = 0; i < j; i++)
        printf("%c", str[i]);
    return 0;
}