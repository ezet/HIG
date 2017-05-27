// Lars Kristian Dahl, 10HBPUA

#include  <iostream>         //  cin, cout
#include  <fstream>          //  ifstream, ofstream
#include  <cstring>          //  strcpy, strlen, strncmp
#include  <cctype>           //  toupper
#include  <cstdlib>          //  atoi

using namespace std;

//  CONST:
const int MAX_ANS  = 100;    //  Max.antall ansatte.
const int MAX_BARN =  20;    //  Max.antall barn EN ansatt kan ha.
const int MAX_TEXT =  80;    //  Max.lengde for en tekst/streng.
const int DATO_LEN =   7;    //  Fast lengde for en dato (inkl. '\0').

//  ENUM:
enum Kjonn { jente, gutt };

//  DEKLARASJON AV FUNKSJONER:
void skriv_meny();
char les();
int  les_tall(char* t, int min, int max);
int  finnes_allerede(int ans_nr);
void smett_inn();
void les_fra_fil();
void skriv_til_fil();
void ny_ansatt();
void partner_endring();
void nytt_barn();
void data_om_ansatt();
void alle_ett_aar();
void fjern_ansatt();

//  KLASSER:
class Person  {                   //  Abstrakt baseklasse.
protected:
  char* fornavn;                //  Personens fornavn.
  char  fodselsdato[DATO_LEN];  //  Dens fõdselsadato pÜ formen: ÜÜmmdd

public:
  Person() { GetInput(); }

  Person(istream& inn) {
    char buffer[MAX_TEXT];
    inn.getline(buffer, MAX_TEXT);
    fornavn = new char[strlen(buffer)+1];
    strcpy_s(fornavn, strlen(buffer)+1, buffer);
    inn.getline(fodselsdato, DATO_LEN);
  }

  virtual ~Person() {           // has to be virtual to allow child 
    delete[] fornavn;           // desctuctors to be executed
  }

  void skriv_fil(ostream& ut)  {
    ut << fornavn << '\n' << fodselsdato << '\n';
  }

  void display() {
    cout << "\n\tFornavn: " << fornavn
      << "\n\tFodselsdato: " << fodselsdato;
  }

  void GetInput() {                    // gets and sets user input
    char buffer[MAX_TEXT];
    cout << "Fornavn: ";
    cin.getline(buffer, MAX_TEXT);
    fornavn = new char[strlen(buffer)+1];
    strcpy_s(fornavn, strlen(buffer)+1, buffer);
    cout << "Fodselsdato: ";
    cin.getline(fodselsdato, DATO_LEN);
  }

  int GetBirthYear() {                  // return birthyear converted to int
    char charyear[3];
    strncpy_s(charyear, 3, fodselsdato, 2);
    int year = atoi(charyear);
    return year += (year < 12) ? 2000 : 1900;
  }
};


class Barn : public Person  {          //  Konkret klasse.
private:
  Kjonn kjonn;                       //  Barnets kjõnn (jente eller gutt).

public:
  Barn()  {
    GetInput();
  }

  Barn(istream& inn) : Person(inn)  {
    int input;
    inn >> input;
    kjonn = (Kjonn)input;
    inn.ignore();
  }

  void skriv_fil(ostream& ut)  {
    Person::skriv_fil(ut);
    ut << kjonn << '\n';
  }

  void display()  {
    cout << "\nBarn";
    Person::display();
    cout << "\n\tKjonn: " << ((kjonn) ? "gutt" : "jente") << "\n";
  }

  void GetInput() {                   // gets and sets user input
    char buffer;
    cout << "Kjonn (j/g): ";
    cin >> buffer;
    cin.ignore();
    kjonn = (buffer == 'j') ? (Kjonn)0 : (Kjonn)1;
  }
};

class Voksen : public Person  {   //  Abstrakt baseklasse.
protected:
  char* etternavn;              //  Den voksnes etternavn.

public:
  Voksen()  { GetInput(); }

