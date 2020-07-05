#include<iostream>
using namespace std;

typedef struct node {
	int a[2];
	node* next;
}node;

void attach(int e, int c, node** rear)
{
	node* p = (node*)malloc(sizeof(node));
	p->a[0] = e;
	p->a[1] = c;
	p->next = NULL;
	(*rear)->next = p;
	*rear = p;
}

node* add(node* p1, node* p2)
{
	node* p = (node*)malloc(sizeof(node));
	p->next = NULL;
	node* rear = p;
	p1 = p1->next;
	p2 = p2->next;
	while (p1 && p2) {
		if (p1->a[1] > p2->a[1]) {
			attach(p1->a[0], p1->a[1], &rear);
			p1 = p1->next;
		}
		else if (p1->a[1] < p2->a[1]) {
			attach(p2->a[0], p2->a[1], &rear);
			p2 = p2->next;
		}
		else {
			if (p1->a[0] + p2->a[0])
				attach(p1->a[0] + p2->a[0], p1->a[1], &rear);
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	while (p1) {
		attach(p1->a[0], p1->a[1], &rear);
		p1 = p1->next;
	}
	while (p2) {
		attach(p2->a[0], p2->a[1], &rear);
		p2 = p2->next;
	}
	return p;
}

node * mul(node* p1, int e, int c)
{
	int e1, c1;
	node* p = (node*)malloc(sizeof(node));
	node* rear = p;
	//p1 = p1->next;
	while (p1->next) {
		e1 = p1->next->a[0] * e;
		c1 = p1->next->a[1] + c;
		if (e1 == 0 && c1 == 0) {
			node* t = p1->next;
			p1->next = t->next;
			free(t);
		}
		else {
			rear->next = (node*)malloc(sizeof(node));
			rear->next->a[0] = e1;
			rear->next->a[1] = c1;
			rear->next->next = NULL;
			rear = rear->next;
			p1 = p1->next;
		}
	}
	return p;
}

int main()
{
	int T, K, e, c;
	node* nmul, * nadd,* tnmul,* fnmul;
	node* rear1 = (node*)malloc(sizeof(node));
	node* p1 = rear1;
	node* rear2 = (node*)malloc(sizeof(node));
	node* p2 = rear2;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> e >> c;
		attach(e, c, &rear1);
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> e >> c;
		attach(e, c, &rear2);
	}

	nadd = add(p1, p2);
	nmul = (node*)malloc(sizeof(node));
	nmul->next = NULL;

	for (node* tmp = p2->next; tmp; tmp = tmp->next)
	{
		tnmul = add(nmul,mul(p1, tmp->a[0], tmp->a[1]));
		while (nmul) {
			fnmul = nmul;
			nmul = nmul->next;
			free(fnmul);
		}
		nmul = tnmul;
	}
	
	nmul = nmul -> next;
    if(!nmul)
        cout <<"0 0"<<endl;
	else{
        while (nmul->next) {
            cout << nmul->a[0] << " " << nmul->a[1] << " ";
            nmul = nmul->next;
        }
        cout << nmul->a[0] << " " << nmul->a[1] << endl;
    }
    nadd = nadd->next;
	if(!nadd)
        cout << "0 0"<<endl;
    else{
        while (nadd->next) {
            cout << nadd->a[0] << " " << nadd->a[1] << " ";
            nadd = nadd->next;
        }
        cout << nadd->a[0] << " " << nadd->a[1] << endl;
    }
	return 0;
}