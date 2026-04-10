// AVL TREE //

#include<iostream>
using namespace std;

struct AVLNode{
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;
};

AVLNode* root = nullptr;

int height (AVLNode* node)
{
    if (node == nullptr){
        return -1;
    }
    return node->height;
}

AVLNode* rotate_right(AVLNode* cur)
{
    AVLNode* temp = cur;
    cur = cur ->left;
    AVLNode* temp2 = cur ->right;
    cur ->right = temp;
    temp ->left = temp2;

    temp ->height = max(height(temp ->left), height(temp->right)) + 1;
    cur ->height = max(height(cur ->left), height(cur->right)) + 1;

    return cur;
}

AVLNode* rotate_left(AVLNode* cur)
{
    AVLNode* temp = cur;
    cur = cur ->right;
    AVLNode* temp2 = cur ->left;
    cur ->left = temp;
    temp ->right = temp2;

    temp ->height = max(height(temp ->left), height (temp ->right)) + 1;
    cur -> height = max(height(cur ->left), height (cur ->right)) + 1;

    return cur;
}

AVLNode* rotate_right_left(AVLNode* cur)
{
    cur -> right = rotate_right(cur ->right);
    return rotate_left(cur);
}

AVLNode* rotate_left_right(AVLNode* cur)
{
    cur ->left = rotate_left(cur -> left);
    return rotate_right(cur);
}

int balanceFactor(AVLNode* node)
{
    return height(node->left) - height(node->right);
}

AVLNode* insert(AVLNode* cur, int val)
{
    if (cur == nullptr)
    {
        AVLNode* temp = new AVLNode;
        temp ->data = val;
        temp ->left = nullptr;
        temp ->right = nullptr;
        temp->height = 0;
        return temp;
    }
    
    if (val < cur ->data)
    {
        cur ->left = insert(cur ->left, val);
    }
    else
    {
        cur ->right = insert (cur -> right, val);
    }
    
     
    cur -> height = max (height (cur -> left), height (cur -> right)) + 1;

    int bf = balanceFactor(cur);

    if (bf > 1 )
    {
        //if the left side has more nodes then it is left heavy
        int leftbf = balanceFactor(cur -> left);
        if (leftbf < 0)
        {
            return rotate_left_right(cur);
        }
        else
        {
            return rotate_right(cur);
        }
    }
    if (bf < -1)
    {
        //if the rught side has more nodes then it is right heavy
        int rightbf = balanceFactor(cur -> right);
        if (rightbf > 0)
        {
            return rotate_right_left(cur);
        }
        else
        {
            return rotate_left(cur);
        }
    }
    return cur;
}

AVLNode* remove (AVLNode* cur, int val)
{
    if (cur == nullptr)
    {
        return nullptr;
    }
    if (cur -> data == val)
    {
        //if the node has no child
        if (cur -> right == nullptr && cur -> left == nullptr)
        {
            delete cur;
            return nullptr;
        }
        //if the node has one child
        else if (cur ->left == nullptr){
            //the child exists on the left side
            AVLNode* temp = cur ->right;
            delete cur;
            return temp;
        }
        else if (cur ->right == nullptr){
            //the child exists on the right side
            AVLNode* temp = cur ->left;
            delete cur;
            return temp;
        }
        else{
            //have both child
            //find a successor(minimum value) that will take its place
            //-> go right once then most left and replace cur with sucessor then delete sucessor

            AVLNode* sucessor = cur -> right;
            while (sucessor ->left != nullptr)
            {
                sucessor = sucessor ->left;
            }
            cur -> data = sucessor -> data;
            cur -> right = remove (cur -> right, sucessor -> data);
        }
    }
    else if (val > cur ->data)
    {
        cur ->right = remove(cur ->right, val);
    }
    else
    {
        cur ->left = remove(cur ->left, val);
    }

    cur -> height = max(height(cur -> left), height(cur -> right)) + 1;

    int bf = balanceFactor(cur);

    if (bf > 1 )
    {
        int leftbf = balanceFactor(cur ->left);
        if (leftbf < 0)
        {
            return rotate_left_right(cur);
        }
        else
        {
            return rotate_right(cur);
        }
    }
    if (bf < -1)
    {
        int rightbf = balanceFactor(cur ->right);
        if (rightbf > 0)
        {
            return rotate_right_left(cur);
        }
        else
        {
            return rotate_left(cur);
        }
    }
    return cur;
}
void inorder(AVLNode* root)
{
    if (root == nullptr)
    {
        return;
    }
    else
    {
        inorder(root -> left);
        cout << root -> data << " ";
        inorder(root -> right);
    }
}
void preorder(AVLNode* root)
{
    if (root == nullptr)
    {
        return;
    }
    else
    {
        cout << root -> data << " ";
        preorder(root -> left);
        preorder(root -> right);
    }
}
void postorder(AVLNode* root)
{
    if (root == nullptr)
    {
        return;
    }
    else
    {
        postorder(root -> left);
        postorder(root -> right);
        cout << root -> data << " ";
    }
}

int main()
{
    int choice, value;
    while(true)
    {
        cout << "1. Insert\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Delete\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice == 1)
        {
            cout << "Enter value to insert: ";
            cin >> value;
            root = insert(root, value);
            cout << "Value inserted into the tree." << endl;
        }
        if(choice == 2)
        {
            cout << "Inorder Traversal: ";
            inorder(root);
            cout << endl;
        }
        else if(choice == 3)
        {
            cout << "Preorder Traversal: ";
            preorder(root);
            cout << endl;
        }
        else if(choice == 4)
        {
            cout << "Postorder Traversal: ";
            postorder(root);
            cout << endl;
        }
        else if(choice == 5)
        {
            cout << "Enter value to delete: ";
            cin >> value;
            root = remove(root, value);
            cout << "Value deleted from the tree." << endl;
        }
        else if(choice == 6)
        {
            break;
        }
    }
}