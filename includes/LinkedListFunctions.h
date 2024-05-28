#ifndef LINKEDLISTFUNCTIONS_H
#define LINKEDLISTFUNCTIONS_H

#include "contact.h"


//Linked List General Functions:
void _print_list(Contact* head);

//return ptr to key or NULL
Contact* _search_list(Contact* head, Name key){};

template <typename T>
Contact* _insert_head(Contact *&head, T insert_this);

//insert after ptr: insert head if marker null
template <typename T>
Contact* _insert_after(Contact*& head, Contact *after_this,T insert_this);

//insert before ptr: insert head if marker null
template <typename T>
Contact* _insert_before(Contact*& head, Contact* before_this, T insert_this);

//ptr to previous node
template <typename T>
Contact* _previous_node(Contact* prev_to_this);

//delete, return item
template <typename T>
T _delete_node(Contact*& head, Contact* delete_this);

//duplicate the list...
template <typename T>
Contact* _copy_list(Contact* head);

//duplicate the list, return pointer to last node in dest... 
template <typename T>
Contact *_copy_list(Contact *&dest, Contact*src);



//delete all the nodes
template <typename T>
void _clear_list(Contact*& head);

//_item at this position
template <typename T>
T& _at(Contact* head, int pos);



#endif