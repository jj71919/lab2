#include <iostream>
#include <iomanip>
using namespace std;
#include "stack.h"
template <class ItemType>
void replace(Stack<ItemType>& stack, ItemType oldItem, ItemType newItem);
int main()
{
	Stack<int> stack1;
	for (int i = 1; i <= 5; i++) {
		stack1.push(i);
	}
	for (int i = 1; i <= 5; i++) {
		stack1.push(i);
	}
	stack1.print();
	replace(stack1, 1, 99);
	stack1.print();

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
