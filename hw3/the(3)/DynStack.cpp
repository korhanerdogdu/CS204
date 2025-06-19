#include "DynStack.h"
using namespace std;





dynamicStack::dynamicStack(void){
    top = nullptr;
}

const bool dynamicStack::isEmpty(void){
    return top == nullptr;
}

void dynamicStack::push(string w){
    top = new node(w,top);
}




void dynamicStack::pop(string& w){
    while(!isEmpty()){
        w = top->wordname;
        //a = top->number;
        //cout << "The word " << w << " occurred at least " << a << " time(s)  in both files." << endl;
        node* tmp = top->next;
        delete top;
        top = tmp;
    }

}

void dynamicStack::pop2(string& w,dynamicStack &mystack){
    while(!isEmpty()){
        w = top->wordname;
        mystack.push(w);
        //a = top->number;
        //cout << "The word " << w << " occurred at least " << a << " time(s)  in both files." << endl;
        node* tmp = top->next;
        delete top;
        top = tmp;
    }

}

void dynamicStack::onlypop3(string& w){  // deleting only once. (Deleting the top)
    if(!isEmpty()){
        w = top->wordname;
        //a = top->number;
        //cout << "The word " << w << " occurred at least " << a << " time(s)  in both files." << endl;
        node* tmp = top->next;
        delete top;
        top = tmp;

        
    }

}



bool dynamicStack::onlyonce(string w){
    
    if (top == nullptr) {
        return false; // if stack is empty, we return false.
    }
    
    else{
        
        node * current = top;
        
        while(current != nullptr){
            
            if(current ->wordname == w){
                return true;  // alredy exists in the stack.
                
            }
            current = current -> next;
        }
        
        return false;
        
    }
}

void dynamicStack::printStack() {
     if (isEmpty()) {
         cout << "Stack is empty." << endl;
         
     }
     
     
     else{
         cout << "Stack contents:" << endl;
         node* current = top;
         while (current != nullptr) {
             cout << current->wordname << " ";
             current = current->next;
         }
         cout << endl;
         
     }


 }


void dynamicStack::move(dynamicStack &mystack1,dynamicStack &mystack2,dynamicStack &mystack3){
    node *maincurrent = mystack1.top;
    node *copycurrent = mystack1.top;
    
    node *otherstackcurrent = mystack3.top;
    bool itisempty = false;
    while (maincurrent != nullptr) { // mystack 2 ---> commonwords stack.
        int countfirstfile = 0;
        int countsecondfile = 0;
        
        string willberemoved;
        mystack2.onlypop3(willberemoved);
        
        while(copycurrent != nullptr && itisempty == false){
            
            if(copycurrent -> wordname == willberemoved){
                countfirstfile ++;
                
                
                
            }
            copycurrent = copycurrent->next;
            
            
        }
        
        copycurrent = mystack1.top;
        
        
        while (otherstackcurrent!=nullptr && itisempty == false) { //!mystack2.isEmpty()
            if(otherstackcurrent ->wordname == willberemoved){
                countsecondfile ++;
                
            }
            otherstackcurrent = otherstackcurrent ->next;
        }
        
        otherstackcurrent = mystack3.top; // main current diğer node' a geçtiğinde 2 dosya en başından itibaren okunsun diye.
        
        
        if(countfirstfile <= countsecondfile && itisempty == false){
            cout << "The word \"" << willberemoved << "\" occurred at least " << countfirstfile << " time(s) in both files." << endl;

            
        }
        
        else if (countfirstfile > countsecondfile && itisempty==false){
            
            cout << "The word \"" << willberemoved << "\" occurred at least " << countsecondfile << " time(s) in both files." << endl;
            

        }
        

        
        if(mystack2.isEmpty()){
            itisempty = true;
        }
        
        
        maincurrent = maincurrent->next;
       
    }
    
}
