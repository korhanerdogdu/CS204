

/*
 `getline` işlevi bir sayı bulunsa bile, onu string olarak alır. `getline` işlevi, bir dosya akımından karakterleri satır satır okumak için kullanılır ve her satırı bir string olarak alır.

 Eğer bir txt dosyasında sayılar da olsa, `getline` işlevi bu sayıları string olarak algılar. Bu durum, sayıların dosyada basit metin olarak saklandığı anlamına gelir.

 Örneğin, aşağıdaki txt dosyası içeriğini ele alalım:

 ```
 Merhaba
 12345
 Dünya
 ```

 Bu dosyayı açıp `getline` işlevini kullanarak satır satır okumak, tüm satırları string olarak alacaktır. Yani, `getline` işlevi, dosyanın içeriğini şu şekilde okur:

 ```
 Satır 1: "Merhaba"
 Satır 2: "12345"
 Satır 3: "Dünya"
 ```

 Sayılar da metin olarak dosyada saklandığından, `getline` işlevi tüm satırları string olarak okur. Eğer bu sayıları sayısal türlerde elde etmek isterseniz, okunan stringleri uygun sayısal türlere dönüştürmeniz gerekecektir. Bu dönüşüm için `std::stoi` veya `std::stod` gibi fonksiyonlar kullanılabilir.
 */


#include <mutex>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

std::mutex mtx;

// dosyayı olduğu gibi yazdırıyor.
void Print(const vector<vector<string> > & mat){ // referans koymasan da olur, vektörü değiştiremiyon çünkü. Ama performans için kullan.
    for (int j=0; j < mat.size(); j++){   // mat.size() bize içerdeki vektörlerin sayısını eleman sayısı olarak verir.
        for (int k=0; k < mat[0].size(); k++){
            
            if(k != mat[0].size() -1){
                cout << mat[j][k] << " ";
            }
            
            else{
                cout << mat[j][k];
            }
            
        }
        cout << endl;
    }
}

void Print2(const vector<vector<string> > & mat){ // referans koymasan da olur, vektörü değiştiremiyon çünkü. Ama performans için kullan.
    for (int j=0; j < mat.size(); j++){   // mat.size() bize içerdeki vektörlerin sayısını eleman sayısı olarak verir.
        for (int k=0; k < mat[0].size(); k++){
            
            if(k != mat[0].size() -1){
                cout << setw(5) << left << mat[j][k];
            }
            
            else{
                cout << setw(5) << left << mat[j][k];
            }
            
        }
        cout << endl;
    }
}


void Printc(const vector<vector<char> > & mat){ // referans koymasan da olur, vektörü değiştiremiyon çünkü. Ama performans için kullan.
    for (int j=0; j < mat.size(); j++){   // mat.size() bize içerdeki vektörlerin sayısını eleman sayısı olarak verir.
        for (int k=0; k < mat[0].size(); k++){
            
            if(k != mat[0].size() -1){
                cout << setw(5) << left << mat[j][k];
            }
            
            else{
                cout << setw(5) << left << mat[j][k];
            }
            
        }
        cout << endl;
        
    }
}



void sayiyacevir(vector<vector<string> > & cikarilcak, vector<int> &toplam){
    for (int j=0; j < cikarilcak[0].size(); j++){
        int sum = 0;
        for (int k=0; k < cikarilcak.size(); k++){
            string valueStr = cikarilcak[k][j];
            int value = stoi(valueStr);

            sum += value;

        }
        
        mtx.lock();
        toplam.push_back(sum);
        mtx.unlock();
        
    }
    
}



