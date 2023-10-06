//ROURE Amandine
#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


// constructs a new (empty) list
List *list_create(void) {
    List *l = malloc(sizeof(List));
    l->first = l->last = NULL;
    return l;
}

// counts the items on a list
size_t list_count(const List *list) {
    size_t count = 0;

    ListNode *p=list->first;
    while(p!=NULL) {
        count++;
        p=p->next;
    }

    return count;
}

// inserts item_data at *end* of a list
void list_addlast(List *list, data_t item_data) {
    ListNode *t=list->last;
    ListNode *p=((list->last)->next);
    p->data=item_data;
    p->prev=t;
    p->next=NULL;
}

// removes the item from *end* of the list and returns its value
data_t list_rmlast(List *list) {
    ListNode *t=list->last;
    ListNode *p=((list->last)->prev);
    t=p;
    p->next=NULL;
    return list;
}

void list_print(List *l){
    ListNode *p=l->first;
    int el=(l->first)->data;
    while (el!=NULL){
        printf("%d", el);
        p=p->next;
        el=p->data;
    }
}

void detruire(List *l){
    ListNode *p=l->first;
    int el=(l->first)->data;
    while (el!=NULL){
        ListNode *g=p;
        free(p->data);
        free(p);
        p=g->next;
        el=p->data;
    }
}



int main(void) {

    List *l = list_create();

    assert(list_count(l)==0);

    list_addlast(l,10);
    list_addlast(l,20);
    list_addlast(l,30);
    list_addlast(l,40);

    assert(list_count(l)==4);

    list_print(l);

    data_t t =  list_rmlast(l);

    assert(t==40);
    list_print(l);
    detruire(l);

    return 0;
}