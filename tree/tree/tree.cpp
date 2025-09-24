//#include<iostream>
//#include<vector>
//using namespace std;
//int binarySearch(vector<int> vec, int l, int r, int target)
//{
//	if (l > r)return -1;
//	int mid = (l + r) / 2;
//	if (vec[mid] == target)
//		return mid;
//	if (vec[mid] > target)
//		return binarySearch(vec, l, mid - 1, target);
//	if (vec[mid] < target)
//		return binarySearch(vec, mid + 1, r, target);
//}
//struct ListNode
//{
//	int date;
//	struct ListNode* next;
//	ListNode(int v)
//	{
//		date = v, next = NULL;
//	}
//};
//ListNode* head = NULL;
//ListNode* tail = NULL;
//void buildList(vector<int> vec)
//{
//	for (int i = 0; i < vec.size(); i++)
//	{
//		ListNode* Newp = new ListNode(vec[i]);
//		if (head == NULL)
//		{
//			head = Newp;
//		}
//		else
//		{
//			tail->next = Newp;
//		}
//		tail = Newp;
//	}
//}
//void printList(ListNode* head)
//{
//	ListNode* p = head;
//	while (p)
//	{
//		cout << p->date << " ";
//		p = p->next;
//	}
//}
//int main()
//{
//	vector<int> vec{ 1,2,3,4,5,6,7,8,9,0 };
//	buildList(vec);
//	printList(head);
//	return 0;
//}
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct treeNode
{
	int date;
	treeNode* lNext;
	treeNode* rNext;
	treeNode(int v)
	{
		date = v;
		lNext = rNext = NULL;
	}
};
treeNode* buildBinaryTree(vector<int> vec)
{
	treeNode* root = new treeNode(vec[0]);
	for (int i = 1; i < vec.size(); i++)
	{
		treeNode* temp = new treeNode(vec[i]);
		treeNode* troot = root;
		while (troot)
		{
			if (temp->date < troot->date)
			{
				if (troot->lNext == NULL)
				{
					troot->lNext = temp;
					break;
				}
				else
				{
					troot = troot->lNext;
				}
			}
			else if (temp->date > troot->date)
			{
				if (troot->rNext == NULL)
				{
					troot->rNext = temp;
					break;
				}
				else
				{
					troot = troot->rNext;
				}
			}
		}
	}
	return root;
}
void InOrder(treeNode* root)
{
	if (root == NULL)return;
	InOrder(root->lNext);
	cout << root->date;
	InOrder(root->rNext);
}
void BeOrder(treeNode* root)
{
	if (root == NULL)return;
	cout << root->date;
	BeOrder(root->lNext);
	BeOrder(root->rNext);
}
void AfOrder(treeNode* root)
{
	if (root == NULL)return;
	AfOrder(root->lNext);
	AfOrder(root->rNext);
	cout << root->date;
}
void LayerOrde(treeNode* root)
{
	queue<treeNode*> q;
	treeNode* last = root;
	treeNode* nlast = NULL;
	q.push(root);
	while (!q.empty())
	{
		treeNode* temp = q.front();
		cout << temp->date << " ";
		q.pop();
		if (temp->lNext != NULL)
		{
			q.push(temp->lNext);
			nlast = temp->lNext;
		}
		if (temp->rNext != NULL)
		{
			q.push(temp->rNext);
			nlast = temp->rNext;
		}
		if (temp == last)
		{
			cout << endl;
			last = nlast;
		}
	}
}
int treeHight(treeNode* root)
{
	if (root == NULL)return 0;
	return 1 + max(treeHight(root->lNext), treeHight(root->rNext));
}
bool binaryTreeSearch(vector<int> vec,int target)
{
	treeNode* root = buildBinaryTree(vec);
	while (root)
	{
		if (root->date == target)
		{
			return true;
		}
		else if (root->date > target)
		{
			root = root->lNext;
		}
		else
		{
			root = root->rNext;
		}
	}
	return false;
}
int main()
{
	vector<int> vec{ 5,7,3,9,1,4,6,2,8,10 };
	treeNode* root = buildBinaryTree(vec);
	//InOrder(root);
	//BeOrder(root);
	//AfOrder(root);
	LayerOrde(root);
	//cout << binaryTreeSearch(vec, 2);
	cout << treeHight(root);
	return 0;
}