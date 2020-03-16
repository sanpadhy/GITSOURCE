#include "../include/BinaryTree.h"


/**********************************************************************************************
 * ********************                                           *****************************
 * ********************       LOCAL FUNCTIONS (STATIC)            *****************************
 * ********************                                           *****************************
 * ********************************************************************************************/

static binaryTree *getNode(uint32 var)
{
	binaryTree *node = (binaryTree *)malloc(sizeof(binaryTree));
	if(node == NULL) {
		perror("failed to allocate memory.\n");
		return NULL;
	}

	node->key = var;
	node->lChild = NULL;
	node->rChild = NULL;

	return node;
}

static void inorder_bt(binaryTree *head)
{
	if(!head)
		return;

	if(head->lChild) inorder_bt(head->lChild);
	printf("%d --> ", head->key);
	if (head->rChild) inorder_bt(head->rChild);
	return;
}

static void preorder_bt(binaryTree *head)
{
	if(!head)
		return;

	printf("%d --> ", head->key);
	if (head->lChild) preorder_bt(head->lChild);
	if (head->rChild) preorder_bt(head->rChild);
	return;
}

static void postorder_bt(binaryTree *head)
{
	if(!head)
		return;

	if (head->lChild) postorder_bt(head->lChild);
	if (head->rChild) postorder_bt(head->rChild);
	printf("%d --> ", head->key);

	return;
}

queue *initBinaryQueue(uint32 size) {
	queue *BinaryQueue = (queue *)malloc(sizeof(queue));
	if(BinaryQueue == NULL) {
		perror("Failed to allocate memory for queue.\n");
		return NULL;
	}

	BinaryQueue->front = 0;
	BinaryQueue->back = 0;
	BinaryQueue->size = size;

	BinaryQueue->NodeQueue = (binaryTree **)malloc(sizeof(binaryTree *) * BinaryQueue->size);
	if(BinaryQueue->NodeQueue == NULL) {
		perror("Failed to allocate memory.\n");
		return NULL;
	}
	return BinaryQueue;
}

static queue *enqueue(queue *BQ, binaryTree *node)
{
	if(BQ->back == BQ->size) {
		printf("The queue is full.\n");
		return BQ;
	}

	BQ->NodeQueue[BQ->back++] = node;
	return BQ;

}

static binaryTree *dequeue(queue *BQ)
{
	if(BQ->front == BQ->back)
		perror("The empty Queue.");

	return BQ->NodeQueue[BQ->front++];
}

static stack *stackInit(uint32 size) {
	stack *ST = NULL;

	if(size == 0) {
		return ST;
	}

	ST = (stack *)malloc(sizeof(stack));
	if(ST == NULL) {
		perror("Failed to allocate memory. ");
		return ST;
	}

	ST->size = size;
	ST->top = 0;
	ST->NodeStack = (binaryTree **)malloc(sizeof(binaryTree *) * ST->size);
	if(!ST->NodeStack) {
		perror("Failed to allocate memory ");
		return NULL;
	}

	return ST;
}

static void pushStack(stack *ST, binaryTree *node)
{
	if(ST->top == ST->size) {
		perror("stack is full\n");
		return;
	}

	ST->NodeStack[ST->top++] = node;
}

static binaryTree *popStack(stack *ST) {
	if(ST->top <= 0) {
		perror("empty Stack.\n");
		return NULL;
	}

	return ST->NodeStack[--ST->top];
}

bool isEmpty(queue *BQ) {
	if(BQ->front == BQ->back)
		return true;

	return false;
}

binaryTree *SearchInTree(binaryTree *root, uint32 find) {
	if(root == NULL)
		return NULL;

	if(root->key == find)
		return root;

	if(find < root->key)
		return SearchInTree(root->lChild, find);
	else
		return SearchInTree(root->rChild, find);

}

