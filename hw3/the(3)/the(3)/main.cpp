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
        cout << "---" << endl;
        cin >> choice;
        
        if(choice != "1" && choice!="2"){
            
            cout << "Invalid choice" << endl;
            cout << "---" << endl;
        }
        
        
    }while(choice != "1" && choice!="2");
    
    
    if(choice =="1"){
        
        dynamicStack wordsfromfirstfile;
        dynamicStack wordsfromsecondfile;
        dynamicStack forwardwordsfromfirstfile;
        dynamicStack forwardwordsfromsecondfile;
        
        
        dynamicStack newstack1;
        dynamicStack newstack2;
        
        
        
        dynamicStack commonwords;
        dynamicStack forwardcommonwords;

        dynamicStack copyforwardcommonwords;
        
        while(getline(file2,line2)){
            string word;
            istringstream iss(line2);
            while(iss >> word){
                wordsfromsecondfile.push(word);
            }
            
        }
        
        
        while(getline(file1,line1)){
            string word2;
            istringstream iss2(line1);
            while(iss2 >> word2){
                wordsfromfirstfile.push(word2);
                
                
                
                if (wordsfromsecondfile.onlyonce(word2) && !commonwords.onlyonce(word2)) { // For not including twice.
                    commonwords.push(word2);  // commonwords will be generated from the file that is wanted to the result to be sorted. If we want to get the result with respect to the first file, the common words between the first and second file will be sorted according to the first file although there are same words in second file as well.
                }
            }
            
        }
        
        
        
        
        

        string wilbepoppedfromfirstfile;
        string wilbepoppedfromsecondfile;
        wordsfromfirstfile.pop2(wilbepoppedfromfirstfile, forwardwordsfromfirstfile);
        wordsfromsecondfile.pop2(wilbepoppedfromsecondfile, forwardwordsfromsecondfile);
        
        dynamicStack copycommonwords = commonwords;
        string wilbepopped;
        commonwords.pop2(wilbepopped,forwardcommonwords);

        
        if(!copycommonwords.isEmpty()){
            forwardwordsfromfirstfile.move(forwardwordsfromfirstfile, forwardcommonwords, forwardwordsfromsecondfile);

            
        }
        

        
        
    }
    
    else if (choice =="2"){
        
        dynamicStack wordsfromfirstfile;
        dynamicStack wordsfromsecondfile;
        dynamicStack forwardwordsfromfirstfile;
        dynamicStack forwardwordsfromsecondfile;
        
        
        dynamicStack newstack1;
        dynamicStack newstack2;
        
        
        
        dynamicStack commonwords;
        dynamicStack forwardcommonwords;

        dynamicStack copyforwardcommonwords;

        
        while(getline(file1,line1)){
            string word;
            istringstream iss(line1);
            while(iss >> word){
                wordsfromfirstfile.push(word);
            }
            
        }
        
        
        while(getline(file2,line2)){
            string word2;
            istringstream iss2(line2);
            while(iss2 >> word2){
                wordsfromsecondfile.push(word2);
                
                if (wordsfromfirstfile.onlyonce(word2) && !commonwords.onlyonce(word2)) {
                    commonwords.push(word2);
                }
            }
            
        }
        

        
        
        
        
        string wilbepoppedfromfirstfile;
        string wilbepoppedfromsecondfile;
        wordsfromfirstfile.pop2(wilbepoppedfromfirstfile, forwardwordsfromfirstfile);
        wordsfromsecondfile.pop2(wilbepoppedfromsecondfile, forwardwordsfromsecondfile);
        
        dynamicStack copycommonwords = commonwords;
        string wilbepopped;
        
        commonwords.pop2(wilbepopped,forwardcommonwords);

        
        
        
        if(!copycommonwords.isEmpty()){
            forwardwordsfromfirstfile.move(forwardwordsfromsecondfile, forwardcommonwords, forwardwordsfromfirstfile);

            
        }

        
        

        
        
        
        
    }
    
    

    
    
    
    

    
    
    
    
    
}
