/**

作者：咪路

> 不要問我為甚麼有中文
> 還不是為了某些人

JUN 1, 2021
*/

#ifndef LINK_LIST
#define LINK_LIST
#include <iostream>

template<class T>
class Node {
public:
  Node(T _element): element(_element) {
    next = nullptr;
  }
  T getElement () const {
    return element;
  }
  Node* getNext () const {
    return next;
  }
  void setElement (T _element) {
    element = _element;
  }
  void setNext (Node* _next) {
    next = _next;
  }
private:
  T element;
  Node* next;
};

template<class U>
class LinkList {
public:
  LinkList() {
    first = nullptr;
    size = 0;
  }
  void push (U e) {
    Node<U>* n = new Node<U>(e);
    n->setNext(first);
    first = n;
    ++size;
  }
  void pushBack (U e) {
    insert(size,e);
  }
  U removeFront () {
    Node<U>* n = first;
    first = n->getNext();
    delete n;
    --size;
  }
  void removeBack () {
    remove(size-1);
  }
  void insert (int index,U e) {
    if (! (index  <= size)) throw "The index is out of size.";
    if (index == 0) push(e);
    else {
      Node<U>* ptr = first;
      for (int i=0;i<index - 1;++i) {
        ptr = ptr->getNext();
      }
      Node<U>* n = new Node<U>(e);
      n -> setNext(ptr->getNext());
      ptr-> setNext(n);
      ++size;
    }
  }
  int find (U e) const {
    int index = 0;
    Node<U>* ptr = first;
    while (index < size) {
      if (ptr->getElement() == e) return index;
      ptr = ptr-> getNext();
      ++index;
    }
    return -1;
  }
  U get (int index) const {
    if (! (index < size)) throw "The index is out of size.";
    Node<U>* ptr = first;
    for (int i=0;i<index;++i) {
      ptr = ptr->getNext();
    }
    return ptr->getElement();
  }
  void remove (int index) {
    if (! (index < size)) throw "The index is out of size.";
    Node<U>* ptr = first;
    for (int i=0;i<index-1;++i) {
      ptr = ptr->getNext();
    }
    Node<U>* del = ptr->getNext();
    ptr->setNext(del->getNext());
    delete del;
    --size;
  }
  int length () const {
    return size;
  }
  friend std::ostream& operator<< (std::ostream& o,LinkList& li) {
    Node<U>* ptr = li.first;
    for (int i=0;i<li.size;++i) {
      o << ptr->getElement() << ' ';
      ptr = ptr->getNext();
    }
    return o << std::endl;
  }
private:
  Node<U>* first;
  int size;
};

#endif