binaryTree *SearchInBinaryTree_iter(binaryTree *root, uint32 find)
{
	if(root == NULL)
		return NULL;

	while(root) {
		if(root->key == find)
			return root;
		else if(root->key > find) {
			root = root->lChild;
		}
		else {
			root = root->rChild;
		}
	}

	return NULL;
}

uint32 sizeOfBinaryTree(binaryTree *root)
{
	if(root == NULL)
		return 0;

	return sizeOfBinaryTree(root->lChild) + sizeOfBinaryTree(root->rChild) + 1;
}

void inorder_traversal(binaryTree *root, uint32 k, uint32 *c)
{
	if(root == NULL || *c >= k) {
		return;
	}

	inorder_traversal(root->lChild, k, c);

	printf("root->key: %d, k: %d, c: %d\n", root->key, k, *c);

	(*c)++;

	if(*c == k) {
		printf("the kth smallest element is: %d\n", root->key);
		return;
	}

	inorder_traversal(root->rChild, k, c);

}

bool checkForAncestor(binaryTree *root, uint32 node1, uint32 node2)
{
	if(root == NULL) {
		return false;
	}

	if(node1 < root->key && node2 < root->key)
		return checkForAncestor(root->lChild, node1, node2);
	if(node1 > root->key && node2 > root->key)
		return checkForAncestor(root->rChild, node1, node2);

	if(node1 == root->key || node2 == root->key)
		return true;
	else
		return false;
}

void printFromQueue(queue *QE) {
	uint32 i = 0;
	for(i = QE->front; i < QE->back; i++) {
		printf("%d\t", QE->NodeQueue[i]->key);
	}
	printf("\n");
	return;
}

queue *getLeftNodes(binaryTree *root, queue *QE)
{
	printf("root key: %d\n", root->key);
	if(root->lChild == NULL && root->rChild == NULL)
		return QE;

	printFromQueue(QE);

	QE = enqueue(QE, root);

	getLeftNodes(root->lChild, QE);

	return QE;
}

queue *getAllLeafNodes(binaryTree *root, queue *QE)
{
	if(root->lChild == NULL && root->rChild == NULL) {
		QE = enqueue(QE, root);
	}

	QE = getAllLeafNodes(root->lChild, QE);
	QE = getAllLeafNodes(root->rChild, QE);

	return QE;
}

queue *getAllRightNodesButtomUP(binaryTree *root, queue *QE)
{
	if(root->lChild == NULL && root->rChild == NULL)
		return QE;

	getAllRightNodesButtomUP(root->lChild, QE);

	QE = enqueue(QE, root);

	return QE;
}



void DestroyQueue(queue *QE)
{
	if(QE) {
		for(int i = 0; i < QE->size; i++)
		{
			free(QE[i].NodeQueue);
			QE[i].NodeQueue = NULL;
			QE->back = 0;
			QE->front = 0;
			QE->size = 0;
		}

		free(QE);
		QE = NULL;
	}

	return;
}


/*

static void updateParent(binaryTree *head, bool enableLock)
{
	if (head->parent) {
		head->parent->descendentCount++;
		updateParent(head->parent, enableLock);
	}
}

static bool isParentLocked(BinaryTree *node)
{
	if(node->parent == NULL)
		return false;
	else if(node->parent->locked == true)
		return true;
	else
		isParentLocked(node->parent);
}

static bool is_locked(BinaryTree *head)
{
	return head->locked;
}
*/


/**********************************************************************************************
 * ********************                                           *****************************
 * ********************       GLOBAL APIs BINARY SEARCH TREE      *****************************
 * ********************                                           *****************************
 * ********************************************************************************************/


/*
 * Note: Preferred when the tree is very deep and desired values or data
 * occurs infrequently.
 *
 * Time complexity: O(n)
 * space complexity: O(h)
 *
 *
 */

binaryTree *pushToTree(binaryTree *head, unsigned int newVar)
{
	if(!head)
	{
		head = getNode(newVar);
		if(head == NULL)
		{
			printf("Failed to add a Node. \n");
			return NULL;
		}
		return head;
	}

	if(newVar <= head->key) head->lChild = pushToTree(head->lChild, newVar);
	else head->rChild = pushToTree(head->rChild, newVar);

	return head;
}

