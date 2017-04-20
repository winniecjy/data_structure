typedef struct Node{
	int data;
	Node* left;
	Node* right;
}Node;

class BinarySearchTree{
	private:
		Node *root;
		
	public:
		// constructor
		BinarySearchTree();
		// destructor
		~BinarySearchTree();
		Node* getRoot();
		// create or insert node
		void insert(const int value);
		// delete a node
		void remove_node(const int value);
		/*
		/* All traversal function 
		*/
		// pre-order:  recursive realization
		void pre_order_traversal1(Node* node);
		// pre-order: non recursive realization
		void pre_order_traversal2(Node* node);
		// in-order: recursive realization
		void in_order_traversal1(Node* node);
		// in-order: non recursive realization
		void in_order_traversal2(Node* node);
		// post-order: recursive realization
		void post_order_traversal1(Node* node);
		// post-order: non recursive realization
		void post_order_traversal2(Node* node);
		// level traversal: non recursive realization
		void level_traversal(Node* node);
		
		// search a target node: recursive realization
		Node* search_for_node1(Node* sub_root, const int target);
		// search a target node: non recursive realization 
		Node* search_for_node2(Node* sub_root, const int target);
		
	protected:
		// delete a subtree whose root is node
		void deleteSubtree(Node *node);
};


