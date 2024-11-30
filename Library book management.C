#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

// Structure to store book information
struct Book {
    int id;
    char title[100];
    char author[100];
};

// Array to store the books
struct Book library[MAX_BOOKS];
int book_count = 0;

// Function to add a book to the library
void add_book() {
    if (book_count >= MAX_BOOKS) {
        printf("Library is full! Cannot add more books.\n");
        return;
    }

    struct Book new_book;
    printf("Enter book ID: ");
    scanf("%d", &new_book.id);
    getchar(); // To consume newline character left by scanf
    printf("Enter book title: ");
    fgets(new_book.title, sizeof(new_book.title), stdin);
    new_book.title[strcspn(new_book.title, "\n")] = '\0'; // Remove trailing newline
    printf("Enter book author: ");
    fgets(new_book.author, sizeof(new_book.author), stdin);
    new_book.author[strcspn(new_book.author, "\n")] = '\0'; // Remove trailing newline

    library[book_count++] = new_book;
    printf("Book added successfully!\n");
}

// Function to search for a book by title
void search_book() {
    char title[100];
    printf("Enter the title of the book to search: ");
    getchar(); // To consume newline character left by scanf
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = '\0'; // Remove trailing newline

    int found = 0;
    for (int i = 0; i < book_count; i++) {
        if (strcasecmp(library[i].title, title) == 0) {
            printf("Book found:\n");
            printf("ID: %d\nTitle: %s\nAuthor: %s\n", library[i].id, library[i].title, library[i].author);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No book found with the title \"%s\".\n", title);
    }
}

// Function to delete a book by ID
void delete_book() {
    int id;
    printf("Enter the ID of the book to delete: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < book_count; i++) {
        if (library[i].id == id) {
            // Shift all books after the found book to the left
            for (int j = i; j < book_count - 1; j++) {
                library[j] = library[j + 1];
            }
            book_count--;
            printf("Book with ID %d deleted successfully!\n", id);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No book found with ID %d.\n", id);
    }
}

// Function to display all books
void display_books() {
    if (book_count == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("\nLibrary Books:\n");
    for (int i = 0; i < book_count; i++) {
        printf("ID: %d\nTitle: %s\nAuthor: %s\n\n", library[i].id, library[i].title, library[i].author);
    }
}

int main() {
    int choice;

    do {
        printf("\nLibrary Book Management System\n");
        printf("1. Add Book\n");
        printf("2. Search Book\n");
        printf("3. Delete Book\n");
        printf("4. Display All Books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                search_book();
                break;
            case 3:
                delete_book();
                break;
            case 4:
                display_books();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
