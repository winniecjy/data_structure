#include<iostream>
using namespace std;
#define num_chars 26
struct TrieNode{
	int count;
	TrieNode *branches[num_chars];
};

class Trie{
	public:
		// constructor
		Trie(){
			root = new TrieNode;
			for(int i=0; i<num_chars; i++){
				root->branches[i] = NULL;
				root->count = 0;
			}
		}
		// destructor
		~Trie(){
			deleteNode(root);
			root = NULL;
		}
		
		// create or insert new string
		void insert(const string str){
			int len = str.length();
			if(len<=0) return;
			
			TrieNode *recNode = root;
			for(int i=0; i<len; i++){
				if(recNode->branches[str[i]-'a']==NULL){
					TrieNode *tmp = new TrieNode;
					for(int j=0; j<num_chars; j++)
						tmp->branches[j] = NULL;
					tmp->count = 0;
					recNode->branches[str[i]-'a'] = tmp;
					recNode = tmp;
				}
				else{
					recNode = recNode->branches[str[i]-'a'];
				}
			}
			recNode->count++;
		} 
		
		// Check whether a string exists in the trie
		bool search(const string str){
			int len = str.length();
			if(len<=0) return true;
			TrieNode *recNode = root;
			for(int i=0; i<len; i++){
				if(recNode->branches[str[i]-'a']==NULL)
					return false;
				recNode = recNode->branches[str[i]-'a'];
			}
			if(recNode->count>0) return true;
			
			return false;
		}
		
	protected:
		void deleteNode(TrieNode *node){
			for(int i=0; i<num_chars; i++){
				if(node->branches[i]!=NULL){
					deleteNode(node->branches[i]);
				}
			}
			delete node;
		}
		
	private:
		TrieNode *root;
};

void Test(){
	Trie trie;
	trie.insert("hello");
	trie.insert("he");
	trie.insert("her");
	trie.insert("world");
	trie.insert("word");
	if(trie.search("hello")) cout << "YES" << endl;
	else cout << "NO" << endl; 
	if(trie.search("hel")) cout << "YES" << endl;
	else cout << "NO" << endl;
	if(trie.search("helloooo")) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main(){
	Test();
	
	return 0;
} 
