// Lars Kristian Dahl, 10HBPUA
// Er klar over at dette er langt utover det obligen krever og unodvendig tungt,
// men lærer mye av å prøve å tenke mer objekt-orientert og å skrive "tunge" løsninger.
// Ville selvsagt holdt det enklest mulig i en reell jobb.

#include <iostream>
#include <fstream>
#include "listtool.h"
using namespace std;

// Forward declarations
class Patient;
class Prescription;
class Doctor;
class Drug;

//-----------------------------------------------
// UTILITY DECLARATIONS
//-----------------------------------------------
class Util {
public:
  static const int STRLEN = 80;
  static bool IsValidDate(int date);
  static bool IsValidString(char string[]);
  static int GetInt(char text[]);
  static int GetIntInRange(char text[], int min, int max);
  static int GetDate(char text[]);
  static char GetChar(char text[]);
  static void GetString(char text[], char dest[], int size=STRLEN);
  static bool OpenFile(char filename[], fstream &fshandle);
};

//-----------------------------------------------
// ABSTRACT FACTORY DECLARATIONS
//-----------------------------------------------
class Factory {
public:
  static void InjectLists(List *patients, List *doctors, List *drugs);
  static Patient *GetPatient();
  static Patient *GetPatient(char name[]);
  static Drug *GetDrug();
  static Drug *GetDrug(char name[]);
  static Doctor *GetDoctor();
  static Doctor *GetDoctor(char name[]);
  virtual void MakeAbstract() =0;

private:
  static List *prescripts_;
  static List *patients_;
  static List *doctors_;
  static List *drugs_;
};

List *Factory::prescripts_;
List *Factory::patients_;
List *Factory::doctors_;
List *Factory::drugs_;


//-----------------------------------------------
// PATIENT DECLARATIONS
//-----------------------------------------------
class Patient : public Text_element {
public:
  Patient(List *list, char name[]);
  char *get_name();
  List *get_prescriptions();
  bool AddPrescription(Prescription *prescript);
  void RemovePrescription(int date);
  void display();

private:
  List *prescripts_;
};


//-----------------------------------------------
// DRUG DECLARATIONS
//-----------------------------------------------
class Drug : public Text_element {
public:
  Drug(List *list, char name[]);
  char *get_name();
  List *get_prescriptions();
  bool AddPrescription(Prescription *prescript);
  void RemovePrescription(int date);
  void ReadFromDisk(fstream &ifile);
  void WriteToDisk(fstream &ofile);
  void display();

private:
  List *prescripts_;
};


//-----------------------------------------------
// DOCTOR DECLARATIONS
//-----------------------------------------------
class Doctor : public Text_element {
public:
  Doctor(List *list, char name[]);
  Doctor(List *list, char name[], ifstream *ifile);
  virtual ~Doctor();
  char *get_name();
  void ReadFromConsole();
  List *get_prescriptions();
  bool AddPrescription(Prescription *prescript);
  void RemovePrescription(int date);
  bool HasPrescriptions();
  void ReadFromDisk(fstream &ifile);
  void WriteToDisk(fstream &ofile);
  void display();

private:
  List *prescripts_;
  char *address_;
  int phone_;
};


//-----------------------------------------------
// PRESCRIPTION DECLARATIONS
//-----------------------------------------------
class Prescription : public Num_element {
public:
  Prescription(Patient *patient, Doctor *doc, Drug *drug, int date);
  int get_date();
  Doctor *GetDoctor();
  Patient *GetPatient();
  Drug *GetDrug();
  void Purge();
  void ReadFromConsole();
  void ReadFromDisk(fstream &ifile);
  void WriteToDisk(fstream &ofile);
  void display();

private:
  int dose_;
  Doctor *doctor_;
  Drug *drug_;
  Patient *patient_;
};


//-----------------------------------------------
// APPLICATION DECLARATIONS
//-----------------------------------------------
class Application {
public:
  Application();

  // Application control
  void Run();
  void PrintMenu();
  void GetCommand();
  void Dispatch();
  void RegisterPrescription(Prescription *prescript);

  // Commands
  void NewPrescript();
  void PurgePrescripts();
  void PrintDoctor();
  void PrintPatient();
  void PrintPrescript();
  void WriteToDisk();
  void ReadFromDisk();
  void PrintHelp();
  void Quit();

private:
  char cmd_;
  List *prescripts_;
  List *patients_;
  List *doctors_;
  List *drugs_;
};


//-----------------------------------------------
// MAIN
//-----------------------------------------------
int main(int argc, char *argv[]) {
  Application app;
  app.Run();
  return 0;
}


//-----------------------------------------------
// UTILITY METHODS
// Basic helper methods
//-----------------------------------------------
char Util::GetChar(char text[]) {
  char c;
  cout << text;
  cin >> noskipws >> c;
  cin.ignore();
  return c;
}

