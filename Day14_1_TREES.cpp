#include <iostream>
#include <queue>
using namespace std;

class TreeNode{
public:
    int data ;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

int levelOrderSum(TreeNode* root, int k) {
    if (!root) return 0;

    queue<TreeNode*> q;
    q.push(root);
    int currentLevel = 0;
    int sum = 0;

    while (!q.empty()) {
        int levelSize = q.size();
        if (currentLevel == k) {
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->data;
            }
            break;
        } else {
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            currentLevel++;
        }
    }

    return sum;
}

int sumOfData(TreeNode *root ){
    if(!root) return 0;
    return root->data + sumOfData(root->left) + sumOfData(root->right);
}

int countNodes(TreeNode *root){
    if(!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}



int heightOfTree(TreeNode *root){
    if(!root) return 0;
    return 1+ max(heightOfTree(root->left), heightOfTree(root->right));    
}




int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    int k = 2;
    int sum = levelOrderSum(root, k);
    cout << "Sum of nodes at level " << k << ": " << sum << endl;

    return 0;
}
