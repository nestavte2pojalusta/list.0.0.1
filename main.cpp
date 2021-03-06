#include <iostream>
#include <string>
using namespace std;

int count = 0;
struct node_t {
	int value;
	node_t * next;
};
void reverse(node_t * list) {
	node_t * begin = list;
	node_t * last = begin;
	for (int j = 0; j < count / 2; j++) {
		for (int i = j; i < count - 1 - j; i++) {
			last = last->next;
		}
		int saved = begin->value;
		begin->value = last->value;
		last->value = saved;
		begin = begin->next;
		last = begin;
	}
}
void add(node_t * & head, int value) {
	node_t * node = new node_t;
	node->value = value;
	node->next = nullptr;
	if (head == nullptr) {
		head = node;
	}
	else {
		node_t * last = head;
		while (last->next) {
			last = last->next;
		}
		last->next = node;
	}
	count++;
}
void out(node_t * & list) {
	node_t * first = list;
	list = list->next;
	delete first;
	count--;
}
void print(node_t * first, int count) {
	node_t *print = first;
	for (int a = 0; a < count; a++) {
		cout << "+---+    ";
	}
	cout << endl;
	for (int a = 0; a < count; a++) {
		if (a != 0) {
			cout << "--->";
		}
		cout << "| " << print->value << " |";
		print = print->next;
	}
	cout << endl;
	for (int a = 0; a < count; a++) {
		cout << "+---+    ";
	}
	cout << endl;
}
void delet(node_t * head) {
	while (head) {
		delete head;
		head = head->next;
	}
}
int main()
{
	int value;
	char op;
	node_t * head = nullptr;
	while (cin >> op) {
		switch (op) {
		case '+': {
			cin >> value;
			add(head, value);
			print(head, count);
			break;
		};
		case '-': {
			out(head);
			print(head, count);
			break;
		};
		case 'q': {
			exit(0);
		};
		case '=': {
			print(head, count);
			break;
		};
		case '/': {
			reverse(head);
			print(head, count);
			break;
		};
		}
	}
	delet(head);
}
