// 152 Why Quicksort is preferred for. Arrays and Merge Sort for LinkedLists ?

// https://www.codingninjas.com/codestudio/library/why-is-quick-sort-preferred-for-arrays-and-merge-sort-for-linked-lists

// Introduction

// Both quicksort and mergesort algorithms are based on the divide and conquer approach. The quick sort is an internal sorting algorithm where the data is sorted in the main memory. In contrast, merge sort is an external sorting algorithm in which the data cannot be stored in the main memory and thus requires an auxiliary memory for sorting the algorithm.

// In quick sort, the arrays are divided into any ratio as there is no compulsion to divide them into equal parts. Whereas in merge sort, the array is divided into two halves only.

// Merge sort is more stable than quick sort, as two elements having equal values appear in the same order in the sorted output as they were in the unsorted input. Quick sort becomes unstable for this scenario. But we can make it stable by making some changes in the code.

// The worst-case complexity of quick sort is O(n^2), as there is a need for many comparisons in the worst condition. In merge sort, worst and average cases have the same complexities O(n*log n).

// Why is Quick Sort preferred for Arrays?

// No other sorting algorithm performs better than Quick sort on Arrays because of the following reasons:

//     Quick sort is an in-place sorting algorithm, i.e. which means it does not require any additional space, whereas Merge sort does, which can be rather costly. In merge sort, the allocation and deallocation of the excess space increase the execution time of the algorithm.

//     The locality of reference is one of the critical reasons for quick sort’s efficiency. It allows the computer system to access memory locations close to each other, which is faster than memory locations distributed throughout the memory, as in the case of merge sort.

//     Quick sort is most commonly implemented using a randomized version with anticipated time complexity of O(NlogN). Although the worst case is possible in the randomized version, it does not occur for a specific pattern (such as a sorted array). Hence the randomized quick sort works well in practice.

// Why is Merge-Sort preferred for Linked Lists?

// No other sorting algorithm performs better than Merge Sort on Linked Lists because of the following reasons:

//     If we have to access an ith index in a linked list using quicksort, we will have to travel every node from the head node to the ith node as we do not have a contiguous memory block. As a result, the cost of quicksort rises. Whereas merge sort sequentially accesses data, therefore the need for random access is low.

//     It might happen that the nodes in linked lists may not be present in nearby memory locations, therefore Merge Sort is preferred.

//     Unlike arrays, in linked lists, we can insert elements in the middle in O(1) extra space and O(1) time complexities if we are given a reference/pointer to the previous node. As a result, we can implement the merge operation in the merge sort without using any additional space.

//     Merge sort is preferred when stable sorting is needed. Stable Sorting means the order of elements with the same value remains the same after the elements have been sorted. This is significant as elements will have auxiliary data that is additional data associated with the element. Quick Sort is an unstable sorting algorithm, whereas Merge Sort is a stable method. Although Quick Sort can be adjusted to become a stable sorting algorithm, such modifications are inefficient and should not be employed.