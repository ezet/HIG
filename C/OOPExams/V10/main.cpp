//  Fil:  FRODEH \ OO \ EXTRAMEN \ EX_V08_2.TPL

//  Hovedrisset til eksamen i C++, 23.mai 2008, oppgave 2.
//  Laget av Frode Haug, HiG, mai 2008.


//  Programmet holder orden pÜ reservering og utleie av ulike 
//      kjõretõyer (biler, busser) for et utleiefirma.
//      
//
//  Det er mulig Ü:
//      - skrive ut alle kjõretõy av en visse type/klasse  (oppgave 2B)
//      - legge inn et nytt kjõretõy i datastrukturen      (oppgave 2C)
//      - hente et kjõretõy                                (oppgave 2D)
//      - levere (inn igjen) et kjõretõy                   (oppgave 2E)
//      - reservere et kjõretõy for en viss periode        (oppgave 2F)
//      - alle kjõretõy skrives til fil                    (oppgave 2G) 

                        //  INCLUDE:
#include <iostream>          //  cin, cout
#include <fstream>           //  i(f)stream, o(f)stream
#include <cstring>           //  strlen, strcpy
#include <cctype>            //  toupper
#include <cstdlib>           //  atoi
#include "../listtool.h"        //  "Verktõykasse" for listehÜndtering.

using namespace std;

                        //  CONST og ENUM:
const int STRLEN      =   80;  //  Max. streng-lengde.
const int GR_SUM_BIL  =  500;  //  Fast grunnsum for ALLE biler.
const int GR_SUM_BUSS = 1000;  //  Fast grunnsum for ALLE (mini)busser.
const int GR_DAG      =  100;  //  Grunntillegg pr.dag (bÜde bil og buss).
const int KAT_TILLEGG =   50;  //  Tillegg pr.dag pr. modellklasse (bil).
const int BUSS_TILLEGG = 500;  //  Fast tillegg pr.dag for buss.
const int MINDATO = 20080523;  //  Fõrste dato det er mulig Ü reservere fra.
const int MAXDATO = 20203012;  //  Siste dato det er mulig Ü reservere til.
const int DAGIMND      =  30;  //  FAST antall dager i en mÜned er 30!
enum  Kategori { bil, buss };  //  Objektene er enten 'bil' eller 'buss'.

                        //  KLASSER:
class Utlaan : public Num_element  {
  private:                   //  number = fra_dato (leie-/utlÜnsdato).
    int til_dato;            //  Dato det leies/lÜnes til.
    char* person_data;       //  Leiers personalia (navn, adr, tlf, ....)

  public:                    //  Funksjons-deklarasjoner:
    Utlaan(int dato);                  //  Lag innmaten ifm. oppgave 2F.
    ~Utlaan()          {  delete [] person_data;  }
    void display();                    //  Lag innmaten ifm. oppgave 2B.
    int  dager();                      //  Lag innmaten ifm. oppgave 2E.
    void skriv_til_fil(ostream* ut);   //  Lag innmaten ifm. oppgave 2G.
};


class Kjoretoy : public Text_element  {
  private:                   //  text=Regnr (BBTTTTT).
    Kategori kat;            //  Kjõretõy-kategori (bil, buss).
    char*    modell;         //  Modell/type kjõretõy.
    bool     utlaant;        //  UtlÜnt for õyeblikket eller ei.
    List*    reservasjoner;  //  Alle reservasjonene pÜ kjõretõyet.

  public:                    //  Funksjons-deklarasjoner:
    Kjoretoy(char* t, Kategori k);            //  Lag innmaten ifm. oppgave 2C.
    ~Kjoretoy()                   { delete [] modell;  delete reservasjoner;  }
    virtual void display();                   //  (Ferdiglaget)
    virtual int faktura();                    //  Lag innmaten ifm. oppgave 2E.
    void reserver();                          //  Lag innmaten ifm. oppgave 2F.
    virtual void skriv_til_fil(ostream* ut);  //  Lag innmaten ifm. oppgave 2G.
    bool operator == (Kategori k) {  return (kat == k);  }
    bool utlaant_allerede()       {  return utlaant;     }
    void sett_laan(bool b)        {  utlaant = b;        }
};