void addbuilding(vector<vector<char>>& colony,vector<vector<char>> copycolony,vector<vector<string>> consumption,vector<vector<string>> &stock){
    
    
    bool bul = false;
    
    for (int j=0; j < colony.size(); j++){
        for (int k=0; k < colony[0].size(); k++){
            if(colony[j][k] == '-'){
                bul = true;
            }
            
            
        }
   
    }
    
    
    
    if(bul == true){
        bool dongu = true;
        
        bool varmi = false;
        
        int alan,row,column;
        char girdi;
        cout << "Please enter the type of the building that you want to construct:" << endl;
        
        
        
        
        
        
        
        do{
            
            cin >> girdi;
            
            for(int p = 0 ; p < copycolony.size(); p++){
                for(int o = 0 ; o< copycolony[0].size(); o++){
                    if(copycolony[p][o] == girdi ){
                        varmi = true;
                        
                    }
                    
                }
            }

            if((girdi >= 'A' && girdi <= 'Z') && varmi == true){
                
                cout << "Please enter the number of cells that the building will occupy:" << endl;
                
               
                
                int count = 0;
                for(int i = 0 ; i < colony.size();i++){
                    for(int j = 0 ; j < colony[0].size();j++){
                        if(colony[i][j] == '-'){
                            count +=1;
                            
                        }
                        
                    }
                }
                
                bool ic = true;
                
                
                
                do{
                    
                    cin >> alan;
                    
                    
                    if(alan <= count && alan !=0){  // burada hata oluşuyor.
                        for(int m =0 ; m < alan; m++){
                            
                            cout << "Please enter the row and the column index of the cell number " << m + 1 << ":" << endl;
                            
                            
                            // do while gelebilir.
                            
                            bool dongu2 = true;
                            
                            
                            do{
                               
                                
                                cin >> row >> column;
                                
                                if(!(row >= 0 && row < colony.size()) || !(column >= 0 && column < colony[0].size()) ){
                                    
                                    cout << "Invalid row or column index, please enter a valid row and column index:" << endl;
                                    dongu2 = false;
                                    
                                    
                                    
                                    
                                }
                                
                                else{
                                    
                                    
                                    if(!(colony[row][column] == '-')){
                                        cout << "The cell is not empty, please enter the row and the column index of another cell:" << endl;
                                        dongu2 = false;
                                            
                                            
                                            
                                    }
                                        
                                    else{
                                        colony[row][column] = girdi; // burada hata oluşuyor.
                                        //cout << "The building is added to the colony." << endl;
                                        char onceki = colony[row][column];
                                        //colony[row][column] = '-';
                                        string onceki_str = string(1, onceki);
                                        //cout <<  "??????????" << endl;
                                        
                                        
                                        
                                        for(int j=0; j < consumption.size(); j++){
                                            if(consumption[j][0] == onceki_str){
                                                
                                                
                                                
                                                for(int l=0; l < stock.size(); l++){
                                                    int deger = stoi(stock[l][1]);
                                                    
                                                    for(int m=1; m < stock[0].size(); m++){
                                                        
                                                        deger += stoi(consumption[j][l+1]); //0,j
                                                        
                                                        
                                                        string yeni = to_string(deger);
                                                        
                                                        stock[l][1] = yeni;
                                                        //cout <<  "??????????" << endl;
                                                        
                                                        
                                                        
                                                        
                                                        
                                                        //to_string(deger) =stock[l][m];

                                                        
                                                        
                                                    }
                                                    

                                                }
                                                
                                                
                                            }
                                            
                                        }
                                        
                                        dongu2 = true;
                                        ic = true;
                                    }
                                        
                                        
                                        
                                }
                                
                                
                            }while(dongu2 == false);
                            
                            

                            
                        }
                        
                        dongu = true;
                        cout << "The building is added to the colony." << endl;

                        
                        
                        //cout <<
                        
                        
                    }
                    
                    
                    
                    else{
                        cout << "Invalid number of cells, please enter a valid number of cells:" << endl;
                        ic = false;
                    }
                    
                    
                    
                }while(ic == false);
                //cout << "The building is added to the colony." << endl;
                
                

                

                
                
            }
            
            else {
                cout << "Invalid building type, please enter a valid building type:" << endl;
                dongu = false;
            }
            
            
            
            
            
        }while(dongu == false);

        
        

        
        
        
    }
    
    else {
        
        cout << "There are no empty cells in the colony. Can not add a new building." << endl;
    }
    
    
    
    
    
    
};

