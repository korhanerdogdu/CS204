
#include "PrintQueue.h"
#include <iostream>
#include <time.h>
#include <random>
#include <thread>

#include <mutex>
using namespace std;
mutex mtx;




//for generating random number of pages and waiting times inside the threads.

void print_time() {
    time_t now = time(0);
    struct tm *ltm = localtime(&now);
    cout << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;
}


int random_range(const int &min, const int &max) {
    static mt19937 generator(time(0));
    uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}



void userThread(PrintQueue &printerQueue, int userID, int minPages, int maxPages, int minWaitTime, int maxWaitTime) {
    int jobID = 1;
    this_thread::sleep_for(chrono::seconds(random_range(minWaitTime, maxWaitTime))); // Initial wait
    while (true) {
        int numPages = random_range(minPages, maxPages);
        {
            lock_guard<mutex> lock(mtx);
            cout << "User " << userID << ": Job with ID " << jobID << " sent to the printer queue, number of pages: " << numPages << " (print queue size: " << printerQueue.getCurrentSize() << ") ";
            print_time();
            printerQueue.enqueue(jobID, numPages);
        }
        this_thread::sleep_for(chrono::seconds(random_range(minWaitTime, maxWaitTime))); // Wait before sending the next job
        jobID++;
    }
}

void PrinterThread(PrintQueue &printerQueue) {
    while (true) {
        int userID, numPages;
        {
            lock_guard<mutex> lock(mtx);
            if (!printerQueue.isEmpty()) {
                printerQueue.dequeue(userID, numPages);
                cout << "The printer started to print the job with ID: " << userID << ", number of pages: " << numPages << " (queue size is: " << printerQueue.getCurrentSize() << ") ";
                print_time();
                if (numPages > 0) {
                    this_thread::sleep_for(chrono::seconds(numPages)); // Simulate printing time
                    cout << "The printer finished printing the job with ID: " << userID << ", number of pages: " << numPages << " ";
                    print_time();
                    printerQueue.printQueueContents();
                }
            }
        }
    }
}




int main(){
    
    
    
    
    int maxPrintJobs, minWaitTime, maxWaitTime, minPages, maxPages;

    cout << "Please enter the max number of print jobs: ";
    cin >> maxPrintJobs;
    
    cout << "Please enter the min and max values for the time range between two print jobs:" << endl;
    cout << "Min: ";
    cin >> minWaitTime;
    
    cout << "Max: ";
    cin >> maxWaitTime;
    
    cout << "Please enter the min and max values for the number of pages in a print job:" << endl;
    cout << "Min number of pages: ";
    cin >> minPages;
    cout << "Max number of pages: ";
    cin >> maxPages;
    
    

    
    PrintQueue printerQueue;

    thread userThread1(userThread, ref(printerQueue), 1);
    thread userThread2(userThread, ref(printerQueue), 2);
    thread userThread3(userThread, ref(printerQueue), 3);
    thread printerThread(PrinterThread, ref(printerQueue));

    userThread1.join();
    userThread2.join();
    userThread3.join();
    printerThread.join();
    
    
    
    
    
}


/*
 Bu ödevde, çoklu iş parçacığı (multithreading) tekniklerini kullanarak C++ dilinde bir yazıcı sırası (printer queue) simülasyonu yapmanız isteniyor. Temel olarak, kullanıcıların baskı işleri oluşturmasını ve bunları sıraya eklemesini, ardından yazıcının bu işleri sıradan çıkarmasını (dequeue) ve işlemesini simüle etmeniz gerekiyor. Bu işlemi gerçekleştirirken, dinamik bir sıra veri yapısını tamamlamanız, belirli operatörleri aşırı yüklemeniz (overloading), iş parçacıkları arasında senkronizasyon sağlamanız ve rastgele değerleri kullanarak belirli süreleri ve sayfaları simüle etmeniz gerekiyor.

 Ana görevleri ve kavramları şu şekilde açıklayabiliriz:

 1. **Dinamik Sıra (Queue) Uygulaması**: Verilen eksik dinamik sıra veri yapısını tamamlamanız gerekiyor. Bu sırayı aşırı yüklenmiş operatörlerle (enqueue ve dequeue) kullanarak iş parçacıkları arasında paylaşılan bir kuyruk yapısı olarak kullanacaksınız.

 2. **Operatörlerin Aşırı Yüklenmesi**: `+` ve `-` operatörlerini aşırı yükleyerek, yazıcı kuyruğuna iş ekleme (enqueue) ve iş çıkarma (dequeue) işlemlerini gerçekleştirmelisiniz. Bu operatörler, sıra içerisindeki işleri eklemek ve çıkarmak için kullanılacak.

 3. **İş Parçacıkları (Threads)**: Toplamda dört farklı iş parçacığı kullanmanız gerekiyor: üç kullanıcı iş parçacığı ve bir yazıcı iş parçacığı. Kullanıcı iş parçacıkları, rastgele sayıda sayfa içeren işleri oluşturup sıraya ekleyecek. Yazıcı iş parçacığı ise sıradaki işleri alıp (dequeue) ve işlemesi (yani yazdırması) gerekiyor.

 4. **Rastgele Değerler**: Kullanıcıların iş oluşturduktan sonra bekleyeceği süreyi ve her bir işin sayfa sayısını rastgele değerlerle belirlemeniz gerekiyor. Bu rastgele değerleri oluşturmak için `random_range` fonksiyonunu kullanmalısınız.

 5. **Simülasyon Ayrıntıları**: Kullanıcı iş parçacıkları, her bir işin oluşturulmasından sonra bekleme süresi ve sıraya eklenen işin ayrıntılarını görüntülemelidir. Yazıcı iş parçacığı ise işlerin işlemesi sırasında ayrıntıları görüntülemeli ve kuyruğun içeriğini takip etmelidir.

 6. **Global Değişkenler**: Bu ödevde global değişkenler kullanmanıza izin veriliyor, ancak abartmamaya dikkat etmeniz gerekiyor. Aşırı miktarda global değişken kullanmak, programın kontrolünü kaybetmenize neden olabilir.

 Bu ödevde verilen görevleri tamamlamak ve açıklanan konseptleri anlamak, çoklu iş parçacığı programlaması ve aşırı yükleme operatörlerinin nasıl kullanılacağını anlamak açısından önemlidir. Aynı zamanda senkronizasyon, rastgele sayı üretimi ve dinamik veri yapılarını kullanma becerilerinizi de geliştirecektir.
 */
