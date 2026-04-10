# Lost-and-Found Object Tracker

**Group 8**  
**Roll No.:** U24ev018, U24ev011, U24ev001, U24ev027  
**Course:** 2nd Year Data Structures / C Programming Project

## 1. Problem Breakdown
The college campus needs a system to store and match lost and found items. We broke the problem down into the following sub-problems:
- **Item Storage:** How to store the details of an item (ID, Category, Description, Status).
- **Add Operations:** Separate functions for `add-lost` and `add-found` to categorize incoming reports.
- **Search Operation:** Searching for an item by its ID or Category to quickly retrieve details.
- **Match Operation:** Comparing the "Lost" list with the "Found" list based on Category and Description to find potential matches.

## 2. Proposed Approaches
To solve this, we considered three data structure approaches:
1. **Array of Records (Structs):** 
   - Uses a fixed-size array to store items. 
   - *Pros:* Extremely simple to implement, fast $O(1)$ insertion at the end, easy to iterate. 
   - *Cons:* Fixed memory size; moving elements can be costly if we need to delete.
2. **Linked List:**
   - Uses nodes linked via pointers.
   - *Pros:* Dynamic memory allocation (grows as needed), no wasted space.
   - *Cons:* Sequential search is strictly $O(N)$, slightly more complex to code due to pointers.
3. **Binary Search Tree (BST) / Hash Table:**
   - *Pros:* Very fast searching $O(\log N)$ or $O(1)$.
   - *Cons:* Overly complex for a simple campus system with a small number of items. "Fuzzy matching" descriptions is hard in a standard BST/Hash Table.

## 3. Justification of Final Choice
We chose the **Array of Records (Structs)** approach. 
*Reasoning:* For a 2nd-year college project, simplicity and correctness are the top priorities. The campus lost-and-found will likely not exceed a few hundred active items at a time, making an Array perfectly efficient. It provides $O(1)$ insertion at the tail and makes iterating through items to fuzzy-match strings (like categories and descriptions) very straightforward using basic C loops.

## 4. Complexity Table

| Operation | Time Complexity | Space Complexity | Explanation |
| :--- | :---: | :---: | :--- |
| **Add Lost Item** | $O(1)$ | $O(1)$ | Inserted at the end of the `lostItems` array. |
| **Add Found Item** | $O(1)$ | $O(1)$ | Inserted at the end of the `foundItems` array. |
| **Search (by ID/Category)**| $O(N)$ | $O(1)$ | Linear scan through the array to find the match. |
| **Match Items** | $O(L \times F)$ | $O(1)$ | Compares every Lost item ($L$) with every Found item ($F$). |

## 5. Output Screenshots
*(Note for students: Compile the C program, run it, test the menu options, and paste your console screenshots here!)*