/*
 * Note: Preferred when the tree is very deep and desired values or data
 * occurs infrequently.
 *
 * Time complexity: O(n)
 * space complexity: O(h)
 *
 *
 */

binaryTree *delete_Node(binaryTree *head, unsigned int key)
{
	if(!head)
		return NULL;

	unsigned int tmp = 0;
	binaryTree *pv = NULL;
	binaryTree *p = head;

	if(head->key == key)
	{
		if(head->lChild == NULL)
			return head->rChild;
		else if(head->rChild == NULL)
			return head->lChild;
		else {
			binaryTree *q = NULL;
			pv = head;
			p = head;
			q = head->rChild;
			while(q->lChild != NULL)
			{
				pv = q;
				q = q->lChild;
			}

			p->key = q->key;
			pv->lChild = q->rChild;
			free(q);
			q = NULL;
		}
	}
	else if (head->key < key) head->lChild = delete_Node(head->lChild, key);
	else head->rChild = delete_Node(head->rChild, key);

	return head;
}

/*
 * Note: Preferred when the tree is very deep and desired values or data
 * occurs infrequently.
 *
 * Time complexity: O(n)
 * space complexity: O(h)
 *
 *
 */

binaryTree *findNode(binaryTree *root, uint32 find)
{
	if(root == NULL)
		return NULL;

	if(root->key == find)
		return root;
	else if(find < root->key)
		return findNode(root->lChild, find);
	else
		return findNode(root->rChild, find);
}


/*
 * Note: preferred in shallow trees that aren’t too wide. Also used if it is known that
 * the desired node is closer to the root level.
 *
 * Time complexity: O(n)
 * space complexity: O(w)
 *
 *
 */

void breadthFirstSearch(binaryTree *root)
{
	if(!root)
		return;

	binaryTree *node = NULL;
	queue *NQ = NULL;

	NQ = initBinaryQueue(15);

	NQ = enqueue(NQ, root);

	while(!isEmpty(NQ)) {
		node = dequeue(NQ);
		printf("%d \n", node->key);
		if(node->lChild)enqueue(NQ, node->lChild);
		if(node->rChild)enqueue(NQ, node->rChild);
	}

	return;
}

/*
 * Note: Preferred when the tree is very deep and desired values or data
 * occurs infrequently.
 *
 * Time complexity: O(n)
 * space complexity: O(h)
 *
 *
 */

uint32 findInorderSuccessor(binaryTree *root, uint32 var)
{
	if(root == NULL)
		return 0;

	binaryTree *node = findNode(root, var);

	binaryTree *tmp = NULL;

	if(node->rChild) {
		tmp = node->rChild;
		while(tmp->lChild != NULL) {
			tmp = tmp->lChild;
		}
		return tmp->key;
	}
	else {
		tmp = NULL;
		binaryTree *p = root;

		while(p->key != node->key) {
			if(p->key > node->key) {
				tmp = p;
				p = p->rChild;
			}
			else {
				p = p->lChild;
			}
		}
		return tmp->key;
	}
}

/*
 * Note: Preferred when the tree is very deep and desired values or data
 * occurs infrequently.
 *
 * Time complexity: O(n)
 * space complexity: O(h)
 *
 *
 */


uint32 findInorderPredecessor(binaryTree *root, uint32 var)
{
	if(root == NULL)
		return 0;

	binaryTree *node = findNode(root, var);

	binaryTree *tmp = NULL;
	if(node->lChild) {
		tmp = node->lChild;
		while(tmp->rChild != NULL) {
			tmp = tmp->rChild;
		}
		return tmp->key;
	}
	else {
		tmp = NULL;
		binaryTree *p = root;

		while(p->key != node->key) {
			if(p->key < node->key) {
				tmp = p;
				p = p->rChild;
			}
			else {
				p = p->lChild;
			}
		}
		return tmp->key;
	}
}

