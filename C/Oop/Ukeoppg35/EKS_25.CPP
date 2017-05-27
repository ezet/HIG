//   Fil:  FRODEH \ CPP \ EKSEMPEL \ EKS_25.CPP

//       Programeksempel nr.25 for forelesning i  C++ -programmering. 
//       Laget av Frode Haug, HIG,  v†ren 1994.
//       Litt endret/modifisert av FrodeH, HiG, v†ren 2003


//  Programmet leser inn data om billetter til 10 langrennsarrangementer
//  fra filen "BIL_OL94.DTA". Det leser ogs† inn bestillingene for 200
//  kunder (fra "KUN_OL94.DTA"). Ut fra dette s† fordeler programmet
//  billettene og skriver resultatet bin‘rt til filene "*.RES".


                             //  INCLUDE:
#include <fstream>                     //  ifstream, ofstream
#include <iostream>                    //  cout
#include <cstring>                     //  strcpy
#include <cstdlib>                     //  (s)rand

using namespace std;

                             //  CONST:
const int  ANT_ARR    =  11;           //  Antall arrangement (1-10 stk).
const int  ANT_KUNDER = 201;           //  Antall kunder (1-200 stk).
const int  NVNLEN     =  20;           //  Kundenavns lengde.
const int  ARRLEN     =  35;           //  Arrangementnavns lengde.

                             //  PROSEDYREDEKLARASJON:
void les_billetter_fra_fil();         
void les_kunder_fra_fil();
void fordel_billetter();
void skriv_billetter_til_fil();
void skriv_kunder_til_fil();

                             //  KLASSER:
class kunde  {
  private:
    char navn[NVNLEN];                 //  Kundens navn.
    int  ant_bestilt[ANT_ARR];         //  Antall bestilte pr. arrangement.
    int  ant_faatt[ANT_ARR];           //  Antall f†tt pr. arrangement.

  public:
    kunde();
    void oppdater_navn(char nvn[]);
    void oppdater_bestilt_faatt(int nr, int ant = 0, char nvn = 'X');
    int  ant_oensket(int nr);
    bool faatt_billett_allerede(int nr);
                                       //  Ekstra prosedyre for † se hva
                                       //   som skjer ved trekkingen:
                                   void skriv()  {
                                      int i;
                                      cout << '\n' << navn << "\n\t";
                                      for (i = 1; i < ANT_ARR;  i++)
                                              cout << ant_bestilt[i] << " ";
                                      cout << "\n\t";
                                      for (i = 1; i < ANT_ARR;  i++)  
                                                  cout << ant_faatt[i] << " ";
                                   }
};


class arrangement  {
  private:
    char tittel[ARRLEN];               //  Arrangementets tittel/navn.
    int  pris;                         //  Pris pr. billett.
    int  ant_plasser;                  //  Antall plasser/billetter totalt.
    int  ant_solgt;                    //  Antall billetter solgt hittil.
    int  tot_billetter_bestilt;        //  Totalt ›nsket antall billetter.
    int  tot_kunder_bestilt;           //  Antall kunder som ›nsker billetter.

  public:
    arrangement();
    void oppdater(char titt[], int ant, int pri);
    void oppdater_antall_oenskede_billetter(int ant_bill);
    void oppdater_antall_solgte(int ant);
    bool maa_trekke();
    int  ant_igjen();
    int  ant_bestilt();
                                       //  Ekstra prosedyre for † se hva
                                       //   som skjer ved trekkingen:
                                   void skriv()  {
                                     cout << '\n' << pris << "\t"
                                          << ant_plasser << "\t" 
                                          << ant_solgt << "\t"
                                          << tot_billetter_bestilt 
                                          << "\t" << tot_kunder_bestilt
                                          << '\t' << tittel;  }
};

                             //  GLOBALE VARIABLE:
kunde        kunder[ANT_KUNDER];       //  Alle kundene.
arrangement  arrangementer[ANT_ARR];   //  Alle arrangementene.
int          antall_kunder;            //  Antall kunder som har bestilt.


                             //  HOVEDPROGRAM:
int main(void)  {
       cout << "\n\n\tLeser data fra filene "
            << "'BIL_OL94.DTA' og 'KUN_OL94.DTA' .....";
  les_billetter_fra_fil();
  les_kunder_fra_fil();

       cout << "\n\n\tFordeler billetter .....";
  fordel_billetter();

       cout << "\n\n\tSkriver resultat til filene "
            << "'BIL_OL94.RES' og 'KUN_OL94.RES' .....\n\n";
  skriv_billetter_til_fil();
  skriv_kunder_til_fil();
  return 0;
}

                             //  DEFINISJON AV KLASSE-PROSEDYRER:
kunde::kunde()                         //  Nullstiller arrayers innhold.
  { int i;  for(i = 1;  i < ANT_ARR;  i++) 
                ant_bestilt[i] = ant_faatt[i] = 0;  }


