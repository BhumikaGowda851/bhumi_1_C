#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is a special character
int is_special_character(char ch) {
    return (ch >= 33 && ch <= 47) || (ch >= 58 && ch <= 64) ||
           (ch >= 91 && ch <= 96) || (ch >= 123 && ch <= 126);
}

// Function to validate the password
int validate_password(char *password) {
    int length = strlen(password);
    int has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0;

    if (length < 8) {
        printf("Password must be at least 8 characters long.\n");
        return 0;
    }

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) has_upper = 1;
        if (islower(password[i])) has_lower = 1;
        if (isdigit(password[i])) has_digit = 1;
        if (is_special_character(password[i])) has_special = 1;
    }

    if (!has_upper) {
        printf("Password must contain at least one uppercase letter.\n");
        return 0;
    }
    if (!has_lower) {
        printf("Password must contain at least one lowercase letter.\n");
        return 0;
    }
    if (!has_digit) {
        printf("Password must contain at least one digit.\n");
        return 0;
    }
    if (!has_special) {
        printf("Password must contain at least one special character.\n");
        return 0;
    }

    printf("Password is valid.\n");
    return 1;
}

int main() {
    char password[100];

    printf("Enter a password to validate: ");
    scanf("%s", password);

    validate_password(password);

    return 0;
}