  Voksen(istream& inn) : Person(inn)  {
    char buffer[MAX_TEXT];
    inn.getline(buffer, MAX_TEXT);
    etternavn = new char[strlen(buffer)+1];
    strcpy_s(etternavn, strlen(buffer)+1, buffer);
  }

  virtual ~Voksen()  {
    delete[] etternavn;
  }

  void skriv_fil(ostream& ut)  {
    Person::skriv_fil(ut);
    ut << etternavn << '\n';
  }

  void display()  {
    Person::display();
    cout << "\n\tEtternavn: " << etternavn;
  }

  void GetInput() {                         // gets and sets user input
    char buffer[MAX_TEXT];
    cout << "Etternavn: ";
    cin.getline(buffer, MAX_TEXT);
    etternavn = new char[strlen(buffer)+1];
    strcpy_s(etternavn, strlen(buffer)+1, buffer);
  }
};

class Partner : public Voksen  {  //  Konkret klasse.
private:
  int telefon1;                 //  Partnerens 1.treff-telefon (f.eks. jobb)
  int telefon2;                 //  Partnerens 2.treff-telefon (f.eks. mobil)

public:
  Partner()  { GetInput(); }

  Partner(istream& inn) : Voksen(inn)  {
    inn >> telefon1 >> telefon2;
    inn.ignore();
  }

  void skriv_fil(ostream& ut)  {
    Voksen::skriv_fil(ut);
    ut << telefon1 << ' ' << telefon2 << '\n';
  }

  void display()  {
    cout << "\n\nPartner";
    Voksen::display();
    cout << "\n\tTelefon 1: " << telefon1
      << "\n\tTelefon 2: " << telefon2 << '\n';
  }

  void GetInput() {               // fetches and sets properties from keyboard
    telefon1 = les_tall("Telefon no1: ", 10000000, 99999999);
    telefon2 = les_tall("Telefon no2: ", 10000000, 99999999);
  }

  void Edit() {                 // function to edit Partner properties
    Person::GetInput();
    Voksen::GetInput();
    GetInput();
  }
};

class Ansatt : public Voksen  {        //  Konkret klasse.
private:
  int      nr;                       //  Unikt/entydig ansatt-nummer.
  int      ant_barn;                 //  Antall barn vedkommende har.
  char*    adresse;                  //  Gate- og postadresse.
  Partner* partner;                  //  Peker til partnere.
  Barn*    barn[MAX_BARN+1];         //  Pekere til alle barna.

public:
  Ansatt()  {
    cout << "\n\nWARNING 1: Denne constructor skal IKKE kalles/kjõres!\n\n";
  }

  Ansatt(int n) {
    nr = n;
    ant_barn = 0;
    GetInput();
  }

  bool operator==(int n) {
    return nr == n;
  }

  Ansatt(int n, istream& inn) : Voksen(inn)  {
    nr = n;
    char buffer[MAX_TEXT];
    inn.getline(buffer, MAX_TEXT);
    adresse = new char[strlen(buffer)+1];
    strcpy_s(adresse, strlen(buffer)+1, buffer);
    partner = new Partner(inn);
    inn >> ant_barn;
    inn.ignore();
    for (int i = 1; i <= ant_barn; ++i)
      *(barn+i) = new Barn(inn);
  }

  ~Ansatt()  {
    delete partner;
    for (int i = 1; i <= ant_barn; ++i)
      delete *(barn+i);
  }

  void skriv_fil(ostream& ut)  {
    ut << nr << '\n';
    Voksen::skriv_fil(ut);
    ut << adresse << '\n';
    partner->skriv_fil(ut);
    ut << ant_barn << '\n';
    for (int i = 1; i <= ant_barn; ++i)
      (*(barn+i))->skriv_fil(ut);
  }

