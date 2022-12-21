#include <iostream>
#include<algorithm>
#include<queue>
using namespace std;

class TreeNode;

class Tree {
public:
	void preorder() { preorder(root); }
	void inorder() { inorder(root); }
	void postorder() { postorder(root); }
	Tree() { root = 0; }
	void mktree(int, TreeNode*&);
private:
	TreeNode* root;
	void preorder(TreeNode*);
	void inorder(TreeNode*);
	void postorder(TreeNode*);
};

class TreeNode {
public:
	friend Tree;
	char data;
	TreeNode* leftChild;
	TreeNode* rightChild;
private:

};

void Tree::mktree(int s, TreeNode* &arr) {
	for (int i = 1; i <= s; i++) {
		char current, left, right;
		cin >> current >> left >> right;

		if (current == 'A')
			root=(&arr[int(current) - 64]);

		arr[int(current)-64].data = current;

			arr[int(left) - 64].data = left;
			arr[int(current) - 64].leftChild = &arr[int(left) - 64];

			arr[int(right) - 64].data = right;
			arr[int(current) - 64].rightChild = &arr[int(right) - 64];
	}
}

void Tree::preorder(TreeNode* current) {
	if (current->data == '.')
		return;
	cout << current->data;
	preorder(current->leftChild);
	preorder(current->rightChild);
}
void Tree::inorder(TreeNode* current) {
	if (current->data == '.')
		return;
	
	inorder(current->leftChild);
	cout << current->data;
	inorder(current->rightChild);
}
void Tree::postorder(TreeNode* current) {
	if (current->data == '.')
		return;
	
	postorder(current->leftChild);
	postorder(current->rightChild);
	cout << current->data;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int size;
	TreeNode* tree;
	cin >> size;
	tree = new TreeNode[size+1];

	TreeNode n;
	fill(tree, tree + size + 1, n);
	
	Tree a;
	a.mktree(size, tree);
	
	a.preorder();
	cout << "\n";
	a.inorder();
	cout << "\n";
	a.postorder();

}