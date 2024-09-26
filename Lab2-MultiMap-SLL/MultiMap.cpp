#include "MultiMap.h"
#include "MultiMapIterator.h"
#include <exception>
#include <iostream>
//vector included in header

using namespace std;


MultiMap::MultiMap() {
    head = nullptr;
    totalPairs = 0;
}


void MultiMap::add(TKey c, TValue v) {
    //create the pair element
    TElem newElem = std::make_pair(c, v);
    //assign pair elem in new node struct
    Node * newNode  = new Node(newElem);
    //add to head
    newNode->next = head;
    head = newNode;
    //increment list size
    totalPairs++;
}


bool MultiMap::remove(TKey c, TValue v) {
    if (head == nullptr) {
        return false;
    }
    Node * nomad = head;
    Node * prevNomad = nullptr;
    // NOTE: logic here important
    while (nomad != nullptr && (nomad->elem.first != c || nomad->elem.second != v)) {
        prevNomad = nomad;
        nomad = nomad->next;
    }
    if (nomad == nullptr) {
        return false;
    }
    //if pair is first in list
    if (head != nullptr && prevNomad == nullptr) {
        head = head->next;
    }
    else {
        //pair is somehwere in the list or last
        prevNomad->next = nomad->next;
    }
    delete nomad;
    totalPairs--;
	return true;
}


vector<TValue> MultiMap::search(TKey c) const {
    Node * nomad = head;
    vector<TValue> result;
    
    while (nomad != nullptr) {
        if (nomad->elem.first == c) {
            //what's push-back?? (gpt)
            result.push_back(nomad->elem.second);
        }
        nomad = nomad->next;
    }
	return result;
}


int MultiMap::size() const {
    return totalPairs;
}


bool MultiMap::isEmpty() const {
	return totalPairs == 0;
}

MultiMapIterator MultiMap::iterator() const {
	return MultiMapIterator(*this);
}

MultiMap::~MultiMap() {
    while (head != nullptr) {
        Node * temp = head;
        head = head->next;
        delete temp;
    }
}