/*
 * Note: Preferred when the tree is very deep and desired values or data
 * occurs infrequently.
 *
 * Time complexity: O(n)
 * space complexity: O(h)
 *
 *
 */

binaryTree *constructBSTFromPreorderLimit(uint32 *arr, uint32 left, uint32 right)
{
	binaryTree *root = getNode(arr[left]);
	if(left == right) {
		return root;
	}

	/*
	 * Pivot point is the point where the array can be divided into two with array more then root and array
	 * less then root.
	 */
	uint32 pivot = 1;

	while(arr[pivot] < root->key)
		pivot++;

	root->lChild = constructBSTFromPreorderLimit(arr, left+1, pivot-1);
	root->lChild = constructBSTFromPreorderLimit(arr, pivot, right);

	return root;
}

/*
 * Note: Preferred when the tree is very deep and desired values or data
 * occurs infrequently.
 *
 * Time complexity: O(n)
 * space complexity: O(h)
 *
 *
 */

binaryTree *constructBSTFromPreorderTraversal(uint32 *arr, uint32 len) {
	if((arr == NULL) || (len == 0)) {
		return NULL;
	}

	binaryTree *root = NULL;
/*
	if(len(arr) == 0) {
		return root;
	}
	else {
		return constructBSTFromPreorderLimit(arr, 0, len-1);
	}
	*/
}

/*
 * Note: Preferred when the tree is very deep and desired values or data
 * occurs infrequently.
 *
 * Time complexity: O(n)
 * space complexity: O(h)
 *
 *
 */

uint32 countNoOfBSD(uint32 range)
{
	int i = 0;
	int T[] = {0};

	T[0] = 1;
	T[1] = 1;

	for(i = 2; i <= range; i++) {
		for(uint32 j=0; j < i; j++) {
			T[i] += T[i-j-1]*T[j];
		}
	}

	return T[i];
}

/*
 * Note: Preferred when the tree is very deep and desired values or data
 * occurs infrequently.
 *
 * Time complexity: O(n)
 * space complexity: O(h)
 *
 *
 */

unsigned int findParentOfLargest(binaryTree *head)
{
	binaryTree *parent = NULL;
	while(head->rChild) {
		parent = head;
		head = head->rChild;
	}
	return head->key;
}

/*
 * Note: Preferred when the tree is very deep and desired values or data
 * occurs infrequently.
 *
 * Time complexity: O(n)
 * space complexity: O(h)
 *
 *
 */

void findSecondLargestNode (binaryTree *root)
{
	if(root->rChild == NULL)
		return;

	unsigned int secondLargest = 0;

	/* Two conditions
	 * 1. Go to extreme right, that is the largest no.
	 * 2. if right not present, call the routine with root_left. Extreme right will be the highest.
	 */
	if((root->lChild) && (!root->rChild))
	{
		secondLargest = findParentOfLargest(root->lChild);
	}
	else {
		secondLargest = findParentOfLargest(root->rChild);
	}

	printf("%d", secondLargest);
	return;
}


void findSecondLargestIterative(binaryTree *root) {
	if(root == NULL) 
		return; 

	if(root->rChild == NULL) 
		return; 

	binaryTree *p = root; 
	binaryTree *pv = NULL; 

	while(p) {
		if(!p->lChild && !p->rChild)
			break; 
		else {
			if(p->lChild && !p->rChild) {
				pv = p; 
				p = p->lChild; 
			}
			else {
				pv = p; 
				p = p->rChild;
			}
		}
	}

	if(pv != NULL) {
		printf("Second largest: %d\n", pv->key); 	
	}
	else {
		printf("insufficient number of nodes.\n"); 
	}

	return; 
}

/*
 * Note: Preferred when the tree is very deep and desired values or data
 * occurs infrequently.
 *
 * Time complexity: O(n)
 * space complexity: O(h)
 *
 *
 */