void Util::GetString(char text[], char dest[], int size) {
  do {
    cout << text;
    cin.getline(dest, size);
  } while (!IsValidString(dest));
}

int Util::GetInt(char text[]) {
  int buffer;
  cout << text;
  cin >> buffer;
  cin.ignore();
  return buffer;
}

int Util::GetIntInRange(char text[], int min, int max) {
  int buffer;
  do {
    buffer = Util::GetInt(text);
  } while (buffer < min && buffer > max);
  return buffer;
}

int Util::GetDate(char text[]) {
  int buffer;
  buffer = Util::GetIntInRange(text, 19900101, 20101231);
  while (!IsValidDate(buffer)) {
    cout << "\nInvalid date, please try again.";
    buffer = Util::GetIntInRange(text, 19900101, 20101231);
  }
  return buffer;
}

bool Util::IsValidDate(int date) {
  int y = date / 10000;
  int m = date/100 - y*100;
  int d = date - y*10000 - m*100;
  return y > 1989 && y < 2011   // valid year
         && m > 0 && m < 13     // valid month
         && d > 0 && d < 32;    // valid date
}

bool Util::IsValidString(char string[]) {
  bool valid = true;
  for (int i = 0; string[i]; ++i)
    if (!isalpha(string[i]) && !isspace(string[i]))
      valid = false;
  return valid;
}

bool Util::OpenFile(char filename[], fstream &fshandle) {
  fshandle.open(filename);
  if (!fshandle)
    cerr << "Could not open file: " << filename << endl;
  return (fshandle) ? true : false;
}


//-----------------------------------------------
// FACTORY METHODS
// Controls and helps in the creation of new objects using a simple 
// abstract factory pattern
//-----------------------------------------------
void Factory::InjectLists(List *patients, List *doctors, List *drugs) {
  patients_ = patients;
  doctors_ = doctors;
  drugs_ = drugs;
}

Patient *Factory::GetPatient() {
  char buffer[Util::STRLEN];
  Util::GetString("Enter the patient's name: ", buffer);
  return Factory::GetPatient(buffer);
}

// If patient already exists, returns a pointer to it, else returns a new Patient
Patient *Factory::GetPatient(char name[]) {
  Patient *patient = (Patient*)patients_->remove(name);
  if (!patient) patient = new Patient(new List(Sorted), name);
  patients_->add(patient);
  return patient; 
}

Drug *Factory::GetDrug() {
  char buffer[Util::STRLEN];
  Util::GetString("Enter the drug's name: ", buffer);
  return Factory::GetDrug(buffer);
}

// If drug already exists, returns a pointer to it, else returns a new Drug
Drug *Factory::GetDrug(char name[]) {
  Drug *drug = (Drug*)drugs_->remove(name);
  if (!drug) drug = new Drug(new List(Sorted), name);
  drugs_->add(drug);
  return drug; 
}

Doctor *Factory::GetDoctor() {
  char buffer[Util::STRLEN];
  Util::GetString("Enter the Doctors's name: ", buffer);
  return Factory::GetDoctor(buffer);
}

// If doctor already exists, returns a pointer to it, else returns a new Doctor
Doctor *Factory::GetDoctor(char name[]) {
  Doctor *doctor = (Doctor*)doctors_->remove(name);
  if (!doctor) doctor =  new Doctor(new List(Sorted), name);
  doctors_->add(doctor);
  return doctor;
}

//-----------------------------------------------
// PATIENT METHODS
//-----------------------------------------------
Patient::Patient(List *list, char name[]) : Text_element(name) {
  prescripts_ = list;
}

char *Patient::get_name() {
  return text;
}

List *Patient::get_prescriptions() {
  return prescripts_;
}

// Adds prescription to a list of this pasients prescriptions
bool Patient::AddPrescription(Prescription *prescript) {
  return prescripts_->add(prescript);
}

void Patient::RemovePrescription(int date) {
  prescripts_->remove(date);
}

void Patient::display() {
  cout << text;
}

//-----------------------------------------------
// DRUG METHODS
//-----------------------------------------------
Drug::Drug(List *list, char name[]) : Text_element(name) {
  prescripts_ = list;
}

char *Drug::get_name() {
  return text;
}

List *Drug::get_prescriptions() {
  return prescripts_;
}

// Adds prescription to a list of prescriptions issuing this drug
bool Drug::AddPrescription(Prescription *prescript) {
  return prescripts_->add(prescript);
}

void Drug::RemovePrescription(int date) {
  prescripts_->remove(date);
}

void Drug::display() {
  cout << text;
}

//-----------------------------------------------
// DOCTOR METHODS
//-----------------------------------------------
Doctor::Doctor(List *list, char name[]) : Text_element(name) {
  prescripts_ = list;
}

Doctor::~Doctor() {
  delete[] address_;
}