class Bil : public Kjoretoy  {
  private:
    char klasse;             //  Bilklasse (A-J).

  public:                    //  Funksjons-deklarasjoner:
    Bil(char* t);                             //  Lag innmaten ifm. oppgave 2C.
    virtual void display();                   //  (Ferdiglaget)
    virtual int  faktura();                   //  Lag innmaten ifm. oppgave 2E.
    virtual void skriv_til_fil(ostream* ut);  //  Lag innmaten ifm. oppgave 2G.
};


class Buss : public Kjoretoy  {
  private:
    int ant_passasjerer;
  public:                    //  Funksjons-deklarasjoner:
    Buss(char* t);                            //  Lag innmaten ifm. oppgave 2C.
    virtual void display();                   //  (Ferdiglaget)
    virtual int  faktura();                   //  Lag innmaten ifm. oppgave 2E.
    virtual void skriv_til_fil(ostream* ut);  //  Lag innmaten ifm. oppgave 2G.
};


                        //  DEKLARASJON AV FUNKSJONER:
char     les();
int      les(char* t, const int MIN, const int MAX);
void     les(const char t[], char s[], const int LEN);
char     les_klasse();
Kategori les_kategori();                //  Lag innmaten ifm. oppgave 2A.
void skriv_meny();
void skriv_dato(int d);
void skriv();                           //  Lag innmaten ifm. oppgave 2B.
void nytt();                            //  Lag innmaten ifm. oppgave 2C.
void hent();                            //  Lag innmaten ifm. oppgave 2D.
void lever();                           //  Oppgave 2E "=" oppgave 2D.
void reserver();                        //  Lag innmaten ifm. oppgave 2F.
void skriv_til_fil();                   //  Lag innmaten ifm. oppgave 2G.

                        //  GLOBAL VARIABEL:
List* kartotek;                         //  HELE datastrukturen - 
                                        //         EN liste med ulike objekter.
                        //  HOVEDPROGRAM:
int main()  {
  char valg;

  kartotek = new List(Sorted);

  skriv_meny();
  valg = les();
  while (valg != 'Q')  {
    switch(valg)  {
      case 'D': skriv();        break;  //  Oppgave 2B
      case 'N': nytt();         break;  //  Oppgave 2C
      case 'H': hent();         break;  //  Oppgave 2D
      case 'L': lever();        break;  //  Oppgave 2E
      case 'R': reserver();     break;  //  Oppgave 2F
      default:  skriv_meny();	break;
    }
    valg = les();
  }
  skriv_til_fil();                      //  Oppgave 2G
  cout << "\n\n";
  return 0;
}


// *************************************************************************
// ******************  DEFINISJON AV MEDLEMS-FUNKSJONER:  ******************
// *************************************************************************


// ********************************  UTLAAN:  ******************************

                             //  Oppgave 2F:  Setter/leser ALLE datamedlemmer:
Utlaan::Utlaan(int dato) : Num_element(dato)  {      //  fra_dato (=number).
//   Lag innmaten
}


void Utlaan::display()  {    //  Oppgave 2B:  Skriver ut ALLE objektets data:
  skriv_dato(number);
  skriv_dato(til_dato);
  cout << person_data << '\n';
//   Lag innmaten
}


int Utlaan::dager()  {       //  Oppgave 2E:  Regner ut antall dager utlÜnt:
//   Lag innmaten
}

                             //  Oppgave 2G: Skriver ALLE datamedlemmer til fil:
void Utlaan::skriv_til_fil(ostream* ut)  {  
//   Lag innmaten
}



