#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    struct Node* prev;
    struct Node* next;
};

struct Node* create_node(char* name) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    strcpy(new_node->name, name);
    new_node->prev = new_node->next = NULL;
    return new_node;
}

void insert_contact(struct Node** head, char* name, int position) {
    struct Node* new_node = create_node(name);
    struct Node* temp = *head;

    if (position == 0) {
        if (*head != NULL) 
        (*head)->prev = new_node;
        new_node->next = *head;
        *head = new_node;
        return;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds!\n");
        return;
    }

    new_node->next = temp->next;
    new_node->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = new_node;
    }
    temp->next = new_node;
}

void delete_by_position(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node* temp = *head;

    if (position == 0) {
        *head = temp->next;
        if (*head != NULL) (*head)->prev = NULL;
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < position; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds!\n");
        return;
    }

    if (temp->next != NULL) 
    temp->next->prev = temp->prev;
    if (temp->prev != NULL) 
    temp->prev->next = temp->next;

    free(temp);
}

void delete_by_name(struct Node** head, char* name) {
    struct Node* temp = *head;

    while (temp != NULL && strcmp(temp->name, name) != 0) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Contact not found!\n");
        return;
    }

    if (temp->prev != NULL) 
    temp->prev->next = temp->next;
    if (temp->next != NULL) 
    temp->next->prev = temp->prev;

    if (temp == *head) 
    *head = temp->next;

    free(temp);
}

void traverse_forward(struct Node* head) {
    struct Node* temp = head;
    printf("Contact list (forward): ");
    while (temp != NULL) {
        printf("%s <-> ", temp->name);
        temp = temp->next;
    }
    printf("NULL\n");
}

void traverse_backward(struct Node* head) {
    struct Node* temp = head;

    if (temp == NULL) {
        printf("Contact list is empty.\n");
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("Contact list (backward): ");
    while (temp != NULL) {
        printf("%s <-> ", temp->name);
        temp = temp->prev;
    }
    printf("NULL\n");
}

void search_contact(struct Node* head, char* name) {
    struct Node* temp = head;
    int position = 0;

    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("%s found at position %d\n", name, position);
            return;
        }
        temp = temp->next;
        position++;
    }

    printf("Contact not found!\n");
}

void create_list(struct Node** head, int n) {
    char name[50];
    for (int i = 0; i < n; i++) {
        printf("Enter contact name %d: ", i + 1);
        scanf("%s", name);
        insert_contact(head, name, i);
    }
}

int main() {
    struct Node* head = NULL;
    int choice, num_contacts, position;
    char name[50];
    char delete_choice;

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
                printf("Enter the contact's name to insert: ");
                scanf("%s", name);
                printf("Enter the position (0-based index) to insert the contact: ");
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
                } else if (delete_choice == 'p') {
                    printf("Enter the position of the contact to delete: ");
                    scanf("%d", &position);
                    delete_by_position(&head, position);
                }
                break;

            case 4:
                traverse_forward(head);
                traverse_backward(head);
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

    return 0;
}
