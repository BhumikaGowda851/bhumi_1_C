#include <stdio.h>

// Function to convert Celsius to Fahrenheit
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

// Function to convert Fahrenheit to Celsius
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

int main() {
    int choice;
    float temperature, converted;

    printf("Temperature Conversion Program\n");
    printf("1: Convert Celsius to Fahrenheit\n");
    printf("2: Convert Fahrenheit to Celsius\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temperature);
            converted = celsius_to_fahrenheit(temperature);
            printf("%.2f°C is equal to %.2f°F\n", temperature, converted);
            break;

        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temperature);
            converted = fahrenheit_to_celsius(temperature);
            printf("%.2f°F is equal to %.2f°C\n", temperature, converted);
            break;

        default:
            printf("Invalid choice. Please select 1 or 2.\n");
            break;
    }

    return 0;
}
