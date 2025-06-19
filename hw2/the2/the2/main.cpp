#include <mutex>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;



struct stockNode{
    string resourceName;
    int resourceQuantity;
    stockNode *next;
    stockNode *prev;
    
    stockNode(string resourceN, int resourceQ) {  //  defining constructor.
        
        resourceName = resourceN;
        resourceQuantity = resourceQ;
        next = nullptr;
        prev = nullptr;
    }
};


struct consumpNode{
    string buildType;
    vector<int> consumpQtys;
    consumpNode *next;
    consumpNode *prev;
    
    consumpNode(string buildT, vector<int> consumpQ) {  //  defining constructor.
        
        string buildType = buildT;
        vector<int> consumpQtys = consumpQ;
        next = nullptr;
        prev = nullptr;
    }
};


struct colonyNode{
    string buildType;
    int emptyBlocks2TheLeft;
    colonyNode *next;
    colonyNode *prev;
    
    colonyNode(string buildT, int emptyBlocks2) {  //  defining constructor.
        
        buildType = buildT;
        emptyBlocks2TheLeft = emptyBlocks2;
        next = nullptr;
        prev = nullptr;
    }
};

class Doublestock {
private:
    stockNode* head;
    stockNode* tail;

public:
    Doublestock() {
        head = nullptr;
        tail = nullptr;
    }

    // creating the double linked list by adding items.
    void addBack(string resourceN, int resourceQ) {
        stockNode* newNode = new stockNode(resourceN, resourceQ);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // printing double linked list for the 7'th option.
    void printForward() {
        cout << "Stock DLL:" << endl;
        stockNode* current = head;
        while (current != nullptr) {
            cout << current->resourceName << "(" << current -> resourceQuantity << ")" << endl;
            current = current->next;
        }
        
    }
    
    void resourceupdate(vector<string> ilkcolony, vector<vector<string>> ilkconsumption){
        stockNode* current = head;
        
        for(int m = 0 ; m < ilkcolony.size(); m++){
            
            for(int i = 0 ; i < ilkconsumption.size(); i++){
                
                if(ilkconsumption[i][0] == ilkcolony[m]){
                    for(int j = 0 ; j < ilkconsumption[i].size() -1 ; j ++){
                        int newvalue = stoi(ilkconsumption[i][j+1]);
                        bool check = true;
                        
                        current->resourceQuantity = (current->resourceQuantity) - newvalue;
                                                
                        if(current->next == NULL) {
                            check = false;
                        }

                        if(check == true) {
                            current = current->next;
                        }

                        
                    }
                    current = head;
                    
                }
                
            }
        }
        
    }

};


class Doubleconsumption {
private:
    consumpNode* head;
    consumpNode* tail;

public:
    Doubleconsumption() {
        head = nullptr;
        tail = nullptr;
    }

    // creating the list by inserting each node from the end(back).

    void addBack(string buildT, vector<int> consumpQ) {
        consumpNode* newNode = new consumpNode(buildT,consumpQ);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
};

class Doublecolony {
private:
    colonyNode* head;
    colonyNode* tail;

public:
    Doublecolony() {
        head = nullptr;
        tail = nullptr;
    }

