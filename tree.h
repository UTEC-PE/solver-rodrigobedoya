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

	void build(std::string &content,Node *&node)
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
		deleteOuterP(content);
		build(content,node);
		return;
	}

	bool find(char search,char *start, std::string &left_str, std::string &right_str)
	{
		bool found = false;
		int count = 0;
		std::string left_string = "";
		for (char* it = start; *it; ++it)
		{
			if(*it == '(')
				count++;
			else if (*it == ')')
				count--;

			if(found)
			{
				right_str+= *it;
				continue;
			}

			if (*it == search and !count)
			{
				found = true;
				left_str = left_string;
				continue;
			}

			left_string += *it;
		}
		return found;
	}

	void deleteOuterP(std::string &content)
	{
		bool found_left_p = false;
		int left_pos,right_pos;
		for(int i = 0; i < content.size();i++)
		{
			if (!found_left_p)
			{
				if(content[i] == '(')
				{
					left_pos = i;
					found_left_p = true;
					continue;
				}
			}

			if(content[i] == ')')
				right_pos = i;

		}
		content.erase(content.begin()+right_pos);
		content.erase(content.begin()+left_pos);
		return;
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

	//determine the value of int or variable
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

	//determine operation required
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


