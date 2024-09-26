#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    struct Node* next;
};

struct Node* create_node(char* name) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    strcpy(new_node->name, name);
    new_node->next = NULL;
    return new_node;
}

void create_list(struct Node** head, int n) {
    char name[50];
    for (int i = 0; i < n; i++) {
        printf("Enter contact name %d: ", i + 1);
        scanf("%s", name);
        insert_contact(head, name, i);
    }
}

void insert_contact(struct Node** head, char* name, int position) {
    struct Node* new_node = create_node(name);
    if (position == 0) {
        new_node->next = *head;
        *head = new_node;
    } else {
        struct Node* temp = *head;
        for (int i = 0; temp != NULL && i < position - 1; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Position out of bounds!\n");
        } else {
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }
    traverse_list(*head);
}


void delete_by_name(struct Node** head, char* name) {
    struct Node *temp = *head, *prev = NULL;

    if (temp != NULL && strcmp(temp->name, name) == 0) {
        *head = temp->next;
        free(temp);
    } else {
        while (temp != NULL && strcmp(temp->name, name) != 0) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Contact not found!\n");
            return;
        }
        prev->next = temp->next;
        free(temp);
    }
    traverse_list(*head);
}


void delete_by_position(struct Node** head, int position) {
    struct Node *temp = *head, *prev = NULL;

    if (position == 0 && temp != NULL) {
        *head = temp->next;
        free(temp);
    } else {
        for (int i = 0; temp != NULL && i < position; i++) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Position out of bounds!\n");
            return;
        }
        prev->next = temp->next;
        free(temp);
    }
    traverse_list(*head);
}

void traverse_list(struct Node* head) {
    if (head == NULL) {
        printf("Contact list is empty.\n");
        return;
    }
    printf("Contact list: ");
    while (head != NULL) {
        printf("%s -> ", head->name);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to search for a contact by name
void search_contact(struct Node* head, char* name) {
    int position = 0;
    while (head != NULL) {
        if (strcmp(head->name, name) == 0) {
            printf("%s found at position %d\n", name, position);
            return;
        }
        head = head->next;
        position++;
    }
    printf("Contact not found!\n");
}


int main() {
    struct Node* head = NULL;
    int choice, num_contacts, position;
    char name[50], delete_choice;

    while (1) {
        printf("\n--- Contact Management System ---\n");
        printf("1. Create the list of contacts\n");
        printf("2. Insert a new contact\n");
        printf("3. Delete a contact\n");
        printf("4. Display contact list\n");
        printf("5. Search for a contact\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of contacts: ");
                scanf("%d", &num_contacts);
                create_list(&head, num_contacts);
                break;
            case 2:
                printf("Enter contact name to insert: ");
                scanf("%s", name);
                printf("Enter the position (0-based): ");
                scanf("%d", &position);
                insert_contact(&head, name, position);
                break;
            case 3:
                printf("Delete by name or position? (n/p): ");
                scanf(" %c", &delete_choice);
                if (delete_choice == 'n') {
                    printf("Enter the contact's name to delete: ");
                    scanf("%s", name);
                    delete_by_name(&head, name);
                } else {
                    printf("Enter the position to delete: ");
                    scanf("%d", &position);
                    delete_by_position(&head, position);
                }
                break;
            case 4:
                traverse_list(head);
                break;
            case 5:
                printf("Enter the contact's name to search: ");
                scanf("%s", name);
                search_contact(head, name);
                break;
            case 6:
                printf("Exiting the program...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}
