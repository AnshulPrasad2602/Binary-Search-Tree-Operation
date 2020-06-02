

//Code for binary Search tree

#include <iostream>
using namespace std;

class node
{
	public:
		int data;
		node *left;
		node *right;
};

class bin_search : public node
{
	public:
		node *root;
		
		bin_search()	//default constructor to initialise root
		{
			root = NULL;
		}
		
		void create()
		{
			cout << "\n\n\tCREATE NODE OF BINARY SEARCH TREE\n";
			char ch; //choice variable for user
			
			do
			{
				int data;
				node *temp;
				node *newnode = new node();
				
				cout << "\nEnter the value : ";
				cin >> data;
				newnode->data = data;	//storning data in node
				newnode->left = newnode->right = NULL;	//assigning pointer to null
				if (root == NULL)	//condition for empty tree
				{
					root = newnode;
					cout << "Root node created successfully.";
				}
				else
				{
					temp = root;
					while(1)
					{
						
						if (newnode->data < temp->data)
						{
							if (temp->left == NULL)
							{
								temp->left = newnode;
								cout << "Node added to the left.";
								break;
							}
							else
							{
								temp = temp->left;
								cout << "Temp moved to its left.\n";
							}
						}
						else if (newnode->data > temp->data)
						{
							if (temp->right == NULL)
							{
								temp->right = newnode;
								cout << "Node added to the right.\n";
								break;
							}
							else
							{
								temp = temp->right;
								cout << "Temp moved to its right.\n";
							}
						}
						
						
					}
				}
				cout << "\n\nAdd anymore node? Y/N\nEnter your choice : ";
				fflush (stdin);
				cin >> ch;
				fflush (stdin);
			}while (ch == 'y' || ch == 'Y');
		}
		
		void search_bintree()
		{
			cout << "\n\n\tSEARCH IN BINARY TREE\n\n";
			
			int ele;
			node *temp = root;
			
			cout << "Enter the search element : ";
			cin >> ele;
			if (temp == NULL)
			{
				cout << "Empty tree, no searching";
			}
			else
			{
				while(1)
				{
					if (temp->data == ele)
					{
						cout << "Element found.";
						break;
					}
					else if ((ele > temp->data) && (temp->right != NULL))
					{
						temp = temp->right;
						cout << "Temp moved to its right\n";
					}
					else if ((ele < temp->data) && (temp->left != NULL))
					{
						temp = temp->left;
						cout << "Temp moved to its left\n";
					}
					else
					{
						cout << "Element not found.";
						break;
					}
				}
			}
		}
		
		void delete_node()
		{
			cout << "\n\n\tDELETE NODE\n\n";
			
			int e;
			node *temp,*parent,*replace;
			node *father,*son;
			
			cout << "Enter element to delete : ";
			cin >> e;
			temp=root;
		
			while((temp->data!=e) && (temp!=NULL))
			{
				if(e<temp->data)
				{
					parent=temp;
					temp=temp->left;
				}
					
				else
				{
					parent=temp;
					temp=temp->right;
				}
			}
			
			if(temp==NULL)
			{
				cout<<"\nNumber  not found";
				return;			
			}
			
			if(temp->left==NULL)
			{
				replace=temp->right;
			}
			else if(temp->right==NULL)
			{
				replace=temp->left;
			}
			else
			{
				father=temp;
				replace=temp->right;
				son=replace->left;
		
				while(son!=NULL)
				{
					father=replace;
					replace=son;
					son=replace->left;
				}
		   
			
				if(father!=temp)
				{
					father->left=replace->right;
					replace->right=temp->right;
				}
				replace->left=temp->left;
				
		   }
			
			if(parent==NULL)
			{
				root=replace;
			}
			
			else
			{
				if(temp==parent->left)
				{
					parent->left=replace;
				}
				else
				{
					parent->right=replace;
				}
			}
			
			delete temp;
			
			cout<<"\nElement deleted successfully";
		}
		
		void insert_node()
		{
			cout << "\n\n\tINSERT NODE OF BINARY SEARCH TREE\n";
			char ch; //choice variable for user
			
			
				int data;
				node *temp;
				node *newnode = new node();
				
				cout << "\nEnter the value : ";
				cin >> data;
				newnode->data = data;	//storning data in node
				newnode->left = newnode->right = NULL;	//assigning pointer to null
				if (root == NULL)	//condition for empty tree
				{
					root = newnode;
					cout << "Root node created successfully.";
				}
				else
				{
					temp = root;
					while(1)
					{
						
						if (newnode->data < temp->data)
						{
							if (temp->left == NULL)
							{
								temp->left = newnode;
								cout << "Node added to the left.";
								break;
							}
							else
							{
								temp = temp->left;
								cout << "Temp moved to its left.\n";
							}
						}
						else if (newnode->data > temp->data)
						{
							if (temp->right == NULL)
							{
								temp->right = newnode;
								cout << "Node added to the right.\n";
								break;
							}
							else
							{
								temp = temp->right;
								cout << "Temp moved to its right.\n";
							}
						}
						
						
					}
				}
				
		}
};

void choice(bin_search tr)
{
	int ch;
	cout << "\n\n\nChoose one of the following :\n1. Create Binary Search Tree\n2. Search in binary Search tree\n3. Delete node\n4. Insert node\n5. Exit\nEnter Your Choice : ";
	cin >> ch;
	node *tt;
	switch (ch)
	{
		case 1 :
			tr.create();
			choice(tr);
			break;
			
		case 2 :
			tr.search_bintree();
			choice(tr);
			break;
			
		case 3:
			tr.delete_node();
			choice(tr);
			break;
			
		case 4:
			tr.insert_node();
			choice(tr);
			break;
			
		case 5 :
			exit(0);
			break;
			
		default : 
			cout << "Enter valid choice.";
			choice(tr);
	}
}

main()
{
	bin_search tr;
	choice(tr);
}