// ********************************  KJORETOY:  *******************************

                             //  Oppgave 2C: Setter/leser ALLE datamedlemmer:
Kjoretoy::Kjoretoy(char* t, Kategori k) : Text_element(t)  {
  utlaant = false;
  reservasjoner = new List(Sorted);
  kat = k;
  char buffer[80];
  les("Modell", buffer, STRLEN);
  modell = new char[strlen(buffer)+1];
  strcpy(modell, buffer);

//   Lag innmaten
}


void Kjoretoy::display()  {   //  Skriver "alle" (ikke 'kat') kjõretõyets data:
  cout << '\t' << text << "  Modell: " << modell
       << ((!utlaant) ? "\tIKKE ": "\t") << "utlÜnt" << '\n';
  reservasjoner->display_list();                //  Alle utlÜnene skrives.
}

                      //  Oppgave 2E: Lager faktura for det nÜvërende utlÜnet.
int Kjoretoy::faktura()  {    //      Returnerer antall dager har vërt utlÜnt.
//   Lag innmaten
}

                             //  Oppgave 2F: Lager og legger inn et nytt utlÜn:
void Kjoretoy::reserver()  {          
//   Lag innmaten
}

                             //  Oppgave 2G: Skriver ALLE datamedlemmer til fil:
void Kjoretoy::skriv_til_fil(ostream* ut)  {   
//   Lag innmaten
}



// ********************************  BIL:  *******************************

                             //  Oppgave 2C: Setter/leser ALLE datamedlemmer:
Bil::Bil(char* t) : Kjoretoy(t, bil)  {
  klasse = les_klasse();
//   Lag innmaten
}


void Bil::display()  {       //  Skriver "alle" bilens data:
  cout << "\tBIL:  Klasse " << klasse << '\n';
  Kjoretoy::display();       //  'Kjoretoy' gjõr det meste av jobben ...
}

                             //  Oppgave 2E: Lager faktura for utlÜnt bil:
int Bil::faktura()  {
//   Lag innmaten
}


                             //  Oppgave 2G: Skriver ALLE datamedlemmer til fil:
void Bil::skriv_til_fil(ostream* ut)  {
//   Lag innmaten
}



// ******************************  (MINI)BUSS:  ******************************

                             //  Oppgave 2C: Setter/leser ALLE datamedlemmer:
Buss::Buss(char* t) : Kjoretoy(t, buss)  {
  ant_passasjerer = les("Max passasjerer", 2, 100);
//   Lag innmaten
}


void Buss::display()  {      //  Skriver "alle" bussens data:
  cout << "\tBUSS: #Passasjerer: " << ant_passasjerer << '\n';
  Kjoretoy::display();       //  'Kjoretoy' gjõr det meste av jobben ...
}

                             
int Buss::faktura()  {       //  Oppgave 2E: Lager faktura for utlÜnt buss:    
//   Lag innmaten
}


                             //  Oppgave 2G: Skriver ALLE datamedlemmer til fil:
void Buss::skriv_til_fil(ostream* ut)  {
//   Lag innmaten
}



// ****************************************************************************
// ******************   DEFINISJON AV (GLOBALE) FUNKSJONER:  ******************
// ****************************************************************************

void skriv_meny()  {         //  Skriver alle mulige menyvalg:
  cout << "\n\nFùLGENDE KOMMANDOER ER TILGJENGELIGE:"
       << "\n   D  - skriv/Display alle kjõretõy av en viss kategori/type"
       << "\n   N  - Nytt kjõretõy"
       << "\n   H  - Hente et kjõretõy"
       << "\n   L  - Lever et kjõretõy"
       << "\n   R  - Reserver et kjõretõy"
       << "\n   Q  - Quit / avslutt";
}


char les()  {                //  Leser og upcaser brukerens valg/õnske:
  char ch;
  cout << "\n\nKommando: ";
  cin >> ch;   cin.ignore();
  return (toupper(ch));
}

                             //  Leser et TALL mellom MIN og MAX:
