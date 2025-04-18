#include "MinHeap.h"

int MinHeap::parent(int i) {
    return i >> 1;
}

int MinHeap::left(int i) {
    return i << 1;
}

int MinHeap::right(int i) {
    return (i << 1) + 1;
}

void MinHeap::percolateUp(int i) {
    if(i > size) return;
    if(i == 1 || i == 0) return;
    int parentNode = parent(i);
    if(minHeap[i].score < minHeap[parentNode].score) {
        swap(handleArr[minHeap[i].id], handleArr[minHeap[parentNode].id]);
        swap(minHeap[i], minHeap[parentNode]);
    }
    percolateUp(parentNode);
}

void MinHeap::percolateDown(int i) {
    if(i > size) return;
    int swapId = i;
    if(left(i) <= size && minHeap[i].score > minHeap[left(i)].score) {
        swapId = left(i);
    }
    if(right(i) <= size && minHeap[swapId].score > minHeap[right(i)].score) {
        swapId = right(i);
    }
    if(swapId != i) {
        swap(handleArr[minHeap[i].id], handleArr[minHeap[swapId].id]);
        swap(minHeap[i], minHeap[swapId]);
        percolateDown(swapId);
    }
}

void MinHeap::findContestant(int id, ofstream &output) {
    if(handleArr[id] == -1) {
        output << "Contestant <" << id << "> is not in the extended heap." << endl;
    } else {
        output << "Contestant <" << id << "> is in the extended heap with score " << minHeap[handleArr[id]].score << "." << endl;
    }
}

void MinHeap::insertContestant(int id, int points, ofstream &output) {
    if(maxSize == size) {
        output << "Contestant <" << id << "> could not be inserted because the extended heap is full." << endl;
        return;
    }
    if(handleArr[id] != -1) {
        output << "Contestant <" << id << "> is already in the extended heap: cannot insert." << endl;
        return;
    }
    size++;
    minHeap.push_back(Node(id, points));
    output << "Contestant <" << id << "> inserted with initial score <" << points << ">." << endl;
    handleArr[id] = size;
    percolateUp(size);
}

void MinHeap::eliminateWeakest(ofstream &output) {
    if(size == 0) {
        output << "No contestant can be eliminated since the extended heap is empty." << endl;
    } else {
        output << "Contestant <" << minHeap[1].id << "> with current lowest score <" << minHeap[1].score << "> eliminated." << endl;
        handleArr[minHeap[1].id] = -1;
        if(size > 1) {
            swap(minHeap[1], minHeap[size]);
            handleArr[minHeap[1].id] = 1;
        }
        size--;
        percolateDown(1);
    }
}

void MinHeap::earnPoints(int id, int points, ofstream &output) {
    if(handleArr[id] == -1) {
        output << "Contestant <" << id << "> is not in the extended heap." << endl;
    } else {
        minHeap[handleArr[id]].score += points;
        percolateDown(handleArr[id]);
        output << "Contestant <" << id <<">'s score increased by <" << points << "> points to <" << minHeap[handleArr[id]].score << ">." << endl;
    }
}

void MinHeap::losePoints(int id, int points, ofstream &output) {
    if(handleArr[id] == -1) {
        output << "Contestant <" << id << "> is not in the extended heap." << endl;
    } else {
        minHeap[handleArr[id]].score -= points;
        percolateUp(handleArr[id]);
        output << "Contestant <" << id <<">'s score decreased by <" << points << "> points to <" << minHeap[handleArr[id]].score << ">." << endl;
    }
}

void MinHeap::showContestants(ofstream &output) {
    for(int i = 1; i < size + 1; i++) {
        output << "Contestant <" << minHeap[i].id << "> in extended heap location <" << i << "> with score <" << minHeap[i].score << ">." << endl;
    }
}

void MinHeap::showHandles(ofstream &output) {
    for(int i = 1; i < handleArr.size(); i++) {
        if(handleArr[i] == -1) {
            output << "There is no Contestant <" << i << "> in the extended heap: handle[<" << i << ">] = " << handleArr[i] << "." << endl;
        } else {
            output << "Contestant <" << i << "> stored in extended heap location <" << handleArr[i] << ">." << endl;
        }
    }
}

void MinHeap::showLocation(int id, ofstream &output) {
    if(handleArr[id] == -1) {
        output << "There is no Contestant <" << id << "> in the extended heap: handle[<" << id << ">] = " << handleArr[id] << "." << endl;
    } else {
        output << "Contestant <" << id << "> stored in extended heap location <" << handleArr[id] << ">." << endl;
    }
}

void MinHeap::crownWinner(ofstream &output) {
    for(int i = 1; i < minHeap.size() - 2; i++) {
        swap(minHeap[1], minHeap[size--]);
        percolateDown(1);
    }
    output << "Contestant <" << minHeap[1].id << "> wins with score <" << minHeap[1].score << ">!" << endl;
}