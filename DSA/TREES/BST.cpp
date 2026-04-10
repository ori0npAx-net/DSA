//---BINARY SEARCH TREE---//

#include <iostream>
using namespace std;

struct Bnode{
    int data;
    Bnode* left;
    Bnode* right;
};
Bnode* root = NULL;

Bnode* insert(Bnode* curr,int value){  
    if (curr==NULL){
        Bnode* temp=(Bnode*)malloc(sizeof(Bnode));
        temp->data= value;
        temp->left=NULL;
        temp->right=NULL;
        return temp;
    }

    if(value<curr->data){
        curr->left=insert(curr->left,value);
    
    }
    else{
        curr->right=insert(curr->right,value);
    }
    return curr;        //returns updated subtree
    
}

// DISPLAY //

void PreOrder(Bnode* curr){
    if(curr!= NULL){
        cout<<curr->data<<" ";
        PreOrder(curr->left);
        PreOrder(curr->right);
    }
}

void PostOrder(Bnode* curr){
    if (curr!= NULL){
        PostOrder(curr->left);
        PostOrder(curr->right);
        cout<<curr->data<<" ";
    }
}

void InOrder(Bnode* curr){
    if (curr!= NULL){
        InOrder(curr->left);
        cout<<curr->data<<" ";
        InOrder(curr->right);
    }
}

Bnode* search (Bnode* root,int ToFind){   
    // if (root==NULL||root->data==ToFind){
    //     return root;
    //}
    if(root==NULL){
        cout<<"\n"<<ToFind<<" not found";
        return root;
    }
    if (root->data==ToFind){
        cout<<"\n"<<ToFind<<" found";
        return root;
    }
    if (root->data>ToFind){
        return search(root->left,ToFind);
    }else{
        return search(root->right, ToFind);
    }

}
Bnode* MIN(Bnode* root){
    while (root->left!=NULL){
        root=root->left;
    }
    return root;
}

Bnode* Delete (Bnode* root,int ToDelete){
   
    if(root==NULL){
        cout<<"\nvalue not found to be deleted";
        return NULL;
    }
    //search//
    if(ToDelete>root->data){
        root->right=Delete(root->right,ToDelete);
    }
    else if(ToDelete<root->data){
        root->left=Delete(root->left,ToDelete);
    }
    else{
        if(root->left==NULL && root->right==NULL){      //has zero child
            delete (root);
            cout<<"\nnode deleted (0child)";
            return NULL;
            }

        else if(root->left==NULL){
            Bnode* temp=root->right;
            delete(root);
            cout<<"\nnode deleted (1 child on right)";
            return temp;
            }

        else if(root->right==NULL){
            Bnode* temp=root->left;
            delete root;
            cout<<"\nnode deleted (1 child on left)";
            return temp;
            }

        else{
            Bnode* temp=MIN(root->right);
            root->data=temp->data;
            root->right=Delete(root->right,temp->data);
        }
    }
    return root;
}


int main(){
   root= insert(root,45);
   root= insert(root,67);
   root= insert(root,23);
   root= insert(root,78);
   root= insert(root,70);
   cout<<"inorder: ";
    InOrder(root);
    cout<<"\npreorder: ";
    PreOrder(root);
    cout<<"\npostorder: ";
    PostOrder(root);
    search(root,45);
    search(root,67);
    search(root,10);
    root=Delete(root,70);



//     int choice;
//     cout<<"----BINARY SEARCH TREE----";
//     cout<<"SELECT ANY NUMBER FROM 1-6 TO PROCEED: \n 1-Insert \n 2-Search \n3-Delete\n4-InOder Traversal\n5-PostOrder Traversal\n6-PreOrder Traversal\n7-Exit\n";
//     cin>>"Enter a Number: ">>choice;
//     while(true){
//     if (choice==1){
// 		int num;
// 		cout<<"enter a number to insert in the tree:  ";
// 		cin>>num;
// 		insert(num);
// 	}
// 	if (choice==2){
// 		int num;
// 		cout<<"enter a number to search: ";
// 		cin>>num;
// 		search(num);
// 	}
// 	if(choice==3){
// 		int num;
// 		cout<<"enter a number to delete in the tree; ";
// 		cin>>num;
// 		Delete(Num);
// 	}
// 	if (choice==4){
//         cout<<"INORDER TRAVERSAL:";
// 		InOder();
// 	}
// 	if (choice==5){
//         cout<<"POSTORDER TRAVERSAL:";
// 		PostOrder();
// 	}
//     if (choice==6){
//         cout<<"PREORDER TRAVERSAL:";
//         PreOrder();
//     }
// 	if (choice==7){
// 		cout<<"program ended";
// 		break;
// 	}
	
// }
}




