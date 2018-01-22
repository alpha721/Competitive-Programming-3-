#include<iostream>
#include<vector>
using namespace std;

struct node{
	int data;
	struct node* left;
};

struct node* create_node(int d)
{
	struct node* n = (struct node*) malloc(sizeof(struct node));
	n->data = d;
	n->next = NULL;
	return n;
}

struct q{
	struct node* head;
};

struct q* create_q()
{
	struct q* q = (struct q*)malloc(sizeof(struct q));
	q->head = NULL;
	return q;
}

void enq(struct q* q,int d)
{
		