void kunde::oppdater_navn(char nvn[])  //  Oppdaterer kundens navn.
  {  strcpy(navn, nvn);  }

                             //  Oppdaterer element nr."nr" i
                             //    "ant_bestilt" med "ant", dersom "nvn" = B
                             //    "ant_faatt" med "ant", dersom "nvn" = F
                             //    "ant_faatt" med "ant_bestilt[nr]",
                             //        dersom "nvn" er utelatt.
void kunde::oppdater_bestilt_faatt(int nr, int ant, char nvn) 
  {       if (nvn == 'B')  ant_bestilt[nr] = ant;
     else if (nvn == 'F')  ant_faatt[nr] = ant;
     else                  ant_faatt[nr] = ant_bestilt[nr];  }

                             //  Returnerer med antall billetter kunden
                             //    ›nsker p† arrangement nr."nr".
int kunde::ant_oensket(int nr) 
  {  return  ant_bestilt[nr];  }

                             //  Returnerer "true" dersom kunden allerede er
                             //    tildelt billetter p† arrangement nr."nr".
bool kunde::faatt_billett_allerede(int nr)  
  {  return (ant_faatt[nr] != 0)  ?  true  :  false;  }


                                       //  Nullstiller medlemmene.
arrangement::arrangement()
  {  pris = ant_plasser = ant_solgt = 
     tot_billetter_bestilt = tot_kunder_bestilt = 0;  }

                                       //  Oppdaterer en del av medlemmene.
void arrangement::oppdater(char titt[], int ant, int pri) 
  {  strcpy(tittel, titt);   ant_plasser = ant;   pris = pri;  }

                                       // Oppdaterer hvor mange billetter
                                       //  som er bestilt.
void arrangement::oppdater_antall_oenskede_billetter(int ant_bill) 
  {  ++tot_kunder_bestilt;    tot_billetter_bestilt += ant_bill;  }

                                       //  Oppdaterer antall solgte billetter.
void arrangement::oppdater_antall_solgte(int ant)  
  {  ant_solgt += ant;  }

                                       //  Returnerer "true" dersom ikke alle
                                       //   kundene kan f† sine billett›nsker.
bool arrangement::maa_trekke()
  {  return (ant_plasser < tot_billetter_bestilt)  ?  true  :  false;  }

                                       //  Returnerer antall ikke solgte.
int arrangement::ant_igjen()  
  {  return  (ant_plasser - ant_solgt);  }

                                       //  Returnerer antall kunder bestilt.
int arrangement::ant_bestilt() 
  {  return  tot_kunder_bestilt;  }



                             //  DEFINISJONER AV PROSEDYRER:

                             //  Leser innholdet av filen "BIL_OL94.DTA".
                             //  Filformat:
                             //    Felt:   <nr>  <ant.bill.>  <pris>  <tittel>
                             //    Lengde:  2     4            3       30
void les_billetter_fra_fil()  {
  char tittel[ARRLEN];
  int  nr, antall, pris;     //  Variable til de tre f›rste feltene i hver
                             //    post/linje p† filen.
  ifstream innfil("bil_ol94.dta");

  innfil >> nr;              //  Pr›ver † lese arrangementsnummer.
  while (!innfil.eof())  {   //  S†lenge ikke slutt p† filen:
    innfil >> antall >> pris;    //  Leser to neste verdier.
    innfil.getline(tittel, ARRLEN);  //  Leser resten av linjen.
                                 //  Oppdaterer arrangementsobjektet:
    arrangementer[nr].oppdater(tittel, antall, pris);
    innfil >> nr;            //  Pr›ver † lese arrangementsnummer.
  }
}

             //  Leser innholdet av filen "KUN_OL94.DTA".
             //  Filformat:
             //    Felt:  <navn>  <ant.bestillinger>  <arr.nr>  <ant.bill> ..
             //                           (De to siste feltene er repetert
             //                           <ant.bestillinger> ganger.
             //                           <ant.bestillinger> kan max. v‘re 6.
             //                           <ant.bill.> kan max. v‘re 10. )
             //    Lengde: 20     1                   2         1
void les_kunder_fra_fil()  {
  char navn[NVNLEN];                   //  Kundens navn.
  int  ant_arr, arr_nr, ant_bill;      //  Variable til de tre siste feltene
                                       //    i hver post/linje p† filen.
  int  nr = 0, j;                      //  Antall linjer p† filen, og
                                       //    tellevariabel for bestillingene.
  ifstream innfil("kun_ol94.dta");

  innfil.get(navn, NVNLEN);            //  Pr›ver † hente kundens navn.
  while (!innfil.eof())  {             //  S†lenge ikke slutt p† filen:
    ++nr;                              //  Teller opp antall linjer.
    kunder[nr].oppdater_navn(navn);    //  Oppdaterer kundens navn.
    innfil >> ant_arr;                 //  Leser antall bestillinger.
    for (j = 1;  j <= ant_arr;  j++)  {  //  Leser inn alle bestillingene:
      innfil >> arr_nr >> ant_bill;      //  Leser arr.nr og antall billetter.
                                       //  Oppdaterer kundens ›nsker:
      kunder[nr].oppdater_bestilt_faatt(arr_nr, ant_bill, 'B');
                                       //  Oppdaterer antall bestilte/›nskede
                                       //    billetter p†/til arrangementet:
      arrangementer[arr_nr].oppdater_antall_oenskede_billetter(ant_bill);
    }
    innfil.ignore();
    innfil.get(navn, NVNLEN);          //  Pr›ver † hente kundens navn.
  }
  antall_kunder = nr;
}

                                       //  Fordeler billettene til alle
                                       //    arrangementene.
