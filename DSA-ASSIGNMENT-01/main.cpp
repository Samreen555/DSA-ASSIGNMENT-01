#include<iostream>
#include<stack>
#define MAX_ITEMS 20

typedef int ItemType;
using namespace std;
class Advanced_Stack 
{
private:
	int top,min_top;
	ItemType items[MAX_ITEMS]; 
	ItemType min_items[MAX_ITEMS];
	
public:	
	Advanced_Stack()
	{
		top = -1;
		min_top = -1;
	}
	bool is_full() const
	{
		return top == MAX_ITEMS - 1;
	}
	bool is_Empty() const
	{
		return top == - 1;
	}
	void push(ItemType newitem)
	{
		if (is_full())
		{
			cout << "Stack overflow:";
			exit(1);
		}
		top++;
		items[top] = newitem;

		if (min_top==-1 || newitem <=min_items[min_top]) {
			min_top++;
			min_items[min_top] = newitem;
		}
	}
	void pop(ItemType& item)
	{
		if (is_Empty())
		{
			cout << "Stack underflow:";
			exit(1);
		}
		item = items[top];  
		top--;
		if (item == min_items[min_top]) {
			min_top--;
		}
	}
	int get_min()
	{
		if (min_top==-1) {
			cout << "Stack is empty, no minimum element." << endl;
			return -1; // Indicate that the stack is empty
		}
		return min_items[min_top];
	}
	
	int size()
	{
		return top + 1;
	}

};


int main()
{
	Advanced_Stack stack;
	int poppedItem;
	stack.push(5);
	stack.push(4);
	stack.push(3);
	stack.push(6);
	stack.push(2);
	cout << "Minimum number is:" << stack.get_min() << endl;
	cout<<"Size of stack is:"<<stack.size()<<endl;
	stack.pop(poppedItem);
	cout << "Minimum number after pop is:" <<stack.get_min() << endl;
	cout << "Size of the stack is:" << stack.size() << endl;
	system("pause");
	return 0;
}