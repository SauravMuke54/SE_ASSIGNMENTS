#include<iostream>

#include<string.h>

using namespace std;

class node
{
     public:
     char data[200];
      string key;
     	node *left;
     	node *right;
};

class bst
{

public:
		node *root;
	bst() 
	{
		root=NULL; 
	}
	
	void insert();
	void inorder(node *root);
	void print_ascending(node *);
	void print_descending(node *);
	int search(node * root,string k);
	node* delet(node * root,string k);
	int update(node * root,string k);
	node* minimum(node *q);
	
 	
   
};

void bst::print_ascending(node *root)
{
	if(root!=NULL)
	{
		print_ascending(root->left);
		cout<<" "<<root->key <<" : "<<root->data<<"\n";
		print_ascending(root->right);
	}
}
void bst::print_descending(node *root)
{
	if(root!=NULL)
	{
		print_descending(root->left);
		print_descending(root->right);
		cout<<" "<<root->key <<" : "<<root->data<<"\n";
	}
}

int bst::search(node * root,string k)
{
 int c=0;
 while(root != NULL)
 {
  c++;
  if(k==root->key)
  {
   cout<<"\nNo of Comparisons:"<<c;
   return 1;
  }
  if(k< root->key)
   root = root->left;
  if(k > root->key)
   root = root->right;
 }

 return -1;
}
node* bst::delet(node * root,string k)
{
 node *temp;

 if(root == NULL)
 {
  cout<<"\nElement No Found";
  return root;
 }

 if (k < root->key)
 {
  root->left = delet(root->left, k);
  return root;
 }
 if (k > root->key)
 {
   root->right = delet(root->right, k);
   return root;
 }

 if (root->right==NULL&&root->left==NULL)
 {
  temp = root;
  delete temp;
  return NULL;
  }
  if(root->right==NULL)
  {
  temp = root;
  root = root->left;
  delete temp;
  return root;
  }
  else if(root->left==NULL)
  {
  temp = root;
  root = root->right;
  delete temp;
  return root;
  }
  temp = minimum(root->right);
  root->key = temp->key;
  root->right = delet(root->right, temp->key);
  return root;

}
node * bst :: minimum(node *q)
{
 while(q->left != NULL)
 {
  q = q->left;
 }
 return q;
}
int bst :: update(node * root,string k)
{
 while(root != NULL)
 {
  if(k==root->key)
  {
   cout<<"\nEnter New Meaning ofKeyword"<<root->key;
   cin.ignore();
	  cin.getline(root->data,200);
   return 1;
  }
  if(k < root->key)
   root = root->left;
  if(k > root->key)
   root = root->right;
 }
 return -1;
}


void bst::insert()
{
	node *curr,*temp;
	int ans=1;
 
	
	
		curr=new node;
     cout<<"enter key:";
     	cin>>curr->key;

	cout<<"enter data:";
  cin.ignore();
	  cin.getline(curr->data,200);
		curr->left=curr->right=NULL;
		if(root==NULL)
		{
			root=curr;
		}
		else
		{
			temp=root;
			while(1)
			{
				if(curr->key<=temp->key)
				{
					if(temp->left==NULL)
					{
						temp->left=curr;
						break;
					}
					else
					{
						temp=temp->left;
					}
				}
				else
				{
					if(temp->right==NULL)
					{
						temp->right=curr;
						break;
					}
					else
					{
						temp=temp->right;
					}
				}
			}
		}
}



int main()
{
	bst b,c,d;
	int key,ch;
	do
	{
		cout<<"\n1.Insert";
		cout<<"\n2. Ascending";
		cout<<"\n3. Descending";
		cout<<"\n4. Update";
		cout<<"\n5.Delete Keyword";
		cout<<"\n6.Search Keyword";
        cout<<"\npress 0 to exit\n";
		cout<<"enter your choice:";
		cin>>ch;
		switch(ch)
		{
			
			case 1:b.insert();
				break;
			case 2:b.print_ascending(b.root);
				break;
			case 3:b.print_descending(b.root);
				break;
			case 4:
			if(b.root == NULL)
  			{
  				cout<<"\nDictionary is Empty. First add keywords then try again ";
 			}
				else
				{
				cout<<"\nEnter Keyword which meaning  want to update:";
				string k;
				cin>>k;
				if(b.update(b.root,k) == 1)
				cout<<"\nMeaning Updated";
				else
				cout<<"\nMeaning Not Found";
				}
				break;
			case 5:
				if(b.root == NULL)
				{
				cout<<"\nDictionary is Empty. First add keywords then try again ";
				}
				else
				{
				cout<<"\nEnter Keyword which u want to delete:";
				string k;
				cin>>k;
				if(b.root == NULL)
				{
				cout<<"\nNo any Keyword";
				}
				else
				{
				b.root = b.delet(b.root,k);
					}
				}
				
		    case 6:
		        if(b.root == NULL)
				{
				cout<<"\nDictionary is Empty. First add keywords then try again ";
				}
				else
				{
				cout<<"\nEnter Keyword which u want to search:";
				string k;
				cin>>k;
				if(b.root == NULL)
				{
				cout<<"\nNo any Keyword";
				}
				else
				{
				    int val = b.search(b.root,k);
				    if(val==0){
				        cout<<"Element not found";
				    }else{
				        cout<<"Element found";
				    }
				}
				}
				}
						
	}while(ch!=0);
	return 0;
}



