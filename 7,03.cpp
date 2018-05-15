#include <string>
#include <iostream>

using namespace std;

struct Node 
{
	string name;
	char gender;
	int id;
	Node* next;
};

typedef Node *PNode;
PNode CreateNode (string newName, char newGender, int newID)
{
	PNode newNode=new Node;
	newNode -> name = newName;
	newNode -> gender = newGender;
	newNode -> id = newID;
	newNode -> next = NULL;
	return newNode;
}

void Addfirst (PNode &Head, PNode Node)
{
	Node -> next=Head;
	Head = Node;
}

void AddAfter (PNode p, PNode Node) 
{
	Node -> next= p->next;
	p -> next = Node;
}

void AddBefore (PNode &Head, PNode p, PNode Node)
{
	PNode q = Head;
	if (Head == p) 
	{
		Addfirst(Head, Node); 
 	return;
	}
	while (q && q->next!=p) 
	{
 		q = q->next;
 	}
	if (q)
	{
		Node -> next= p->next;
		p -> next = Node;
	} 
}
 
void AddLast (PNode &Head, PNode Node)
{
	PNode q = Head;
	if (Head == NULL)
	{ 
 		Addfirst(Head, Node); 
 		return;
 	}
	while (q->next)
	{
	q = q->next; 
	}
		AddAfter(q, Node);
}

void PrintList (PNode Head)
{
	while (Head) 
	{
		cout << Head -> name <<" "<< Head ->gender <<" "<< Head -> id << endl;
		Head=Head->next;
	}
}

void DeleteFirst (PNode &Head)
{
	PNode OldNode=Head;
	if (Head)
	{
		Head = Head -> next;
		delete OldNode;
	}
}

void DeleteAll (PNode &Head)
{
	PNode OldNode=Head;
	while(Head)
	{
		Head = Head -> next;
		delete OldNode;
	}
}

void DeleteNode (PNode &Head, PNode OldNode)
{
	PNode q = Head;
	if (Head == OldNode)
	{
 		Head = OldNode->next; 
 	}
	else
	{
 		while (q && q->next != OldNode)
		{ 
 			q = q->next;
 		}
 		if (q == NULL)
		{
			return;
		}
 		q->next = OldNode->next;
 	}
	delete OldNode; 
}

void PrintByID (PNode Head)
{
	int k=0, prevmin=-1;
	PNode q=Head;
	while (q)
	{
		k++;
		q=q->next;
	}
	int printed=0;
	while (printed <k)
	{
		PNode minNode;
		int min;
		q=Head;
		while(q)
		{
			if(q->id>prevmin)
			{
				min = q->id;
				minNode=q;
				break;
			}
			q=q->next;
		}
		PNode r = Head;
		while (r)
		{
			if (r->id>prevmin && r->id<=min)
			{
				min= r->id;
				minNode = r;
				
			}
			r = r->next;
		}
		cout << minNode -> name <<" "<< minNode->gender <<" "<< minNode -> id << endl;
		prevmin = min;
		printed ++;	
	}
}

void PrintByGender (PNode Head)
{
	PNode r = Head;
	PNode k = Head;
	while (r)
	{
		if (r->gender=='w')
		{
			cout << r -> name <<" "<< r ->gender <<" "<< r -> id <<endl;
		}
		r = r->next;
		
		if (k->gender=='m')
		{
			cout << k -> name <<" "<< k ->gender <<" "<< k -> id <<endl;
		}
		k = k->next;
	}
}


int main (void)
{
	PNode Head=NULL; 
	PNode first = CreateNode ("Maria", 'w', 999);
	PNode second = CreateNode ("Alexandr", 'm', 1025);
	PNode third = CreateNode ("Rita", 'w', 321);
	PNode fourth = CreateNode ("Maksim", 'm', 69);
	PNode fifth = CreateNode ("Noora", 'w', 12345); 
	
	Addfirst (Head, first);
	AddLast (Head, second);
	AddBefore (Head, first, third);
	AddLast (Head, fourth);
	AddAfter (first, fifth);

	cout << endl;
	PrintList (Head);	
	
	cout << endl;
	PrintByID(Head);
	
	cout << endl;
	PrintByGender(Head);
	
	return 0;
}