binaryTree *reconstructBinaryTree(unsigned int *preorder, unsigned int len)
{
	binaryTree *rootNode = NULL;
	uint32 i = 0;

	if (preorder == NULL)
		return NULL;

	unsigned int rootVar = preorder[i];

	rootNode = getNode(rootVar);

	while(preorder[i] < rootVar)
		i++;

	rootNode->lChild = reconstructBinaryTree(&preorder[i], i-1);
	rootNode->rChild = reconstructBinaryTree(&preorder[i+1], len-i);

	return rootNode;
}

/*
 * Note: Preferred when the tree is very deep and desired values or data
 * occurs infrequently.
 *
 * Time complexity: O(n)
 * space complexity: O(h)
 *
 *
 */

unsigned int evaluateArithmaticBT(binaryTree *head)
{
	if(isdigit(head->key) || isalpha(head->key))
		return head->key;

	char opr = head->key;
	if(opr == '+')
		return evaluateArithmaticBT(head->lChild)+evaluateArithmaticBT(head->rChild);
	else if(opr == '*')
		return evaluateArithmaticBT(head->lChild)*evaluateArithmaticBT(head->rChild);
	else if(opr == '%')
		return evaluateArithmaticBT(head->lChild)%evaluateArithmaticBT(head->rChild);
	else if(opr == '/')
		return evaluateArithmaticBT(head->lChild)/evaluateArithmaticBT(head->rChild);
	else
		return 0;
}

/*
 * To check
 */

/*
 * Note: Preferred when the tree is very deep and desired values or data
 * occurs infrequently.
 *
 * Time complexity: O(n)
 * space complexity: O(h)
 *
 *
 */


unsigned int deepestNodeBinaryTree(binaryTree *head)
{
	unsigned int leftDepth = 0;
	unsigned int rightDepth = 0;

	if(head == NULL)
		return 0;

	if(head->lChild) {
		leftDepth = deepestNodeBinaryTree(head->lChild);
	}
	if (head->rChild) {
		rightDepth = deepestNodeBinaryTree(head->rChild);
	}

	if(leftDepth > rightDepth)
		return leftDepth+1;
	else
		return rightDepth+1;
}

/*
 * Note: Preferred when the tree is very deep and desired values or data
 * occurs infrequently.
 *
 * Time complexity: O(n)
 * space complexity: O(h)
 *
 *
 */


binaryTree *invertBinaryTree(binaryTree *head)
{
	if(head == NULL)
		return NULL;

	binaryTree *leftNode = NULL;
	binaryTree *rightNode = NULL;

	leftNode = invertBinaryTree(head->rChild);
	rightNode = invertBinaryTree(head->lChild);

	head->lChild = leftNode;
	head->rChild = rightNode;

	return head;
}

/*
 * Note: Preferred when the tree is very deep and desired values or data
 * occurs infrequently.
 *
 * Time complexity: O(n)
 * space complexity: O(h)
 *
 *
 */

bool isBinarySearchTree(binaryTree *head)
{
	if(head == NULL)
		return true;

	if(head->lChild && head->lChild->key < head->key)
		return isBinarySearchTree(head->lChild);

	if(head->rChild && head->rChild->key > head->key)
		return isBinarySearchTree(head->rChild);

	return false;
}

/*
 * Note: Preferred when the tree is very deep and desired values or data
 * occurs infrequently.
 *
 * Time complexity: O(n)
 * space complexity: O(h)
 *
 *
 */


void printAllPathToLeaves(binaryTree *head)
{
	binaryTree *temp = 0;
	stack *ST = NULL;

	if(!head)
		return;

	ST = stackInit(10);

	pushStack(ST, head);
	if(head->lChild) printAllPathToLeaves(head->lChild);
	while((temp = popStack(ST)) != 0)
		printf("%d --> ", temp->key);

	if(head->rChild) printAllPathToLeaves(head->rChild);
		while((temp = popStack(ST)) != 0)
			printf("%d --> ", temp->key);

	return;
}

