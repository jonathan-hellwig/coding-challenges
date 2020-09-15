#include <iostream>

struct Node
{
  int mKey;
  Node* mRight;
  Node* mLeft;
};
Node* newNode(int key)
{
  Node* node = new Node;
  node->mKey = key;

  node->mLeft = nullptr;
  node->mRight = nullptr;
  return node;
}
void findNode(Node* &current, int key, Node* &parent)
{
  while(current != nullptr && current->mKey != key)
  {
    parent = current;
    if(key < current->mKey)
      current = current->mLeft;
    else 
      current = current->mRight;
  }
}
void postorder(Node* root)
{
  if(root == nullptr)
    return;
  postorder(root->mLeft);
  postorder(root->mRight);
  std::cout << root->mKey << " ";
}

void preorder(Node* root)
{
  if(root == nullptr)
    return;
  std::cout << root->mKey << " ";
  preorder(root->mLeft);
  preorder(root->mRight);
}

void inorder(Node* root)
{
  if(root == nullptr)
    return;
  inorder(root->mLeft);
  std::cout << root->mKey << " ";
  inorder(root->mRight);
}
Node* findMinimumKey(Node* current)
{
  while(current != nullptr)
  {
    current = current->mLeft;
  }
  return current;
}
Node* insertNode(Node* root, int key)
{
  if(root == nullptr)
    return newNode(key);

  if(key < root->mKey)
    root->mLeft = insertNode(root->mLeft, key);
  else if(key > root->mKey)
    root->mRight = insertNode(root->mRight, key);

  return root;
}
void insertIterative(Node* &root, int key)
{
  Node* current = root;

  if(root == nullptr)
  {
    root = newNode(key);
    return;
  }
  while(current->mKey != key)
  {
    if(key < current->mKey)
    {
      if(current->mLeft == nullptr)
        current->mLeft = newNode(key);
      current = current->mLeft;
    }
    else
    {
      if(current->mRight == nullptr)
        current->mRight = newNode(key);
      current = current->mRight;
    }
  }
}
/*void insertNode(Node* &root, int key)
{
  Node* parent = nullptr;
  findNode(root, key, parent);

  if(root)
    return;

  if(parent)
  {
    root = newNode(key);
    if(key < parent->mKey)
      parent->mLeft = root;
    else
      parent->mRight = root;
  }
  else
    root = newNode(key);
}*/ 
void deleteNode(Node* &root, int key)
{
  Node* parent = nullptr;
  Node* toDelete = root;
  findNode(toDelete, key, parent);

  if(toDelete == nullptr)
    return;

  Node* right = toDelete->mRight;
  Node* left = toDelete->mLeft;

  if(!right && !left)
  {
    if(toDelete != root)
    {
      if(toDelete == parent->mRight)
        parent->mRight = nullptr;
      else
        parent->mLeft = nullptr;
    }
    else
      root = nullptr;
    free(toDelete);
  }
  else if(right && left)
  {
    Node* successor = findMinimumKey(right);
    int val = successor->mKey;
    deleteNode(root, successor->mKey);
    toDelete->mKey = val;

  } 
  else 
  {
    Node* child = right?right:left;
    if(toDelete != root)
    {
      if(toDelete == parent->mRight)
        parent->mRight = child;
      else
        parent->mLeft = child;
    }
    else 
      root = child;
    free(toDelete);
  }
}

int main()
{
  Node* root = nullptr;
  int keys[] = {1, 5, 3, 7, 8, 2};

  for(int key: keys)
    insertIterative(root, key);
  inorder(root);
  std::cout << std::endl;
  deleteNode(root, 7);
  inorder(root);
  std::cout << std::endl;
  return 0;
}
