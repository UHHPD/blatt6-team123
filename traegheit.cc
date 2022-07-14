#include "Vektor.hh"
#include "Zylindermantel.hh"
#include "Vollzylinder.hh"
#include <iostream>
#include <memory>
#include <cmath>

const int N = 10000;     // Anzahl Integrationspunkte
const double M = 1;      // Masse des Zylindermantels
const double ZM_R = 1.0; // Radius der Zylindermantels
const double ZM_L = 1.0; // Laenge des Zylindermantels

 double traegheit ( Koerper *k, Vektor a, Vektor u) {
  std :: cout << " berechne  fuer " << k-> name() << "\n" ;
  double J = 0;
  double m = M/N;
  for (int i = 0; i < N; ++i) {
    Vektor x = k->punkt();
    Vektor n = (x-a).kreuz(u); 
    double r = n.betrag() / u.betrag();
    J += m * r * r;
  }
}

int main() {

  Vektor a; // Punkt auf der Rotationsachse
  std::cout << "Aufpunkt:";
  std::cin >> a;
  Vektor u; // Richtung der Rotationsachsee
  std::cout << "Richtung:";
  std::cin >> u;
  
  std :: unique_ptr <Koerper> k( new Zylindermantel ( ZM_R , ZM_L ));
  traegheit (k.get() ,a , u );
  
  std :: unique_ptr < Koerper > l( new Vollzylinder ( ZM_R , ZM_L ));
  traegheit (l.get() ,a , u );  
   
  return 0;
}
