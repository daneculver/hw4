#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here

//Uses recursion to check whether or not they are equal
bool heightMachine(struct Node *root, int height, int *leafHeight)
{
    //Base case
    if (root == NULL) return true;
    // If a leaf node is encountered
    if (root->left == NULL && root->right == NULL){
        // First leaf node found
        if (*leafHeight == 0)
        {
					// Sets the height of the first found leaf
            *leafHeight = height; 
            return true;
        }
        // Compare level with first leaf's level
        return (height == *leafHeight);
    }
    //Recursively check right and left trees 
    //if this node is not a leaf.
    return heightMachine(root->left, height + 1, leafHeight) &&
        heightMachine(root->right, height + 1, leafHeight);
}
bool equalPaths(Node * root)
{
    // Add your code below
	int height = 0, leafHeight = 0;
  return heightMachine(root, height, &leafHeight);
}

