#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

struct Record {
    int id;
    char name[50];
};

void readData(struct Record records[], int *count) {
    FILE *file = fopen("file.csv", "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }

    *count = 0;
    while (fscanf(file, "%d,%49[^\n]", &records[*count].id, records[*count].name) == 2) {
        (*count)++;
        if (*count >= MAX_RECORDS) {
            break;
        }
    }

    fclose(file);
}

void displayData(struct Record records[], int count) {
    printf("ID\tName\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\n", records[i].id, records[i].name);
    }
}

void searchData(struct Record records[], int count, int searchId) {
    for (int i = 0; i < count; i++) {
        if (records[i].id == searchId) {
            printf("Record found:\nID: %d\nName: %s\n", records[i].id, records[i].name);
            return;
        }
    }
    printf("Record not found.\n");
}

void sortData(struct Record records[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (records[j].id > records[j + 1].id) {
                struct Record temp = records[j];
                records[j] = records[j + 1];
                records[j + 1] = temp;
            }
        }
    }
    printf("Data sorted.\n");
}

void exportData(struct Record records[], int count) {
    FILE *file = fopen("file.csv", "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        return;
    }

    fprintf(file, "ID,Name\n");
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s\n", records[i].id, records[i].name);
    }

    fclose(file);
    printf("Data exported to %s.\n", file);
}

int main() {
    struct Record records[MAX_RECORDS];
    int key;
    int choice;

    do {
        printf("1. Dispaly data\n");
        printf("2. Search data\n");
        printf("3. Sort data\n");
        printf("4. Export data\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
               	displayData(records, key);
                break;
            case 2:
                printf("Enter the words to search: ");
                int a;
                scanf("%s", a);
                searchData (records, key, a);
                break;
            case 3:
                sortData (records, key);
                break;
            case 4:
                exportData (records, key);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);

    return 0;
}

