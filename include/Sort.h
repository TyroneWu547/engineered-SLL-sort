/**
 * @file Sort.h
 * @author Andrew Sauerbrei
 *         AJ Bulthuis
 *         Tyrone Wu
 * @brief Class for bringing in the sort functionality to main.
 * 
 */

#ifndef SORT_H
#define SORT_H

#include "LinkedList.h"

/**
 * @brief Sort function to be implemented.
 * 
 * @param list the linked list to be sorted
 * @param k the block size of when to switch to insertion sort. If -1, only perform main sort function
 */
void sort(LinkedList* list, int k);

#endif // SORT_H