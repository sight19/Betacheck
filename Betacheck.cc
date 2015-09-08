#include <iostream>
using namespace std;

/* Vul hieronder de huidige datum in */
const int cur_year = 2015;
const int cur_month = 9;
const int cur_day = 18;
  
  
/* Deze functie helpt om te bepalen of de persoon met u of met je moet worden
 * aangesproken. De integer 'type_of_adj' dient ter identificatie van welk
 * woord gebruikt kan worden. 0 geeft u/je, 1 geeft uw/jouw, 2 geeft U/Je,
 * 3 geeft Uw/Jouw, 4 geeft u/jou en 5 geeft U/Jou.
 *
 * De input bestaat uit een getal die het type voornaamwoord aanduidt en twee
 * booleaanse waarden die respectievelijk aanduiden of de persoon ouder is dan
 * dertig en of dit al vast staat
 */
string lookupPronoun (int type_of_adj, bool older30, bool older_sure) {
  
  bool use_u = older30||!older_sure;
  
  if (type_of_adj == 0) {
    if (use_u) {
      return "u";
    } else {
      return "je";
    }
  }
  
  if (type_of_adj == 1) {
    if (use_u) {
      return "uw";
    } else {
      return "je";
    }
  }
  
  if (type_of_adj == 2) {
    if (use_u) {
      return "U";
    } else {
      return "Je";
    }
  }
  
  if (type_of_adj == 3) {
    if (use_u) {
      return "Uw";
    } else {
      return "Je";
    }
  }

} //lookupPronoun

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
  
  
   bool older30 = true; //Geeft true als de persoon ouder dan 30 is
   bool older_sure = false; 
   /* Geeft true aan als we zeker weten dat deze persoon inderdaad ouder dan
    */
   bool should_check = false; //Geeft aan of we nog de leeftijd moeten verifieren

  
   cout << "Betacheck 0.0" << endl
       << "Gemaakt door Jasper Bootsma en Christian Groeneveld" << endl
       << "             s1669141          s1468340" << endl
       << "Studiejaar 2015/2016, Natuur- en Sterrenkunde" << endl;
       
   cout << "Vul alstublieft uw geboortejaar in: ";
   cin >> user_year;
  
   /* Hier controleren we of de persoon niet te jong is of te oud is
    * Dit wordt nu nog alleen bepaald aan de hand van het geboortejaar
    */
   if (user_year > (cur_year - min_age_years)) {
      cout << "Je bent te jong" << endl;
      return 1;
   }
   else if (user_year < (cur_year - max_age_years)) {
      cout << "U bent te oud" << endl;
      return 1;
   }
  
   /* Bovendien controleren we hier of we al kunnen vaststellen of
    * de persoon ouder dan 30 is.
    */
   if (user_year == (cur_year - 29)) {
      older30 = true;
      older_sure = false;
   } else if (user_year > (cur_year - 29)) {
      older30 = false;
      older_sure = true;
   } else if (user_year < cur_year - 30) {
      older30 = true;
      older_sure = true;
   }
   
   cout << older30 << older_sure;
   
   cout << "Vul alstublieft " << lookupPronoun(1,older30,older_sure) << " (numerieke) geboortemaand in: ";
   cin >> user_month;
  
  /* Hier controleren we of eventueel te oude of te jonge mensen daadwerkelijk
   * te oud zijn. Dat controleren we door de maand op te vragen
   */
   
   if (user_year == (cur_year - max_age_years + 1)) {
      if (user_month < cur_month) {
         cout << "U bent te oud" << endl;
         return 1;
      } else if (user_month == cur_month) {
         should_check = true;
      }
   }
   
   if (user_year == (cur_year - min_age_years)) {
      if (user_month > cur_month) {
         cout << "Je bent te jong" << endl;
         return 1;
      } else if (user_month == cur_month) {
         should_check = true;
      }
   }
   
   /* Daarnaast kunnen we nu ook met meer zekerheid vaststellen of de persoon
    * ouder dan 30 is.
    */
   
   
   if (!older_sure) {
      if (user_month < cur_month) {
         older30 = true;
         older_sure = true;
      } else if (user_month > cur_month) {
         older30 = false;
         older_sure = true;
      } else if (user_month == cur_month) {
         older30 = true;
         older_sure = false;
      }
   }
  
  
   cout << "Vul alstublieft " << lookupPronoun(1,older30,older_sure) << " geboortedag in: ";
   cin >> user_day;
  
  
   return 0;
       
} //main
