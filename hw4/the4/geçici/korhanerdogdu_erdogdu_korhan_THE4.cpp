// Korhan Erdogdu 30838

#include "PrintQueue.h"
#include <iostream>
#include <time.h>
#include <random>

#include <mutex>
using namespace std;
mutex mtx;


//for generating random number of pages and waiting times inside the threads.
int random_range(const int &min, const int &max) {
    static mt19937 generator(time(0));
    uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}


//for getting the current timr for saying "Simulation starts".
void printthetime() {
    time_t now = time(0);
    struct tm *ltm = localtime(&now);
    cout << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;
}





int main(){
    
    int maxjobs, mintime, maxtime, minpage, maxpage;
    
    cout << "Please enter the max number of print jobs: ";
    cin >> maxjobs;
    
    
    cout << "Please enter the min and max values for the time range between two print jobs:" << endl;
    cout << "Min: ";
    cin >> mintime;
    
    
    cout << "Max: ";
    cin >> maxtime;
    
    
    cout << "Please enter the min and max values for the number of pages in a print job:" << endl;
    cout << "Min number of pages: ";
    cin >> minpage;
    
    
    
    cout << "Max number of pages: ";
    cin >> maxpage;
    
    
    
    cout << "Simulation starts ";
    printthetime();
    
    
    
    cout << "End of the simulation at: ";
    printthetime();
    
    
    
    
    
}
