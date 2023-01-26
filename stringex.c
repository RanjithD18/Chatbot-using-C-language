#include<stdio.h>
int main(){
    char arrayx[2][10];
    char array1[2][10]={"Ranjith","Manoj"};
    char* ptr10=&arrayx[0][0];
    *ptr10=array1[2][10];
    printf("%s\n",arrayx);
    printf("%s",*(ptr10));
}