# Lost-and-Found Object Tracker

**Group 8**  
**Roll No.:** U24ev018 (Arush Poonia), U24ev011 (Aman Gupta), U24ev001 (Jayant Kumawat), U24ev027 (Sneha Ahir)  
**Course:** B.Tech in Electronics and VLSI (2nd year)

## 1. Problem Breakdown
Basically, our college campus needs a simple system to keep track of lost and found stuff, and match them up if someone finds what another person lost. Before writing the code, we divided the problem into these main parts:
- **Storing Data:** How do we actually save an item's details (like its ID, category, what it looks like, and if it's been returned)?
- **Taking Inputs:** We need separate functions for `add-lost` and `add-found` so things don't get mixed up.
- **Searching:** A way to quickly search through the list by category (like "Electronics" or "Books").
- **The Matcher:** The main logic that checks the "Lost" list against the "Found" list and sees if the categories match up.

## 2. Proposed Approaches
When deciding how to code this, we thought about three different data structures we learned about:

1. **Arrays and Structs:** 
   - Just making an array of a custom `struct`.
   - *Pros:* Super easy to write and understand. Adding a new item at the end is instant ($O(1)$).
   - *Cons:* We have to give it a fixed size (like 100 items maximum), so it wastes a little bit of memory if the array isn't full.
2. **Linked Lists:**
   - Using nodes and pointers to link items together.
   - *Pros:* Dynamic size, so it only uses exactly as much memory as it needs.
   - *Cons:* Pointers can be annoying to debug (segmentation faults!), and searching still requires checking every single node one by one.
3. **Binary Search Tree (BST) or Hash Tables:**
   - *Pros:* Super fast searching ($O(\log N)$ or $O(1)$).
   - *Cons:* Way too overcomplicated for what we need. It's hard to do "fuzzy" string matching (like checking descriptions) with normal hash tables.

## 3. Justification of Final Choice
We decided to go with the **Array of Structs**. 
*Why?* Honestly, for a 2nd-year project—especially since our core branch is Electronics and VLSI—simplicity and getting a bug-free working code was our top priority. Our campus lost-and-found probably won't have more than a hundred active items at a time anyway. Using basic arrays lets us use simple `for` loops to compare strings without overcomplicating things with pointers or complex tree logic.

## 4. Complexity Breakdown
Here is the time and space complexity for how our code runs:

| Operation | Time Complexity | Space Complexity | Explanation |
| :--- | :---: | :---: | :--- |
| **Add Lost Item** | $O(1)$ | $O(1)$ | We just put it at the very end of the `lost_arr` array. |
| **Add Found Item** | $O(1)$ | $O(1)$ | Placed at the end of the `found_arr` array. |
| **Search (by Category)**| $O(N)$ | $O(1)$ | We use a loop to check every item in the array to see if the category matches. |
| **Match Items** | $O(L \times F)$ | $O(1)$ | Uses a nested loop. It compares every Lost item ($L$) with every Found item ($F$). |

## 5. Output Screenshots
*(Below are the screenshots from our terminal showing the code compiling, adding items, and successfully matching a lost item with a found item!)*

[//]: # (Hey team, don't forget to paste the images of the terminal output here before submitting!)