void fordel_billetter()  {
  int  i, j, k;                        //  L›kke-/tellevariable
  int  ant_oensket, ant_igjen;         //  Antall billetter som en kunde har
                                       //   ›nsket, og antall som er igjen.
  int  rel_nr, abs_nr;                 //  Relativt og absolutt kundenummer.

  srand(0);

  for (i = 1;  i < ANT_ARR;  i++)      //  G†r gjennom ALLE arrangementene:
                                       //  Dersom ikke alle kan f† (m† trekke)
     if (arrangementer[i].maa_trekke())  { 
                                       //  S†lenge flere billetter † dele ut:
        while ((ant_igjen = arrangementer[i].ant_igjen()) > 0)  {
                                       //  Trekker kundens relative nummer:
          rel_nr = (rand() % arrangementer[i].ant_bestilt()) + 1;

                                       //  M† lete etter denne kunden:
          abs_nr = 0;
          k = 0;
          while (k < rel_nr)  {        //  S†lenge ikke funnet s† mange kunder
                                       //   som ›nsker dette arrangementet:  
            ++abs_nr;
            if ((ant_oensket=kunder[abs_nr].ant_oensket(i)) != 0)  ++k;
          }

                                       //  Har n† funnet kunden som skal ha
                                       //    billett. "abs_nr" inneholder
                                       //    aktuell indeks i "kunder".

                                       //  Dersom kunden ikke allerede har
                                       //    blitt tildelt billetter til
                                       //    vedkommende arrangement:
          if (!kunder[abs_nr].faatt_billett_allerede(i))  {
                                       //  Dersom ikke de siste billettene
                                       //    som g†r/selges unna:
             if (ant_igjen >= ant_oensket)  {
                                       //  Oppdaterer kundens mottatte 
                                       //    billetter med ALLE de hun/han
                                       //    ›nsket seg.
               kunder[abs_nr].oppdater_bestilt_faatt(i);
                                       //  Oppdaterer hvor mange som n† 
                                       //    totalt er solgt p† arrangementet.
               arrangementer[i].oppdater_antall_solgte(ant_oensket);
             }  else  {                //  Det er de aller siste billettene
                                       //    som n† selges:
                                       //  Oppdaterer kundens mottatte 
                                       //    billetter med de som er igjen.
               kunder[abs_nr].oppdater_bestilt_faatt(i, ant_igjen, 'F');
                                       //  Oppdaterer med at alt er n† 
                                       //    utsolgt p† arrangementet.
               arrangementer[i].oppdater_antall_solgte(ant_igjen);
             }
          }
        }
                                     arrangementer[i].skriv();
     } else {                          //  Trenger ikke trekke:
                                       //  G†r gjennom ALLE kundene og gir de
                                       //    som bestilte billetter det 
                                       //    ›nskede antall:
        for (j = 1;  j <= antall_kunder;  j++)
                                       //  Dersom kunden har bestilt til 
                                       //    dette arrangement:
           if ((ant_oensket = kunder[j].ant_oensket(i)) != 0)  {
                                       //  Oppdaterer kundens mottatte 
                                       //    billetter med ALLE de hun/han
                                       //    ›nsket seg.
              kunder[j].oppdater_bestilt_faatt(i);
                                       //  Oppdaterer hvor mange som n† 
                                       //    totalt er solgt p† arrangementet.
              arrangementer[i].oppdater_antall_solgte(ant_oensket);
           }
                                   arrangementer[i].skriv();
     }
}

                                       //  Skriver data om alle arrangementene
                                       //    BIN’RT til filen "BIL_OL94.DTA".
void skriv_billetter_til_fil()  {
  int i;
  ofstream utfil("bil_ol94.res", ios::binary);
  for (i = 1;  i < ANT_ARR;  i++)
    utfil.write( (char *) & arrangementer[i],  sizeof(arrangement) ) ;
}


                                       //  Skriver data om alle kundene
                                       //    BIN’RT til filen "KUN_OL94.DTA".
void skriv_kunder_til_fil()  {
  int i;
  ofstream utfil("kun_ol94.res", ios::binary);
  for (i = 1;  i <= antall_kunder;  i++)     {
    utfil.write( (char *) & kunder[i],  sizeof(kunde) ) ;
//                                               kunder[i].skriv();
  }
}

