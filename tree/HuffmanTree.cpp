#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node{
	int freq;
	Node* left;
	Node* right;
};

struct cmpNode{
	bool operator()(const Node* a, const Node* b){
		return a->freq >= b->freq;
	}
}; 

Node* mergeTree(Node* &small1, Node* &small2){
	Node* newNode = new Node();
	newNode->freq = small1->freq + small2->freq;
	newNode->left = small1;
	newNode->right = small2;
	return newNode;
} 

void level_traversal(Node* node){
	Node* curNode = node;
	queue<Node*> q;
	if(curNode != NULL) q.push(curNode);
	while(!q.empty()){
		curNode = q.front();
		q.pop();
		cout << curNode->freq << " ";
		if(curNode->left != NULL) q.push(curNode->left);
		if(curNode->right != NULL) q.push(curNode->right);
	}
}

int main(){
	int n, freq; 
	Node *less1, *less2, *root;
	cin >> n;
	// Construct MinHeap
	priority_queue<Node*, vector<Node*>, cmpNode> Q;
	for(int i=0; i<n; i++){
		cin >> freq;
		Node* newNode = new Node();
		newNode->freq = freq;
		newNode->left = NULL;
		newNode->right = NULL;
		Q.push(newNode); // Put the value into heap
	}
	while(Q.size() > 1){
		less1 = Q.top();
		Q.pop();
		less2 = Q.top();
		Q.pop();
		root = mergeTree(less1, less2);
		Q.push(root);
	}
	level_traversal(root);
	cout << "END" << endl;
	
	return 0;
}

