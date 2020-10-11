#include <iostream>

using namespace std;

struct node 
{
	int val;
	node* next;
};

class LinkedList
{
	node* top;
	public:
		LinkedList()
		{
			top = nullptr;
		}
		void insert(int x, int pos);
		int size();
		void display();
		void search(int x);
		void deleteNode(int pos);
};

void LinkedList:: insert(int x, int pos)
{
	node* newNode = new node;
	newNode->val = x;
	//if list is empty
	if(top == nullptr)
	{
		cout<<"No element in list, data will be entered at top.\n";
		newNode->next = nullptr;
		top = newNode;
	}
	else
	{
		node* ptr = top;
		int nodeNo{1};
		while(ptr->next != nullptr && nodeNo < pos-1)
		{
			ptr = ptr->next;
			nodeNo++;
		}
		if(ptr == nullptr)
		{
			ptr->next = newNode;
			newNode->next = nullptr;
		}
		else
		{
			newNode->next = ptr->next;
			ptr->next = newNode;
		}
	}
}

void LinkedList:: display()
{
	node* n = top;
	while(n != nullptr)
	{
		cout<<n->val<<" -> ";
		n = n->next;
	}
	cout<<"null\n";
}

int LinkedList:: size()
{
	int size{};
	node* n = top;
	while(n != nullptr)
	{
		size++;
		n = n->next;
	}
	return size;
}

void LinkedList:: search(int x)
{
	int pos = 1;
	node* ptr = top;
	while(ptr != nullptr)
	{
		if(ptr->val == x)
		{
			cout<<"Number found at position: "<<pos<<endl;
			return;
		}
		pos++;
		ptr = ptr->next;
	}
	cout<<"Number not found!\n";
}

void LinkedList:: deleteNode(int pos)
{
	node* ptr = top;
	if(pos>this->size())
	{
		cout<<"Position is greater than size of list!!\n";
		return;
	}
	else
	{
		int nodeNo{1};
		while(nodeNo<pos-1)
		{
			ptr=ptr->next;
		}
		ptr->next = (ptr->next)->next;
	}
	
}

int main()
{
	LinkedList list;
	int choice;
	cout<<"-----------\n";
	cout<<"Linked List\n";
	cout<<"-----------\n";
	do {
		cout<<"\nWhat operation do you want to perform ->\n";
		cout<<"1. Insert\n2. Display\n3. CountAll\n4. Search\n5. Delete\n6. Exit\nEnter choice -> ";
		cin>>choice;
		switch (choice)
		{
		case 1:
			int newVal, position;
			cout<<"Enter new node information ->\n";
			cin>>newVal;
			cout<<"Where do you want to enter the node? (enter position, not index) -> ";
			cin>>position;
			list.insert(newVal,position);
			cout<<"*Node Entered*\n";
			break;
		case 2:
			list.display();
			break;
		case 3:
			cout<<"Size of Linked List = "<<list.size()<<endl;
			break;
		case 4:
			int num;
			cout<<"Enter number to search -> ";
			cin>>num;
			list.search(num);
			break;
		case 5: 
			int pos;
			cout<<"Which node do you want to delete (enter position, not index) -> ";
			cin>>pos;
			list.deleteNode(pos);
			break;
		case 6:
			cout<<"Now exiting...\n";
			break;
		default:
			cout<<"INVALID CODE!!\n";
			break;
		}
	} while (choice!=6);
	return 0;
}