#include<iostream>
using namespace std;
class node
{
	int data;
	node*left;
	node*right;
	friend class BinaryTree;
	public:
		node(int val)
		{
			data=val;
			left=NULL;
			right=NULL;
		}
};
class Stack
{
	node*S[20];
	int top;
	public:
		Stack()
		{
			top=-1;
		}
	node*pop();
	void push(node*);
	int isfull();
	int isempty();
};
node*Stack::pop()
{
	node*P;
	P=S[top];
	top=top-1;
	return P;
}
void Stack::push(node*P)
{
	top=top+1;
	S[top]=P;
}
int Stack::isfull()
{
	if(top==19)
		return 1;
	else
		return 0;
}
int Stack::isempty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
class BinaryTree
{
	node*root;
	public:
		BinaryTree()
		{
			root=NULL;
		}
	node*create();
	void nonrec_inorder();
	void nonrec_preorder();
	void nonrec_postorder();
};
node*BinaryTree::create()
{
	int val;
	cout<<"enter value";
	cin>>val;
	if(val==-1)
		return NULL;
	node*P=new node(val);
	if(root==NULL)
		root=P;
	cout<<"enter left child node for "<<val;
	P->left=create();
	cout<<"enter right child node for "<<val;
	P->right=create();
	return P;
}
void BinaryTree::nonrec_inorder()
{
	if(root==NULL)
		cout<<"\n Tree is empty!";
		Stack S;
		node*t=root;
		while(t!=NULL)
		{
			S.push(t);
			t=t->left;			
		}
		while(!S.isempty())
		{
			t=S.pop();
			cout<<" "<<t->data;
			t=t->right;
			while(t!=NULL)
			{
				S.push(t);
				t=t->left;		
			}
	     }
}

void BinaryTree::nonrec_preorder()
{    if(root==NULL)
		cout<<"\n Tree is empty!";
     Stack s;
	node*t = root;
    do
    {
        while(t!=NULL)
        {
            cout<<t->data;
            s.push(t);
            t = t->left;
        }
        t= s.pop();
        t = t->right;
    }while(!s.isempty());
}
int main()
{
	node*P;
	BinaryTree T1;
	P=T1.create();
	cout<<"inorder traversal is ";
	T1.nonrec_inorder();
	cout<<"preorder traversal is ";
	T1.nonrec_preorder();
	return(0);
}