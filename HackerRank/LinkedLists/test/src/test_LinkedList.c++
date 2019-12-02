#define CATCH_CONFIG_MAIN
#include <stdlib.h>
#include <catch/catch.hpp>
#include "/home/scott/Documents/code/HackerRank/LinkedLists/src/LinkedList.c++"

int VAL_0 = 0;
int VAL_1 = 1;
int VAL_2 = 2;
int VAL_3 = 3;
int VAL_I = 10;

SCENARIO("An SLLNode object", "[SLLNode]"){
    GIVEN("A node with data but no next node"){
        SLLNode* testNode = new SLLNode(VAL_1);
        REQUIRE( testNode->data == VAL_1);
        REQUIRE( ! testNode->next );
        WHEN("A node is added"){
            testNode->next = new SLLNode(VAL_2);
            THEN("The second node is present."){
                REQUIRE( testNode->next->data == VAL_2);
            }
        }
        free_singly_linked_list(testNode);
    }
    GIVEN("Two interconnected nodes"){
        SLLNode* testNode = new SLLNode(VAL_1, new SLLNode(VAL_2));
        THEN("The head node has the first value specified."){
            REQUIRE(testNode->data == VAL_1);
        }
        THEN("The second node is referenced by the first"){
            REQUIRE(testNode->next->data == VAL_2);
        }
        THEN("The second node's 'next' value isn't present."){
            REQUIRE(!testNode->next->next);
        }
        WHEN("A value is added"){
            testNode->next->next = new SLLNode(3);
            THEN("The new element is at the tail"){
                REQUIRE(testNode->next->next->data == 3);
                REQUIRE(!testNode->next->next->next);
            }
            THEN("The values are as expected."){
                int c = VAL_1;
                SLLNode *element = testNode;
                while (element) {
                    REQUIRE(element->data == c);
                    element = element->next;
                    c++;
                }
            }
        }
        free_singly_linked_list(testNode);
    }
}
SCENARIO("A SinglyLinkedList", "[SinglyLinkedList]"){
    GIVEN("An empty list"){
        SinglyLinkedList *list = new SinglyLinkedList();
        THEN("The head and tail are both null"){
            REQUIRE( ! list->head );
            REQUIRE( ! list->tail );
        }
        WHEN("A value is appended"){
            SinglyLinkedList* changedList = list->append(VAL_1);
            THEN("The head points at the new node, which has no 'next'."){
                REQUIRE(  changedList->head->data  == VAL_1 );
                REQUIRE( !changedList->head->next );}
            THEN("The tail is the same as the head, and has the data"){
                REQUIRE(  changedList->tail         == changedList->head );
                REQUIRE(  changedList->tail->data   == VAL_1 );}
            THEN("The tail has no next."){
                REQUIRE( !changedList->tail->next );}
        }
        WHEN("A node is appended."){
            SLLNode *node           = new SLLNode(VAL_1);
            SinglyLinkedList *list  = new SinglyLinkedList(node);
            SinglyLinkedList* changedList = list->append(node);
            THEN("The head is that node."){
                REQUIRE( changedList->head == node );
                REQUIRE( changedList->head->data == node->data);
                REQUIRE( changedList->head->data == VAL_1);}
            THEN("The tail is that node"){
                REQUIRE( changedList->tail == node );
                REQUIRE( changedList->tail->data == node->data );
                REQUIRE( changedList->tail->data == VAL_1 );}
            THEN("The and tail have no next values."){
                REQUIRE( !changedList->tail->next );
                REQUIRE( !changedList->head->next );
            }
        }
        WHEN("A node is prepended"){
            SinglyLinkedList *list = new SinglyLinkedList();
            SLLNode *node = new SLLNode(VAL_0);
            SinglyLinkedList* changedList = list->prepend(node);
            THEN("The head is that node."){
                REQUIRE( changedList->head == node );
                REQUIRE( changedList->head->data == node->data);
                REQUIRE( changedList->head->data == VAL_1);}
            THEN("The tail is that node"){
                REQUIRE( changedList->tail == node );
                REQUIRE( changedList->tail->data == node->data );
                REQUIRE( changedList->tail->data == VAL_1 );}
            THEN("The and tail have no next values."){
                REQUIRE( !changedList->tail->next );
                REQUIRE( !changedList->head->next );
            }
        }
        WHEN("A value is prepended"){
            SinglyLinkedList *list = new SinglyLinkedList();
            SinglyLinkedList* changedList = list->prepend(VAL_1);
            THEN("The head points at the new node, which has no 'next'."){
                REQUIRE(  changedList->head->data  == VAL_1 );
                REQUIRE( !changedList->head->next );}
            THEN("The tail is the same as the head, and has the data"){
                REQUIRE(  changedList->tail         == changedList->head );
                REQUIRE(  changedList->tail->data   == VAL_1 );}
            THEN("The tail has no next."){
                REQUIRE( !changedList->tail->next );}
        }
    }
    GIVEN("A list with a single node"){
        SLLNode *node = new SLLNode(VAL_1);
        SinglyLinkedList *list = new SinglyLinkedList(node);
        THEN("The head and tail both match that node"){
            REQUIRE(  list->head == node );
            REQUIRE(  list->tail == node );
            REQUIRE(  list->head == list->tail );
            REQUIRE(  list->head->data == node->data );
            REQUIRE(  list->tail->data == node->data );
            REQUIRE( !list->head->next );
            REQUIRE( !list->tail->next );
        }
        WHEN("A node is appended"){
            SLLNode *node2 = new SLLNode(VAL_2);
            SinglyLinkedList* changedList = list->append(node2);
            THEN("The head's next is that node."){
                REQUIRE( changedList->head->next == node2 );
                REQUIRE( changedList->head->next->data == node2->data);
                REQUIRE( changedList->head->next->data == VAL_2);
            }
            THEN("The tail is that node"){
                REQUIRE( changedList->tail == node2 );
                REQUIRE( changedList->tail->data == node2->data );
                REQUIRE( changedList->tail->data == VAL_2 );
            }
            THEN("The tail has no next."){
                REQUIRE( !changedList->tail->next );}
        }
        WHEN("A value is appended"){
            SLLNode* node = new SLLNode(VAL_1);
            SinglyLinkedList* list = new SinglyLinkedList(node);
            SinglyLinkedList* changedList = list->append(VAL_2);
            THEN("The list is 2 nodes long."){
                REQUIRE( !changedList->head->next->next );
            }
            THEN("The head's next has that value."){
                REQUIRE(  changedList->head->next->data == VAL_2);
            }
            THEN("The tail has the new value"){
                REQUIRE(  changedList->tail->data == VAL_2);
            }
            THEN("The tail has no next."){
                REQUIRE( !changedList->tail->next );}
        }
        WHEN("A node is prepended"){
            node = new SLLNode(VAL_1);
            SinglyLinkedList *list = new SinglyLinkedList(node);
            SLLNode *node0 = new SLLNode(VAL_0);
            SinglyLinkedList* changedList = list->prepend(node0);
            THEN("That node's 'next' is now the old head."){
                REQUIRE(  changedList->head == node0 );
                REQUIRE(  node0->next == node );
                REQUIRE(  changedList->head->next == node);}
            THEN("The new tail is the old head."){
                REQUIRE(  changedList->tail == node );
                REQUIRE(  changedList->tail->data == VAL_1 );
                REQUIRE(  changedList->head->next == changedList->tail );}
            THEN("The values are correct"){
                REQUIRE(  changedList->tail->data == VAL_1 );
                REQUIRE(  changedList->head->data == VAL_0 );
                REQUIRE(  changedList->head->next->data == VAL_1);}
            THEN("The tail has no next."){
                REQUIRE( !changedList->tail->next );}
        }
        WHEN("A value is prepended"){
            node = new SLLNode(VAL_1);
            SinglyLinkedList *list = new SinglyLinkedList(node);
            SinglyLinkedList* changedList = list->prepend(VAL_0);
            THEN("The list is 2 nodes long."){
                REQUIRE( !changedList->head->next->next );
            }
            THEN("The tail has the original head."){
                REQUIRE(  changedList->tail == list->head );
                REQUIRE(  changedList->tail == node );
                REQUIRE(  changedList->head->next == node );
                REQUIRE(  changedList->head->next->data == VAL_1 );
            }
            THEN("The head has the new value"){
                REQUIRE(  changedList->head->data == VAL_0);
            }
            THEN("The tail has no next."){
                REQUIRE( !changedList->tail->next );}
        }
    }
    GIVEN("Two nodes to start with"){
        SLLNode *node2 = new SLLNode(VAL_2);
        SLLNode *node  = new SLLNode(VAL_1, node2);
        SinglyLinkedList *list = new SinglyLinkedList(node);
        THEN("Check the first node"){
            REQUIRE(  list->head == node );
            REQUIRE(  list->head->data == node->data );
            REQUIRE(  list->head->data == VAL_1 );}
        THEN("Check the second node"){
            REQUIRE(  list->tail == node2 );
            REQUIRE(  list->tail->data == node2->data );
            REQUIRE(  list->tail->data == VAL_2 );}
        THEN("Check the link"){
            REQUIRE(  list->tail == list->head->next );
            REQUIRE(  list->head->next == node2);
        }
        THEN("The tail has no next."){
                REQUIRE( !list->tail->next );}
        WHEN("A node is appended to the original list"){
            SLLNode *node3 = new SLLNode(VAL_3);
            SinglyLinkedList* changedList = list->append(node3);
            THEN("The node is the new tail, after the old second node"){
                REQUIRE(  changedList->tail == node3 );
                REQUIRE(  changedList->tail->data == VAL_3 );
                REQUIRE(  changedList->tail->data == node3->data );}
            THEN("The new tail is after the second node in the original list"){
                REQUIRE(  changedList->head->next->next == node3 );
                REQUIRE(  changedList->head->next->next->data == node3->data );
            }
            THEN("The tail has no next."){
                REQUIRE( !changedList->tail->next );}
        }
        WHEN("A value is appended to the original list"){
            SLLNode *node2 = new SLLNode(VAL_2);
            SLLNode *node  = new SLLNode(VAL_1, node2);
            SinglyLinkedList *list = new SinglyLinkedList(node);
            SinglyLinkedList* changedList = list->append(VAL_3);
            THEN("The tail is a new node with the value."){
                REQUIRE(  changedList->tail->data == VAL_3 );}
            THEN("The new tail is after the second node in the original list"){
                REQUIRE(  changedList->head->next->next->data == VAL_3 );}
            THEN("The tail has no next."){
                REQUIRE( !changedList->tail->next );}
        }
        WHEN("A node is prepended to the original list"){
            SLLNode *node0 = new SLLNode(VAL_0);
            SLLNode *node2 = new SLLNode(VAL_2);
            SLLNode *node  = new SLLNode(VAL_1, node2);
            SinglyLinkedList *list = new SinglyLinkedList(node);
            SLLNode *oldHead = list->head;
            SinglyLinkedList* changedList = list->prepend(node0);
            THEN("The node is the new tail, and its 'next' is the old head"){
                REQUIRE(  oldHead == node );
                REQUIRE(  changedList->head == node0 );
                REQUIRE(  changedList->head->next == oldHead );
                REQUIRE(  changedList->head->data == VAL_0 );
                REQUIRE(  changedList->head->next->data == VAL_1 );
                REQUIRE(  changedList->head->next->data == oldHead->data );}
            THEN("The list is three nodes long"){
                REQUIRE( !changedList->head->next->next->next );}
            THEN("The tail has no next."){
                REQUIRE( !changedList->tail->next );
            }
        }
        WHEN("A value is prepended to the original list"){
            SLLNode *node2 = new SLLNode(VAL_2);
            SLLNode *node  = new SLLNode(VAL_1, node2);
            SinglyLinkedList *list = new SinglyLinkedList(node);
            SLLNode *oldHead = list->head;
            SinglyLinkedList* changedList = list->prepend(VAL_0);
            THEN("The node is the new tail, and its 'next' is the old head"){
                REQUIRE(  oldHead == node );
                REQUIRE(  changedList->head->next == oldHead );
                REQUIRE(  changedList->head->data == VAL_0 );
                REQUIRE(  changedList->head->next->data == VAL_1 );
                REQUIRE(  changedList->head->next->data == oldHead->data );}
            THEN("The list is three nodes long"){
                REQUIRE( !changedList->head->next->next->next );}
            THEN("The tail has no next."){
                REQUIRE( !changedList->tail->next );
            }
        }
        WHEN("A value is inserted at the index 1 (the second node)"){
            SLLNode *node2 = new SLLNode(VAL_2);
            SLLNode *node  = new SLLNode(VAL_1, node2);
            SinglyLinkedList *list = new SinglyLinkedList(node);
            SLLNode *oldSecondNode = list->head->next->next;
            SinglyLinkedList* changedList = list->insertAt(VAL_I, 1);
            THEN("The new value is now the second node"){
                REQUIRE( changedList->head->next->data == VAL_I );}
            THEN("The new old second node is now the third node."){
                REQUIRE( changedList->head->next->next == oldSecondNode );
                REQUIRE( changedList->head->next->next->data
                    == oldSecondNode->data );
            }
        }
    }
}

SCENARIO("Print a linked list. Results need manually verified."){
    GIVEN("An empty linked list"){
        SinglyLinkedList *list = new SinglyLinkedList();
        THEN("'NULL' should be printed."){
            printLinkedList(list->head);
            std::cout << "'NULL' should have been printed on the previous line"
                << '\n';
        }
    }
    GIVEN("A linked list with one element"){
        SinglyLinkedList *list = new SinglyLinkedList(new SLLNode(VAL_1));
        char* out1;
        sprintf(out1, "That value (%d) should be printed", VAL_1);
        THEN(out1){
            printLinkedList(list->head);
            printf(
                "The value %d should have been printed on the previous line",
                VAL_1
            );
        }
    }
}
