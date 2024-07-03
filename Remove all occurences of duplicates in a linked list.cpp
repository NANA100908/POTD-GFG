Problem :- Given a sorted linked list, delete all nodes that have duplicate numbers (all occurrences), leaving only numbers that appear once in the original list, and return the head of the modified linked list. 

Intiution :- 

The problem is to remove all nodes from a sorted linked list that have duplicate values, leaving only nodes with unique values. Given that the list is sorted, duplicates will always be contiguous, which simplifies the detection and removal process.
The key intuition behind the solution is to leverage the sorted property of the linked list to easily identify and handle duplicates. By maintaining a reference to the previous node, we can efficiently remove nodes when duplicates are detected.

Let's apply the algorithm to the given linked list: 23 -> 28 -> 28 -> 35 -> 49 -> 49 -> 53 -> 53.

Step-by-Step Execution

  1. Initialization
      1. head = 23, prev = NULL, curr = 23, num = -1e9.
  2. Traverse the Linked List:
      1. Node 23:
          1. curr = 23, curr->next = 28.
          2. 23 is not a duplicate (since 23 != 28).
          3. Move prev to 23, move curr to 28.
      2. Node 28:
          1. curr = 28, curr->next = 28.
          2. 28 is a duplicate (since 28 == 28).
          3. Skip the next node: curr->next = curr->next->next (28 -> 35).
          4. Update num = 28.
          5. Move curr to 28 (next duplicate 28).
      3. Node 28 (next duplicate 28):
          1. curr = 28, curr->next = 35.
          2. num == 28, so remove this node:
          3. prev->next = curr->next (23 -> 35).
          4. Reset num = -1e9.
          5. Move curr to 35.
      4. Node 35:
          1. curr = 35, curr->next = 49.
          2. 35 is not a duplicate (since 35 != 49).
          3. Move prev to 35, move curr to 49.
      5. Node 49:
          1. curr = 49, curr->next = 49.
          2. 49 is a duplicate (since 49 == 49).
          3. Skip the next node: curr->next = curr->next->next (49 -> 53).
          4. Update num = 49.
          5. Move curr to 49 (next duplicate 49).
      6. Node 49 (next duplicate 49):
          1. curr = 49, curr->next = 53.
          2. num == 49, so remove this node:
          3. prev->next = curr->next (35 -> 53).
          4. Reset num = -1e9.
          5. Move curr to 53.
      7. Node 53:
          1. curr = 53, curr->next = 53.
          2. 53 is a duplicate (since 53 == 53).
          3. Skip the next node: curr->next = curr->next->next (53 -> NULL).
          4. Update num = 53.
          5. Move curr to 53 (next duplicate 53).
      8. Node 53 (next duplicate 53):
          1. curr = 53, curr->next = NULL.
          2. num == 53, so remove this node:
          3. prev->next = curr->next (35 -> NULL).
          4. Reset num = -1e9.
          5. Move curr to NULL.
  3. Completion:
      1. The traversal is complete.
      2. The modified linked list is: 23 -> 35.

Algorithm :-

1. Initialization:
    1. prev is a pointer to the previous node, initially set to NULL.
    2. curr is a pointer to the current node, initially set to head.
    3. num is a variable to track the last duplicate number, initialized to a very small number (-1e9).
2. Traversal:
    1. The algorithm traverses the linked list using the curr pointer.
    2. If the current node and the next node have the same data, it's identified as a duplicate. The algorithm skips the next node and updates num to the duplicate value.
3. Handling Non-Duplicate Nodes:
    1. If the current node's data matches num (the last duplicate value), it's a duplicate node, and the algorithm removes it.
    2. If there's no previous node (prev is NULL), the head is updated to the next node.
    3. Otherwise, the previous node's next is updated to skip the current node.
    4. If the current node's data doesn't match num, it's not a duplicate. The algorithm moves the prev pointer to the current node.
5. Final Step:
    1. The algorithm returns the modified head of the linked list after removing all duplicates.
 

C++ Code :-

    Node* removeAllDuplicates(struct Node* head) {
        // Initialize pointers
        Node *prev = NULL, *curr = head;
        // This variable will keep track of the last duplicate number we encountered
        int num = -1e9;
        
        // Traverse the linked list
        while (curr) {
            // If the current node and the next node have the same data, it's a duplicate
            if (curr->next && curr->data == curr->next->data) {
                // Skip the next node
                curr->next = curr->next->next;
                // Store the duplicate number
                num = curr->data;
            } 
            else {
                // If the current node's data matches the last duplicate number, remove it
                if (num == curr->data) {
                    // If there's no previous node, update the head to the next node
                    if (!prev) {
                        head = curr->next;
                    } 
                    else {
                        // Otherwise, link the previous node to the next node
                        prev->next = curr->next;
                    }
                    // Reset the duplicate number
                    num = -1e9;
                    // Move to the next node
                    curr = curr->next;
                } 
                else {
                    // If it's not a duplicate, move the previous pointer to the current node
                    prev = curr;
                    // Move to the next node
                    curr = curr->next;
                }
            }
        }
        // Return the modified head of the linked list
        return head;
    }

Time Complexity :- O(n)
Space Complexity :- O(1)
