#include <iostream>
#include <map>


int main ()
{
  std::map<char,std::string> mymap;

  mymap.insert ( std::pair<char,std::string>('1',"UNO") );
  mymap.insert ( std::pair<char,std::string>('2',"DOS") );
  mymap.insert ( std::pair<char,std::string>('3',"TRES") );
  mymap.insert ( std::pair<char,std::string>('4',"CUATRO") );
  mymap.insert ( std::pair<char,std::string>('5',"CINCO") );
  mymap.insert ( std::pair<char,std::string>('6',"SEIS") );
  mymap.insert ( std::pair<char,std::string>('7',"SIETE") );

  //CONTENIDO A IMPRIMIR CON ITERADOR:
  for (std::map<char,std::string>::iterator it=mymap.begin(); it!=mymap.end(); ++it){
    std::cout << "[" << it->first << ":" << it->second << "]";
  }
  return 0;
}