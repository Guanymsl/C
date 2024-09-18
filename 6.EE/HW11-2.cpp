#include <iostream>
using namespace std;

//############################# Do not modify the code below #############################//
// ================= node.h =================
class Node {
    friend class BST;
public:
    Node();
    Node(int value);
protected:
    int data;
    Node* left;
    Node* right;
};

// ================= bst.h =================
class BST {
public:
    BST();
    BST(Node* root);
    Node* search(int key);
    void insert(Node* node, int data);
    void preorder(Node* node);
    void inorder(Node* node);
    void postorder(Node* node);
    Node* reconstruct(int* preorder, int* inorder, int n);

    Node* root;
};

//############################# Do not modify the code above #############################//


//############################# Modify the code below #############################//

// ================= node.cpp =================
Node::Node() {

    data = 0;
    left = nullptr;
    right = nullptr;

}

Node::Node(int value) {

    data = value;
    left = nullptr;
    right = nullptr;

}

// ================= bst.cpp =================
BST::BST() { root = nullptr; }
BST::BST(Node* root) { this->root = root; }

Node* BST::search(int key) {

    Node* cur = root;

    while(cur != nullptr && cur->data != key){

        if(key > cur->data) cur = cur->right;
        else cur = cur->left;

    }

    return cur;

}

void BST::insert(Node* node, int data) {

    if (node == nullptr) {

        root = new Node(data);
        return;

    }

    if (data > node->data){

        if(node->right == nullptr) node->right = new Node(data);
        else insert(node->right , data);

    }else{

        if(node->left == nullptr) node->left = new Node(data);
        else insert(node->left , data);

    }

}

void BST::preorder(Node* node) {

    if(node != nullptr){

        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);

    }

}

void BST::inorder(Node* node) {

    if(node != nullptr){

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);

    }

}

void BST::postorder(Node* node) {

    if(node != nullptr){

        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";

    }

}

Node* BST::reconstruct(int* preorder, int* inorder, int n) {

    if(n == 0) return nullptr;

    Node* temp = new Node(preorder[0]);

    int ind;
    for(int i=0; i<n; i++) if(inorder[i] == temp->data) ind = i;

    temp->left = reconstruct(preorder + 1 , inorder , ind);
    temp->right = reconstruct(preorder + ind + 1 , inorder + ind + 1 , n - ind - 1);

    return temp;

}

//############################# Modify the code above #############################//

//############################# Do not modify the code below #############################//
void Sample1and2() {
    /*
        Goal:
            1. Construct a BST from a sequence of integers.
            2. Print the preorder traversal of the BST.
            3. Print the inorder traversal of the BST.
            4. Print the postorder traversal of the BST.
    */
    int n, data;
    cin >> n;

    BST bst;
    for (int i = 0; i < n; i++) {
        cin >> data;
        bst.insert(bst.root, data);
    }
    cout << "Preorder:\n";
    bst.preorder(bst.root);
    cout << "\nInorder:\n";
    bst.inorder(bst.root);
    cout << "\nPostorder:\n";
    bst.postorder(bst.root);
    cout << endl;
    return;
}

void Sample3() {
    /*
        Goal:
            1. Construct a BST from a sequence of integers.
            2. Print the preorder traversal of the BST.
            3. Search for several keys in the BST.
    */
    int n, data;
    cin >> n;

    BST bst;
    for (int i = 0; i < n; i++) {
        cin >> data;
        bst.insert(bst.root, data);
    }
    cout << "Preorder:\n";
    bst.preorder(bst.root);
    cout << endl;

    int key, num_search;
    cin >> num_search;
    for (int i = 0; i < num_search; i++) {
        cin >> key;
        if (bst.search(key) != nullptr) {
            cout << key << " is in the BST.\n";
        } else {
            cout << key << " is not in the BST.\n";
        }
    }

    return;
}

void Sample4() {
    /*
        Goal:
            1. Construct a BST from preorder and inorder traversal.
            2. Print the postorder traversal of the BST.
    */
    int n;
    cin >> n;
    int* preorder = new int[n];
    int* inorder = new int[n];
    for (int i = 0; i < n; i++)
        cin >> preorder[i];
    for (int i = 0; i < n; i++)
        cin >> inorder[i];

    BST bst;
    bst.root = bst.reconstruct(preorder, inorder, n);
    bst.postorder(bst.root);
    cout << endl;
    return;
}

int main() {
	int choice;
	// cout << "Enter a choice for the sample program:\n";
	cin >> choice;

	if (choice == 1 || choice == 2)
        Sample1and2();
	else if (choice == 3)
		Sample3();
	else if (choice == 4)
		Sample4();

	return 0;
}

//############################# Do not modify the code above #############################//