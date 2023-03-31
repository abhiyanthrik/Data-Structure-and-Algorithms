#include <iostream>
#include"binarytree.h"
using namespace std;


int main()
{
   /* Tree t;
    t.levelOrder();
	t.inOrder();
	t.preOrder();
	t.postOrder();
	t.levelOrder();
	cout << "There are " << t.countNodes() << " nodes in the tree.\n";
	cout << "There are " << t.countLeaves() << " leaves in the tree.\n";
	cout << "There are " << t.twoDNodes() << " 2d nodes in the tree.\n";
	cout << "There are " << t.oneDNodes() << " 1d nodes in the tree.\n";
	cout << "There are " << t.deg2Or1() << " nodes with degree 1 or higher in the tree.\n";
	cout << "Height of the tree is: " << t.height() << endl;
	cout << "There are " << t.levels() << " levels in the tree.\n";*/

	int a[8] = { 30, 20, 10, 15, 25, 40, 50, 45 };
	BST bst{ a,8 };
	bst.display();
	bst.bFactor();
	cout << "Balance factor of the tree is: " << bst.treeBF() << endl;
	bst.convertIntoAVL();
	cout << "Balance factor of the tree is: " << bst.treeBF() << endl;
	bst.bFactor();
	bst.display();

	int a1[7] = { 10, 20, 30, 25, 28, 27, 5 };
	BST b;
	b.createAVL(a1, 7);
	b.display();
	//b.bFactor();
	b.avlDelete(25);
	b.display();
	//b.bFactor();
	b.insertAVL(23);
	b.display();
	//b.bFactor();

}