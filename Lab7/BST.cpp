#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (!root) return;  // Nothing to print
  traverseInOrder(root->left);
  cout << root->key << " ";
  traverseInOrder(root->right);
}

// Preorder traversal
void traversePreOrder(struct node *root) {
  if (!root) return;  // Nothing to print
  cout << root->key << " ";
  traversePreOrder(root->left);
  traversePreOrder(root->right);
}

// Postorder traversal
void traversePostOrder(struct node *root) {
  if (!root) return;  // Nothing to print
  traversePostOrder(root->left);
  traversePostOrder(root->right);
  cout << root->key << " ";
}

// Insert a node
struct node *insertNode(struct node *root, int key) {
  if (!root) {  // create new node and make it root
      struct node *new_node = new struct node;
      new_node->key = key;
      new_node->left = NULL;
      new_node->right = NULL;
      return new_node;
  }
  if (root->key > key) {  
    if (root->left) { //Insert into left subtree
      insertNode(root->left, key);
    } else {  // Create new node and make it left
      struct node *new_node = new struct node;
      new_node->key = key;
      new_node->left = NULL;
      new_node->right = NULL;
      root->left = new_node;
    }
  } else if (root->key < key){
    if (root->right) {  //Insert into right subtree
      insertNode(root->right, key);
    } else {      // Create new node and make it right
      struct node *new_node = new struct node;
      new_node->key = key;
      new_node->left = NULL;
      new_node->right = NULL;
      root->right = new_node;
    }
  }
  return root;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  if (!root) return root;
  if (root->key > key) {  //should be in left subtree
    root->left = deleteNode(root->left, key);
    return root;
  } else if (root->key < key) {   // should be in right subtree
    root->right = deleteNode(root->right, key);
    return root;
  } else {  // This is what we should delete
    if (!root->left) { //replace root by root.right
      struct node *new_root = root->right;
      delete root;
      return new_root;

    } else if (!root->right) { //replace root by root.left
      struct node *new_root = root->left;
      delete root;
      return new_root;

    } else {
      // find minimum in right subtree
      struct node* min = root->right;
      while (min->left) {
        min = min->left;
      }
      //change key of root to min
      root->key = min->key;
      //delete min
      root->right = deleteNode(root->right, root->key);
      return root;
    }
  }
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
  cout << endl;
  traversePreOrder(root);
  cout << endl;
  traversePostOrder(root);
  cout << endl;
}