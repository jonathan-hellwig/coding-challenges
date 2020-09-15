#include <stack>
#include <queue>
#include <iostream>

struct Node
{
  Node* rightChild;
  Node* leftChild;
  int key;
  
};

Node* newNode(int key)
{
    Node* result = new Node;
    result->rightChild = nullptr;
    result->leftChild = nullptr;
    result->key = key;
    return result;
}
class Tree
{
  private:
    Node* root;
  public:
    Tree()
    {
      root = newNode(1);
    }
    void builtTree(int numNodes)
    {
      builtTree(root, numNodes);
    }
    void builtTree(Node* node, int numNodes)
    {
      if(2*node->key <= numNodes)
      {
        node->leftChild = newNode(2*node->key);
        builtTreeRec(node->leftChild, numNodes);
        if(2*node->key+1 <= numNodes)
        {
          node->rightChild = newNode(2*node->key+1);
          builtTreeRec(node->rightChild, numNodes);
        }
      }
    }

    void printTree(Node* node, int spaces)
    {
      if(node == nullptr)
        return;
      
      spaces += 3;
      printTree(node->rightChild, spaces);

      for(int i=0; i<spaces; i++)
        std::cout << " ";
      std::cout << node->key << std::endl;
      
      printTree(node->leftChild, spaces);
    }

    void printTree()
    {
      printTree(root, 0);
    }
};

int main()
{
  std::cout << "Start executing code!" << std::endl;
  Tree bt;
  bt.builtTree(16);
  bt.printTree();
  std::cout << "Stop executing code!" << std::endl;
}
