#include <iostream>
#include <algorithm>
#include "avlTree.h"
using namespace std;

// constructor
avlTree::avlTree(){
	root = NULL;
}

// destructor
avlTree::~avlTree(){
	deleteSubtree(root);
	root = NULL;
}

// get the root of the tree
avlNode*& avlTree::getRoot(){
	return root;
}

// create or insert node
avlNode* avlTree::insert(avlNode* &subroot, const int value){
	if(NULL==subroot){ 	
		avlNode* newNode = new avlNode();
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->data = value;
		newNode->height = 0;
		if(NULL==root) root = newNode;
		return newNode;
	}
	else{
		if(subroot->data > value){
			// insert the node into the left subtree
			subroot->left =insert(subroot->left, value);
			// check if the subtree is still avl tree
			if(getHeight(subroot->left)-getHeight(subroot->right)>1){
				// LL: insert into the left children node of the left subtree
				if(value < subroot->left->data)
					subroot = SingleRightRotate(subroot);
				// LR: insert into the right children node of the left subtree
				if(value > subroot->left->data)
					subroot = DoubleRightRotate(subroot);
			}
		}
			
		if(subroot->data < value){
			// insert the node into the right subtree
			subroot->right = insert(subroot->right, value);
			// check if the subtree is still avl tree
			if(getHeight(subroot->right)-getHeight(subroot->left)>1){
				// RR: insert into the left children node of the left subtree
				if(value > subroot->right->data)
					subroot = SingleLeftRotate(subroot);
				// RL: insert into the right children node of the left subtree
				if(value < subroot->right->data)
					subroot = DoubleRightRotate(subroot);
			}
		}		
		setHeight(subroot, max(getHeight(subroot->left), getHeight(subroot->right))+1);
		
		return subroot;
	}
}

// pre-order:  recursive realization
void avlTree::pre_order_traversal(avlNode* node){
	if(node==NULL) return;
	cout << node->data << " ";
	if(node->left != NULL)
		pre_order_traversal(node->left);
	if(node->right != NULL)
		pre_order_traversal(node->right);
}

// in-order: recursive realization
void avlTree::in_order_traversal(avlNode* node){
	if(node==NULL) return;
	if(node->left != NULL)
		in_order_traversal(node->left);
	cout << node->data << " ";
	if(node->right != NULL)
		in_order_traversal(node->right);
}
		
// search a target node: non recursive realization 
avlNode* avlTree::search_for_node(avlNode* sub_root, const int target){
	if(sub_root==NULL || sub_root->data == target) return sub_root;
	while(sub_root!=NULL && sub_root->data != target){
		if(sub_root->data > target) 
			sub_root = sub_root->left;
		else if(sub_root->data < target) 
			sub_root = sub_root->right;
	} 
	return sub_root;
}

// delete the avl tree whose root is node
void avlTree::deleteSubtree(avlNode *node){
	if(node->left!=NULL){
		deleteSubtree(node->left);
	}
	if(node->right!=NULL){
		deleteSubtree(node->right);
	}
	delete node;
	node = NULL;
}

// get the height of a subtree
int avlTree::getHeight(avlNode* node){
	return (NULL==node)?-1:node->height;
}

// set the height of a subtree
void avlTree::setHeight(avlNode* subroot, const int subtreeHeight){
	subroot->height = subtreeHeight;
}

/* 
/* For LL, use single right rotation
/* subroot: the root of the minmal non-AVL tree
/* return : return new subtree root
*/
avlNode* avlTree::SingleRightRotate(avlNode* subroot){
	avlNode* originRoot = subroot;
	avlNode* newRoot = subroot->left;
	originRoot->left = newRoot->right;
	newRoot->right = originRoot;
	
	// Update the height of subtree
	originRoot->height = max(getHeight(originRoot->left), getHeight(originRoot->right))+1;
	newRoot->height =  max(getHeight(newRoot->left), getHeight(newRoot->right))+1;
	
	return newRoot;
}

/* 
/* For RR, use single left rotation
/* subroot: the root of the minmal non-AVL tree
/* return : return new subtree root
*/
avlNode* avlTree::SingleLeftRotate(avlNode* subroot){
	avlNode* originRoot = subroot;
	avlNode* newRoot = subroot->right;
	originRoot->right = newRoot->left;
	newRoot->left = originRoot;
	
	// Update the height of subtree
	originRoot->height = max(getHeight(originRoot->left), getHeight(originRoot->right))+1;
	newRoot->height =  max(getHeight(newRoot->left), getHeight(newRoot->right))+1;
	
	return newRoot;	
}

/* 
/* For LR, use double right rotation
/* subroot: the root of the minmal non-AVL tree
/* return : return new subtree root
*/
avlNode* avlTree::DoubleRightRotate(avlNode* subroot){
	// Use two single rotation to achieve double right rotation
	subroot->left = SingleLeftRotate(subroot->left);
	return SingleRightRotate(subroot);	
}

/* 
/* For RL, use double left rotation
/* subroot: the root of the minmal non-AVL tree
/* return : return new subtree root
*/
avlNode* avlTree::DoubleLeftRotate(avlNode* subroot){
	subroot->right = SingleRightRotate(subroot->right);
	return SingleLeftRotate(subroot);
}
