#include<iostream>
using namespace std;

//defining a structure of linked list node.
typedef struct list_node
{
    int data;
    struct list_node *next;
}node;

//creating new node.
node *getNewNode(int data)
{
    node *new_node= new node;   //allocating dynamic memory.
    new_node->data=data;
    new_node->next=NULL;
    return new_node;
}

//insert node at beginning
node *insertNodeBeg(node *head, int data)
{
    node *ptr=getNewNode(data);  //ptr is the pointer pointing to the new node.
    if(head==NULL)  //if there is no element in the linked list.
    {
        head=ptr;
    }
    else
    {
        ptr->next=head;
        head=ptr;
    }
    return head;
}

//insert node at the end.
node *insertNodeEnd(node *head,int data)
{
    node *p=getNewNode(data);
    node *tmp=head;
    while(tmp->next!=NULL)  //iterate through linked list.
    {
        tmp=tmp->next;
    }
    tmp->next=p;  //write address of last node in penultimate one.
    return head;
}

//display linked list
node *displayList(node *head)
{
    node *tmp=head;
    while(tmp!=NULL)  //iterate through loop and print data elements.
    {
        cout<<tmp->data<<endl;
        tmp=tmp->next;
    }
    return head;
}

//find given element
node *findElement(node *head,int srch)
{
    node *tmp=head;
    node *p=NULL;
    while(tmp!=NULL)
    {
        if(tmp->data==srch)
        {
            p=tmp; //allocating location of the element to the pointer.
            break;
        }
        tmp=tmp->next;
    }
    return p;
}

//insert node in the middle
node *insertNodeMid(node *head,int data,int srch)
{
    node *tmp=findElement(head,srch);
	if(tmp==NULL)
	{
		cout<<"Invalid position"<<endl;
		return head;
	}	
	node *ptr=getNewNode(data);
    ptr->next=tmp->next;  //replaces NULL of the new node with address of next node.
    tmp->next=ptr;  //address of previous node in the new node.
    return head;
}

//delete node from beg
node *deleteNodeBeg(node *head)
{
    node *ptr=head; //when ptr is allocated to head, it is actually pointing to the first node.
    head=ptr->next;  //allocate address of head to second node.
    delete ptr;
    return head;
}

// delete node in the middle.
node *deleteNodeMid(node *head,int srch)
{
    node *ptr=findElement(head,srch);
    if(ptr==NULL)
    {
        cout<<"Element not found"<<endl;
        return head;
    }
    node *tmp=head;
    while(tmp!=NULL) //finding the element before the srch element.
    {
        if(tmp->next==ptr)
        {
            tmp->next=ptr->next; //allocating address to next element.
            break;
        }
    }
    delete ptr;
    return head;
}

//delete node from end
node *deleteNodeEnd(node *head)
{
    node *ptr=head;
    if(head==NULL) //if list is empty.
        return NULL;
    else if(head->next==NULL)  //if list contains only 1 element.
    {
        delete head;
        return NULL;
    }
    else
    {
        while(head!=NULL)
        {
            if(ptr->next->next==NULL)  
            {
                delete ptr->next->next;
                ptr->next=NULL;  //reallocating NULL.
                break;
            }
            ptr=ptr->next;
        }
        return head;
    }
}

//stack operations
//push element into stack.
node *pushElement(node *head,int data)
{
	head=insertNodeBeg(head,data);
	return head;
}	

//pop elements from stack.
node *popElement(node *head)
{
	head=deleteNodeBeg(head);
	return head;
}	

//queue operations
//enqueue 
node *enqueueElement(node *head,int data)
{
	if(head==NULL)
	{
		head=insertNodeBeg(head,data);
		return head;
	}	
	head=insertNodeEnd(head,data);
	return head;
}

//dequeue
node *dequeueElement(node *head)
{
	head=deleteNodeEnd(head);
	return head;
}


