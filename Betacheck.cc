/* Betacheck 0.0
mkpmpppl,lp,lp,l,lp,lp,lp,lp,lp,,,l,l,l,l[p,
 * Jasper Bootsma en Christian Groeneveld
 * s1669141          s1468340
 * Gedit
 */
#include <iostream>
using namespace std;

/* Vul hieronder de huidige datum in */
const int cur_year = 2015;
const int cur_month = 9;
const int cur_day = 18;
const int days_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int days_month_leap[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main () {     
   /* Hieronder worden de minimum- en maximumleeftijden aangewezen.
    * Deze leeftijden worden in jaren en maanden gegeven.
    */
   int min_age_years = 10;
   int min_age_months = 120; 
   int max_age_years = 101;
   int max_age_months = 1200;
  
   /* Declaraties van user input */
   int user_year;
   int user_month;
   int user_day;
   int first_day;
  
   bool older30 = false; //Geeft true als de persoon ouder dan 30 is
   bool older_sure = false; 
   /* Geeft aan of we zeker weten dat deze persoon inderdaad ouder is dan 30 */
   bool should_check = true; //Geeft aan of we nog de leeftijd moeten verifieren
   bool possible_too_old = false; /* Geeft true als de persoon mogelijkerwijs
   te oud is */

   cout << "Betacheck 0.0" << endl
       << "Gemaakt door Jasper Bootsma en Christian Groeneveld" << endl
       << "             s1669141          s1468340" << endl
       << "Studiejaar 2015/2016, Natuur- en Sterrenkunde" << endl;
       
   cout << "Vul alstublieft uw geboortejaar in: ";
   cin >> user_year;
  
   /* Hier controleren we of de persoon niet te jong is of te oud is
    * Dit wordt nu nog alleen bepaald aan de hand van het geboortejaar */
   if (user_year > (cur_year - min_age_years)) {
      cout << "Je bent te jong" << endl;
      return 1;
   }
   if (user_year < (cur_year - max_age_years)) {
      cout << "U bent te oud" << endl;
      return 1;
   }
   if (user_year == (cur_year - min_age_years)) {
   } else if (user_year == (cur_year - max_age_years)) {
     possible_too_old = true;
   } else {
     should_check = false;
   }
  
   /* Bovendien controleren we hier of we al kunnen vaststellen of
    * de persoon ouder dan 30 is. */
   if (user_year > (cur_year - 29)) {
      older_sure = true;
   } else if (user_year < cur_year - 30) {
      older30 = true;
      older_sure = true;
   }
   
   cout << "Vul alstublieft " << ((older30||!older_sure) ? "uw" : "je") << " (numerieke) geboortemaand in: ";
   cin >> user_month;
   
   if (user_month > 12|| user_month < 1) {
     cout << "De ingevulde waarde zijn incorrect" << endl;
     return 1;
   }
  
  /* Hier controleren we of eventueel te oude of te jonge mensen daadwerkelijk
   * te oud zijn. Dat controleren we door de maand op te vragen */
   if (should_check) {
     if (possible_too_old){
       if (user_month < cur_month) {
         cout << "U bent te oud" << endl;
         return 1;
       } else if (user_month > cur_month) {
         should_check = false;
       }
     
     } else {
       if (user_month > cur_month){
       cout << "Je bent te jong" << endl;
       return 1;
       } else if (user_month < cur_month) {
         should_check = false;
       }
     }
   }
   
   /* Daarnaast kunnen we nu ook met meer zekerheid vaststellen of de persoon
    * ouder dan 30 is. */
   if (!older_sure) {
      if (user_month < cur_month) {
         older30 = true;
         older_sure = true;
      } else if (user_month > cur_month) {
         older_sure = true;
      }
   }
  
   cout << "Vul alstublieft " << ((older30||!older_sure) ? "uw" : "je") 
        << " geboortedag in: ";
   cin >> user_day;
   
   if (user_month == cur_month && user_day == cur_day) {
     cout << "Gefeliciteerd met " << ((older30||!older_sure) ? "uw" : "je")
          << " verjaardag!" << endl;
   }
  
   if (user_year % 4 == 0) {
     if (user_day > days_month_leap[user_month-1]||user_day < 1) {
       cout << "De ingevulde waarde zijn incorrect" << endl;
       return 1;
     }
   } else {
      if (user_day > days_month[user_month-1]||user_day < 1) {
       cout << "De ingevulde waarde zijn incorrect" << endl;
       return 1;
      }
   }
   
   /* Hier controleren we of eventueel te oude of te jonge mensen daadwerkelijk
   * te oud zijn. Dat controleren we door de dag te gebruiken */   
   if (should_check) {
     if (possible_too_old){
       if (user_day < cur_day) {
         cout << "U bent te oud" << endl;
         return 1;
       } else if (user_day == cur_day) {
         cout << "Gefeliciteerd met uw verjaardag!" << endl;
       }
     
     } else {
       if (user_day > cur_day){
       cout << "Je bent te jong" << endl;
       return 1;
       } else if (user_day == cur_day) {
         cout << "Gefeliciteerd :D!!" << endl;
       }
     }
   }
   
   if (!older_sure) {
      if (user_day <= cur_day) {
         older30 = true;
         older_sure = true;
      } else if (user_day > cur_day) {
         older_sure = true;
      }
   }
   
   // De ijkdatum is maandag 1 januari 1900
   first_day = (user_year - 1900 + (user_year - 1900)/4) % 7
   cout << first_day << endl;
  
   return 0;  
} //main
