/*******************************************************************************
*
* File: redblacktree.cpp
* Name:
*
* Description: Red Black Tree specific routines.
*
* Copyright
*
******************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <stddef.h>
#include <time.h>
#include <wchar.h>
#include <sys/types.h>

#define NULL (void *)0

enum COLOR {RED, BLACK};

#define error(msg, ...) printf("%s\n", msg)

typedef struct rbtree_t_ {
	struct rbtree_t_ *left;
	struct rbtree_t_ *right;
	struct rbtree_t_ *parent;
	COLOR color;
	unsigned int value;
}rbtree;

rbtree *root = NULL;


rbtree *Node(unsigned int var)
{
	rbtree *newNode = (rbtree *)malloc(sizeof(rbtree));
	if(newNode == NULL)
		return NULL;

	newNode->color = RED;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = NULL;
	newNode->value = var;

	return newNode;
}

rbtree *searchParent(rbtree *root, unsigned int var)
{
	rbtree *p = root;
	while(p != NULL)
	{
		if(var < p->value)
		{
			if (p->left == NULL)
				break;
			else
				p = p->left;
		}
		else {
			if(p->right == NULL)
				break;
			else
				p = p->right;
		}
	}

	return p;
}

bool isOnLeft(rbtree *node)
{
	return (node == node->parent->left)?true:false;
}

rbtree *uncle(rbtree *node)
{
	rbtree *parent = node->parent;

	if(parent == NULL || parent->parent == NULL)
		return NULL;

	if (true == isOnLeft(parent))
	{
		return parent->parent->right;
	}
	else
	{
		return parent->parent->left;
	}
}

void swapColors(rbtree **parent, rbtree **grandParent)
{
	COLOR temp;
	temp = (*parent)->color;
	(*parent)->color = (*grandParent)->color;
	(*grandParent)->color = temp;
}

rbtree *leftRotate(rbtree *node)
{
	rbtree *nParent = node->right;

	if(node == root)
		root = nParent;

	node->right = nParent->left;

	if(nParent->left != NULL)
		nParent->left->parent = node;

	nParent->left = node;

	return nParent;
}

rbtree *rightRotate(rbtree *node)
{
	rbtree *nParent = node->left;

	if(node == root)
		root = nParent;

	node->left = nParent->right;

	if(nParent->right != NULL)
		nParent->right->parent = node;

	nParent->right = node;

	return nParent;
}


rbtree *fixDoubleRed(rbtree *node)
{
	rbtree *parent = node->parent;
	rbtree *grandParent = node->parent->parent;
	rbtree *Uncle = uncle(node);

	if(parent->color != BLACK)
	{
		if(Uncle != NULL && Uncle->color == RED)
		{
			parent->color = BLACK;
			Uncle->color = BLACK;
			grandParent->color = RED;
			parent = fixDoubleRed(grandParent);
		}
		// Perform the LR, LL, RR, RL rotate to rebalance.
		else {
			if(isOnLeft(parent))
			{
				if(isOnLeft(node))
				{
					swapColors(&parent, &grandParent);
				}
				else
				{
					grandParent = leftRotate(grandParent);
					swapColors(&parent, &grandParent);
				}
				grandParent = rightRotate(grandParent);
			}
			else {
				if(isOnLeft(node))
				{
					grandParent = rightRotate(grandParent);
					swapColors(&parent, &grandParent);
				}
				else
				{
					swapColors(&parent, &grandParent);
				}

				grandParent = leftRotate(grandParent);
			}
		}
	}

	return node;
}

void  levelOrder(rbtree *node)
{
	if(node == NULL)
		return;

	rbtree queue[MAX_NO];
	rbtree *temp;

	push(queue, node);

	while(!emptyQueue())
	{
		temp =
	}

}


rbtree *fixViolation(rbtree *root)
{

}


rbtree *insertNodeRB(rbtree *rootNode, unsigned int var)
{
	rbtree *node = NULL;
	rbtree *temp = NULL;

	node = Node(var);
	if(node == NULL)
	{
		error("Failed to Allocate memory. %d\n", errno);
		return NOMEM;
	}

	if (rootNode == NULL)
	{
		node->color = BLACK;
		return node;
	}
	else {

		temp = searchParent(rootNode, var);

		if(temp->value == var)
			break;
	}

	node->parent = temp;

	if(var < temp->value)
		temp->left = node;
	else
		temp->right = node;

	return fixViolation(rootNode);
}





int main(int argc, char **argv) {
	rbtree *rootNode = NULL;

	rootNode = insertNodeRB(rootNode, 7);
	rootNode = insertNodeRB(rootNode, 4);
	rootNode = insertNodeRB(rootNode, 18);
	rootNode = insertNodeRB(rootNode, 15);
	rootNode = insertNodeRB(rootNode, 11);
	rootNode = insertNodeRB(rootNode, 21);
	rootNode = insertNodeRB(rootNode, 2);
	rootNode = insertNodeRB(rootNode, 12);
	rootNode = insertNodeRB(rootNode, 7);

	printInOrderRB(rootNode);
	PrintLevelOrderRB(rootNode);

	rootNode = deleteNodeRB(rootNode, 21);
	printInOrderRB(rootNode);
	PrintLevelOrderRB(rootNode);

	return 0;
}
