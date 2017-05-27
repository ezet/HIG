#include <iostream>
#include <iomanip>
#include <fstream>
#include <time.h>
using namespace std;

const int NUMEVENTS = 11;
const int NUMCUSTOMERS = 201;
const int STRLEN = 20;
const int EVENTLEN = 35;

class Customer {
private:
  char name_[STRLEN];
  int num_ordered_[NUMEVENTS];
  int num_received_[NUMEVENTS];

public:
  Customer() { };
  char* name() { return name_; }
  int num_ordered(int n) { return num_ordered_[n]; }
  int num_received(int n) { return num_received_[n]; }
};

class Event {
private:
  char title_[EVENTLEN];
  int price_;
  int tickets_total_;
  int tickets_sold_;
  int tickets_ordered_;
  int unique_orders_;

public:
  Event() { }
  char* title() { return title_; }
  int price() { return price_; }
};


// Class for handling dynamic arrays of events and customers
class TicketHandler {
public:
  TicketHandler() {
    customer_loglen_ = 0;
    customer_alloclen_ = 10;
    customers = new Customer*[customer_alloclen_];
    event_loglen_ = 1;
    event_alloclen_ = 5;
    events = new Event*[event_alloclen_];
  }

  // Reads customers from the binary file
  int ReadCustomerFile(char filename[]) {
    ifstream ifile;
    ifile.open(filename, ios::binary);
    if (!ifile) {
      cerr << "Could not open file: " << filename << endl;
      return 0;
    }
    while (ifile.good()) {

      // if the array is full, expand it
      if (customer_loglen_ == customer_alloclen_) {
        customers = (Customer**)ExpandArray(customers, customer_loglen_, customer_alloclen_);
      }
      Customer *buffer = new Customer;
      ifile.read((char*)buffer,  sizeof(Customer));
      if (ifile.good()) {
        *(customers+customer_loglen_) = buffer;
        customer_loglen_++;
      }
    }
    ifile.close();
    return customer_loglen_;
  }

  // Reads events from a binary file
  int ReadEventFile(char filename[]) {
    ifstream ifile;
    ifile.open(filename, ios::binary);
    if (!ifile) {
      cerr << "Could not open file: " << filename << endl;
      return 0;
    }
    while (ifile.good()) {
      // If the array is full, expand it
      if (event_loglen_ == event_alloclen_) {
        events = (Event**)ExpandArray(events, event_loglen_, event_alloclen_);
      }
      Event *buffer = new Event;
      ifile.read((char*)buffer,  sizeof(Event));
      if (ifile.good()) {
        *(events+event_loglen_) = buffer;
        event_loglen_++;
      }
    }
    ifile.close();
    return event_loglen_;
  }

  // Fetches a new memblock, copies elements over, frees the old block and returns a pointer
  void* ExpandArray(void *oldarray, int loglen, int &alloclen) {
    void **newarray = new void*[alloclen*2];
    memcpy(newarray, oldarray, loglen*sizeof(void*));
    delete[] oldarray;
    alloclen *= 2;
    return newarray;
  }

  // Generates and writes all invoices to file
  void WriteInvoicesToFile(char filename[]) {
    ofstream ofile;
    ofile.open(filename);
    for (int i = 0; i < 4; ++i) {
      GenerateInvoice(ofile, i);
    }
    ofile.close();
  }

  // Generates invoices
  ostream& GenerateInvoice(ostream &s, int n) {
    char date[9];
    _strdate_s(date);
    int total = 0;
    s << "\n\n\Invoice: " << 1001+n
      << "\nDate: " << date
      << "\nCustomer ID: " << 100001+n
      << "\n\tName: " << (*(customers+n))->name()
      << "\n\tAddress: "
      << "\n\nProduct:";
    for (int j = 1; j < NUMEVENTS; j++) {
      if ( (*(customers+n))->num_ordered(j) > 0) {
        s << "\n\tEvent no:\t" << j
          << "\n\tDescription:  " << (*(events+j))->title()
          << "\n\tOrdered qty:\t" << (*(customers+n))->num_ordered(j)
          << "\n\tReceived qty:\t" << (*(customers+n))->num_received(j)
          << "\n\tPrice per:\t" << (*(events+j))->price() << ",- NOK"
          << "\n\tSum:\t\t" << (*(events+j))->price() *
          (*(customers+n))->num_received(j) << ",- NOK"
          << endl;
        total += (*(events+j))->price() * (*(customers+n))->num_received(j);
      }
    }
    s << "\nTax\t: " << 0
      << "\nTOTAL\t: " << total << ",- NOK"
      << "\n\nComments:" << "\n\tEnjoy your days at the Olympics!"
      << "\n\tFor inquiries call us at: 123 12 312\n\n";
    for (int i = 0; i < 60; ++i) {
      s << '-';
    }
    return s;
  }

private:
  Customer **customers;
  int customer_loglen_;
  int customer_alloclen_;

  Event **events;
  int event_loglen_;
  int event_alloclen_;
};

int main(int argc, char *argv[]) {
  TicketHandler handler;
  handler.ReadCustomerFile("kun_ol94.res");
  handler.ReadEventFile("bil_ol94.res");
  handler.WriteInvoicesToFile("invoices.txt");

  return 0;
}