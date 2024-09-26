#include "MultiMapIterator.h"
#include "MultiMap.h"


MultiMapIterator::MultiMapIterator(const MultiMap& c): col(c) {
    currentElem = col.head;
}

TElem MultiMapIterator::getCurrent() const{
    if (!valid()) {
        throw exception();
    }
    return currentElem->elem;
}

bool MultiMapIterator::valid() const {
	return currentElem != nullptr;
}

void MultiMapIterator::next() {
    if (!valid()) {
        throw exception();
    }
    currentElem = currentElem->next;
}

void MultiMapIterator::first() {
    currentElem = col.head;
}

