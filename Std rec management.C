#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

// Structure to store student information
struct Student {
    int roll_number;
    char name[100];
    float marks;
};

// Array to store students
struct Student students[MAX_STUDENTS];
int student_count = 0;

// Function to add a new student
void add_student() {
    if (student_count >= MAX_STUDENTS) {
        printf("Student database is full! Cannot add more students.\n");
        return;
    }

    struct Student new_student;
    printf("Enter roll number: ");
    scanf("%d", &new_student.roll_number);
    getchar(); // Consume newline character left by scanf
    printf("Enter name: ");
    fgets(new_student.name, sizeof(new_student.name), stdin);
    new_student.name[strcspn(new_student.name, "\n")] = '\0'; // Remove trailing newline
    printf("Enter marks: ");
    scanf("%f", &new_student.marks);

    students[student_count++] = new_student;
    printf("Student added successfully!\n");
}

// Function to view all students
void view_students() {
    if (student_count == 0) {
        printf("No student records found.\n");
        return;
    }

    printf("\nStudent Records:\n");
    for (int i = 0; i < student_count; i++) {
        printf("Roll Number: %d\nName: %s\nMarks: %.2f\n\n",
               students[i].roll_number, students[i].name, students[i].marks);
    }
}

// Function to edit a student's information by roll number
void edit_student() {
    int roll_number;
    printf("Enter the roll number of the student to edit: ");
    scanf("%d", &roll_number);

    for (int i = 0; i < student_count; i++) {
        if (students[i].roll_number == roll_number) {
            printf("Editing record for %s (Roll Number: %d)\n", students[i].name, roll_number);
            printf("Enter new name: ");
            getchar(); // Consume newline
            fgets(students[i].name, sizeof(students[i].name), stdin);
            students[i].name[strcspn(students[i].name, "\n")] = '\0'; // Remove newline
            printf("Enter new marks: ");
            scanf("%f", &students[i].marks);
            printf("Student record updated successfully!\n");
            return;
        }
    }

    printf("No student found with Roll Number %d.\n", roll_number);
}

// Function to delete a student's record by roll number
void delete_student() {
    int roll_number;
    printf("Enter the roll number of the student to delete: ");
    scanf("%d", &roll_number);

    for (int i = 0; i < student_count; i++) {
        if (students[i].roll_number == roll_number) {
            for (int j = i; j < student_count - 1; j++) {
                students[j] = students[j + 1];
            }
            student_count--;
            printf("Student record deleted successfully!\n");
            return;
        }
    }

    printf("No student found with Roll Number %d.\n", roll_number);
}

int main() {
    int choice;

    do {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Edit Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                view_students();
                break;
            case 3:
                edit_student();
                break;
            case 4:
                delete_student();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
