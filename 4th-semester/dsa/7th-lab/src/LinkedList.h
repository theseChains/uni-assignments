#ifndef LINKED_LIST_H
#define LINKED_LIST_H

enum class AddOption
{
	beforeElement,
	afterElement
};

struct Node
{
	int value{};
	Node* next{ nullptr };
	Node* prev{ nullptr };
};

bool isListEmpty(const Node* head);
void addToList(Node* head, AddOption option = AddOption::afterElement);
void removeFromList(Node* head, int valueToRemove);
void findInList(const Node* head, int itemToFind);
void printList(Node* head);

#endif
