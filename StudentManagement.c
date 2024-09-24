#include <stdio.h>
#include <string.h>
#define MAX 100
#define MAX_NAME_LEN 50

void displayList(char students[][MAX_NAME_LEN], int size) {
    printf("Student list: ");
    for (int i = 0; i < size; i++) {
        printf("%s", students[i]);
        if (i < size - 1) printf(", ");
    }
    printf("\n");
}

// Function to create a list of students
void createList(char students[][MAX_NAME_LEN], int *size) {
    printf("Enter the number of students: ");
    scanf("%d", size);
    for (int i = 0; i < *size; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", students[i]);
    }
}

// Function to insert a new student
void insertStudent(char students[][MAX_NAME_LEN], int *size) {
    char name[MAX_NAME_LEN];
    int pos;
    printf("Enter name to insert: ");
    scanf("%s", name);
    printf("Enter position (0-based index): ");
    scanf("%d", &pos);

    if (pos < 0 || pos > *size) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = *size; i > pos; i--) {
        strcpy(students[i], students[i - 1]);
    }
    strcpy(students[pos], name);
    (*size)++;
}

// Function to delete a student
void deleteStudent(char students[][MAX_NAME_LEN], int *size) {
    int pos;
    printf("Enter position (0-based index) to delete: ");
    scanf("%d", &pos);

    if (pos < 0 || pos >= *size) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = pos; i < *size - 1; i++) {
        strcpy(students[i], students[i + 1]);
    }
    (*size)--;
}

// Function to search for a student
void searchStudent(char students[][MAX_NAME_LEN], int size) {
    char name[MAX_NAME_LEN];
    printf("Enter name to search: ");
    scanf("%s", name);

    for (int i = 0; i < size; i++) {
        if (strcmp(students[i], name) == 0) {
            printf("%s found at position %d\n", name, i);
            return;
        }
    }
    printf("%s not found!\n", name);
}

int main() {
    char students[MAX][MAX_NAME_LEN];
    int size = 0, choice;

    do {
        printf("\n1. Create list\n2. Insert student\n3. Delete student\n4. Display list\n5. Search student\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createList(students, &size); break;
            case 2: insertStudent(students, &size); break;
            case 3: deleteStudent(students, &size); break;
            case 4: displayList(students, size); break;
            case 5: searchStudent(students, size); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}