  void display()  {
    cout << "\nAnsatt ID: " << nr;
    Voksen::display();
    cout << "\n\tAddresse: " << adresse;
    partner->display();
    for (int i = 1; i <= ant_barn; ++i)
      (*(barn+i))->display();
  }

  void GetInput() {
    char buffer[MAX_TEXT];
    cout << "Addresse: ";
    cin.getline(buffer, MAX_TEXT);
    adresse = new char[strlen(buffer)+1];
    strcpy_s(adresse, strlen(buffer)+1, buffer);
    cout << "\n\nPartner:\n";
    partner = new Partner;
  }

  void NyttBarn() {                   // adds a new child
    if (ant_barn >= MAX_BARN) {
      cout << "Det er ikke plass til flere barn her i verden, proev igjen senere.";
      return;
    }
    ant_barn++;
    *(barn+ant_barn) = new Barn;
  }

  int get_nr() {            // returns Ansatt:nr
    return nr;
  }

  void EditPartner() {        // function to edit Ansatts partners properties
    partner->Edit();
  }

  void PrintByChildBirth(int year) {  // Finds and prints ansatt ID by child birth
    for (int i = 1; i <= ant_barn; ++i)
      if ( (*(barn+i))->GetBirthYear() == year) {
        cout << "\nAnsatt ID: " << nr;
        return;
      }
  }
};

//  GLOBALE VARIABLE:
Ansatt* ansatte[MAX_ANS+1];     //  Array med peker til alle de ansatte.
int siste_brukt;                //  Siste 'skuff' brukt av "ansatte"-arrayen.

//  HOVEDPROGRAMMET:
int main()  {
  char kommando;                //  Brukerens õnske/valg.

  les_fra_fil();                //  Leser inn hele datastrukturen fra fil.
  skriv_meny();                 //  Meny av brukerens valg.

  kommando = les();             //  Leser brukerens õnske/valg.
  while (kommando != 'Q')  {
    switch(kommando)  {
    case 'N': ny_ansatt();       break;   //  Legg inn (om mulig) ny ansatt.
    case 'P': partner_endring(); break;   //  Endre data om partner.
    case 'B': nytt_barn();       break;   //  Legg inn (om mulig) nytt barn.
    case 'D': data_om_ansatt();  break;   //  Skriv alle data om en ansatt.
    case 'A': alle_ett_aar();    break;   //  Ansnr med barn fõdt et gitt Ür.
    case 'F': fjern_ansatt();    break;   //  Fjern/slett en ansatt.
    default:  skriv_meny();      break;   //  Meny av brukerens valg.
    }
    kommando = les();           //  Leser brukerens õnske/valg.
  }
  return 0;
}

//  DEFINISJON AV FUNKSJONER:
void skriv_meny()  {
  cout << "\n\nFùLGENDE KOMMANDOER ER TILGJENGELIGE:";
  cout << "\n\tN - Ny ansatt";
  cout << "\n\tP - Partner-endring";
  cout << "\n\tB - nytt Barn";
  cout << "\n\tD - alle Data om en ansatt";
  cout << "\n\tA - Alle barn fõdt ett gitt Ür";
  cout << "\n\tF - Fjern en ansatt";
  cout << "\n\tQ - Quit / avslutt";
}

char les()  {                     //  Leser og returnerer ETT upcaset tegn.
  char ch;
  cout << "\n\nKommando:  ";
  cin >> ch;
  cin.ignore();
  return (toupper(ch));
}

//  Skriver ledetekst (t), leser og
//    returnerer et tall mellom min og max:
int les_tall(char* t, int min, int max) {
  int tall;
  do  {
    cout << '\t' << t << " (" << min << '-' << max <<  "):  ";
    cin >> tall;  cin.ignore();
  } while (tall < min  ||  tall > max);
  return tall;
}

//  Leter etter en ansatt med et gitt nummer
int finnes_allerede(int ans_nr)  { //    ("ans_nr"). Retur: indeks eller 0.
  for (int i = 1; i <= siste_brukt; ++i)
    if ( **(ansatte+i) == ans_nr)
      return i;
  return 0;
}

