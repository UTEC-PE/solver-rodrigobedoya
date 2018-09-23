#ifndef NODE_H
#define NODE_H

struct Node
{
	char data;
	Node* left_child;
	Node* right_child;

	Node(Node *left_child = NULL, Node *right_child = NULL):
		left_child(left_child),
		right_child(right_child)
	{}

	Node(char data, Node *left_child = NULL, Node *right_child = NULL):
		data(data),
		left_child(left_child),
		right_child(right_child)
	{}

};

#endif