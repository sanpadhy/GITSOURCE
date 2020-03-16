#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <stddef.h>
#include <time.h>
#include <wchar.h>

/*
 * Binomial heap doesn't allow more then 1 tree of same degree.
 *
 */

typedef struct binomialNode_t_
{
	unsigned int data;
	unsigned int degree;
	struct binomialNode_t_*child;
	struct binomialNode_t_ *sibling;
	struct binomialNode_t_ *parent;
}binomialNode;

typedef struct singlelinkedlist_t_
{
	binomialNode *node;
	struct singlelinkedlist_t_ *next;
}singlelinkedlist;

typedef struct binarytree_t_
{
	binomialNode *node;
	struct binarytree_t_ *left;
	struct binarytree_t_ *right;
}binarytree;


/*
 * newBinomialNode: Create a new Binomial node.
 *    Parameter: New key to be added.
 *    Return: Pointer to new binomial node.
 *    Error Case: If malloc failed.
 */

binomialNode *newBinomialNode(int key)
{
	binomialNode *temp = (binomialNode *)malloc(sizeof(binomialNode));
	if(temp == NULL)
	{
		error("Failed to allocate memory. \n");
		return NULL;
	}
	temp->data = key;
	temp->degree = 0;
	temp->child = NULL;
	temp->sibling = NULL;
	temp->parent = NULL;
}

void swap(binomialNode *Node1, binomialNode *Node2)
{
	binomialNode *temp = NULL;
	temp = Node1;
	Node1 = Node2;
	Node2 = temp;
	return;
}


/*
 * mergeBinomialTrees: Since Binomial heap doesn't allow more then 1 tree of same level.
 *                     Two tree will be merged.
 *       Parameter:
 *       Return:
 *
 *        BN2  BN1
 *       ->3 -> 4 ->  1        -->       -> 3  ->   1
 *                  / | \                   |     / | \
 *                  1 6  5                  4    1  6  5
 *
 *       Binomial node 3 and 4 has been merged. BN1 has to be less then BN2.
 *
 *       Complexity is O(logn), since there are O(logn) trees, which might all
 *       be involved in merge operations.
 *
 */


binomialNode *mergeBinomialNodes(binomialNode *BN1, binomialNode *BN2)
{
	/* Note: Make sure BN1 need to be smaller. */
	if(BN1->data > BN2->data)
		swap(BN1, BN2);

	/*
	 * Build the tree with larger node being the parent and smaller will be the child.
	 */
	BN2->parent = BN1;
	BN2->sibling = BN1->child;
	BN1->child = BN2;
	BN1->degree++;

	return BN1;
}

/*
 *  mergeBinomialTrees: Merging two binomial trees of same level.
 *      Parameter:
 *      Return:
 *
 *         BT1     BT2
 *         2        6         -->         2
 *         |        |                    /  \
 *         5        9                   6    5
 *                                       \
 *                                        9
 *
 *      Merge two trees of same degree to build bigger tree with higher degree.
 */

binomialNode *mergeBinomialTrees(binarytree *bt1, binarytree *bt2)
{

}



singlelinkedlist *mergeBinomialHeap(singlelinkedlist *list1, singlelinkedlist *list2)
{
	singlelinkedlist *new;
	singlelinkedlist *p1 = list1;
	singlelinkedlist *p2 = list2;

	while (p1 != NULL && p2 != NULL)
	{
		p1->node->degree <= p1->node->degree;
	}
}










int main(int argc, char **argv) {
	return 0;
}
