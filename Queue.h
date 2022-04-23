/*Function templates are special functions that can operate
with generic types. This allows us to create a function
template whose functionality can be adapted to more than
one type or class without repeating the entire code for each type.*/

/*To use this function template we use the following format for the function call:

function_name <type> (parameters);
*/
#ifndef QUEUE_H
#define QUEUE_H
#include "Truck.h"
template<typename T>
class Queue {
	public:
	Queue(){
	}
	~Queue(){
	}
	bool isEmpty() const{
		if(_head==NULL){
			return true;
		}
		else{
			return false;
		}
	}
	int size() const{
		return _size;
	}
	//Enqueue: Items are added to the back of the queue
	void enqueue(const T& newItem){
	QueueNode* newuser=new QueueNode();
	newuser->item=newItem;
	if(_head==NULL){
		_head=newuser;
		_lastNode=newuser;
		newuser->next=NULL;
		_size=1;
	}
	else{
		_lastNode->next=newuser;
		newuser->next=NULL;
		_lastNode=newuser;
		_size++;
	}
}
	//Dequeue: Items are removed from the front of the queue
	void dequeue(){
		if(_head==NULL){
		   cout<<"Queue is empty"<<endl;
		  _size=0;
		   }
		else{
		   QueueNode* temp=_head;
		   _head = _head->next;
		   free(temp);
		   _size--;
		}
	}
	//Get Front: Take a look at the first item
	void getFront(T& queueTop) const{
		if(_head!=NULL){
		queueTop=_head->item;
		}
		else{
			throw "QueueException";
		}
	}
	private:
	struct QueueNode {
		T item;
		QueueNode *next;
		};
	int _size;
	/* to avoid the traversal to the last node,
	 an additional pointer to the last node is defined*/
	QueueNode *_head=NULL;
	QueueNode *_lastNode=NULL;
};
#endif
