#include <iostream>
using namespace std;
#define MAX 50005
int father[MAX];

// Find the father of node x
int findFather(int x){
	if(father[x] != x) 
		return father[x] = findFather(father[x]); // path compression
	else return x;
}

// a and b are in the same set. The trees 
// that a and b belong to should be combined
int combineTree(int a, int b){
	father[findFather(a)] = findFather(b);
}

int main(){
	int numNode, numEdge, numQuery, tmp1, tmp2;
	cin >> numNode >> numEdge >> numQuery;
	
	// Initialize the father of each node as itself
	for(int i=1; i<=numNode; i++){
		father[i]=i;
	} 
	// if two trees are connected, combine them
	for(int i=1; i<=numEdge; i++){
		cin >> tmp1 >> tmp2;
		combineTree(tmp1, tmp2);
	}
	// check if two nodes are in one set
	for(int i=1; i<=numQuery; i++){
		cin >> tmp1 >> tmp2;
		if(findFather(tmp1)==findFather(tmp2)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
} 
