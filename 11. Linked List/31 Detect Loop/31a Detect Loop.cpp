#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node* next;

	Node(int data_)
	{
		data=data_;
		next=NULL;
	}
};

//Time: O(N)
//Space: O(N)
bool detectLoop(Node* &head)
{
	unordered_set<Node*> s;

	Node* curr=head;
	while(curr)
	{
		if(s.find(curr)!=s.end())
		{
			return true;
		}
		s.insert(curr);
		curr=curr->next;
	}

	return false;
}

int main()
{
	Node* node1=new Node(10);
	Node* node2=new Node(20);
	Node* node3=new Node(30);
	Node* node4=new Node(40);

	node1->next=node2;
	node2->next=node3;
	node3->next=node4;
	node4->next=node2;

	cout<<detectLoop(node1)<<endl;
	return 0;
}