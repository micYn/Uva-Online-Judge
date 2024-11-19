/****************************
Author: 尹信淳             
Date: Aug. 14,2023          
Purpose: UVa122
****************************/
#include <iostream>
#include <cstdlib>
#include <string>
#include <queue>
using namespace std;

struct node{    //tree node structure
    int value;
    node* left;
    node* right;

    node(int value) : value(value), left(NULL), right(NULL) {}
};
void destroyTree(node* root){   //destroy tree by recursion
    if(root == NULL) return;
    
    destroyTree(root->left);
    destroyTree(root->right);
    free(root);
}
bool EveryNodeHasItsValue(node* root){  //check if there's missing node
    if(root==NULL)  return true;

    if(root->value==-1) return false;
    bool flag = EveryNodeHasItsValue(root->left)&&EveryNodeHasItsValue(root->right) ;

    return flag;
}
void TreeLevelOrderTraversal(node* root){   //level-order traversal : using queue
    queue<node*> nodeQueue;
    nodeQueue.push(root);

    bool flag = false;  //為了符合輸出格式而生的flag
    while(!nodeQueue.empty()){
        if(flag==true)  cout<<" ";

        node* currentNode = nodeQueue.front();
        nodeQueue.pop();
        cout<<currentNode->value;
        
        if(currentNode->left != NULL) nodeQueue.push(currentNode->left);
        if(currentNode->right != NULL) nodeQueue.push(currentNode->right);

        flag = true;
    }
    cout<<endl;
}

int main(){

    node* inputTree = NULL;     //Tree Root
    node* current = NULL;

    string tempstr;
    int tempvalue;
    string temppath;

    bool valid=true;    //valid is true if 沒有重複給值
    int i,j;
    while(cin>>tempstr){
        if(tempstr!="()"){ 
            //Parse the input node
            tempvalue=0;
            temppath="";
            for(i=1;tempstr[i]!=',';i++){   
                tempvalue = tempvalue*10 + (tempstr[i]-'0');
            }
            for(j=i+1;tempstr[j]!=')';j++){
                temppath += tempstr[j];
            }
            ////////////////////////////////////////////////////////////

            //Add the node into the tree
            current = inputTree;
            if(temppath==""){
            //進來的是一個root
                    if(inputTree==NULL){
                    //這個tree目前還是空的
                        inputTree = new node(tempvalue);
                        current = inputTree;
                    }

                    else{ 
                        if(inputTree->value!=-1)    valid = false;  
                        //tree非空，且root已經給過值->重複給值
                        else    inputTree->value = tempvalue;   
                        //tree非空，且root還沒給值->給值
                    }    
            }
            else{
            //進來一個非root的node
                    if(inputTree==NULL){
                        inputTree = new node(-1);
                        current = inputTree;
                    }
                    for(i=0;i<temppath.length();i++){
                        if(temppath[i]=='L'){
                            if(current->left==NULL){
                                current->left = new node(-1);
                            }
                            current = current->left;
                        }
                        else{
                            if(current->right==NULL)    current->right = new node(-1);
                            current = current->right;
                        }
                    }
                    //(The tree is invalid if there is more than one value for one node.)
                    if(current->value!=-1)  valid=false;
                    else    current->value = tempvalue;
            }
            /////////////////////////////////////////////////////////////
        }
        else{   //這棵樹已經輸入完畢
            if( (!valid) || (!EveryNodeHasItsValue(inputTree)) ){
                //輸入的過程中若重複給值，則valid==false 需輸出not complete
                //如果有缺少不可或缺的node 也要輸出not complete
                cout<<"not complete"<<endl;
            }
            else{
                TreeLevelOrderTraversal(inputTree);
            }
            valid = true;
            destroyTree(inputTree);
            inputTree = NULL;
            //下一顆樹一切重新開始
        }
    }

    return 0;
}