char *Doctor::get_name() {
  return text;
}

List *Doctor::get_prescriptions() {
  return prescripts_;
}

bool Doctor::AddPrescription(Prescription *prescript) {
  return prescripts_->add(prescript);
}

void Doctor::RemovePrescription(int date) {
  prescripts_->remove(date);
}

bool Doctor::HasPrescriptions() {
  return !prescripts_->is_empty();
}

// Reads doctor information from the keyboard
void Doctor::ReadFromConsole() {
  char buffer[Util::STRLEN];
  Util::GetString("Enter the Doctors address: ", buffer);
  address_ = new char[strlen(buffer)+1];
  strcpy_s(address_, strlen(buffer)+1, buffer);
  phone_ = Util::GetIntInRange("Enter the Doctors phone number: ", 10000000, 99999999);
}

void Doctor::WriteToDisk(fstream &ofile) {
  ofile << text << '\n' << phone_ << ' ' << address_ << '\n';
}

void Doctor::ReadFromDisk(fstream &ifile) {
  ifile >> phone_;
  ifile.ignore();
  char buffer[Util::STRLEN];
  ifile.getline(buffer, Util::STRLEN);
  address_ = new char[strlen(buffer)+1];
  strcpy_s(address_, strlen(buffer)+1, buffer);
}

void Doctor::display() {
  cout << "\n\tName: " << text
       << "\n\tAddress: " << address_
       << "\n\tPhone: " << phone_;
}


//-----------------------------------------------
// PRESCRIPTION METHODS
//-----------------------------------------------
// Creates a new prescription, which adds itself to the objects it belongs to
Prescription::Prescription(Patient *patient, Doctor *doctor, Drug *drug,
                           int date) : Num_element(date) {
  patient->AddPrescription(this);
  doctor->AddPrescription(this);
  drug->AddPrescription(this);
  patient_ = patient;
  doctor_ = doctor;
  drug_ = drug;
}

int Prescription::get_date() { return number; }

Doctor *Prescription::GetDoctor() {
  return doctor_;
}

Patient *Prescription::GetPatient() {
  return patient_;
}

Drug *Prescription::GetDrug() {
  return drug_;
}

// Deletes the prescription from the objects it is registered with
void Prescription::Purge() {
  patient_->RemovePrescription(number);
  doctor_->RemovePrescription(number);
  drug_->RemovePrescription(number);
}

void Prescription::ReadFromConsole() {
  dose_ = Util::GetIntInRange("Enter dose (mg): ", 0, 1000);
}

void Prescription::ReadFromDisk(fstream &ifile) {
  ifile >> dose_;
  ifile.ignore();
}

void Prescription::WriteToDisk(fstream &ofile) {
  ofile << patient_->get_name() << '\n'
        << doctor_->get_name() << '\n'
        << drug_->get_name() << '\n'
        << number << '\n' << dose_ << '\n';
}

void Prescription::display() {
  cout << "\n\n----------------------"
       << "\nDate issued: " << number
       << "\nIssued to: ";
  patient_->display();
  
  cout << "\n\nIssued by:";
  doctor_->display();
  cout << "\n\nDetails:"
       << "\n\tPharmaceutical: ";
  drug_->display();
  cout << "\n\tDose: " << dose_
       << "\n----------------------\n";
}

//-----------------------------------------------
// APPLICATION METHODS
//-----------------------------------------------
// Initializes the application and the factory
Application::Application() {
  prescripts_ = new List(Sorted);
  patients_ = new List(Sorted);
  doctors_ = new List(Sorted);
  drugs_ = new List(Sorted);
  Factory::InjectLists(patients_, doctors_, drugs_);
}

void Application::Run() {
  do {
    PrintMenu();
    GetCommand();
    Dispatch();
  } while (cmd_ != 'q');
}

void Application::PrintMenu() {
  cout << "\n\n\tApplication menu\n";
  cout << "\n\tR - Register new prescription"
    << "\n\tF - Purge okld prescriptions"
    << "\n\tL - Print doctor information"
    << "\n\tP - Print patient information"
    << "\n\tU - Write data to file"
    << "\n\tI - Read data from file"
    << "\n\tH - Help"
    << "\n\tQ - Quit";
}

void Application::GetCommand() {
  cmd_ = tolower(Util::GetChar("\n\nEnter command: "));
}

void Application::Dispatch() {
  switch (cmd_) {
  case 'r': NewPrescript(); break;
  case 'f': PurgePrescripts(); break;
  case 'l': PrintDoctor(); break;
  case 'p': PrintPatient(); break;
  case 'u': WriteToDisk(); break;
  case 'i': ReadFromDisk(); break;
  case 'h': PrintHelp(); break;
  case 'q': break;
  default: cout << "\nUnknown command: " << cmd_ << endl;
  }
}


