#ifndef LINKED_LIST_H 
#define LINKED_LIST_H 

struct Node
{
	int item{};
	int nextIndex{};
};

bool isListEmpty(const Node& head);
void addToList(Node& head);
void removeFromList(Node& head, int itemToRemove);
Node findInList(Node& head, int itemToFind);
void printList(Node& head);

#endif