// blir gjort i ny_ansatt
void smett_inn()  {                    //  Innstikkssortering av ETT objekt:
}

void les_fra_fil()  {                  //  Leser HELE datastrukturen fra fil:
  ifstream ifile;
  ifile.open("ansatte.txt");
  if (!ifile) {
    cerr << "Could not open file.";
    return;
  }
  int buffer;
  ifile >> buffer;
  while (ifile && siste_brukt <= MAX_ANS) {
    ifile.ignore();
    siste_brukt++;
    (*(ansatte+siste_brukt)) = new Ansatt(buffer, ifile);
    ifile >> buffer;
  }
  ifile.close();
}

void skriv_til_fil()  {                //  Skriver HELE datastrukturen til fil:
  ofstream ofile;
  ofile.open("ansatte.txt", ios::trunc);
  if (!ofile) {
    cerr << "Could not open file.";
    return;
  }
  for (int i = 1; i <= siste_brukt; ++i)
    (*(ansatte+i))->skriv_fil(ofile);
  ofile.close();
}

void ny_ansatt()  {                    //  N - NY ANSATT:
  if (siste_brukt == MAX_ANS+1) {
    cout << "Ikke plass til flere ansatte!";
    return;
  }
  int id;
  cout << "Ansatt ID: ";
  cin >> id;
  cin.ignore();
  if (finnes_allerede(id)) {
    cout << "Ansatt finnes allerede.";
    return;
  }
  int i = siste_brukt++;
  while (i > 0 && (*(ansatte+i))->get_nr() > id)  // finds where to insert
    *(ansatte+i+1) = *(ansatte+i--);              // the new object
  *(ansatte+i+1) = new Ansatt(id);
  skriv_til_fil();
}

void partner_endring()  {              //  P - ENDRE DATA OM PARTNER:
  int id;
  cout << "Ansatt ID: ";
  cin >> id;
  cin.ignore();
  int index = finnes_allerede(id);
  if (!index) {
    cout << "Ansatt ID finnes ikke.";
    return;
  }
  (*(ansatte+index))->EditPartner();   // Gets and sets new information
  skriv_til_fil();
}

void nytt_barn()  {                    //  B - NYTT BARN:
  int id;
  cout << "Ansatt ID: ";
  cin >> id;
  cin.ignore();
  int index = finnes_allerede(id);
  if (!index) {
    cout << "Ansatt ID finnes ikke.";
    return;
  }
  (*(ansatte+index))->NyttBarn();
  skriv_til_fil();
}

void data_om_ansatt()  {               //  D - SKRIVER ALLE DATA OM EN ANSATT:
  int id;
  cout << "Ansatt ID: ";
  cin >> id;
  cin.ignore();
  int index = finnes_allerede(id);
  if (!index) {
    cout << "Ansatt ID finnes ikke.";
    return;
  }
  (*(ansatte+index))->display();
}

//  A - SKRIVER ALLE ANSATT MED BARN
void alle_ett_aar()  {                //      FùDT ET GITT èR:
  int year = les_tall("Fodselsdato: ", 1900, 2020);
  for (int i = 1; i <= siste_brukt; ++i)
    (*(ansatte+i))->PrintByChildBirth(year);
}

void fjern_ansatt()  {                //  F - FJERN/SLETT EN ANSATT
  int id;
  cout << "Ansatt ID: ";
  cin >> id;
  cin.ignore();
  int index = finnes_allerede(id);
  if (!index) {
    cout << "Ansatt ID finnes ikke.";
    return;
  }
  delete *(ansatte+index);
  for (index; index < siste_brukt; ++index)  // changes pointers to fill the gap
    *(ansatte+index) = *(ansatte+index+1); 
  --siste_brukt;
  skriv_til_fil();
}