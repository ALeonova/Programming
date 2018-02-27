#include <stdio.h>
#include <string.h>
struct Node
{
char word [10];
int count;
Node* next;
};
typedef Node *PNode;
PNode CreateNode (char newWord[], int count)
{
PNode newNode=new Node;
strcpy(newNode -> word, newWord);
newNode -> count = count;
newNode -> next = NULL;
return newNode;
}
void Addfirst (PNode &Head, PNode Node)
{
Node -> next=Head;
Head= Node;
}
void AddAfter (PNode p, PNode Node) {
Node -> next= p->next;
p -> next = Node;
}
void AddBefore(PNode &Head, PNode p, PNode Node)
{
PNode q = Head;
if (Head == p) {
Addfirst(Head, Node);
return;
}
while (q && q->next!=p)
q = q->next;
if ( q )
Node -> next= p->next;
p -> next = Node;;
}
void AddLast(PNode &Head, PNode Node)
{
PNode q = Head;
if (Head == NULL) {
Addfirst(Head, Node);
return;
}
while (q->next) q = q->next;
AddAfter(q, Node);
}
void PrintList (PNode Head){
while (Head) {printf ("%s %d\n", Head->word, Head -> count); Head=Head->next;};
}
/*PNode Find (PNode Head, char NewWord[])
{
PNode q = Head;
while (q && strcmp(q->word, NewWord))
q = q->next;
return q;
}*/
void DeleteFirst (PNode &Head)
{
if (Head)
Head = Head -> next;
}
void DeleteNode(PNode &Head, PNode OldNode)
{
PNode q = Head;
if (Head == OldNode)
Head = OldNode->next;
else {
while (q && q->next != OldNode)
q = q->next;
if ( q == NULL ) return;
q->next = OldNode->next;
}
delete OldNode;
}
int main (void)
{
PNode Head=NULL;
PNode first = CreateNode ("firstNode", 2);
PNode second= CreateNode ("secondNode", 5);
PNode third = CreateNode ("thirdNode", 3);
PNode fourth = CreateNode ("fourthNode", 8);
Addfirst (Head, first);
AddAfter (Head, second);
AddBefore (Head, first, third);
AddLast (Head, fourth);
PrintList (Head);
printf ("\n");
DeleteNode (Head, second);
PrintList (Head);
return 0;
}
