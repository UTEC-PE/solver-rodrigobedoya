#ifndef TREE_H
#define TREE_H

#include "node.h"
#include <iostream>
#include <math.h>
#include <map>
#include <string>
#include <stdlib.h>
struct Tree
{
	Node* root;
	std::map<char,int> variable_map;

	Tree():
		root(NULL){}

	void defineVariable(char name, int value)
	{
		variable_map[name] = value;
	}

	void load(char *str)
	{
		char priority[] = {'+','-','*','/','^'};
		std::string left,right="";
		for (char sign: priority)
		{
			if(find(sign,str,left,right))
			{
				root = new Node(sign);
				build(left,root->left_child);
				build(right,root->right_child);
				return;
			}			
		}
	}

	void build(std::string content,Node *&node)
	{
		if(content.length() == 1)
		{
			node = new Node(content[0]);
			return;
		}
		std::string left,right="";
		char priority[] = {'+','-','*','/','^'}; 
		for (char sign: priority)
		{
			if(find(sign,&content[0],left,right))
			{
				node = new Node(sign);
				build(left,node->left_child);
				build(right,node->right_child);
				return;
			}			
		}
	}

	bool find(char search,char *start, std::string &left_str, std::string &right_str)
	{
		bool found = false;
		std::string left_string = "";
		for (char* it = start; *it; ++it)
		{
			if(*it == '(')
				return found;
			if(found)
			{
				right_str+= *it;
				continue;
			}

			if (*it == search)
			{
				found = true;
				left_str = left_string;
				continue;
			}

			left_string += *it;
		}
		return found;
	}


	void print()
	{
	 	std::cout << "result: "<<calc(root) << std::endl;
	}



	float calc(Node* node)
	{
		if (node->left_child==NULL)
			return evaluate(node);
		return operate(node);
	}

	float evaluate(Node* node)
	{
		if(isdigit(node->data))
			return int(node->data-'0');
		if (variable_map.count(node->data))	
			return variable_map[node->data];
		else
			std::cout << "ERROR: some varibales were not defined" << std::endl;
			throw "undefined_variables";
	}

	float operate(Node* node)
	{
		switch(node->data)
		{
			case('+'):
				return calc(node->left_child) + calc(node->right_child);
			case('-'):
				return calc(node->left_child) - calc(node->right_child);
			case('*'):
				return calc(node->left_child) * calc(node->right_child);
			case('/'):
				return calc(node->left_child) / calc(node->right_child);
			case('^'):
				return pow(calc(node->left_child),calc(node->right_child));	
		}
	}
};

#endif


