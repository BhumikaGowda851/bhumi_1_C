#include<stdio.h>
#include<string.h>
int main() {
    char str[24],rev[24];
    printf("Enter the string");
    scanf("%s",str);
    strcpy(rev,str);
    strrev(rev);
    if(strcmp(str,rev)==0)
    {
    printf("the string is palindrome");
    }
    else
    {
        printf("the string is not palindrome ");
    }
    return 0;
}
