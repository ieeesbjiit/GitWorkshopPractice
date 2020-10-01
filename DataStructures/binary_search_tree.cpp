//Implementation of RED and BLACK Tree.
//It is a self-balancing Binary Search Tree.


#include <iostream>
using namespace std;
enum Color
{
	RED, BLACK
};

struct nodeRB
{
	int element;
	// int blackHeight;
	Color color;
	struct nodeRB *left, *right, *parent;
};

struct STK
{
	struct nodeRB *nodeTemp;
	struct STK *next;
};

struct STK* pushIntoStack(struct STK *stk, struct nodeRB *node) {
	// cout << "Pushing into Stack: " << node -> element << '\n';
	if (stk == NULL)
	{
		// cout << "Empty Stack" << '\n';
		stk = new struct STK;
		// cout << "statement 1" << '\n';
		stk -> nodeTemp = node;
		// cout << "statement 2" << '\n';
		stk -> next = NULL;
		// cout << "statement 3" << '\n';
		return stk;
	}
	// cout << "Not Empyt Stack" << '\n';
	struct STK *temp = new struct STK;
	// cout << "statement 1" << '\n';
	temp -> nodeTemp = node;
	// cout << "statement 2" << '\n';
	temp -> next = stk;
	// cout << "statement 3" << '\n';
	return temp;
}

class RedBlackTree
{
private:
	struct nodeRB *root;
public:
	RedBlackTree();
	struct nodeRB* nullNode();
	struct nodeRB* initializeNode(int key);
	void leftRotate(struct nodeRB *x);
	void rightRotate(struct nodeRB *y);
	void redBlackTreeInsert(int key);
	void displayTree();
	~RedBlackTree();
	
};

RedBlackTree::RedBlackTree() {
	// cout << "RB Tree Object Created" << '\n';
	root = NULL;
}

struct nodeRB* RedBlackTree::nullNode() {
	struct nodeRB *nullnode = new struct nodeRB;
	nullnode -> element = -9999;
	nullnode -> color = BLACK;
	nullnode -> left = nullnode;
	nullnode -> right = nullnode;
	nullnode -> parent = NULL;
	return nullnode;
}

struct nodeRB* RedBlackTree::initializeNode(int key) {
	struct nodeRB *newnode = new struct nodeRB;
	newnode -> element = key;
	// newnode -> blackHeight = 1;
	newnode -> color = RED;
	newnode -> left = NULL;
	// newnode -> left -> parent = newnode;
	newnode -> right = NULL;
	// newnode -> right -> parent = newnode;
	newnode -> parent = NULL;
	// cout << "New Node Initialized for key: " << key << '\n';
	return newnode;
}

void RedBlackTree::leftRotate(struct nodeRB *x) {
	struct nodeRB *y = x -> right;
	x -> right = y -> left;
	if (y -> left != NULL)
	{
		x -> right -> parent = x;
	}
	y -> parent = x -> parent;
	if (x -> parent == NULL)
	{
		root = y;
	} else {
		if (x -> parent -> left == x)
		{
			x -> parent -> left = y;
		} else {
			x -> parent -> right = y;
		}
	}
	y -> left = x;
	x -> parent = y;
}

void RedBlackTree::rightRotate(struct nodeRB *y) {
	struct nodeRB *x = y -> left;
	y -> left = x -> right;
	if (x -> right != NULL)
	{
		y -> left -> parent = y;
	}
	x -> parent = y -> parent;
	if (y -> parent == NULL)
	{
		root = x;
	} else {
		if (y -> parent -> left == y)
		{
			y -> parent -> left = x;
		} else {
			y -> parent -> right = x;
		}
	}
	x -> right = y;
	y -> parent = x;
}

