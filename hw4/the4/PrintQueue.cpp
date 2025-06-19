#include "PrintQueue.h"
#include <iostream>

using namespace std;

//************************************************
// Constructor. Generates an empty queue         *
//************************************************
PrintQueue::PrintQueue()
{
    front = nullptr;
    rear = nullptr;
    currentSize = 0;
}


void PrintQueue::enqueue(int num, int numberOfPages)
{
    if (isEmpty())   //if the queue is empty
    {    //make it the first element
        front = new PrintJobNode(num, numberOfPages);
        rear = front;
        currentSize++;

    }
    else  //if the queue is not empty
    {    //add it after rear
        rear->next = new PrintJobNode(num, numberOfPages);
        rear = rear->next;
        currentSize++;
    }
}

void PrintQueue::dequeue(int& num, int & pages)
{
    PrintJobNode* temp;
    if (isEmpty())
    {
        cout << "Attempting to dequeue on empty queue, exiting program...\n";
        exit(1);
    }
    else //if the queue is not empty
    {    //return front's value, advance front and delete old front
        num = front->PrintJobId;
        pages = front->numberOfPages;
        temp = front;
        front = front->next;
        delete temp;
        currentSize--;
    }
}

int PrintQueue::getCurrentSize() const
{
    return currentSize;
}

bool PrintQueue::isEmpty() const
{
    if (front == nullptr)
        return true;
    else
        return false;
}


void PrintQueue::printQueueContents() {
    PrintJobNode *temp = front;
    cout << "Queue Contents: ";
    while (temp != nullptr) {
        cout << temp->PrintJobId << " " <<  temp -> numberOfPages;
        temp = temp->next;
    }
    cout << endl;
}
