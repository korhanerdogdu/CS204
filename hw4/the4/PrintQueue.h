#ifndef PrintQueue_H
#define PrintQueue_H

struct PrintJobNode
{
    int PrintJobId, numberOfPages;
    PrintJobNode* next;
    PrintJobNode(int num = 0, int nPages = 0, PrintJobNode* ptr = nullptr)
    {
        PrintJobId = num;
        numberOfPages = nPages;
        next = ptr;
    }
};

class PrintQueue
{
private:
    // These track the front and rear of the queue.
    PrintJobNode* front;
    PrintJobNode* rear;
    int currentSize;
public:
    // Constructor.
    PrintQueue();
    int getCurrentSize() const;
    void enqueue(int id, int numberOfPages);
    void dequeue(int& id, int & pages);
    bool isEmpty () const;
    void printQueueContents(void);
    
    // you can add other functions if you need to, but you should not modify anything else neither in the class nor in the struct

};









#endif

