/*Function templates are special functions that can operate
with generic types. This allows us to create a function
template whose functionality can be adapted to more than
one type or class without repeating the entire code for each type.*/

/*To use this function template we use the following format for the function call:

function_name <type> (parameters);

*/
#ifndef STACK_H
#define STACK_H
#include "Package.h"
#include <iostream>
using namespace std;

template <typename T>
class Stack {
	public:
	Stack(){

	}
	~Stack(){

	}
	bool isEmpty() const{
		if(_head==NULL){
			return true;
		}
		else{
			return false;
		}
	}
	int size() const;

	//Push: Place item on top of the stack
	void push(const T& newItem){
		ListNode* newuser=new ListNode();
			newuser->item=newItem;
			newuser->next=_head;

			_head=newuser;
	}
	//Top: Take a look at the topmost item without removing it
	void getTop(T& stackTop) const{
		if(_head!=NULL){
				stackTop=_head->item;
				}
				else{
					throw "StackException";
				}
	}
	//Pop: Remove item from the top of the stack
	void pop(){
		if(_head==NULL)
		   cout<<"Stack is empty"<<endl;
	    else{
                ListNode *temp = _head;
                _head = _head->next;
                free(temp);
	    }
	}

	private:
	struct ListNode {
		T item;
		ListNode* next;
		};
	ListNode* _head=NULL;
	int _size;
};
#endif