/*
 * Note: Preferred when the tree is very deep and desired values or data
 * occurs infrequently.
 *
 * Time complexity: O(n)
 * space complexity: O(h)
 *
 *
 */


binaryTree *lowestCommonAncestor(binaryTree *head,
		binaryTree *node1,
		binaryTree *node2)
{
	if(head == NULL)
		return NULL;

	if((node1->key < head->key) && (node2->key < head->key))
		return lowestCommonAncestor(head->lChild, node1, node2);
	else if ((node1->key > head->key) && (node2->key > head->key))
		return lowestCommonAncestor(head->lChild, node1, node2);

	return head;
}

/*
 * Note: Preferred when the tree is very deep and desired values or data
 * occurs infrequently.
 *
 * Time complexity: O(n)
 * space complexity: O(h)
 *
 *
 */

bool checkTreesForSim(binaryTree *tree1, binaryTree *tree2)
{
	if(tree1->key != tree2->key)
		return false;

	checkTreesForSim(tree1->lChild, tree2->lChild);
	checkTreesForSim(tree1->rChild, tree2->rChild);

	return true;
}

/*
 * Note: To find the kth smallest element in the BST.
 *
 *
 * Time complexity: O(n)
 * space complexity: O(n)
 *
 *
 */

void findKthSmallestElem(binaryTree *root, uint32 k)
{
	if(root == NULL)
		return;

	uint32 c = 0;

	inorder_traversal(root, k, &c);
}


/*
bool lockBinaryTreeNode(binaryTree *head)
{
	bool enableLocked = false;
	if (isParentLocked(head) || head->descendentCount)
		return false;
	else {
		head->locked = true;
		updateParent(head, enableLocked=true);
		return true;
	}
}

bool unlockBinaryTreeNode(binaryTree *head)
{
	bool enableLocked = false;
	if (isParentLocked(head) || head->descendentCount)
		return false;
	else {
		head->locked = false;
		updateParent(head, enableLocked=false);
		return true;
	}
}
*/



void printBoundaryValue(binaryTree *root)
{
	if(root == NULL)
		return;

	queue *QE = NULL;

	printf("Init Binary Queue.\n");
	QE = initBinaryQueue(20);
	if(QE == NULL) {
		perror("failed to allocate Memory.\n");
		return;
	}

	printf("enqueue root\n");
	QE = enqueue(QE, root);

	if(root->lChild) {
		printf("get the left nodes. \n");
		printFromQueue(QE);
		QE = getLeftNodes(root->lChild, QE);
	}

	printf("Get leaf nodes \n");
	QE = getAllLeafNodes(root, QE);

	if(root->rChild) {
		printf("get all the right nodes \n");
		QE = getAllRightNodesButtomUP(root->rChild, QE);
	}

	printFromQueue(QE);

	DestroyQueue(QE);

	return;
}


int main(int argc, char **argv) {
	binaryTree *root = NULL;
	uint32 depth = 0;
//	binaryTree *kthsmall = NULL;
	bool status = true;

	root = pushToTree(root, 11);
	root = pushToTree(root, 6);
	root = pushToTree(root, 14);
	root = pushToTree(root, 4);
	root = pushToTree(root, 7);
	root = pushToTree(root, 5);
	root = pushToTree(root, 8);
	root = pushToTree(root, 9);
	root = pushToTree(root, 10);

	root = pushToTree(root, 13);
	root = pushToTree(root, 16);
	root = pushToTree(root, 15);
	root = pushToTree(root, 12);
	root = pushToTree(root, 17);
	root = pushToTree(root, 18);
/*
	printf("The left child: %d\n", sizeOfBinaryTree(root));

	breadthFirstSearch(root);

	depth = deepestNodeBinaryTree(root);

	printf("Depth : %d\n", depth);
*/
//	findKthSmallestElem(root, 3);

//	status = checkForAncestor(root, 7, 6);

	printf("Print Boundary Value.\n");

	printBoundaryValue(root);

	return 0;
}