void removebuilding(vector<vector<char>>& colony,vector<vector<string>>& stock,vector<vector<string>>& consumption){
    
    bool bul = true;
    
    for (int j=0; j < colony.size(); j++){
        for (int k=0; k < colony[0].size(); k++){
            if(colony[j][k] >=  'A' && colony[j][k] <= 'Z'){
                bul = false;
            }
            
            
        }
   
    }
    
    if(bul == true){
        cout << "There are no buildings in the colony. Can not remove a building." << endl;
        
    }
    
    else{
        
        cout << "Please enter the row and the column index of the cell that you want to remove:" << endl;
        
        int row; // int olacak bunlar.
        int column;
        //int size = colony.size();
        
        do{
            
            cin >> row >> column;
            
            if(!(row >= 0 && row < colony.size()) || !(column >= 0 && column < colony[0].size()) ){
                
                cout << "Invalid row or column index, please enter a valid row and column index:" << endl;
                
            }
            /*
            if((row != 0) || (column > size)){
                cout
                
            }
            */
            
            
            
            else{
                
                
                if(colony.size() != colony[0].size()){
                    if(colony[row][column] == '-'){
                        cout << "The cell is already empty, please enter the row and the column index of another cell:" << endl;
                        
                    }

                    
                    
                }
                


                
                
                
            }

            
            

            
        
        }while(!(row >= 0 && row < colony.size()) || !(column >= 0 && column < colony[0].size()) || colony[row][column] == '-');
        
        cout << "The building is removed, and the corresponding resources are added back to the stock." << endl;
        
        char onceki = colony[row][column];
        colony[row][column] = '-';
        string onceki_str = string(1, onceki);
        //cout <<  "??????????" << endl;
        
        
        
        for(int j=0; j < consumption.size(); j++){
            if(consumption[j][0] == onceki_str){
                
                
                
                for(int l=0; l < stock.size(); l++){
                    int deger = stoi(stock[l][1]);
                    
                    for(int m=1; m < stock[0].size(); m++){
                        
                        deger += stoi(consumption[j][l+1]); //0,j
                        
                        
                        string yeni = to_string(deger);
                        
                        stock[l][1] = yeni;
                        //cout <<  "??????????" << endl;
                        
                        
                        
                        
                        
                        //to_string(deger) =stock[l][m];

                        
                        
                    }
                    

                }
                
                
            }
        }
        
        
        
        
        
        
        
        
        
        

        
    }
    
    
    
    
};






void resourceupdate(vector<vector<string> > &stock, vector<vector<string>> consumption, vector<vector<char>> colony) {
    
    vector<vector<string>>cikarilcak; // cikarilcak 'In içi booş olunca problem oluşuyor.
    vector<int> toplam;
    vector<string> temp;

    
    
    for(int i =0;i<colony.size();i++){
        for(int j =0;j< colony[i].size();j++){
            char building = colony[i][j];
            string buildingStr = string(1, building);  // char'ı string değerine çevirmiş olduk.

            
            //bool found = false;
            for(int m = 0; m < consumption.size(); m++){
                if(consumption[m][0]==buildingStr){
                    //found = true;
                    for(int p=1;p< consumption[m].size();p++){
                        temp.push_back(consumption[m][p]);
                        
                    }
                    cikarilcak.push_back(temp);
                    temp.clear();
                    
                }
                
                else{
                    for(int p=1;p< consumption[m].size();p++){
                        temp.push_back("0");
                        
                    }
                    cikarilcak.push_back(temp);
                    temp.clear();

                    
                }
                
            }
            
            
        }
        
    }// for bittikten sonra cikarilacak vektörümüz üzerinden işlem yapacaz.
    
    
    //Print(cikarilcak);
    
    sayiyacevir(cikarilcak, toplam);  // sayıya çevirip sütunları topladık.
    
    

    
    
    
    /*
    for(int h= 0 ; h<toplam.size();h++){
        cout << toplam[h] << " ";
        
    }
    */
    
    bool mal = true;
    for (int j=0; j < stock.size(); j++){   // mat.size() bize içerdeki vektörlerin sayısını eleman sayısı olarak verir.
        for (int k=1; k < stock[0].size(); k++){
            
            string valueStr = stock[j][k];
            int value = stoi(valueStr);
            int yenideger;
            /*
            if(mal == true){
                yenideger = value - toplam[0];
                
            }
            else{
                yenideger = value - toplam[1];
                mal = true;
                
            }
            
            mal = false;
            */
            yenideger = value - toplam[j];
            stock[j][k] = to_string(yenideger);
            
            
            
            

            //yenideger = value - toplam[0];
        }
        
    }
    
    cout << "Resources stock after loading the colony:" << endl;
    cout << "Resource stock:" << endl;
    Print(stock);
    
    vector<vector<string> > result(colony.size(), vector<string>(colony[0].size(),"0")); // result ın kaç satır ve sütundan oluşacağını belirliyor.

    for (int j = 0; j < stock.size(); j++) {
        //vector<string> res;
        //res.push_back(stock[j][0]);
        for (int k = 0; k < colony.size(); k++) {
            
            for (int m = 0; m < colony[k].size(); m++) {
                string valueStr = string(1, colony[k][m]);
                
                for(int a = 0 ; a < consumption.size(); a ++){
                    if (consumption[a][0] == valueStr) {
                        result[k][m] = consumption[a][j + 1];
                        
                        //res.push_back(cikarilcak[m][j]);
                        //break;
                    }
                    
                }
                
            }
            
        }
        
        //result.push_back(res);
        cout << "Consumption of resource " << stock[j][0] << " by each building in the colony:" << endl;
        Print2(result);
        
        
        //cout << "..................." << endl;
        
        
        //Print(cikarilcak);
        
        
    }

    
    

    
    
    
}


