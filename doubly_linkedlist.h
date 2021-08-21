#include<iostream>
using namespace std;

// declaring a data structure for doubly linked list.
typedef struct DLL_node
{
	struct DLL_node *next;
	struct DLL_node *prev;
	int data;
}node;

// creating new node.
node *getNewNode(int data)
{
	node *new_node= new node;   //allocating dynamic memory.
    new_node->data=data;
    new_node->next=NULL;
	new_node->prev=NULL;
    return new_node;
}	

// insert element in the beggining 
node *insertNodeBeg(node *head,int data)
{
	node *tmp=getNewNode(data);
	if(head==NULL)  //no element in the list.
	{
		head=tmp;
		return head;
	}
	else
	{
		tmp->next=head;
		head->prev=tmp;
		head=tmp;
	} 	
}

//insert node at the end.
node *insertNodeEnd(node *head,int data)  
{
	node *p=getNewNode(data);
	node *tmp=head;
	while(tmp->next!=NULL)
	{
		tmp=tmp->next;
	}	
	tmp->next=p; //transfer of address.
	p->prev=tmp;
	return head;
}

//search an element in DLL.
node *findElement(node *head,int srch)
{
	node *tmp=head;
	node *p=NULL;
	while(tmp!=NULL)
	{
		if(tmp->data==srch)
		{
			p=tmp;
			break;
		}
		tmp=tmp->next;
	}
	return p;
}	

//insert node in the middle.
node *insertNodeMid(node *head,int srch,int data)
{
	node *tmp=findElement(head,srch);
	if(tmp==NULL)  //if no such element exists.
	{
		cout<<"Invalid position"<<endl;
		return head;
	}	
	node *p=getNewNode(data);
	p->prev=tmp;
	p->next=tmp->next;
	tmp->next->prev=p;  //(tmp->next)->prev
	tmp->next=p;
	return head;
}	

//delete node from the beg.
node *deleteNodeBeg(node *head)
{
	node *tmp=head;
	head=head->next;
	head->prev=NULL;
	delete tmp;
	return head;
}

//delete node from end.
node *deleteNodeEnd(node *head)
{
	node *tmp=head;
	while(tmp->next!=NULL)
	{
		tmp=tmp->next;
	}	
	tmp->prev->next=NULL; //(tmp->prev)->next.
	delete tmp;
	return head;
}

//delete node from the middle.
node *deleteNodeMid(node *head,int srch)
{
	node *tmp=findElement(head,srch);
	if(tmp==NULL)
	{
		cout<<"Element not found"<<endl;
		return head;
	}	
	tmp->prev->next=tmp->next;  //(tmp->prev)->next.
	tmp->next->prev=tmp->prev;  //(tmp->next)->prev.
	delete tmp;
	return head;
}	

//display list in forward direction.
node *displayListForward(node *head)
{
	node *tmp=head;
	cout<<"The elements in Forward direction"<<endl;
	while(tmp!=NULL)
	{
		cout<<tmp->data<<endl;
		tmp=tmp->next;
	}
	return head;
}

//display list in backward direction.
node *displayListBackward(node *head)
{
	node *tmp=head;
	while(tmp->next!=NULL)
	{
		tmp=tmp->next;
	}
	cout<<"The elements in Backward direction"<<endl;
	while(tmp!=NULL)
	{
		cout<<tmp->data<<endl;
		tmp=tmp->prev;
	}
	return head;
}	
	
		
	
	

	