    // creating the list by inserting each node from the end(back).
    void addBack(string buildT, int emptyBlocks2) {
        colonyNode* newNode = new colonyNode(buildT,emptyBlocks2);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
 
    
    
    // printing double linked list for the 3'th option.

    void printForward() {
        colonyNode* current = head;
        cout << "Colony DLL:" << endl;
        while (current != nullptr) {
            cout  << current->buildType;
            current = current->next;
        }
        cout << endl;
        current = head;

        while (current != nullptr) {
            cout << "(" <<  current ->emptyBlocks2TheLeft  << ")" << current->buildType;
            current = current->next;
        }
        cout << endl;
    }
    
    
    // printing double linked list for the 5'th option.

    void printForward2() {
        colonyNode* current = head;
        cout << "Colony DLL:" << endl;
        while (current != nullptr) {
            
            for(int i = 0;i < current->emptyBlocks2TheLeft; i ++){
                cout << "-";
                
            }
            
            cout << current->buildType;
            current = current->next;
        }
        cout << endl;
    }
    
    

    // printing double linked list for the 6'th option.

    void printBackward2() {
        cout << "(Reverse) Colony DLL:" << endl;
        colonyNode* current = tail;
        while (current != nullptr) {
            cout << current->buildType;

            for(int i = 0;i < current->emptyBlocks2TheLeft; i ++){
                cout << "-";
                
            }
            
            
            current = current->prev;
        }
        cout << endl;
    }
    
    
    
    // printing double linked list for the 4'th option.

    void printBackward() {
        cout << "(Reverse) Colony DLL:" << endl;
        colonyNode* current = tail;
        while (current != nullptr) {
            cout << current->buildType;
            current = current->prev;
        }
        cout << endl;
    }
    
    void deleteList() {
        while (head != nullptr) {
            colonyNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    void addcolony(vector<string> &v1){
        
        string giris;
        bool checkit = false;
        
        cout << "Please enter the building type:" << endl;
        do{
            
            cin >> giris;
            
            colonyNode* current = head;
            while (current != nullptr) {
                if(current->buildType == giris){
                    checkit = true;
                    
                }
                current = current->next;
            }
            
            if(checkit == false){
                
                cout <<"Building type " << giris << " is not found in the consumption DLL. Please enter a valid building type:" << endl;
                
            }
            
        
        }while(checkit == false);
        
        
        cout << "Please enter the index of the empty block where you want to construct a building of type " << giris << endl;
        
        int indexx;
        
        cin >> indexx;
        int count =0;
        
        for(int i = 0 ; i < v1.size();i++){
            if(v1[i] == "-"){
                count ++;
            }
            if(count == indexx){
                v1[i] = giris;
                break;
            }
            
        
        }
        
        
        if(indexx > count){
            
            int newvalue = indexx - count;
            
            
            
            for(int m = 0; m<newvalue; m++){
                v1.push_back("-");
                
            }
            
            vector<string>::size_type lastIndex = v1.size() - 1;
            
            //string lastElement = v1.back();
            
            v1[lastIndex] = giris;
            
        }
        
        
        cout << "Building of type " << giris << " has been added at the empty block number: " << indexx << endl;
        
        
        /*
        for(int i = 0 ; i < v1.size();i++){
            cout << v1[i] << " ";
            
        }
        cout << endl;
        */
        
    }
    
    void destructcolonny(vector<string> &v1){
        
        string giris;
        bool checkit = false;
        
        do{
            cout << "Please enter the building type:" << endl;
            cin >> giris;
            
            colonyNode* current = head;
            while (current != nullptr) {
                if(current->buildType == giris){
                    checkit = true;
                    
                }
                current = current->next;
            }
            
            if(checkit == false){
                
                cout << "The building of type " << giris << " is not found in the colony." << endl;
                
            }
            
        
        }while(checkit == false);
        
        
        for(int y = 0 ; y < v1.size(); y++){
            
            if(v1[y] == giris){
                v1[y] = "-";
                break;  // for only the first ocurrance to be deleted.
                
            }
            
        }
        
        
        cout << "The building of type " <<  giris << " has been deleted from the colony." << endl;
        
    }
};

int main(){
    
    
    
    Doublestock nodestockk;
    Doubleconsumption nodeconsumptionn;
    Doublecolony nodecolonyy;
    
    string line;
    string line2;
    string line3;

    
    ifstream getstock;
    ifstream getconsumption;
    ifstream getcolony;

    
    string stockdatabase;
    string consumptiondatabase;
    string colonydatabase;
    
    
    
    
    
    
    
    cout << "Please enter the stock file name: " << endl;
    do{
        cin >> stockdatabase;
        getstock.open(stockdatabase.c_str());
        if(getstock.fail()){

            cout << "Unable to open the file " << stockdatabase << ". Please enter the correct stock file name: " << endl;
        }
    }while(getstock.fail());
    
    
    while (getline(getstock, line)) {
        vector<string> tempwords;
        string word;
        istringstream iss(line);
        while (iss >> word) {
            tempwords.push_back(word);
        }
        
        int newvalue = stoi(tempwords[1]);
        
        nodestockk.addBack(tempwords[0], newvalue);  // we are creating the node with tempwords[0] and newvalue items, which are the items that comes from our file. tempwords[0] is the resource name, newvalue is the resource quantity.

    }

    
    
    if (getstock.eof()) {
        getstock.seekg(0);
    }
    

    
    
    
    
    
    cout << "Please enter the consumption file name: " << endl;
    do{
        cin >> consumptiondatabase;
        getconsumption.open(consumptiondatabase.c_str());
        if(getconsumption.fail()){

            cout << "Unable to open the file " << consumptiondatabase << ". Please enter the correct consumption file name: " << endl;
        }
    }while(getconsumption.fail());
    
    
    vector<vector<string> > ilkconsumption; // yeni

    
    while (getline(getconsumption, line2)) {
        vector<string> temp; // yeni
        
        vector<string> tempwords2;
        string word2;
        istringstream iss(line2);
        while (iss >> word2) {
            tempwords2.push_back(word2);
            temp.push_back(word2); // yeni
        }
        
        ilkconsumption.push_back(temp); // yeni
        
        string btype = tempwords2[0];
        vector<int> depo;
        for(int i = 1 ; i < tempwords2.size();i++){
            int yenideger = stoi(tempwords2[i]);
            depo.push_back(yenideger);
        }
        
        nodeconsumptionn.addBack(btype, depo);
        
    }
    
    
    

    if (getconsumption.eof()) {
        getconsumption.seekg(0);
    }
    
    
    
    
    
    
    cout << "Please enter the colony file name: " << endl;
    do{
        cin >> colonydatabase;
        getcolony.open(colonydatabase.c_str());
        if(getcolony.fail()){

            cout << "Unable to open the file " << colonydatabase << ". Please enter the correct colony file name: " << endl;
        }
    }while(getcolony.fail());
    

    
    
    int count=0;
    vector<string>ilkcolony;
    
    while (getline(getcolony, line3)) {
        for (char letter : line3) {
            string ilkstring = string(1, letter);
            ilkcolony.push_back(ilkstring); // we are going to use the "ilkcolony" vector for updating the colony with the adding or removing the building operations for the vector.
            
            if (letter == '-') {
                count++;
            }
            else {
                string yeni = string(1, letter);
                nodecolonyy.addBack(yeni, count);
                count = 0;
            }
        }
    }
    


    

    
    if (getcolony.eof()) {
        getcolony.seekg(0);
    }
    
    
    
    int choice;
    

    
    cout << "Please enter your choice: " << endl;
    cout << "1. Construct a new building on the colony" << endl;
    cout << "2. Destruct/Disassemble a building from the colony" << endl;
    cout << "3. Print the colony" << endl;
    cout << "4. Print the colony in reverse" << endl;
    cout << "5. Print the colony while showing inner empty blocks" << endl;
    cout << "6. Print the colony while showing inner empty blocks in reverse" << endl;
    cout << "7. Print the stock" << endl;
    cout << "8. Exit" << endl;
    

    do{
        cin >> choice;
        
        if(choice == 1){
            
            nodecolonyy.addcolony(ilkcolony); //buradan yürü
            // burdan add back kullanarak ilkcolony yi düğüm haline getircen.
            nodecolonyy.deleteList();

            int countt=0;

            for(int a = 0 ; a < ilkcolony.size();a++){
                
                if (ilkcolony[a] == "-") {
                    countt++;
                }
                else {
                    //string yeni = string(1, letter);
                    nodecolonyy.addBack(ilkcolony[a], countt);  // node a ekleme yapıyorum.
                    countt = 0;
                }
                
            }
            
        }
        
        else if (choice == 2){
            
            nodecolonyy.destructcolonny(ilkcolony);
            
            nodecolonyy.deleteList();

            int countt=0;

            for(int a = 0 ; a < ilkcolony.size();a++){
                
                if (ilkcolony[a] == "-") {
                    countt++;
                }
                else {
                    //string yeni = string(1, letter);
                    nodecolonyy.addBack(ilkcolony[a], countt);  // node a ekleme yapıyorum.
                    countt = 0;
                }
                
            }
            
        }
        
        else if (choice == 3){
            
            nodecolonyy.printForward();
            
        }
        
        else if (choice == 4){
            nodecolonyy.printBackward();
            
        }
        
        else if (choice == 5){
            nodecolonyy.printForward2();
            
        }
        
        else if (choice == 6){
            nodecolonyy.printBackward2();
            
        }
        
        else if (choice == 7){
            nodestockk.resourceupdate(ilkcolony, ilkconsumption);
            nodestockk.printForward();
            
            
        }
        
        else if (choice == 8){
            
            cout << "Clearing the memory and terminating the program." << endl;
            
        }
        
        
        
    }while(choice !=8 );
    
}


