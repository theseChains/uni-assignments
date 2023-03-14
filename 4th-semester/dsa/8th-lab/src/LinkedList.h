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

struct NodeList
{
	int listValue{};
	Node* head{ nullptr };
	NodeList* next{ nullptr };
};

bool isListEmpty(const Node* head);
bool isNodeListEmpty(const NodeList* head);
void addToList(Node* head, AddOption option);
void addToNodeList(NodeList* head, AddOption option);
void removeFromList(Node* head, int valueToRemove);
void removeFromNodeList(NodeList* head, int listIdToRemove);
bool findInList(const Node* head, int itemToFind);
void printList(Node* head);
void printNodeList(NodeList* head);
void destroyList(Node* head);

#endif
