typedef struct avlNode{
	int data;
	int height;
	avlNode* left;
	avlNode* right;
}avlNode;

class avlTree{	
	private:
		avlNode* root;
		
		// get the height of a subtree
		int getHeight(avlNode* node);
		// set the height of a subtree
		void setHeight(avlNode* subroot, const int subtreeHeight);	
		// For LL, use single right rotation
		avlNode* SingleRightRotate(avlNode* subroot);
		// For LR, use double right rotation
		avlNode* DoubleRightRotate(avlNode* subroot);
		// For RR, use single left rotation
		avlNode* SingleLeftRotate(avlNode* subroot);
		// For RL, use double left rotation
		avlNode* DoubleLeftRotate(avlNode* subroot);
		
	public:
		// constructor
		avlTree();
		// destructor
		~avlTree();
		// get the root of the tree
		avlNode*& getRoot();
		// create or insert node
		avlNode* insert(avlNode* &subroot, const int value);
		// pre-order:  recursive realization
		void pre_order_traversal(avlNode* node);
		// in-order: recursive realization
		void in_order_traversal(avlNode* node);
		// search a target node: non recursive realization 
		avlNode* search_for_node(avlNode* sub_root, const int target);
		
	protected:
		// delete a subtree whose root is node
		void deleteSubtree(avlNode* node);
};


