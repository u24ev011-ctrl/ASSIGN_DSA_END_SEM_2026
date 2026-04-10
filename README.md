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
   - *Cons:* Pointers can be annoying to debug (segmentation faults!),
