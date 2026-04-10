#ifndef TRACKER_H
#define TRACKER_H

#include <iostream>
#include <string>

using namespace std;

// Maximum items the database can hold (Basic Concept: Array size)
const int MAX_ITEMS = 1000;

// 1. Basic Struct Definition
struct Item {
    int id;
    string name;
    string category;
    string status; // "LOST" or "FOUND"
    
    // Default constructor needed for basic arrays
    Item() {
        id = 0;
        name = "";
        category = "";
        status = "";
    }
    
    // Parameterized constructor
    Item(int i, string n, string c, string s) {
        id = i;
        name = n;
        category = c;
        status = s;
    }
};

// 2. Class using an Array of Structs
class LostAndFoundTracker {
private:
    Item database[MAX_ITEMS]; // Basic Concept: Array instead of map/vector
    int itemCount;            // Keep track of how many items are in the array
    int nextId;

public:
    LostAndFoundTracker() {
        itemCount = 0;
        nextId = 101;
    }

    void addLost(string name, string category) {
        if (itemCount >= MAX_ITEMS) {
            cout << "Database is full!\n";
            return;
        }
        database[itemCount] = Item(nextId++, name, category, "LOST");
        cout << "[+] Reported LOST: " << name << " (ID: " << database[itemCount].id << ")\n";
        itemCount++; // Increase the size tracker
    }

    void addFound(string name, string category) {
        if (itemCount >= MAX_ITEMS) {
            cout << "Database is full!\n";
            return;
        }
        database[itemCount] = Item(nextId++, name, category, "FOUND");
        cout << "[+] Reported FOUND: " << name << " (ID: " << database[itemCount].id << ")\n";
        itemCount++;
        
        // Auto-trigger match when something is found
        matchItems(category);
    }

    void searchByCategory(string category) {
        cout << "\n--- Search Results for: '" << category << "' ---\n";
        bool foundAny = false;
        
        // Basic linear search through the array
        for (int i = 0; i < itemCount; i++) {
            if (database[i].category == category) {
                cout << "ID: " << database[i].id << " | Name: " << database[i].name 
                     << " | Status: " << database[i].status << "\n";
                foundAny = true;
            }
        }
        
        if (!foundAny) {
            cout << "No items found in this category.\n";
        }
        cout << "--------------------------------------\n";
    }

    void matchItems(string category) {
        cout << "\n[*] Checking matches for category '" << category << "'...\n";
        bool matchFound = false;

        // Basic nested loops to compare items in the array
        for (int i = 0; i < itemCount; i++) {
            if (database[i].category == category && database[i].status == "LOST") {
                
                for (int j = 0; j < itemCount; j++) {
                    if (database[j].category == category && 
                        database[j].status == "FOUND" && 
                        database[i].name == database[j].name) {
                        
                        cout << "    [!] MATCH: LOST ID " << database[i].id 
                             << " == FOUND ID " << database[j].id << "\n";
                        matchFound = true;
                    }
                }
            }
        }
        
        if (!matchFound) {
            cout << "    No current matches.\n";
        }
        cout << "\n";
    }
};

#endif
