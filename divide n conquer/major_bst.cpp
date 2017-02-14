#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
struct bst
{
	int number, c;
	bst *left, *right;
};
	
bst *get_node(int x)
{
	struct bst *temp;
	temp = (bst *) malloc(sizeof(bst));
	temp->number = x;
	temp->c = 1;
	temp->right = NULL;
	temp->left = NULL;
	return temp;
}
int insert( struct bst *root , int x)
{
		struct bst *new_node = get_node(x);
		if(root == NULL)
		{
			root = new_node;
			std::cout<<"*\n";
		}
		else
		{
			if(new_node->number == root->number)
			{
				
				root->c = root->c+1;
				return(root->c);
			}
			else if(new_node->number < root->number)
			{
				if(root->left == NULL)
				{
					root->left = new_node;	
				}
				else
				{
					insert(root->left,x);
				}
			}
			else if(new_node->number > root->number)
			{
				if(root->right == NULL)
				{
					root->right = new_node;
				}
				else
				{
					insert(root->right,x);
				}
			}
		}
		return(1);
}

int get_majority_element(vector<int> &a, struct bst *root)
{
 // if (left == right) return -1;
 // if (left + 1 == right) return a[left];
  
  int flag = 0;
  for(int i = 0; i<a.size();i++)
  {
  	int x = insert(root,a[i]);	
  	std::cout<<x<<"\n";
  	if(x>a.size()/2)
  	{
  		flag = 1;
  		break;
  	}
  }
 return(flag) ;
}
 void inorder(struct bst *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->number);
        inorder(root->right);
    }
}
int main() {
 struct bst *root = NULL;
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a,root)) << '\n';
   inorder(root);
}
