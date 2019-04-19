#ifndef TEMPLATEDLINKEDLIST_H_
#define TEMPLATEDLINKEDLIST_H_
#include <iostream>
#include <string>
#include <cmath>

using namespace::std;

template <typename T> class node;
template <typename T> class LinkedList;

template <class T>
class node {
 public:
  T data;
  node<T>* next;

  node();
  node(T d);
  ~node();
};

template <class T>
class LinkedList {
 public:
  node<T>* head;
  node<T>* tail;
  int size;;

  LinkedList();
  ~LinkedList();
  void AddToFront(T d);
  void AddToEnd(T d);
  void AddAtIndex(T d, int index);
  T RemoveFromFront();
  T RemoveFromEnd();
  void RemoveTheFirst(T d);
  void RemoveAllOf(T d);
  bool ElementExists(T d);
  node<T>* Find(T d);
  int IndexOf(T data);
  T RetrieveFront();
  T RetrieveEnd();
  T Retrieve(int index);
  int* ToArray();
  void Empty();
  int Length();
  void RemoveFirst();//Removes the head without a return value
  void RemoveLast();//Removes the tail without a return value
  void RemovePosition(int index);
  void ReplaceNode(T d, int index);
};

template <class T>
node<T>::node() {
  next = NULL;
}

template <class T>
node<T>::node(T d) {
  data = d;
  next = NULL;
}

template <class T>
node<T>::~node() {
  delete next;
}

template <class T>
LinkedList <T>::LinkedList() {
  head = NULL;
  tail = NULL;
  size = 0;
}

template <class T>
LinkedList <T>::~LinkedList() {
  head = NULL;
}

template <class T>
void LinkedList<T>::AddToFront(T d) {
  node<T>* newNode = new node<T>(d);

  if(head == NULL) {
    head = newNode;
    tail = newNode;
    size++;
  }

  else {
    newNode->next = head;
    head = newNode;
    size++;
  }
}

template <class T>
void LinkedList<T>::AddToEnd(T d) {
  node<T>* newNode = new node<T>(d);

  if (head == NULL) {
    head = newNode;
    tail = newNode;
    size++;
  }

  else {
    tail->next = newNode;
    tail = tail->next;
    size++;
  }
}

template <class T>
void LinkedList<T>::AddAtIndex(T d, int index) {
  node<T>* newNode = new node<T>(d);
  if(head == NULL) {
    head = newNode;
    tail = newNode;
    size++;
  }
  else {
    node<T>* cur = head;
    node<T>* pre = cur;
    for(int i = 0; i < index; i++) {
      pre = cur;
      cur = cur->next;
    }
    pre->next = newNode;
    newNode->next = cur;
    size++;
  }
}

template <class T>
T LinkedList<T>::RemoveFromFront() {
  node<T>* temp = head;
  head = head->next;
  return(temp->data);
  size--;
}

template <class T>
T LinkedList<T>::RemoveFromEnd() {
  node<T>* cur = head;
  node<T>* pre = cur;

  while(cur->next != NULL) {
    pre = cur;
    cur = cur->next;
  }
  return(cur->data);
  pre->next = NULL;
  tail = pre;
  size--;
}

template <class T>
void LinkedList<T>::RemoveTheFirst(T d) {
  if(ElementExists(d)) {
    node<T>* cur = head;
    node<T>* pre = cur;
    while(cur->data != d) {
      pre = cur;
      cur = cur->next;
    }
    pre->next = cur->next;
    size--;
  }

  else {
    cout << "Element does not exist." << endl;
  }
}

template <class T>
void LinkedList<T>::RemoveAllOf(T d) {
  if(ElementExists(d)) {
    if(head->data == d) {
      RemoveFromFront();
    }
    node<T>* cur = head;
    node<T>* pre = cur;

    while(cur->next != NULL) {
      if(cur->data == d) {
	pre->next = cur->next;
	free(cur);
	cur = pre->next;
	size--;
      }
      pre = cur;
      cur = cur->next;
    }
  }
}

template <class T>
bool LinkedList<T>::ElementExists(T d) {
  bool ans = 0;
  node<T>* cur = head;
  node<T>* pre = cur;
  while(cur->data != d || cur->data != NULL) {
    pre = cur;
    cur = cur->next;
  }

  if(cur->data == d) {
    ans = 1;
  }
  return(ans);
}

template <class T>
node<T>* LinkedList<T>::Find(T d) {
  if(!ElementExists(d)) {
    cout << "Element does not exist." << endl;
  }
  else {
    node<T>* cur = head;
    node<T>* pre = cur;
    while(cur->data != d) {
      pre = cur;
      cur = cur->next;
    }
    return(cur);
  }
}

template <class T>
int LinkedList<T>::IndexOf(T d) {
  if(!ElementExists(d)) {
    cout << "Element does not exist." << endl;
  }
  else {
    node<T>* cur = head;
    node<T>* pre = cur;
    int index = 0;
    while(cur->data != d) {
      index++;
      pre = cur;
      cur = cur->next;
    }
    return(index);
  }
}

template <class T>
T LinkedList<T>::RetrieveFront() {
  return(head->data);
}

template <class T>
T LinkedList<T>::RetrieveEnd() {
  return(tail->data);
}

template <class T>
T LinkedList<T>::Retrieve(int index) {
  node<T>* cur = head;
  for(int i = 0; i < index; i++) {
    cur = cur->next;
  }
  return(cur->data);
}

template <class T>
int* LinkedList<T>::ToArray() {
  T array[size];
  int i = 0;
  node<T>* cur = head;

  while(cur->next != NULL) {
    array[i] = cur->data;
    cur = cur->next;
    i++;
  }
  return(array);
}

template <class T>
void LinkedList<T>::Empty() {
  node<T>* cur = head;
  node<T>* next = cur->next;

  while(cur != NULL) {
    next = cur->next;
    free(cur);
    cur = next;
  }
  head = NULL;
}

template <class T>
int LinkedList<T>::Length() {
  return(size);
}

template <class T>
void LinkedList<T>::RemoveFirst() {
  head = head->next;
  size--;
}

template <class T>
void LinkedList<T>::RemoveLast() {
  node<T>* cur = head;
  node<T>* pre = cur;

  while(cur->next != NULL) {
    pre = cur;
    cur = cur->next;
  }
  pre->next = NULL;
  tail = pre;
  size--;
}

template <class T>
void LinkedList<T>::RemovePosition(int index) {
  if(index == 0) {//at the head
    RemoveFirst();
  }

  else if(index == size - 1) {//at the tail
    RemoveLast();
  }
  else {
    node<T>* temp1 = head;
    for(int i = 1; i < index; i++) {//starts at 1 because we want
      temp1 = temp1->next;//to get to the node prior to the one we
    }                     //want to delete 

    node<T>* temp2 = temp1->next;//this is the node we want to delete
    temp1->next = temp2->next;
    size--;
  }  
}

template <class T>
void LinkedList<T>::ReplaceNode(T d, int index) {
  node<T>* temp = head;
  for(int i = 0; i < index; i++) {
    temp = temp->next;
  }
  temp->data = d;
}

#endif
