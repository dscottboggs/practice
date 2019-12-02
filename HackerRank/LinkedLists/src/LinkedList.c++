#include <bits/stdc++.h>

using namespace std;


class SLLNode {
    public:
        int data;
        SLLNode *next;

        SLLNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
        SLLNode(int node_data, SLLNode *next_node){
            this->data = node_data;
            this->next = next_node;
        }
};

class SinglyLinkedList {
    public:
        SLLNode *head;
        SLLNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }
        SinglyLinkedList(SLLNode* head){
            this->head = head;
            this->tail = getTail(head);
        }
        SLLNode* getTail(){ return getTail(this->head); }
        SLLNode* getTail(SinglyLinkedList* list){ return getTail(list->head); }
        SLLNode* getTail(SLLNode* head){
            if( ! head ){ return NULL; }
            SLLNode *element = head;
            while(element->next){
                // get the next element until there are no more.
                element = element->next;
            }
            return element;
        }
        SinglyLinkedList* append(SLLNode* node){
            // Add a node to the tail of the list.
            // The node may have child nodes.
            SinglyLinkedList *newList;
            if(!this->head){
                newList = new SinglyLinkedList(node);
            } else {
                newList = new SinglyLinkedList(this->head);
                getTail(newList)->next = node;
            }
            return newList;
        }
        SinglyLinkedList* append(int data){
            // create a new node at the tail holding the data specified.
            return append(new SLLNode(data));
        }
        SinglyLinkedList* prepend(SLLNode* node){
            // Add this node to the head of the list.
            // The node may have child nodes.
            getTail(node)->next = this->head;
            SinglyLinkedList *newList = new SinglyLinkedList(node);
            return newList;
        }
        SinglyLinkedList* prepend(int data){
            return this->prepend(new SLLNode(data));
        }
        SinglyLinkedList* insertAt(
            SLLNode* node, int position
        ){
            SLLNode* tailOfNode = getTail(node);
            int index=0;
            SLLNode* workingNode = this->head;
            SinglyLinkedList* outlist = new SinglyLinkedList();
            while ( index < position ){
                if ( !workingNode->next){
                    std::cout   << "Specified position "
                                << std::to_string(position)
                                << " is greater than the length of this list("
                                << std::to_string(index)
                                << "). No changes made."
                                << '\n';
                    return this;
                }
                index++;
                outlist->append(new SLLNode(workingNode->data));
                workingNode = workingNode->next;
            }
            outlist->append(node);
            outlist->append(workingNode);
            return outlist;
        }
        SinglyLinkedList* insertAt(int node_data, int position){
            return insertAt(new SLLNode(node_data), position);
        }
        SinglyLinkedList* deleteAt(int position){
            /* Implementation tested on hackerrank site.
https://www.hackerrank.com/challenges/delete-a-node-from-a-linked-list/problem
            */
            int index = 0;
            SLLNode* workingNode = this->head;
            SinglyLinkedList* output = new SinglyLinkedList();
            while (index < position) {
                if ( ! workingNode->next ) {
                    std::cout   << "Specified position "
                                << std::to_string(position)
                                << " is greater than the length of this list("
                                << std::to_string(index)
                                << "). No changes made."
                                << '\n';
                    return this;
                }
                index++;
                output->append(new SLLNode(workingNode->data));
                workingNode = workingNode->next;
            }
            workingNode = workingNode->next; // skip this one
            output->append(workingNode);
            return output;
        }
};


void free_singly_linked_list(SLLNode* node) {
    while (node) {
        SLLNode* temp = node;
        node = node->next;
        free(temp);
    }
}


void free_singly_linked_list(SinglyLinkedList* list){
    if(list->head){
        free_singly_linked_list(list->head);
    }
    free(list);
}


void printLinkedList(SLLNode *head){
  if ( head == NULL ){
    std::cout << "NULL\n";
  }
  SLLNode *element = head;
  while (element->next != NULL) {
    std::cout << element->data << '\n';
    element = element -> next;
  }
  std::cout << element->data << '\n';
}