void RedBlackTree::redBlackTreeInsert(int key) {
	struct nodeRB *z = initializeNode(key);
	struct nodeRB *pr = NULL;
	if (root == NULL)
	{
		root = z;
		root -> color = BLACK;
		// cout << "Root Node Done" << '\n';
		// cout << "New Node at Root inserted: " << z -> element << " color: " << ((z -> color == RED) ? "RED" : "BLACK") << '\n';
		return ;
	}
	struct nodeRB *trav = root;
	while(trav != NULL) {
		pr = trav;
		if (trav -> element < key)
		{
			trav = trav -> right;
		} else {
			trav = trav -> left;
		}
	}
	// cout << "Parent node where the new node to be inserted: " << pr -> element << '\n';
	if (pr -> element < key)
	{
		pr -> right = z;
		// cout << "Right" << '\n';
	} else {
		pr -> left = z;
		// cout << "Left" << '\n';
	}
	z -> parent = pr;
	// cout << "Parent of new node: " << z -> parent -> element << '\n';
	if (pr != NULL)
	{
		// cout << "z:" << z -> element << '\n';
		// cout << "pr:" << pr -> element << '\n';
		while(pr != NULL && pr -> color == RED) {
			// cout << "Violation of rules" << '\n';
			struct nodeRB *uncleY = NULL;
			if (pr -> parent -> left == pr)
			{
				uncleY = pr -> parent -> right;
				// if(uncleY != NULL) {
				// 	cout << "Right uncleY: " << uncleY -> element << " color: " << ((uncleY -> color == RED) ? "RED" : "BLACK") << '\n';
				// } else {
				// 	cout << "Right uncleY BLACK" << '\n';
				// }
			} else {
				uncleY = pr -> parent -> left;
				// if(uncleY != NULL) {
				// 	cout << "Left uncleY: " << uncleY -> element << " color: " << ((uncleY -> color == RED) ? "RED" : "BLACK") << '\n';
				// } else {
				// 	cout << "Left uncleY BLACK" << '\n';
				// }
			}
			if (uncleY == NULL || uncleY -> color == BLACK)
			{
				// cout << "uncleY BLACK" << '\n';
				if(pr -> parent -> left == pr) {
					if(z -> element < pr -> element) {
						// cout << "CASE 3 LL" << '\n';
						rightRotate(pr -> parent);
						pr -> color = BLACK;
						pr -> right -> color = RED;
					} else {
						// cout << "CASE 3 LR" << '\n';
						leftRotate(pr);
						rightRotate(z -> parent);
						z -> color = BLACK;
						z -> left -> color = RED;
						z -> right -> color = RED;
					}
				} else {
					if (z -> element > pr -> element) 
					{
						// cout << "CASE 3 RR" << '\n';
						leftRotate(pr -> parent);
						pr -> color = BLACK;
						pr -> left -> color = RED;
					} else {
						// cout << "CASE 3 RL" << '\n';
						rightRotate(pr);
						leftRotate(z -> parent);
						z -> color = BLACK;
						z -> right -> color = RED;
						z -> left -> color = RED;
					}
				}
			} else {
				// cout << "CASE 1 uncleY RED Change Colors" << '\n';
				uncleY -> color = BLACK;
				pr -> color = BLACK;
				pr -> parent -> color = RED;
				z = pr -> parent;
				pr = z -> parent;
			}
			if (z -> parent == NULL)
			{
				z -> color = BLACK;
			}
		}
	}
	// cout << "New Node inserted: " << z -> element << " color: " << ((z -> color == RED) ? "RED" : "BLACK") << " parent: " << z -> parent -> element << '\n';
}

void RedBlackTree::displayTree() {
	struct STK *top = NULL;
	struct nodeRB *curr = root;
	// cout << "curr: " << curr -> element << '\n';
	while(top != NULL || curr != NULL) {
		// cout << "Outer Loop" << '\n';
		while(curr != NULL) {
			// cout << "Inner Loop" << '\n';
			top = pushIntoStack(top, curr);
			// cout << "Pushed: " << curr -> element << '\n';
			curr = curr -> left;
		}
		// cout << "out of inner loop 1" << '\n';
		curr = top -> nodeTemp;
		// cout << "out of inner loop 2" << '\n';
		top = top -> next;
		cout << "Element: " << curr -> element << " color: " << ((curr -> color == RED) ? "RED" : "BLACK") << '\n';
		curr = curr -> right;
		// cout << "out of inner loop 3" << '\n';
	}
}

int main(int argc, char const *argv[])
{
	RedBlackTree *rbtree = new RedBlackTree();
	int arr[] = {10, 20, 30, 40, 50};
	for (int i = 0; i < 5; ++i)
	{
		rbtree -> redBlackTreeInsert(arr[i]);
	}
	cout << "RedBlackTree Display" << '\n';
	rbtree -> displayTree();
	return 0;
}