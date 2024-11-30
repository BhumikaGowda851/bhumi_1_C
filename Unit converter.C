#include <stdio.h>

// Function prototypes
float meters_to_kilometers(float meters);
float kilometers_to_meters(float kilometers);
float grams_to_kilograms(float grams);
float kilograms_to_grams(float kilograms);

int main() {
    int choice;
    float input, converted;

    printf("Unit Conversion Program\n");
    printf("1: Meters to Kilometers\n");
    printf("2: Kilometers to Meters\n");
    printf("3: Grams to Kilograms\n");
    printf("4: Kilograms to Grams\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter value in meters: ");
            scanf("%f", &input);
            converted = meters_to_kilometers(input);
            printf("%.2f meters is equal to %.2f kilometers\n", input, converted);
            break;

        case 2:
            printf("Enter value in kilometers: ");
            scanf("%f", &input);
            converted = kilometers_to_meters(input);
            printf("%.2f kilometers is equal to %.2f meters\n", input, converted);
            break;

        case 3:
            printf("Enter value in grams: ");
            scanf("%f", &input);
            converted = grams_to_kilograms(input);
            printf("%.2f grams is equal to %.2f kilograms\n", input, converted);
            break;

        case 4:
            printf("Enter value in kilograms: ");
            scanf("%f", &input);
            converted = kilograms_to_grams(input);
            printf("%.2f kilograms is equal to %.2f grams\n", input, converted);
            break;

        default:
            printf("Invalid choice. Please select an option between 1 and 4.\n");
            break;
    }

    return 0;
}

// Function definitions
float meters_to_kilometers(float meters) {
    return meters / 1000.0;
}

float kilometers_to_meters(float kilometers) {
    return kilometers * 1000.0;
}

float grams_to_kilograms(float grams) {
    return grams / 1000.0;
}

float kilograms_to_grams(float kilograms) {
    return kilograms * 1000.0;
}
