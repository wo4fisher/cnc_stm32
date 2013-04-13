/*
 * Simple doubly linked list.
 */

#ifndef _LIST_H_
#define _LIST_H_

#include "system.h"

typedef time list_sort_order;

/**
 * A list element representation
 */
typedef struct element_s
{
  /* Linked list next element */
  struct element_s* next;
  /* Linked list previous element */
  struct element_s* prev;
  /* Sort order */
  list_sort_order sort_order;
} element_t;

/**
 * A list representation
 */
typedef struct list_s
{
  /* The first element in queue */
  element_t* first_element;
  /* The last element in queue */
  element_t* last_element;
  u32_t length;
} list_t;

/**
 * Checks if list is empty
 */
#define list_empty(alist) \
  ((alist)->first_element == NULL)
/**
 * Returns first element in list
 */
#define list_first(alist) \
  ((alist)->first_element)
/**
 * Returns last element in list
 */
#define list_last(alist) \
  ((alist)->last_element)
/**
 * Checks if list contains only one element
 */
#define list_size_one(alist) \
  ((alist)->last_element == (alist).first_element)
/**
 * Returns list size
 */
#define list_count(alist) \
  ((alist)->length)

/**
 * Returns element succeeding given element, or null if element is last
 */
#define list_next(aelement) \
  (((element_t*)(aelement))->next)
/**
 * Returns element preceding given element, or null if element is first
 */
#define list_prev(aelement) \
  (((element_t*)(aelement))->prev)
/**
 * Returns order of element
 */
#define list_get_order(aelement) \
  (((element_t*)(aelement))->sort_order)
/**
 * Sets order of element
 */
#define list_set_order(aelement, aorder) \
  do { ((element_t*)(aelement))->sort_order = (aorder); } while(0)

/**
 * Initilizes a list
 */
void list_init(list_t* list);
/**
 * Adds an element to end of list
 */
void list_add(list_t* list, void* element);
/**
 * Inserts element before specified element
 */
void list_insert(list_t* list, void* element, void* element_before);
/**
 * Deletes element from list
 */
void list_delete(list_t* list, void* element);
/**
 * Inserts element in list sorted on elements ascending order
 */
void list_sort_insert(list_t* list, void* element);
/**
 * Moves all elements in list src to list dst, list 2 becomes empty
 */
void list_move(list_t* l_dst, list_t* l_src);

#endif /*_LIST_H_*/
