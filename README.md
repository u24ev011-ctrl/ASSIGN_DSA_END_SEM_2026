# ASSIGN_DSA_END_SEM_2026


# Lost-and-Found Object Tracker 🔍
**Group 8 | DSA End Semester Project 2026**
**Roll Numbers:** U24ev018, U24ev011, U24ev001, U24ev027

## 1. Problem Statement & Constraints
A college campus requires a system to store and quickly match lost and recovered items. 
**Constraints observed:**
- **Volume:** High number of item descriptions.
- **Uncertainty:** Matches might not be exact (relying on categories/types).
- **Speed:** Quick retrieval is necessary for a responsive user experience.

## 2. Sub-problems Identified
1. **Item Insertion:** Adding new lost or found items efficiently.
2. **Category-based Storage:** Grouping similar items (e.g., Electronics, Books, Keys) to narrow down searches.
3. **Searching:** Looking up items by ID, name, or type.
4. **Matching:** Comparing newly found items against the existing lost items database.

## 3. Proposed Approaches
### Approach 1: Linked List / Array of Records
- **Mechanism:** Store all lost and found items in a single sequential list.
- **Pros:** Very simple to implement. 
- **Cons:** Searching and matching take **O(N)** time, which becomes slow as the database grows.

### Approach 2: Hash Table by Category (Chaining)
- **Mechanism:** Use a Hash Table where the "Key" is the item category (e.g., "Electronics") and the "Value" is a Linked List (or dynamic array) of items in that category.
- **Pros:** Narrows down the search space. Searching for a matching item in the same category takes **O(K)** time, where K is the number of items in that specific category (K << N).
- **Cons:** Slightly higher memory overhead and hash collision management.

## 4. Final Choice & Justification
We chose **Approach 2: Hash Table by Category**.
- **Search Speed:** Faster than an array. Instead of searching 1,000 mixed items, we only search the 50 items in the "Books" category.
- **Memory Usage:** O(N) memory, which is highly efficient and scalable.
- **Update Frequency:** Insertions (add-lost, add-found) are **O(1)** on average, making it perfect for frequent updates.

## 5. Complexity Table

| Operation | Array/Linked List | Hash Table (Chosen) | BST by ID |
| :--- | :--- | :--- | :--- |
| **Add Item** | O(1) | **O(1)** average | O(log N) |
| **Search by ID** | O(N) | **O(N)** (if unindexed) | O(log N) |
| **Search by Category**| O(N) | **O(1)** to find category | O(N) |
| **Match Items** | O(N^2) | **O(K^2)** (K = items/category)| O(N log N) |

*Note: K is the number of items in a specific category. Since K is much smaller than N, matching is significantly faster.*
