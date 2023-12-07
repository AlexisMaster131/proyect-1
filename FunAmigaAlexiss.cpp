/*Alexis Maldonado Martínez, Alexis Cuevas Eguia 

Fecha: 11/Oct/2023


*/

#include <iostream>
using namespace std;

class Hamburguesa{
  private:
    string pan;
    string lechuga;
    string queso;
    string topping;
    int* p_price;
    int price;
  public:
    Hamburguesa(string pan, string lechuga, string queso, string topping){
      this->pan=pan;
      this->lechuga=lechuga;
      this->queso=queso;
      this->topping=topping;

      this->price=55;
      this->p_price= new int[price];

    }
    Hamburguesa(string pan, string lechuga, string queso){
      this->pan=pan;
      this->lechuga=lechuga;
      this->queso=queso;
    }
    friend void orderHamburguesa(Hamburguesa);//funcion amiga
    friend class sideOrder; //clase amiga

    //constructor copia
    //recuerda que no tiene return y tiene el mismo nombre de su clase
    Hamburguesa(const Hamburguesa& original){
      this->pan=original.pan;
      this->lechuga=original.lechuga;
      this->queso=original.queso;
      this->topping=original.topping;

      p_price = new int[2]; // Primero se crea otro puntero nuevo con las mismas caracteristicas (tambien tiene el mismo nombre, pero es opcional)
          for(int i=0; i<2; i++){
              p_price[i] = original.p_price[i]; // La manera correcta de realizar la copia, de lo contario se tendrian problemas con el destructor.
          }
    }

    ~Hamburguesa(){
      cout<<"Destructor para Hamburguesa"<<endl;
      delete[]p_price;
      p_price=nullptr;
    }

};

void orderHamburguesa(Hamburguesa p){
  cout<<"Aquí tienes tu hamburguesa con ";
  if(!p.pan.empty())
    cout<<p.pan<<" ";
  if(!p.lechuga.empty())
    cout<<p.lechuga<<" ";
  if(!p.queso.empty())
    cout<<p.queso<<" ";
  if(!p.topping.empty())
    cout<<p.topping<<" ";
  cout<<""<<endl;
}

class sideOrder{
  public:
    void showOptions(Hamburguesa p){
      cout<<"Puedes elegir una de las opciones para tu hamburguesa que son: ";
      if(!p.pan.empty())
        cout<<p.pan<<" ";
      if(!p.lechuga.empty())
        cout<<p.lechuga<<" ";
      if(!p.queso.empty())
        cout<<p.queso<<" ";
      if(!p.topping.empty())
        cout<<p.topping<<" ";
      cout<<"1. Refresco mediano"<<endl;
      cout<<"2. Cono de helado"<<endl;
      cout<<"3. nuggets"<<endl;
      cout<<"4. Aros de cebolla"<<endl;	
    }
};

int main(){
  Hamburguesa Hamburguesa1 = Hamburguesa("Pan artesanal", "lechuga", "queso mozarella", "y piña");
  Hamburguesa Hamburguesa2 = Hamburguesa("Pan al carbón", "lechuga", " y queso amarillo");
  orderHamburguesa(Hamburguesa1);
  orderHamburguesa(Hamburguesa2);

  sideOrder s;
  s.showOptions(Hamburguesa1);
  s.showOptions(Hamburguesa2);
}
