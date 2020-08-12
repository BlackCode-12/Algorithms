#include <iostream>
#include <stdlib.h>
using namespace std;

//Creating the nodes
//Maybe linking the child nodes to the parent node will help make some
//functions faster but it will increase the memory usage though
struct node
{
	int data;
	struct node *left;
	struct node *right;
};

node *head = NULL;

//Insertion
void insert(int data)
{
	struct node *temp = new node;
	struct node *node1 = new node;
	node1->data = data;
	temp = head;
	if(temp == NULL)
	{
		head = new node;
		head->data = node1->data;
		head->left = NULL;
		head->right = NULL;
	}
	else
	{
		cout<<"here";
		while(1)
		{
			if(node1->data >= temp->data && temp->right == NULL)
			{
				temp->right = new node;
				temp = temp->right;
				temp->data = node1->data;
				temp->right = NULL;
				temp->left = NULL;
				break;
			}
			else if(node1->data >= temp->data && temp->right != NULL)
			{
				temp = temp->right;
			}
			if(node1->data <= temp->data && temp->left == NULL)
			{
				temp->left = new node;
				temp = temp->left;
				temp->data = node1->data;
				temp->right = NULL;
				temp->left = NULL;
				break;
			}
			else if(node1->data <= temp->data && temp->left != NULL)
			{
				temp = temp->left;
			}		
		}
	}
}

//Displaying the BST
void printB()
{
	struct node *temp = new node;
	temp = head;
	while(temp!= NULL)
	{
		cout<<"Temp is "<<temp<<"\n";
		cout<<temp->left<<" "<<temp->data<<" "<<temp->right;
		cout<<"\n";
		if(temp->right != NULL)
		{
			temp = temp->right;
		}
		else{
			temp = temp->left;
		}	
	}
}

//Searching on a BST
struct node* search(int data)
{
	struct node *temp = new node;
	temp = head;
	while(temp != NULL)
	{
		if(temp->data == data)
		{
			return temp;
		}
		else if(temp->data < data)
		{
			temp = temp->right;
		}
		else if(temp->data > data)
		{
			temp = temp->left;
		}		
	}
	return NULL;
}


//Find max element of tree
struct node *findMax(node *temp)
{
	while(temp->right != NULL)
	{
		temp = temp->right;
	}
	return temp;
}

//deleting a node from a tree
//Assuming the node exists
void deleteNode(int data)
{
	struct node *use = new node;
	struct node *temp = new node;
	temp = head;
	
	//This is to get the parent of the node that we want to delete
	//Makes things much easier
	while(temp != NULL)
	{
		cout<<"FOrever";
		if(temp->data < data)
		{
			if(temp->right->data == data)
			{
				use = temp;
				break;
			}
			else
			{
				temp = temp->right;
			}
		}
		else if(temp->data > data)
		{
			if(temp->left->data == data)
			{
				use = temp;
				break;
			}
			else
			{
				temp = temp->left;
			}
		}		
	}
	int c = 0;
	if(use->right != NULL && use->right->data == data)
	{
		temp = use->right;
	}
	else if(use->left != NULL && use->left->data == data)
	{
		temp = use->left;
	}
	
	if(temp->left == NULL && temp->right == NULL)
	{
		if(use->right != NULL && use->right->data == data)
		{
			use->right = NULL;
		}
		else if(use->left != NULL && use->left->data == data)
		{
			use->left = NULL;
		}
	}
	else if(temp->left == NULL && temp->right != NULL)
	{
		if(use->right != NULL && use->right->data == data)
		{
			use->right = temp->right;
		}
		else if(use->left != NULL && use->left->data == data)
		{
			use->left = temp->right;
		}
	}
	else if(temp->left != NULL && temp->right == NULL)
	{
		if(use->right != NULL && use->right->data == data)
		{
			use->right = temp->left;
		}
		else if(use->left != NULL && use->left->data == data)
		{
			use->left = temp->left;
		}
	}
	else if(temp->left != NULL && temp->right != NULL)
	{
		if(use->right != NULL && use->right->data == data)
		{
			node *maxi = findMax(use->right);
			c = maxi->data;
			deleteNode(maxi->data);
			use->right->data = c;
		}
		else if(use->left != NULL && use->left->data == data)
		{
			node *maxi = findMax(use->left);	
			c = maxi->data;
			deleteNode(maxi->data);
			use->left->data = c;
		}
	}
}

int main()
{
	insert(12);
	insert(14);
	insert(16);
	insert(15);
	insert(10);
	insert(13);
	printB();
	node *temp = new node;
	temp = head;
	temp = temp->left;
	cout<<temp->left<<" "<<temp->data<<" "<<temp->right<<"\n";
	deleteNode(14);
	printB();
	temp = head;
	temp = temp->left;
	cout<<temp->left<<" "<<temp->data<<" "<<temp->right<<"\n";
}

