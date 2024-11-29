#include<stdio.h>
struct Student {
    char name[25];
    int age;
    char gender[10];
    char department[50];
    char college[50];
    };
    int main()
{
    struct Student s1;
    printf("\nStudent details\n");
    printf("enter the name:");
    scanf("%s",&s1.name);
    printf("enter the age:");
    scanf("%d",&s1.age);
    printf("enter the gender:");
    scanf("%s",&s1.gender);
    printf("enter the department:");
    scanf("%s",&s1.department);
    printf("enter the college");
    scanf("%s",&s1.college);
    printf("name:%s\nage:%d\ngender:%s\ndepartment:%s\ncollege:%s\n",s1.name,s1.age,s1.gender,s1.department,s1.college);
    printf("Bhumika A");
    return 0;
}
