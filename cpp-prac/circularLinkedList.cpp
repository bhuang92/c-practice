#include <iostream>

using namespace std;

typedef struct LinkedListNode {
	int value;
	struct LinkedListNode* next;
} LLNode;

void findCircularLinkedList(LLNode* head);
void example1();
void example2();

int main()
{
	example1(); // not circular
	example2(); // circular
	return 0;
}

void findCircularLinkedList(LLNode* head) {
	LLNode* slow = head;
	LLNode* fast = head->next;
	while(slow && fast && fast->next) {
		if (slow == fast || slow == fast->next) {
			printf("Circular!\n");
			return;
		}
		slow = slow->next;
		fast=fast->next->next;
	}
	printf("Not circular!\n");
	return;
}

//Not circular
void example1() {
	LLNode* head = (LLNode*)malloc(sizeof(LLNode));
	LLNode* node1 = (LLNode*)malloc(sizeof(LLNode));
	LLNode* node2 = (LLNode*)malloc(sizeof(LLNode));

	head->value = 1;
	head->next = node1;

	node1->value = 2;
	node1->next = node2;

	head->value = 3;
	head->next = NULL;
	findCircularLinkedList(head);
	free(head);
	free(node1);
	free(node2);
}

//Circular linked list
void example2() {
	LLNode* head = (LLNode*)malloc(sizeof(LLNode));
	LLNode* node1 = (LLNode*)malloc(sizeof(LLNode));
	LLNode* node2 = (LLNode*)malloc(sizeof(LLNode));

	head->value = 1;
	head->next = node1;

	node1->value = 2;
	node1->next = node2;

	head->value = 3;
	head->next = head;
	findCircularLinkedList(head);
	free(head);
	free(node1);
	free(node2);
}