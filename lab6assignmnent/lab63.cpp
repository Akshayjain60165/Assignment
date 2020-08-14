#include <iostream>

using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

class avlTree{

public:
    node* root;
    avlTree(){root = NULL;}

    //HEIGHT OF TREE
    int height(node* ptr){
        if(ptr == NULL)
            return 0;

        int leftHeight, rightHeight;
        leftHeight = height(ptr->left);
        rightHeight = height(ptr->right);
        if(leftHeight > rightHeight)
            return leftHeight + 1;
        else return rightHeight + 1;
    }

    //HEIGHT DIFFERENCE BETWEEN LEFT AND RIGHT SUBTREES OF PTR
    int heightDiff(node* ptr){
        return height(ptr->left) - height(ptr->right);
    }

    //LEFTROTATE ABOUT PTR
    void leftRotate(node*& ptr){
        if(ptr == NULL)
            return;

        node* temp = ptr->right;
        ptr->right = ptr->right->left;
        temp->left = ptr;
        ptr = temp;
    }

    //RIGHTROTATE ABOUT PTR
    void rightRotate(node*& ptr){
        if(ptr == NULL)
            return;

        node* temp = ptr->left;
        ptr->left = ptr->left->right;
        temp->right = ptr;
        ptr = temp;
    }

    //REBALANCE ABOUT PTR
    void rebalanceTree(node*& ptr){
        if(ptr == NULL)
            return;

        if(heightDiff(ptr) > 1){
            //left-left type
            if(heightDiff(ptr->left) >= 1)
                rightRotate(ptr);

            //left-right type
            else if(heightDiff(ptr->left) <= -1){
                leftRotate(ptr->left);
                rightRotate(ptr);
            }
        }

        else if(heightDiff(ptr) < -1){
            //right-right type
            if(heightDiff(ptr->right) <= -1)
                leftRotate(ptr);

            //right-left type
            else if(heightDiff(ptr->right) >= 1){
                rightRotate(ptr->right);
                leftRotate(ptr);
            }
        }

        rebalanceTree(ptr->left);
        rebalanceTree(ptr->right);
    }

    //INSERTS A NODE AND BALANCES TREE
    void addNode(node*& ptr, int elem){
        if(ptr == NULL){
            node* temp = new node();
            temp->data = elem;
            temp->left = NULL;
            temp->right = NULL;
            ptr = temp;
            rebalanceTree(root);
            return;
        }

        if(ptr->data >= elem)
            addNode(ptr->left,elem);

        else addNode(ptr->right,elem);
    }

    //DELETES A NODE AND REBALANCES TREE
    void deleteNode(node*& ptr, int elem){
        if(ptr == NULL)
            return;

        else if(elem > ptr->data)
            deleteNode(ptr->right,elem);

        else if(elem < ptr->data)
            deleteNode(ptr->left,elem);

        else{
            if(ptr->left == NULL && ptr->right == NULL){
                ptr = NULL;
                rebalanceTree(root);
                return;
            }

            node* temp = ptr->right;
            while(temp!= NULL && temp->left != NULL)
                temp = temp->left;

            ptr->data = temp->data;
            deleteNode(ptr->right,temp->data);

            rebalanceTree(root);
            return;
        }
    }

    //CHECKS IF TREE IS BALANCED
    bool isBalanced(node* ptr){
        if(ptr == NULL)
            return true;

        if(height(ptr->left) - height(ptr->right) > 1 || height(ptr->left) - height(ptr->right) < -1)
            return false;

        return isBalanced(ptr->left) && isBalanced(ptr->right);
    }

    //LEVEL ORDER TRAVERSAL
    void printLevelOrder(node* ptr){
        int level = height(ptr);
        int j;
        for(j=1;j<=level;j++){
             printCurrentLevel(ptr,j);
        }
        cout << endl;
    }

    //PRINTS CURRENT LEVEL
    void printCurrentLevel(node* ptr, int level){
        if(ptr==NULL)
            return;
        if(level == 1)
            cout << ptr->data << " ";
        else if(level > 1){
            printCurrentLevel(ptr->left,level-1);
            printCurrentLevel(ptr->right,level-1);
        }
    }

    //RETURNS ROOT
    node* getRoot(){
        return root;
    }
};

int main(){

    avlTree tree;

    cout << "Select the operation and enter the number to inserted or deleted." << endl;
    cout << "1) Insertion" << endl << "2) Deletion" << endl;

    int i,elem;

    while(1){
        cin >> i;
        if(i==1){
            cin >> elem;
            cout << "List before the operation: ";
            tree.printLevelOrder(tree.root);
            cout << "List after the operation: ";
            tree.addNode(tree.root,elem);
            tree.printLevelOrder(tree.root);
        }

        else if(i==2){
            cin >> elem;
            cout << "List before the operation: ";
            tree.printLevelOrder(tree.root);
            cout << "List after the operation: ";
            tree.deleteNode(tree.root,elem);
            tree.printLevelOrder(tree.root);
        }

        else if(i!=1 || i!= 2)
            break;
    }

    return 0;
}
