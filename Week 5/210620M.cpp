#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root == NULL) {
    return;
  }
  traverseInOrder(root->left);
  cout << root->key << " ";
  traverseInOrder(root->right);
}


// Insert a node
struct node *insertNode(struct node *node, int key) {
  if (node == NULL) {
    node = new struct node();
    node->key = key;
    node->left = node->right = NULL;
    return node;
  }
  else if (key <= node->key) {
    node->left = insertNode(node->left, key);
  }
  else {
    node->right = insertNode(node->right, key);
  }
  return node;
}


// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  if (root == NULL) {

    return NULL;
  }

  if (root->key == key) {
    if (root->left == NULL && root->right == NULL) {

      delete root;
      return NULL;
    } else if (root->right == NULL) {

      struct node *temp = root->left;
      delete root;
      return temp;
    } else if (root->left == NULL) {

      struct node *temp = root->right;
      delete root;
      return temp;
    } else {

      struct node *replace = root->right;
      while (replace->left != NULL) {
        replace= replace->left;
      }

      // Copy the value of the successor to the root node.
      root->key = replace->key;

      // Delete the successor node (which has no left child).
      root->right = deleteNode(root->right, replace->key);

      return root;
    }
  } else if (root->key > key) {
    root->left = deleteNode(root->left, key);
    return root;
  } else {
    root->right = deleteNode(root->right, key);
    return root;
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
}