void Application::NewPrescript() {
  // Get the patient, doctor and drug, using a factory to get a new or existing object
  Patient *patient = Factory::GetPatient();
  Doctor *doctor = Factory::GetDoctor();
  doctor->ReadFromConsole();
  Drug *drug = Factory::GetDrug();
  // And create a new prescription, injecting the required objects
  int date = Util::GetDate("Enter date: ");
  Prescription *prescription = new Prescription(patient, doctor, drug, date);
  prescription->ReadFromConsole();
  prescripts_->add(prescription);
  cout << "Prescription successfully added.";
  prescription->display();
}

void Application::PurgePrescripts() {
  int date = Util::GetDate("\nPurge prescriptions issued before (yyyymmdd): ");
  cout << "\n\tPurging prescriptions...";
  Prescription *prescript = NULL;
  int purgedpre = 0, purgeddoc = 0;
  do {
    // if we have a prescription that should be purged
    if (prescript) {
      prescript->Purge();
      // if the doctor has no prescriptions left, delete him
      if (!prescript->GetDoctor()->HasPrescriptions()) {
        doctors_->destroy(prescript->GetDoctor()->get_name());
        purgeddoc++;
      }
      // deleting the prescription
      delete prescript;
      purgedpre++;
    }
    // fetch a new prescription and check the date
    prescript = (Prescription*)prescripts_->remove_no(0);
    } while (prescript && prescript->get_date() < date);
  // if we have exited the loop and still have a prescription, this prescription
  // should be added back
  if (prescript)
    prescripts_->add(prescript);
  cout << "\n\tSuccessfully purged " << purgedpre
       << " prescriptions and " << purgeddoc << " doctors.";
}

void Application::PrintDoctor() {
  char buffer[Util::STRLEN];
  Util::GetString("\nEnter the name of the Doctor to search for: ", buffer);
  if (doctors_->display_element(buffer)) {
    Doctor *doctor = (Doctor*)doctors_->remove(buffer);
    doctor->get_prescriptions()->display_list();
    doctors_->add(doctor);
  } else {
    cout << "\n\tCould not find Doctor: " << buffer << '\n';
  }
}

void Application::PrintPatient() {
  char buffer[Util::STRLEN];
  Util::GetString("\nEnter the name of the patient to search for: ", buffer);
  if (patients_->display_element(buffer)) {
    Patient *patient = (Patient*)patients_->remove(buffer);
    patient->get_prescriptions()->display_list();
    patients_->add(patient);
  } else {
    cout << "\n\tCould not find patient: " << buffer << '\n';
  }
}

// Writes doctors to doctors.txt and prescription to prescriptions.txt
void Application::WriteToDisk() {
  fstream ofile;
  if (!Util::OpenFile("doctors.txt", ofile))
    return;
  cout << "\nWriting doctors to disk...\n";
  for (int i = 1; i <= doctors_->no_of_elements(); ++i) {
    Doctor *doctor = (Doctor*)doctors_->remove_no(i);
    doctors_->add(doctor);
    doctor->WriteToDisk(ofile);
  }
  ofile.close();
  if (!Util::OpenFile("prescriptions.txt", ofile))
    return;
  cout << "\nWriting prescriptions to disk...\n";
  for (int i = 1; i <= prescripts_->no_of_elements(); ++i) {
    Prescription *prescript = (Prescription*)prescripts_->remove_no(i);
    prescripts_->add(prescript);
    prescript->WriteToDisk(ofile);
  }
  ofile.close();
}

// Reads from doctors.txt and prescriptions.txt
void Application::ReadFromDisk() {
  fstream ifile;
  if (!Util::OpenFile("doctors.txt", ifile))
    return;
  char buffer[Util::STRLEN];
    ifile >> buffer;
    while (ifile) {
      Doctor *doctor = Factory::GetDoctor(buffer);
      doctor->ReadFromDisk(ifile);
      doctors_->add(doctor);
      ifile >> buffer;
    }
  ifile.close();
  if (!Util::OpenFile("prescriptions.txt", ifile))
    return;
  int date;
  ifile.getline(buffer, Util::STRLEN);
  while (ifile) {
    // Read the prescription dependencies
    Patient *patient = Factory::GetPatient(buffer);
    ifile.getline(buffer, Util::STRLEN);
    Doctor *doctor = Factory::GetDoctor(buffer);
    ifile.getline(buffer, Util::STRLEN);
    Drug *drug = Factory::GetDrug(buffer);
    ifile >> date;
    ifile.ignore();
    // Create a new prescription, injecting the dependencies
    Prescription *prescription = new Prescription(patient, doctor, drug, date);
    prescription->ReadFromDisk(ifile);
    // And add it to the list of prescriptions
    prescripts_->add(prescription);
    ifile.getline(buffer, Util::STRLEN);
  }
  ifile.close();
}

void Application::PrintHelp() {

}