int main(){
    
    vector<int> toplam;

    
    
    
    vector<vector<string> > stock;
    
    vector<vector<string>> consumption;
    
    vector<vector<char>> colony;
    
    vector<vector<char>> copycolony;

    
    
    
    vector<vector<string>>resourceresult;
    
    ifstream getstock;
    ifstream getconsumption;
    ifstream getcolony;

    
    string stockdatabase;
    string consumptiondatabase;
    string colonydatabase;
    
    
    string line;
    string line2;
    string line3;
    //char letter;
    
    
    
    
    
    
    cout << "Welcome to the colony management system " << endl;
    
    cout << "Please enter file name for resources stock: " << endl;
    do{
        cin >> stockdatabase;
        getstock.open(stockdatabase.c_str());
        if(getstock.fail()){

            cout << "Unable to open the file " << stockdatabase << " for reading." << endl;
            cout << "Please enter the correct file name: "<< endl;
        }
    }while(getstock.fail());
    
    
    
    
    // bilgiler vektöre atanacak.
    
    
    while (getline(getstock, line)) {
        vector<string> tempwords;
        string word;
        istringstream iss(line);
        while (iss >> word) {
            tempwords.push_back(word);
        }
        stock.push_back(tempwords);
    }
    
    /*
     [['Iron', '500'],
      ['Copper', '0'],
      ['Silicon', '1000']]

     */
    
    


    


    cout << "Available resources loaded from " << stockdatabase << endl;
    cout << "Resource stock:" << endl;
    Print(stock);
    
    
    if (getstock.eof()) { // eğer sona gelmiş ise.
        getstock.seekg(0); // Dosyanın başına dön // İkinci işlemleri burada yapabilirsiniz
    }
    

    
    
    
    
    
    cout << "Please enter file name for resource consumption per building type: " << endl;
    do{
        cin >> consumptiondatabase;
        getconsumption.open(consumptiondatabase.c_str());
        if(getconsumption.fail()){

            cout << "Unable to open the file " << consumptiondatabase << " for reading." << endl;
            cout << "Please enter the correct file name: "<< endl;
        }
    }while(getconsumption.fail());
    
    
    
    while (getline(getconsumption, line2)) {
        vector<string> tempwords2;
        string word2;
        istringstream iss(line2);
        while (iss >> word2) {
            tempwords2.push_back(word2);
        }
        consumption.push_back(tempwords2);
    }
    cout << "Resources consumption per building type loaded from " << consumptiondatabase << endl;
    cout << "Resources consumption per building type:" << endl;
    Print(consumption);
    
    
    if (getconsumption.eof()) { // eğer sona gelmiş ise.
        getconsumption.seekg(0); // Dosyanın başına dön // İkinci işlemleri burada yapabilirsiniz
    }
    
    
    cout << "Please enter file name for colony: " << endl;
    do{
        cin >> colonydatabase;
        getcolony.open(colonydatabase.c_str());
        if(getcolony.fail()){

            cout << "Unable to open the file " << colonydatabase << " for reading." << endl;
            cout << "Please enter the correct file name: "<< endl;
        }
    }while(getcolony.fail());
    


    
    
    while (getline(getcolony, line3)) {
        vector<char> tempwords3;
        char word3;
        istringstream iss(line3);
        while (iss >> word3) {
            tempwords3.push_back(word3);
        }
        colony.push_back(tempwords3);
    }
    
    /*
     Satırda tek bir kelime olsa, kelimenin her bir harfi vektörün indeksleri olacaktır.

     Örneğin, "Hello" kelimesini içeren bir vektör oluşturmak için aşağıdaki kodu kullanabilirsiniz:

     ```
     vector<char> words = {'H', 'e', 'l', 'l', 'o'};
     ```

     Bu kod, `words` vektörünü oluşturacak ve vektöre "H", "e", "l", "l" ve "o" harflerini ekleyecektir.
     */

    
    for(int i = 0 ; i < stock.size();i++){
        for(int j = 0 ; j < stock[0].size();j++){
            
        }
    }

    

    cout << "Colony loaded from " << colonydatabase << endl;
    cout << "Colony:" << endl;
    
    

    
    copycolony=colony;
    
    
    Printc(colony);
    
    

    
    
    if (getcolony.eof()) { // eğer sona gelmiş ise.
        getcolony.seekg(0); // Dosyanın başına dön // İkinci işlemleri burada yapabilirsiniz
    }
    
    resourceupdate(stock, consumption, colony);
    

    

    string choice;
    bool dur = true;
    bool tekrar = true;
    do{
        
        if(tekrar == true){
            cout << "Please enter an option number:" << endl;
            
        }
        
        
        if(dur == true){
            cout << "1. Construct a new building on the colony." << endl;
            cout << "2. Destruct/Disassemble a building from the colony." << endl;
            cout << "3. Print the colony." << endl;
            cout << "4. Print the consumption of all resources by each building in the colony." << endl;
            cout << "5. Print the consumption of a specific resource by each building in the colony." << endl;
            cout << "6. Print the resources stock." << endl;
            cout << "7. Exit the program." << endl;
        }
        dur = false;

        
        cin >> choice;
        
        
        if(choice == "1"){
            
            addbuilding(colony,copycolony,consumption,stock);
            tekrar = true;
        
        }
        
        
        else if(choice == "2"){
            
            removebuilding(colony,stock,consumption);
            tekrar = true;
        }
        
        
        else if(choice == "3"){
            cout << "Colony:" << endl;
            Printc(colony);
            tekrar = true;
        }
        
        
        
        
        else if(choice == "4"){
            tekrar = true;
            
            
            vector<vector<string> > result(colony.size(), vector<string>(colony[0].size(),"0")); // result ın kaç satır ve sütundan oluşacağını belirliyor.

            for (int j = 0; j < stock.size(); j++) {
                //vector<string> res;
                //res.push_back(stock[j][0]);
                for (int k = 0; k < colony.size(); k++) {
                    
                    for (int m = 0; m < colony[k].size(); m++) {
                        string valueStr = string(1, colony[k][m]);
                        
                        for(int a = 0 ; a < consumption.size(); a ++){
                            if (consumption[a][0] == valueStr) {
                                result[k][m] = consumption[a][j + 1];
                                
                                //res.push_back(cikarilcak[m][j]);
                                //break;
                            }
                        }
                        
                    }
                    
                }
                
                //result.push_back(res);
                cout << "Consumption of resource " << stock[j][0] << " by each building in the colony:" << endl;
                Print2(result);
                
                
                //cout << "..................." << endl;
                
                
                //Print(cikarilcak);
                
                
            }
            
            
        }
        
        
        
        else if(choice == "5"){
            tekrar = true;
            vector<vector<string> > result(colony.size(), vector<string>(colony[0].size(),"0"));

            
            string gir;
            
            cout << "Please enter the type of the resource:" << endl;
            
            cin >> gir;
            
            bool bul = false;
            int sayi = 0;
            
            
            for (int j=0; j < stock.size(); j++){
                if(stock[j][0] == gir){
                    bul = true;
                    sayi = j;
                    
                }

            }
            
            if(bul == false){
                cout << "The resource " <<  gir << " was not found in the resources stock." << endl;
                
                
            }
            
            else{
                
                
                vector<vector<string> > result(colony.size(), vector<string>(colony[0].size(),"0")); // result ın kaç satır ve sütundan oluşacağını belirliyor.

                for (int j = sayi; j < sayi + 1; j++) {
                    //vector<string> res;
                    //res.push_back(stock[j][0]);
                    for (int k = 0; k < colony.size(); k++) {
                        
                        for (int m = 0; m < colony[k].size(); m++) {
                            string valueStr = string(1, colony[k][m]);
                            
                            for(int a = 0 ; a < consumption.size(); a ++){
                                if (consumption[a][0] == valueStr) {
                                    result[k][m] = consumption[a][sayi + 1];
                                    
                                    //res.push_back(cikarilcak[m][j]);
                                    //break;
                                }
                            }
                            
                        }
                        
                    }
                    

                    
                }
                cout << "Consumption of resource " << gir << " by each building in the colony:" << endl;
                Print2(result);
                
                

                
            }
            
            

         
         
            
        }
        
        
        
        
        else if(choice == "6"){
            cout << "Resource stock:" << endl;
            Print(stock);
            tekrar = true;
        }
        
        
        else if(choice =="7"){
            
            cout << "Thank you for using the colony management system. The program will terminate." << endl;
            cout << "Goodbye!" << endl;
        }
        
        
        else{
            cout << "Invalid option number.Please enter an option number:" << endl;
            tekrar = false;
            

        }
        
    }while(choice !="7");
    
    
    
    
    cout << endl;
    
}



