#include <iostream>
#include <queue>
#include <stack> 
#include "BinarySearchTree.h"
using namespace std;

// constructor
BinarySearchTree::BinarySearchTree(){
	root = NULL;
}
// destructor
BinarySearchTree::~BinarySearchTree(){
	deleteSubtree(root);
	root = NULL;
}
Node* BinarySearchTree::getRoot(){
	return root;
}
// create or insert node
void BinarySearchTree::insert(const int value){
	if(root==NULL){
		root = new Node();
		root->left = NULL;
		root->right = NULL;
		root->data = value;
		return;
	}
	else{
		Node* recNode = root;
		while(recNode != NULL){
			if(recNode->data > value){
				if(recNode->left == NULL) break;
				recNode = recNode->left;
			}
			if(recNode->data < value){
				if(recNode->right == NULL) break;
				recNode = recNode->right;
			} 
		}
		Node* newNode = new Node();
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->data = value;
		if(recNode->data > value){
			recNode->left = newNode;
		}
		else
			recNode->right = newNode;
	}
}
// delete a node
void BinarySearchTree::remove_node(const int value){
	Node* sub_root = root;
	Node* parentNode = root;
	bool isLeft = true;
	if(sub_root==NULL || sub_root->data == value) return;
	while(sub_root!=NULL && sub_root->data != value){
		parentNode = sub_root;
		if(sub_root->data > value){
			sub_root = sub_root->left;
			isLeft = true;
		} 			
		else if(sub_root->data < value){
			sub_root = sub_root->right;
			isLeft = false;
		}
	} 
	if(sub_root == NULL) cout << "No target!" << endl;
	else if(sub_root->left == NULL){
		Node* del = sub_root;
		sub_root = sub_root->right;
		delete del;
	}
	else if(sub_root->right == NULL){
		Node* del = sub_root;
		sub_root = sub_root->left;
		delete del;
	}
	else{
		Node* parent = sub_root;
		Node* preNode = sub_root->left;
		while(preNode->right != NULL){
			parent = preNode;
			preNode = preNode->right;
		}
		sub_root->data = preNode->data;
		if(parent == sub_root) sub_root->left = preNode->left;
		else parent->right = preNode->left;
		delete preNode;
		return;
	}
	if(isLeft) parentNode->left = sub_root; 
	else parentNode->right = sub_root;
}
/*
/* All traversal function 
*/
// pre-order:  recursive realization
void BinarySearchTree::pre_order_traversal1(Node* node){
	if(node==NULL) return;
	cout << node->data << " ";
	if(node->left != NULL)
		pre_order_traversal1(node->left);
	if(node->right != NULL)
		pre_order_traversal1(node->right);
}    
// pre-order: non recursive realization
void BinarySearchTree::pre_order_traversal2(Node* node){
	if(node==NULL) return;
	Node* curNode = node;
	stack<Node*> s;
	while(curNode!=NULL || !s.empty()){
		while(curNode!=NULL){
			cout << curNode->data << " ";
			s.push(curNode);
			curNode = curNode->left;
		}
		curNode = s.top();
		s.pop();
		curNode = curNode->right;
	}
}    
// in-order: recursive realization
void BinarySearchTree::in_order_traversal1(Node* node){
	if(node==NULL) return;
	if(node->left != NULL)
		in_order_traversal1(node->left);
	cout << node->data << " ";
	if(node->right != NULL)
		in_order_traversal1(node->right);
}   
// in-order: non recursive realization
void BinarySearchTree::in_order_traversal2(Node* node){
	if(node==NULL) return;
	Node* curNode = node;
	stack<Node*> s;
	while(curNode!=NULL || !s.empty()){
		while(curNode != NULL){
			s.push(curNode);
			curNode = curNode->left;
		}
		curNode = s.top();
		s.pop();
		cout << curNode->data << " ";
		curNode = curNode->right;
	}
} 
// post-order: recursive realization
void BinarySearchTree::post_order_traversal1(Node* node){
	if(node==NULL) return;
	if(node->left != NULL)
		post_order_traversal1(node->left);
	if(node->right != NULL)
		post_order_traversal1(node->right);
	cout << node->data << " ";
}   
// post-order: non recursive realization
void BinarySearchTree::post_order_traversal2(Node* node){
	if(node == NULL) return;
	Node* curNode = node;
	Node* preNode = NULL;
	stack<Node*> s;
	s.push(curNode);
	while(!s.empty()){
		curNode = s.top();
		// visit a leaf node or all the children nodes have been visited
		if(curNode->left==NULL && curNode->right==NULL
		|| preNode!=NULL && (preNode==curNode->left || preNode==curNode->right)){
			cout << curNode->data << " ";
			s.pop(); 
			preNode = curNode;
		}
		else{
			if(curNode->right!=NULL){
				s.push(curNode->right);
			}
			if(curNode->left!=NULL){
				s.push(curNode->left);
			}
		}
	}
}
// level traversal: non recursive realization
void BinarySearchTree::level_traversal(Node* node){
	if(node==NULL) return;
	Node* curNode = node;
	queue<Node*> q;
	if(curNode != NULL) q.push(curNode);
	while(!q.empty()){
		curNode = q.front();
		q.pop();
		cout << curNode->data << " ";
		if(curNode->left != NULL) q.push(curNode->left);
		if(curNode->right != NULL) q.push(curNode->right);
	}
}
		
// search a target node: recursive realization
Node* BinarySearchTree::search_for_node1(Node* sub_root, const int target){
	if(sub_root==NULL || sub_root->data == target) return sub_root;
	if(sub_root->data > target) return search_for_node1(sub_root->left, target);
	if(sub_root->data < target) return search_for_node1(sub_root->right, target);
}
// search a target node: non recursive realization 
Node* BinarySearchTree::search_for_node2(Node* sub_root, const int target){
	if(sub_root==NULL || sub_root->data == target) return sub_root;
	while(sub_root!=NULL && sub_root->data != target){
		if(sub_root->data > target) 
			sub_root = sub_root->left;
		else if(sub_root->data < target) 
			sub_root = sub_root->right;
	} 
	return sub_root;
}

// delete a subtree whose root is node
void BinarySearchTree::deleteSubtree(Node *node){
	if(node->left!=NULL){
		deleteSubtree(node->left);
	}
	if(node->right!=NULL){
		deleteSubtree(node->right);
	}
	delete node;
	node = NULL;
}

