#include <iostream>
#include "avlTree.h"
using namespace std;

void test(){
	avlTree tree;
	tree.insert(tree.getRoot(), 1);
	tree.insert(tree.getRoot(), 2);
	tree.insert(tree.getRoot(), 3);
	tree.insert(tree.getRoot(), 4);
	tree.insert(tree.getRoot(), 5);
	tree.insert(tree.getRoot(), 6);
	cout << "前序遍历："; tree.pre_order_traversal(tree.getRoot()); cout << endl;
	cout << "中序遍历："; tree.in_order_traversal(tree.getRoot()); cout << endl;
	
}

int main(){
	test();
	
	return 0;
}
