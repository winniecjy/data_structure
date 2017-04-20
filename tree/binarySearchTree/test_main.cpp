#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

void testBinarySearchTree(){
	BinarySearchTree bst;
	bst.insert(2);
	bst.insert(1);
	bst.insert(3);
	bst.insert(5);
	bst.insert(0);
 	cout << "前序遍历："; bst.pre_order_traversal1(bst.getRoot()); cout << endl;
 	cout << "中序遍历："; bst.in_order_traversal1(bst.getRoot()); cout << endl;
 	cout << "后序遍历："; bst.post_order_traversal1(bst.getRoot()); cout << endl; 
 	cout << "层次遍历："; bst.level_traversal(bst.getRoot()); cout << endl;
 	cout << "value = 3的节点是否存在？ " << ((bst.search_for_node1(bst.getRoot(), 3)==NULL)?"NO":"YES") << endl;
 	cout << "移除value = 3的节点..." << endl;
 	bst.remove_node(3); 
 	cout << "前序遍历："; bst.pre_order_traversal1(bst.getRoot()); cout << endl;
	cout << "value = 3的节点是否存在？ " << ((bst.search_for_node1(bst.getRoot(), 3)==NULL)?"NO":"YES") << endl;
}

int main(){
	testBinarySearchTree();
	
	return 0;
} 
