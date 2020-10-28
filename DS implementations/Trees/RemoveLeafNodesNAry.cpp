#include <iostream>
#include <vector>
using namespace std;

// TreeNode Struct
class TreeNode {
    public:
        int data;
        vector<TreeNode*> children;
        TreeNode(int data) {
            this->data = data;
        }
};

// Function that removes one leaf node
void removeLeaf(TreeNode* root) {
    // start iterating for each node
    for (int i = 0; i < root->children.size(); i++){
        TreeNode* child = root->children[i];
        // Check if we are @leafnode
        if (child->children.size() == 0){
            // Move ith element to the last position of the vector of root children
            for (int j = i; j < root->children.size(); j++)
                root->children[j] = root->children[j + 1];
            // We can pop last element of vector
            root->children.pop_back();
            i--;
        }
    }

    // Remove all leaf nodes
    for (int i = 0; i < root->children.size(); i++){
        removeLeaf(root->children[i]);
    }
}

void printTheTree(TreeNode* root) 
{ 
    if (root == NULL) 
        return; 
  
    cout << root->data << " "
         << ":"; 
    for (int i = 0; 
         i < root->children.size(); 
         i++) 
        cout << root->children[i]->data 
  
             << " "; 
    cout << endl; 
  
    for (int i = 0; 
         i < root->children.size(); 
         i++) 
        printTheTree(root->children[i]); 
} 
  
// Driver code 
int main() {   
    TreeNode* root = new TreeNode(5); 
    TreeNode* child1 = new TreeNode(1); 
    root->children.push_back(child1); 
    TreeNode* child11 = new TreeNode(15); 
    child1->children.push_back(child11); 
    TreeNode* child2 = new TreeNode(2); 
    root->children.push_back(child2); 
    TreeNode* child21 = new TreeNode(4); 
    TreeNode* child22 = new TreeNode(5); 
    child2->children.push_back(child21); 
    child2->children.push_back(child22); 
    TreeNode* child3 = new TreeNode(3); 
    root->children.push_back(child3); 
    TreeNode* child31 = new TreeNode(6); 
    child3->children.push_back(child31); 
    TreeNode* child4 = new TreeNode(8); 
    root->children.push_back(child4); 
  
    removeLeaf(root); 
    printTheTree(root); 
}