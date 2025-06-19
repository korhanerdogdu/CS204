#ifndef DynStack_h
#define DynStack_h


#include <iostream>
using namespace std;

struct node{
    string wordname;
    //int number;
    node* next;
    
    
    node(string w = "", node* p = nullptr):wordname(w),next(p){}  // We defined constructor.


};



class dynamicStack{
public:
    dynamicStack(void);
    const bool isEmpty(void);  // this function does not change the object of the class.
    void push(string);
    void pop(string&);
    void pop2(string&,dynamicStack &);
    void onlypop3(string&);
    void move(dynamicStack&,dynamicStack&,dynamicStack&);


    void printStack(void);
    bool onlyonce(string);
    
    
private:
    node* top;
};


#endif
