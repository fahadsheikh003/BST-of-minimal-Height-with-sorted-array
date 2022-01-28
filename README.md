# BST-of-minimal-Height-with-sorted-array

# Problem:
Given a sorted (increasing order) array with unique integer elements, write a function to create a binary search tree with minimal height. The array will be passed as an argument to the function and the function would return the height of the created tree.

# Explanation of Implementation:
I have applied the divide & conquer technique. I, recursively, calculated the mid of the array and inserted the that middle element into the Binary Search Tree. As we know in binary search tree, we insert lower element into left subtree and higher element into right subtree. So, when we calculated the mid of the array, we divided the array into half and inserted our middle element into the array. At this point we have the middle element as the root of the tree. Then I called the function by changing highest index with one reduced from the middle index of the array and repeated the process above. Similarly, the case for right side of the array is the same as stated above.
