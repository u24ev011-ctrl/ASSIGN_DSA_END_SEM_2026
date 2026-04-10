#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <iomanip>

using namespace std;

// Step 1: Define the Item structure
struct Item {
    int id;
    string name;
    string category;
    string status; // "LOST" or "FOUND"
    
    Item(int id, string n, string c, string s) : id(id), name(n), category(c), status(s) {}
};

// Step 2: Define the Tracker System using a Hash Table (unordered_map)
class LostAndFoundTracker {
private:
    // Hash Table: Key is Category, Value is a vector of Items
    unordered_map<string, vector<Item>> database;
    int nextId;

public:
    LostAndFoundTracker() {
        nextId = 101; // Starting ID for items
    }

    // Sub-problem: Item Insertion (Lost)
    void addLost(string name, string category) {
        Item newItem(nextId++, name, category, "LOST");
        database[category].push_back(newItem);
        cout << "[+] Reported LOST: " << name << " (ID: " << newItem.id << ", Category: " << category << ")\n";
    }

    // Sub-problem: Item Insertion (Found)
    void addFound(string name, string category) {
        Item newItem(nextId++, name, category, "FOUND");
        database[category].push_back(newItem);
        cout << "[+] Reported FOUND: " << name << " (ID: " << newItem.id << ", Category: " << category << ")\n";
        
        // Auto-trigger matching when a found item is added
        matchItems(category);
    }

    // Sub-problem: Searching by Category
    void searchByCategory(string category) {
        cout << "\n--- Search Results for Category: '" << category << "' ---\n";
        if (database.find(category) == database.end() || database[category].empty()) {
            cout << "No items found in this category.\n";
            return;
        }
        for (const auto& item : database[category]) {
            cout << "ID: " << item.id << " | Name: " << item.name << " | Status: " << item.status << "\n";
        }
        cout << "--------------------------------------------\n";
    }

    // Sub-problem: Matching logic
    void matchItems(string category) {
        cout << "\n[*] Running Matcher for Category: '" << category << "'...\n";
        if (database.find(category) == database.end()) return;

        vector<Item>& items = database[category];
        bool matchFound = false;

        // Simple nested loop to find Lost & Found items with similar names
        for (size_t i = 0; i < items.size(); i++) {
            if (items[i].status == "LOST") {
                for (size_t j = 0; j < items.size(); j++) {
                    if (items[j].status == "FOUND" && items[i].name == items[j].name) {
                        cout << "    [!] POSSIBLE MATCH FOUND!\n";
                        cout << "    LOST Item ID " << items[i].id << " (" << items[i].name << ") matches ";
                        cout << "FOUND Item ID " << items[j].id << " (" << items[j].name << ")\n";
                        matchFound = true;
                    }
                }
            }
        }
        if (!matchFound) {
            cout << "    No current matches in this category.\n";
        }
        cout << "\n";
    }
};

int main() {
    LostAndFoundTracker tracker;

    cout << "=======================================\n";
    cout << "  CAMPUS LOST & FOUND TRACKER SYSTEM\n";
    cout << "=======================================\n\n";

    // 1. Add some lost items
    tracker.addLost("Blue Water Bottle", "Accessories");
    tracker.addLost("Scientific Calculator", "Electronics");
    tracker.addLost("Hostel Room Keys", "Keys");

    // 2. Add some found items (Triggering matching)
    tracker.addFound("Hostel Room Keys", "Keys");
    tracker.addFound("Generic Black Wallet", "Accessories");
    tracker.addFound("Scientific Calculator", "Electronics");

    // 3. Search functionality
    tracker.searchByCategory("Electronics");
    tracker.searchByCategory("Books"); // Category with no items

    return 0;
}
