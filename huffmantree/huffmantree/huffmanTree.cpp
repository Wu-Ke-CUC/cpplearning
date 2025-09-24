#include<iostream>
#include<vector>
#include<queue>
//#include<algorithm>
using namespace std;
struct treeNode
{
	int date;
	treeNode* lChild;
	treeNode* rChild;
	treeNode(int n, treeNode* l, treeNode* r)
	{
		date = n;
		lChild = l;
		rChild = r;
	}
};
template<class T>
struct cmp
{
	bool operator()(const T& A, const T& B)const
	{
		return A->date > B->date;
	}
};
treeNode* buildHuffmanTree(vector<int> vec)
{
	//vector<treeNode*> b;
	priority_queue<treeNode*,vector<treeNode*>,cmp<treeNode*>> q;
	for (int i = 0; i < vec.size(); i++)
	{
		treeNode* temp = new treeNode(vec[i], NULL, NULL);
		//b.push_back(temp);
		q.push(temp);
	}
	treeNode* l = NULL, * r = NULL, * p = NULL;
	/*while (b.size() > 1)
	{
		sort(b.begin(), b.end(), [=](treeNode * A, treeNode * B) {return A->date > B->date;});
		l = b[b.size() - 1]; b.pop_back();
		r = b[b.size() - 1]; b.pop_back();
		p = new treeNode(l->date + r->date, l, r);
		b.push_back(p);
	}*/
	while (q.size()>1)
	{
		l = q.top(); q.pop();
		r = q.top(); q.pop();
		p = new treeNode(l->date + r->date, l, r);
		q.push(p);
	}
	return p;
}
int countWPL(treeNode* root)
{
	int WPL = 0, L = 0;
	queue<treeNode*>q;
	treeNode* last = root;
	treeNode* nlast = NULL;
	q.push(root);
	while (!q.empty())
	{
		treeNode* temp = q.front();
		//cout << temp->date << " ";
		if (temp->lChild == NULL && temp->rChild == NULL)
		{
			WPL += temp->date * L;
		}
		q.pop();
		if (temp->lChild != NULL)
		{
			q.push(temp->lChild);
			nlast = temp->lChild;
		}
		if (temp->rChild != NULL)
		{
			q.push(temp->rChild);
			nlast = temp->rChild;
		}
		if (temp == last)
		{
			//cout << endl;
			L++;
			last = nlast;
		}
	}
	return WPL;
}
int main()
{
	vector<int> vec{ 10,20,50,100 };
	treeNode* root = buildHuffmanTree(vec);
	//countWPL(root);
	int WPL = countWPL(root);
	cout << WPL;
	return 0;
}