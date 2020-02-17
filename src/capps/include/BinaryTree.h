/*
 * BinaryTree.h
 *
 *  Created on: 31-Dec-2019
 *      Author: santosh
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include "common.h"

#define MAX_ELEMENT 100
#define MAX  10


typedef struct binaryTree_t_ {
	struct binaryTree_t_ *parent;
	struct binaryTree_t_ *lChild;
	struct binaryTree_t_ *rChild;
	uint32 key;
}binaryTree;

typedef struct queue_t_ {
	binaryTree **NodeQueue;
	uint32 size;
	uint32 front;
	uint32 back;
}queue;

typedef struct stack_t_ {
	binaryTree **NodeStack;
	uint32 top;
	uint32 size;
}stack;



enum TRAV_FLAG {IN=1, PRE, POST};


/***********************************************************************************
* ********************                                 *****************************
* ********************    GLOBAL FUNCTION DEFINITION   *****************************
* ********************                                 *****************************
* **********************************************************************************/

extern binaryTree *pushToTree(binaryTree *head, unsigned int newVar);
extern binaryTree *delete_Node(binaryTree *head, unsigned int key);
extern binaryTree *findNode(binaryTree *root, uint32 find);
extern void breadthFirstSearch(binaryTree *root);
extern uint32 findInorderSuccessor(binaryTree *root, uint32 var);
extern uint32 findInorderPredecessor(binaryTree *root, uint32 var);
extern binaryTree *constructBSTFromPreorderLimit(uint32 *arr, uint32 left, uint32 right);
extern binaryTree *constructBSTFromPreorderTraversal(uint32 *arr, uint32 len);
extern uint32 countNoOfBSD(uint32 range);
extern unsigned int findParentOfLargest(binaryTree *head);
extern void findSecondLargestNode (binaryTree *root);
extern binaryTree *reconstructBinaryTree(unsigned int *preorder, unsigned int len);
extern unsigned int evaluateArithmaticBT(binaryTree *head);
extern unsigned int deepestNodeBinaryTree(binaryTree *head);
extern binaryTree *invertBinaryTree(binaryTree *head);
extern bool isBinarySearchTree(binaryTree *head);
extern void printAllPathToLeaves(binaryTree *head);
extern bool checkTreesForSim(binaryTree *tree1, binaryTree *tree2);

#endif /* BINARYTREE_H_ */