int les(char* t, const int MIN, const int MAX)  {
  char text[STRLEN];
  int n;
  do  {
    cout << '\t' << t << " (" << MIN << '-' << MAX << "): ";
    cin.getline(text, STRLEN);   n = atoi(text);  // Leser som tekst - omgjõr:
  } while (n < MIN  ||  n > MAX);
  return n;
}

                             //  Leser inn en ikke-blank tekst:
void les(const char t[], char s[], const int LEN) {  
  do  {
    cout << '\t' << t << ": ";    //  Skriver ledetekst.
    cin.getline(s, LEN);          //  Leser inn tekst.
  } while (strlen(s) == 0);       //  Sjekker at tekstlengden er ulik 0.
}


char les_klasse()  {         //  Leser inn en lovlig leiebil-klasse (A-J):
  char ch;
  do  {
    cout << "\tBilklasse (A-J): ";
    cin >> ch;  cin.ignore();  ch = toupper(ch);
  } while (ch < 'A' ||  ch > 'J');
  return ch;
}


Kategori les_kategori()  {   // Oppgave 2A - Leser Kategori 'bil' eller 'buss':
  return (Kategori)les("Kategori: (bil = 0, buss = 1)", 0, 1);
  
//   Lag innmaten
}


void skriv_dato(int d)  {    // Gjõr om og skriver èèèèMMDD til "DD.MM.èèèè":
  int dag = (d % 100),                          // Finner/ekstraherer "DD".
      mnd = ((d / 100) % 100),                  // Finner/ekstraherer "MM".
      aar = (d / 10000);                        // Finner/ekstraherer "èèèè".
  cout << ((dag < 10)? "0" : "") << dag << '.'  // Skriver, evt. med innledende
       << ((mnd < 10)? "0" : "") << mnd << '.'  //   '0'foran 'D' og 'M':
       << aar;
}


void skriv()  {              //  Oppgave 2B - Skriv ALLE biler ELLER busser:
  Kategori kat = les_kategori();
  for (int i = 1; i <= kartotek->no_of_elements(); ++i) {
    Kjoretoy *elem = (Kjoretoy*)kartotek->remove_no(i);
    kartotek->add(elem);
    if (*elem == kat) {
      elem->display();
    }

  }
//   Lag innmaten
}


void nytt()  {               //  Oppgave 2C - Nytt kjõretõy:
  char reg[STRLEN];
  les("Reg nr", reg, STRLEN);
  if (kartotek->in_list(reg)) {
    cout << "Finnes allerede.";
  } else {
    Kjoretoy *elem;
    if (les_kategori() == bil) {
      elem = new Bil(reg);
    } else {
      elem = new Buss(reg);
    }
    kartotek->add(elem);
  }
//   Lag innmaten
}


void hent()  {               //  Oppgave 2D - Et reservert kjõretõy utlÜnes:
  char reg[STRLEN];
  les("Regnr", reg, STRLEN);
  Kjoretoy *elem;
  for (int i = 1; i < kartotek->no_of_elements(); ++i) {
    elem = (Kjoretoy*)kartotek->remove_no(i);
    kartotek->add(elem);
    if (*elem == reg) {
      if (elem->utlaant_allerede()) {
        cout << "\nUtlaant allerede.\n";
      } else {
        elem->sett_laan(true);
        elem->display();
      }
      break;
    }
  }
  if (*elem != reg) {
    cout << "\nFant ikke reg nr.\n";
  }
//   Lag innmaten
}


void lever()  {              //  Et utlÜnt kjõretõy innleveres:
//   Innmaten er "identisk" til "hent" (se rett ovenfor).
}


void reserver()  {           //  Oppgave 2F - Reserver kjõretõy for en periode:
//   Lag innmaten
}


void skriv_til_fil()  {     //  Oppgave 2G - Skriv HELE datastrukturen til fil:
//   Lag innmaten
}
