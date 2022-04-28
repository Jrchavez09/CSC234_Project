#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <cassert>
#include <cstdbool>

using namespace std;


//*****************  class linkedListIterator  ****************
template <class Type>
struct nodeType
{
        Type info;
        nodeType<Type>* link;
};


template <class Type>
class linkedListIterator
{
        public:
                linkedListIterator();
                linkedListIterator(nodeType<Type>* ptr);
                
                Type operator*();
                linkedListIterator<Type> operator++();
                
                bool operator==(const linkedListIterator<Type>& right) const;
                bool operator!=(const linkedListIterator<Type>& right) const;
        
        private:
                nodeType<Type>* current;
};


//*****************  class linkedListType  ****************
template <class Type>
class linkedListType
{
        public:
                const linkedListType<Type>& operator=(const linkedListType<Type>&);
                void initializeList();
                bool isEmptyList() const;
                void print() const;
                int length() const;
                void destroyList();
                Type front() const;
                Type back() const;
                bool search(const Type& searchItem) const;
                void insertFirst(const Type& newItem);
                void insertLast(const Type& newItem);
                void deleteNode(const Type& deleteItem);
                linkedListIterator<Type> begin();
                linkedListIterator<Type> end();
                linkedListType();
                linkedListType(const linkedListType<Type>& otherList);
                ~linkedListType();

        protected:
                int count;
                nodeType<Type>* first;
                nodeType<Type>* last;

        private:
                void copyList(const linkedListType<Type>& otherList);
};

#endif