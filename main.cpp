#include <iostream>

using namespace std;

class Country {
      public:
           Country ( )   { cout << "Country++" ;};
          ~Country ()  { cout << "Country**" ;};
};


class USA : public Country {
     public:
           USA ( ) : Country () { cout << "USA++" ;};
          ~USA ( ) { cout <<  "USA**" ;};
};


int main ( ) {
    USA usa;
}