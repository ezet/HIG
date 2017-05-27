#include <iostream>
using namespace std;

const int STRLEN = 80;

//-------------------------------
// Class Insect, Abstract
//-------------------------------
class Animal {
public:
  Animal() { GetInput(); }
  explicit Animal(char name[]) { GetInput(name); } // overloaded GetInput

  int GetIntInput(char s[]) {   // retrieves int from keyboard
    int input;
    cout << s;
    cin >> input;
    return input;
  }

  float GetFloatInput(char s[]) {   // retrieves float from keyboard
    float input;
    cout << s;
    cin >> input;
    return input;
  }

  char* GetStringInput(char s[]) {    // retrieves cstring from keyboard
    char *input = new char[STRLEN];
    cout << s;
    cin.getline(input, STRLEN);
    return input;
  }

  virtual void PrintData() const {    // prints 'Animal' specific data
    cout << "\nName: " << name_ << '\n';
    cout << "Weight: " << weight_ << '\n';
  }

private:
  virtual void GetInput()=0 {   // abstracting class
    cout << "No-arg constructor\n";
    char *input = GetStringInput("Name: ");
    strcpy_s(name_, input);
    weight_ = GetFloatInput("Weight: ");  
  }

//----------
// Used when 'name' is provided through Fish constructor
//----------
  void GetInput(char name[]) {
    cout << "One-arg constrctor\n";
    strcpy_s(name_, name);
    weight_ = GetFloatInput("Weight: "); 
  }
  char name_[STRLEN];
  float weight_;
};

//-------------------------------
// Class AirAnimal, Abstract
//-------------------------------
class AirAnimal : public Animal {
public:
  AirAnimal() { GetInput(); }

  virtual void PrintData() const {
    Animal::PrintData();
    cout << "Usual flight altitude in meters: " << altitude_ << '\n';
  }

private:
  virtual void GetInput()=0 {   // abstracting class
    altitude_ = GetIntInput("Usual flight altitude in meters: ");
  }

  int altitude_;
};

//-------------------------------
// Class WaterAnimal, Abstract
//-------------------------------
class WaterAnimal : public Animal {
public:
  WaterAnimal() { GetInput(); }
  explicit WaterAnimal(char name[]) : Animal(name) { GetInput(); }

  virtual void PrintData() const {
    Animal::PrintData();
    cout << "Usual depth: " << depth_ << '\n';
  }

private:
  virtual void GetInput()=0 {   // abstracting class
    depth_ = GetIntInput("Usual depth in meters: ");
  }

  int depth_;
};

//-------------------------------
// Class Insect
//-------------------------------
class Insect : public AirAnimal {
public:
  Insect() { GetInput(); }

  virtual void PrintData() const {
    AirAnimal::PrintData();
    cout << "Number of wings: " << no_of_wings_ << "\n\n";
  }

private:
  virtual void GetInput() {
    no_of_wings_ = GetIntInput("Number of wings: ");
  }
  int no_of_wings_;
};

//-------------------------------
// Class Bird
//-------------------------------
class Bird : public AirAnimal {
public:
  Bird() { GetInput(); }

  virtual void PrintData() const {
    AirAnimal::PrintData();
    cout << "Wingspan in cm: " << wingspan_ << "\n\n";
  }

private:
  virtual void GetInput() {
    wingspan_ = GetIntInput("Wingspan in cm: ");
  }
  int wingspan_;
};

//-------------------------------
// Class Fish
//-------------------------------
class Fish : public WaterAnimal {
public:
  Fish() { GetInput(); }
  explicit Fish(char name[]) : WaterAnimal(name) { GetInput(); }

  virtual void PrintData() const {
    WaterAnimal::PrintData();
    cout << "Length in cm: " << length_ << "\n\n";
  }

private:
  virtual void GetInput() {
    length_ = GetFloatInput("Length in cm: ");
  }
  float length_;
};

//-------------------------------
// Class Shellfish
//-------------------------------
class Shellfish : public WaterAnimal {
public:
  Shellfish() { GetInput(); }

    virtual void PrintData() const {
    WaterAnimal::PrintData();
    cout << "Number of legs: " << no_of_legs_ << "\n\n";
  }

private:
  virtual void GetInput() {
    no_of_legs_ = GetIntInput("Number of legs: ");
  }

  int no_of_legs_;
};


int main(int argc, char *argv[]) {
  const int INITSIZE = 1;
  char cmd;
  Animal **animals = new Animal*[INITSIZE]; // initial array
  int loglen = 0;                           // tracking part of array in use
  int alloclen = INITSIZE;                  // tracking allocated size of array

  do {
    cout << "Enter a command: New (B)ird, (F)ish, (I)nsect, (S)hellfish, "
         << "(P)rint or (Q)uit: ";
    cin >> cmd;
    cin.ignore();
    if (loglen == alloclen && cmd != 'q') {            // if array is full
      Animal **newanimals = new Animal*[alloclen*2]; // allocate twice the space
      memcpy(newanimals, animals,                 // and copy all elements over
             loglen*sizeof(Animal*));
      delete[] animals;                           // freeing old array in heap
      animals = newanimals;
      alloclen *= 2;
    } // endif
    cmd = (char)tolower(cmd);
    char name[STRLEN] = "";
    bool error = false;

    switch (cmd) {
      case 'b': *(animals+loglen) = new Bird; break;
      case 'f':
        cout << "Name: ";
        cin.getline(name, STRLEN);
        strlen(name) ? (*(animals+loglen) = new Fish(name)) // one-arg construct
                     : (*(animals+loglen) = new Fish);    // or no-arg construct
        break;
      case 'i': *(animals+loglen) = new Insect; break;
      case 's': *(animals+loglen) = new Shellfish; break;
      case 'p':
        cout << "\nPrinting array of animals:\n";
        for (int i = 0; i < loglen; ++i) 
          (*(animals+i))->PrintData();
        break;
      case 'q': break;
      default: cout << "\nUnknown command.\n"; error = true;
    } // endswitch

    if (cmd != 'p' && cmd != 'q' && !error) {
      (*(animals+loglen))->PrintData();
      loglen++;
    }
  } while (cmd != 'q'); // enddo

  cout << "\nPrinting array of animals:\n";
  for (int i = 0; i < loglen; ++i) 
    (*(animals+i))->PrintData();

  return 0;
}