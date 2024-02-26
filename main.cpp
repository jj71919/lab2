#include <iostream>
using namespace std;
#include "stack.h"
template <class ItemType>
void replace(Stack<ItemType>& stack, ItemType oldItem, ItemType newItem);
int main()
{
	cout << "----- Problem 1 -----" << endl;
	Stack<int> intStack1;
	intStack1.push(10);
	intStack1.push(15);
	intStack1.push(20);
	cout << "intStack1 contents:" << endl;
	intStack1.print();
	cout << "The size of this stack is " << intStack1.size() << endl;

	cout << endl << "----- Problem 2 -----" << endl;
	Stack<char> charStack1;
	Stack<char> charStack2;
	Stack<char> charStack3;
	charStack1.push('A');
	charStack1.push('B');
	charStack2.push('A');
	charStack2.push('B');
	charStack3.push('C');
	charStack3.push('D');
	cout << "charStack1 contents:" << endl;
	charStack1.print();
	cout << "charStack2 contents:" << endl;
	charStack2.print();
	cout << "charStack3 contents:" << endl;
	charStack3.print();
	cout << "Are charStack1 and charStack2 identical? ";
	if (charStack1.identical(charStack2)) { cout << "Yes" << endl; }
	else { cout << "No" << endl; }
	cout << "Are charStack1 and charStack3 identical? ";
	if (charStack1.identical(charStack3)) { cout << "Yes" << endl; }
	else { cout << "No" << endl; }

	cout << endl << "----- Problem 3 -----" << endl;
	Stack<int> intStack2;
	for (int i = 1; i <= 5; i++) {
		intStack2.push(i);
	}
	cout << "intStack2 contents:" << endl;
	intStack2.print();
	cout << "Replacing 3 with 100" << endl;
	replace(intStack2, 3, 100);
	cout << "intStack2 contents:" << endl;
	intStack2.print();
}
template <class ItemType>
void replace(Stack<ItemType>& stack, ItemType oldItem, ItemType newItem) {
	Stack<ItemType> tempStack;
	while (!stack.empty()) {
		if (stack.top() != oldItem) {
			tempStack.push(stack.top());
			stack.pop();
		}
		else {
			tempStack.push(newItem);
			stack.pop();
		}
		
	}
	while (!tempStack.empty()) {
		stack.push(tempStack.top());
		tempStack.pop();
	}
}
