#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

// Define the structure for an Item
struct Item {
    int id;
    char category[50];
    char description[100];
    int isMatched; // 0 for unmatched, 1 for matched
};

// Global arrays to hold lost and found items
struct Item lostItems[MAX_ITEMS];
struct Item foundItems[MAX_ITEMS];

// Counters to keep track of the number of items
int lostCount = 0;
int foundCount = 0;
int currentId = 101; // Starting ID for items

// Function to add a lost item
void addLost() {
    if (lostCount >= MAX_ITEMS) {
        printf("Error: Lost items database is full!\n");
        return;
    }
    struct Item newItem;
    newItem.id = currentId++;
    newItem.isMatched = 0;

    printf("Enter Category (e.g., Electronics, Book, Clothing): ");
    scanf(" %49[^\n]", newItem.category); // Read string with spaces
    printf("Enter Description (Color, brand, etc.): ");
    scanf(" %99[^\n]", newItem.description);

    lostItems[lostCount] = newItem;
    lostCount++;
    printf("--> Lost item added successfully with ID: %d\n\n", newItem.id);
}

// Function to add a found item
void addFound() {
    if (foundCount >= MAX_ITEMS) {
        printf("Error: Found items database is full!\n");
        return;
    }
    struct Item newItem;
    newItem.id = currentId++;
    newItem.isMatched = 0;

    printf("Enter Category (e.g., Electronics, Book, Clothing): ");
    scanf(" %49[^\n]", newItem.category);
    printf("Enter Description (Color, brand, etc.): ");
    scanf(" %99[^\n]", newItem.description);

    foundItems[foundCount] = newItem;
    foundCount++;
    printf("--> Found item added successfully with ID: %d\n\n", newItem.id);
}

// Function to search items by category
void search() {
    char searchCat[50];
    printf("Enter Category to search: ");
    scanf(" %49[^\n]", searchCat);

    printf("\n--- Search Results for '%s' ---\n", searchCat);
    int foundFlag = 0;

    printf("[LOST ITEMS]\n");
    for (int i = 0; i < lostCount; i++) {
        if (strcasecmp(lostItems[i].category, searchCat) == 0) {
            printf("ID: %d | Desc: %s | Status: %s\n", 
                   lostItems[i].id, lostItems[i].description, 
                   lostItems[i].isMatched ? "Matched" : "Pending");
            foundFlag = 1;
        }
    }

    printf("\n[FOUND ITEMS]\n");
    for (int i = 0; i < foundCount; i++) {
        if (strcasecmp(foundItems[i].category, searchCat) == 0) {
            printf("ID: %d | Desc: %s | Status: %s\n", 
                   foundItems[i].id, foundItems[i].description, 
                   foundItems[i].isMatched ? "Matched" : "Pending");
            foundFlag = 1;
        }
    }

    if (!foundFlag) {
        printf("No items found in this category.\n");
    }
    printf("-------------------------------\n\n");
}

// Function to match lost items with found items based on category
void matchItems() {
    printf("\n--- Potential Matches ---\n");
    int matchFound = 0;

    for (int i = 0; i < lostCount; i++) {
        if (lostItems[i].isMatched == 1) continue; // Skip already matched items

        for (int j = 0; j < foundCount; j++) {
            if (foundItems[j].isMatched == 1) continue;

            // Simple match logic: If categories are the same (case-insensitive)
            if (strcasecmp(lostItems[i].category, foundItems[j].category) == 0) {
                printf("Potential Match found!\n");
                printf("LOST: ID %d - %s (%s)\n", lostItems[i].id, lostItems[i].category, lostItems[i].description);
                printf("FOUND: ID %d - %s (%s)\n", foundItems[j].id, foundItems[j].category, foundItems[j].description);
                
                // Allow user to confirm match
                char choice;
                printf("Confirm match? (y/n): ");
                scanf(" %c", &choice);
                if (choice == 'y' || choice == 'Y') {
                    lostItems[i].isMatched = 1;
                    foundItems[j].isMatched = 1;
                    printf("Items marked as matched!\n\n");
                    matchFound = 1;
                    break; // Move to next lost item
                } else {
                    printf("Match rejected. Continuing search...\n\n");
                }
            }
        }
    }

    if (!matchFound) {
        printf("No new matches found at this time.\n");
    }
    printf("-------------------------\n\n");
}

int main() {
    int choice;

    printf("==========================================\n");
    printf("   Campus Lost and Found Object Tracker   \n");
    printf("==========================================\n");

    while (1) {
        printf("Menu:\n");
        printf("1. Report a Lost Item\n");
        printf("2. Report a Found Item\n");
        printf("3. Search Items by Category\n");
        printf("4. Run Matcher (Find Matches)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addLost();
                break;
            case 2:
                addFound();
                break;
            case 3:
                search();
                break;
            case 4:
                matchItems();
                break;
            case 5:
                printf("Exiting Tracker. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n\n");
        }
    }
    return 0;
}
