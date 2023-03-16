#ifndef ARBOL_RN
#define ARBOL_RN

#define ROJO 'R'
#define NEGRO 'N'
#define IZQ 0
#define DER 1
#include<iostream>
using namespace std;


class ArbolRN {
   friend ostream& operator<<(ostream& salida, ArbolRN &arbol){
       return arbol.imprimir(salida);   
   }
   private:
      class Nodo {
         public:
            Nodo * hijo[2];
            char color; // 'R' 'N'
	          int llave;
            int valor;            
            Nodo(int llave){
               this->llave = llave;
               this->color = ROJO;
               hijo[IZQ]=0;
               hijo[DER]=0;
            }
            Nodo(int llave, int valor){
               hijo[IZQ] = hijo[DER] = 0;
               this->llave = llave;
               this->valor = valor;
               this->color = NEGRO;
            }
            int esHoja(){
               return (color==NEGRO && !hijo[IZQ] && !hijo[DER]);
            }
            ~Nodo(){
               if(hijo[IZQ]){
                  delete hijo[IZQ];
               }
               if(hijo[IZQ]){
                  delete hijo[DER];
               }

            }

            ostream& espacios(int nivel, ostream& salida){
                for(int i=0; i<nivel; ++i){
                   salida << "\t";
                }
                return salida;
            }


            void colorFlip(){
                this->color = ROJO;
                this->hijo[IZQ]->color = NEGRO;
                this->hijo[DER]->color = NEGRO;
            }

            // Inserción de Hoja - Agrega hoja con llave y valor
            void ih(Nodo * &ptrHoja, int llave, int valor){
               // DETERMINAR A QUÉ LADO VA CADA HOJA
               int ladoNueva = IZQ;
               int ladoVieja = DER;
               // ASUME QUE LA LLAVE NUEVA ES LA MENOR
               int llaveMin = llave;
               if( llave > ptrHoja->llave){ // La llave "nueva" va a la derecha de la "vieja"
                   ladoNueva = DER;
                   ladoVieja = IZQ;
                   llaveMin = ptrHoja->llave; // Llave menor es la de la hoja "vieja"
               }
               Nodo * vieja = ptrHoja; // Sostiene hoja vieja
               ptrHoja = new Nodo(llaveMin); // Crea ancestro común con la llave menor
               ptrHoja->hijo[ladoNueva] = new Nodo(llave,valor);
               ptrHoja->hijo[ladoVieja] = vieja;
            }

            int insertar(Nodo * &base, int llave, int valor){
               int exito = 0;
               int lado = IZQ;
               if(llave > this->llave){
                  lado = DER;
               }
               if(this->hijo[lado]->esHoja()){
                  this->ih(this->hijo[lado],llave,valor);
                  exito=true;
               }
               else {
                  if(this->color==NEGRO && hijo[IZQ]->color==ROJO && hijo[DER]->color==ROJO){
                     this->colorFlip();
                  }
                  else {
                     int ladoHijo = IZQ;
                     if(llave > hijo[lado]->llave){
                        ladoHijo = DER;
                     }
                     if(hijo[lado]->hijo[ladoHijo]->esHoja()){
                        hijo[lado]->hijo[ladoHijo]->ih(hijo[lado]->hijo[ladoHijo],llave,valor);
                        if(hijo[lado]->color == ROJO){
                           base->rotacion(base,lado,ladoHijo);
                           // base->recoloreo(base);
                        }
                        exito = 1;
                     }
                     else {
                        exito = hijo[lado]->insertar(base->hijo[lado],llave,valor); // Si puede bajar bajará
                     }
                  }
               }
               return exito;
            }

            void recoloreo(Nodo *&base){
               base->color = NEGRO;
               if(!base->hijo[IZQ]->esHoja()){
                  base->hijo[IZQ]->color=ROJO;
               }
               if(!base->hijo[DER]->esHoja()){
                  base->hijo[DER]->color=ROJO;
               }
            }

            void rotacion(Nodo * &base, int ladoPadre, int ladoHijo){
               if(ladoPadre==ladoHijo){ // Rotación simple
                  if(ladoPadre==IZQ){
                     rsd(base,base,base->hijo[ladoPadre]);
                  }
                  else {
                     rsi(base,base,base->hijo[ladoPadre]);
                  }
                  base->recoloreo(base);
               }
               else { // Rotación doble
                  if(ladoPadre==IZQ){
                    //esta es la que hay que usar
                    rdd(base,base,base->hijo[ladoPadre],base->hijo[ladoPadre]->hijo[ladoHijo]); // doble derecha
                  }
                  else{
                    //rdi(base,base,base->hijo[ladoPadre],base->hijo[ladoPadre]->hijo[ladoHijo]); // doble izquierda
                  }
                  base->recoloreo(base);
               }
               
            }

            void rsd(Nodo * &base,Nodo * a, Nodo * p){
                base = p;
                a->hijo[IZQ]=p->hijo[DER];
                p->hijo[DER]=a;
            }
            void rsi(Nodo * &base,Nodo * a, Nodo * p){
                base = p;
                a->hijo[DER]=p->hijo[IZQ];
                p->hijo[IZQ]=a;
            }

            void rdi(Nodo * &base,Nodo * a, Nodo * p, Nodo * h){
                // AGREGUE SU CÓDIGO AQUÍ SI CONSIDERA QUE ESTE EL
		// EL MÉTODO QUE HACE FALTA
            }

            void rdd(Nodo * &base,Nodo * a, Nodo * p, Nodo * h){
                //Esta es la que hay que usar
              base =h;
              p-> hijo[DER] = h-> hijo[IZQ];
              h-> hijo[IZQ]=p;
              a->hijo[IZQ]=h->hijo[DER];
              h->hijo[DER]=a;


            }

            ostream& imprimir(int nivel, ostream& salida){
               if(esHoja()){
                  espacios(nivel, salida);
                  salida << color << " ["<< llave << ":"<< valor << "]"<< endl;
               }
	       else {
                  if(hijo[DER]){
		     hijo[DER]->imprimir(nivel+1,salida);           
                  }
                  espacios(nivel,salida);
                  salida << color<<" "<<llave<<endl;
                  if(hijo[IZQ]){
                     hijo[IZQ]->imprimir(nivel+1,salida);
                  }
               }
               return salida;
            }            
      };
     

      Nodo * raiz;

   public:
      ArbolRN(){
         raiz = 0;
      }
      ~ArbolRN(){
         if(raiz){
           delete raiz;
         }
      }
      ostream& imprimir(ostream& salida){
         if(raiz){
            raiz->imprimir(0,salida);
         }
         return salida;
      }
      // Cambio Color de Raiz R pasa a N
      void ccr(){
         if(raiz){
            raiz->color = NEGRO;
         }
      }

      void insertar(int llave, int valor){
         if(!raiz){
            raiz = new Nodo(llave,valor);
         }
         else {
            if(raiz->color==ROJO){
              ccr(); // Cambio color de raiz
            }
            if(raiz->esHoja()){
               raiz->ih(raiz, llave, valor);
            }
            else {
               int exito = 0;
               while(!exito){
                   if(raiz->color==ROJO){
                      ccr();
                   }
                   // Si el árbol se reacomoda vuelve a bajar desde la raiz para insertar
                   exito = raiz->insertar(raiz,llave,valor);
               }
            }
         }
      }
};


#endif
