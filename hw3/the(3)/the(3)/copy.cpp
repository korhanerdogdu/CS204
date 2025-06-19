#include <iostream>
#include <fstream>
#include <sstream>
#include "DynStack.h"

using namespace std;


int main(){
    
    ifstream file1;
    ifstream file2;
    
    string filename1;
    string filename2;
    
    string line1;
    string line2;
    string checkline;
    
    string choice;
    
 
    
    
    cout << "This program finds the common words of two files using stacks." << endl;
    cout << "---" << endl;
    
    
    
    
    
    do{
        cout << "Enter the first file name:" << endl;
        cin >> filename1;
        file1.open(filename1.c_str());
    }while(file1.fail());
    
    
    
    do{
        cout << "Enter the second file name:" << endl;
        cin >> filename2;
        file2.open(filename2.c_str());
    }while(file2.fail());
    
    
    
    do{
        
        cout << "Choose with respect to which file the result will be sorted to (1: first file, 2: second file):" << endl;
        cin >> choice;
        
        if(choice != "1" && choice!="2"){
            cout << "---" << endl << endl;
            cout << "Invalid choice" << endl << endl;
            cout << "---" << endl << endl;
        }
        
        
    }while(choice != "1" && choice!="2");
    
    
    
    if(choice == "1"){
        dynamicStack mystack;
        int count0 = 0;
        int count2 = 0;

        //int count1 = 0;
        //bool first = true;
        //bool checkit = true;
        bool aretherany = false;
        
        bool arethereanyoutput = false;
        bool arethereanyoutput2 = false;

        while (getline(file1, line1)) {
            string word;
            istringstream iss(line1);
            while (iss >> word) {
                
                
                while(getline(file2,line2)){
                    
                    string word2;
                    istringstream iss2(line2);
                    while(iss2 >> word2){

                        if (word == word2){
                            aretherany = true;
                            count2 ++;
                            
                        }
                        
                        
                        
                    }
                    
                    
                    
                    if(aretherany == true && word == word2){
                        
                        if(mystack.onlyonce(word) == false){
                            mystack.push(word, count2);
                            count2 = 0;
                            arethereanyoutput = true;
                            
                        }
                        
                    }
                    
                    
                    
                }
                

                
                
                /*
                else if ((count2 < count0) && (aretherany == true)) {
                    
                    if(mystack.onlyonce(word) == false){
                        mystack.push(word, count2);
                        count2 = 0;
                        arethereanyoutput2 = true;
                        aretherany = false;

                    }

                }
                 */
            
               
                /*
                if(aretherany == true){
                    mystack.pop(word, count2);
                    //aretherany = false;
                }
                 */

                
                
            }
            
            /*
            if(aretherany == true){
                mystack.pop(word, count2);
                //aretherany = false;
            }
            */
            
            
            

        }
        
        mystack.printStack();

        
        
        
        if((arethereanyoutput==false) && (arethereanyoutput2 == false)){
            cout << "---" << endl;
            
        }
        
        
    
    }
    
    
    
    
    else if(choice == "2"){
        
    }
    
}

