//LIBRERIAS
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <cstring>
#include <string.h>
#include <fstream>

using namespace std;

//VARIABLES GLOBALES
int opcion;
int n=1;

ofstream usuariosNuevos;


//PROTOTIPO FUNCIONES
void MENUPRINCIPAL(int opcion);
void menuAdministrador(int opcion);

//PROTOTIPO ADMINISTRADOR
void creacionMatricesBase();
void copiaAumentiMatricesBase();
void agregarNuevoElemento();
void menu(int opcion);
void stringAdmin();
void stringAdminAgain();

int main()
{

 MENUPRINCIPAL(opcion);
}


//FUNCIONES
        void MENUPRINCIPAL(int opcion){
        //crecion menu principal
        bool repetir= true;
        char clave;
        char cedula;
        int retiro;
        char claveAdmin;


           do{

                cout <<endl;
                cout << "***** MENU PRINCIPAL ****"<<endl;
                cout << " 1. Consultar su saldo "<<endl;
                cout << " 2. Retiros      "<<endl;
                cout << " 3. ingreso como administrador "<<endl;
                cout << " 4. salir    "<<endl;
                cin >> opcion;

                bool againCedula= true;
                bool againClave= true;
                bool againRetiro= true;
                bool againAdmin= true;

              switch (opcion){
                     case 1:                            

                          do{
                             //pide cedula
                             cout<<"ingrese cedula: "<<endl;
                             cin>>cedula;
                             //busca cedula dentro de archivo de usuarios para saber la posicion

                             //condicional que pertenezca la cedula a los usuarios existentes si se cumple again=false
                             //y de lo contrario repite el ciclo y pide de nuevo cedula
                             if (cedula=='1'){
                                 againCedula=false;
                             }
                             else {
                                 cout<<"esta cedula no esta registrada "<<endl;
                             }

                              }while (againCedula==true);



                            do{
                             //pide contraseña
                             cout<<"ingrese clave: "<<endl;
                             cin>>clave;
                             //busca cedula dentro de archivo de usuarios para saber la posicion y comparar con la contraseña

                             //condicional que pertenezca la clave a posicion de la cedula antes dicha si se cumple again=false
                            // y de lo contrario repite el ciclo y pide de nuevo clave
                             if (clave=='a'){
                                 againClave=false;
                             }
                             else {
                                 cout<<"clave incorrecta "<<endl;
                             }

                              }while (againClave==true);


                             //imprime saldo del usuario
                             cout<<"su saldo es: "<<"100000"<<endl;

                             repetir=false;

                            break;

                     case 2:
                          do{
                           //pide cedula
                           cout<<"ingrese cedula: "<<endl;
                           cin>>cedula;
                           //busca cedula dentro de archivo de usuarios para saber la posicion y comparar con la cedula

                           /*condicional que pertenezca la cedula a los usuarios existentes si se cumple again=false
                           y de lo contrario repite el ciclo y pide de nuevo cedula*/
                           if (cedula==1){
                               againCedula=false;
                           }
                           else {
                               cout<<"esta cedula no esta registrada "<<endl;
                           }

                            }while (againCedula==true);



                          do{
                           //pide contraseña
                           cout<<"ingrese clave: "<<endl;
                           cin>>clave;
                           //busca cedula dentro de archivo de usuarios para saber la posicion y comparar con la contraseña

                           /*condicional que pertenezca la clave a posicion de la cedula antes dicha si se cumple again=false
                           y de lo contrario repite el ciclo y pide de nuevo clave*/
                           if (clave=='a'){
                               againClave=false;
                           }
                           else {
                               cout<<"clave incorrecta "<<endl;
                           }

                            }while (againClave==true);

                            do{
                            //pide saldo a retirar
                            cout<<" ingrese valor que desea retirar: "<<endl;
                            cin>>retiro;
                            //busca saldo de usuario para saber la posicion y comparar con el valor a retirar

                             //condicional que vea si tiene saldo suficiente para retirar
                             if (retiro<100000){
                                 againRetiro=false;
                             }
                             else {
                                 cout<<"no tiene fondos sufucientes "<<endl;
                             }

                              }while (againRetiro==true);

                             //retira el saldo(resta el saldo a retirar menos el saldo original)
                             cout<<"retire su dinero "<<endl;
                             //resta de saldo a retirar menos saldo inicial


                             //sale
                             repetir=false;

                             break;

                     case 3:
                             //pide clave de administrador para mostrar menu de administrador
                              do{
                              cout<<" ingrese clave de administrador: "<<endl;
                              cin>>claveAdmin;
                              //verifica que la clave sea valida
                               if (claveAdmin=='0'){
                                   againRetiro=false;
                               }
                               else {
                                   cout<<"clave incorrecta "<<endl;
                               }

                                }while (againRetiro==true);

                             //creando meno para ingreso de usuarios
                             menu(opcion);
                             repetir=false;

                             break;
                     case 4:
                             //sale del programa
                             repetir=false;
                }
            } while (repetir==true);
         }


//FUNCIONES ADMINISTRADOR
        void menu(int opcion){
             bool repetir= true;
             bool againUsuario=true;

            do{
                 //ingresa primer usuario
                 cout <<endl;
                 cout << "***** MENU ****"<<endl;
                 cout << " 1. ingrese usuario, clave y saldo. "<<endl;
                 cout << " 2. para salir "<<endl;
                 cin >> opcion;



               switch (opcion){
                      case 1:
                              //ingresa nuevo usuario
                              stringAdmin();
                              do{
                              cout <<endl;
                              cout << "***** MENU ****"<<endl;
                              cout << " 1. ingrese usuario, clave y saldo. "<<endl;
                              cout << " 2. para salir. "<<endl;
                              cin >> opcion;

                              switch (opcion){
                              case 1:
                                  stringAdminAgain();
                                  break;

                              case 2:
                                  //sale del programa por completo
                                  //se crea archivo txt usuariosNew.txt donde se encuentran todos los usuarios ingresados
                                  againUsuario=false;
                                  exit(1);
                                  break;

                              }
                              }while (againUsuario==true);
                            break;

                      case 2:
                              //sale del programa
                              //se crea archivo txt usuariosNew.txt donde se encuentran todos los usuarios ingresados
                              repetir=false;
                           break;

                 }
             } while (repetir==true);

                }

        void stringAdmin(){
             char cedula[10];
             char clave[15];
             char saldo[30];
             char datosUsuario[57]="";
             char espacio[] = " ";

             ofstream usuariosNuevos;

             usuariosNuevos.open("d://usuariosNew.txt",ios::out);
             cout<<"ingrese cedula: "<<endl;
             cin>>cedula;
             strcat(datosUsuario,cedula);
            // strcat(datosUsuario,espacio);
             cout<<"ingrese clave: "<<endl;
             cin>>clave;
             strcat(datosUsuario,clave);
             strcat(datosUsuario,espacio);
             cout<<"ingrese saldo: "<<endl;
             cin>>saldo;
             strcat(datosUsuario,saldo);

             usuariosNuevos<<datosUsuario<<endl;
             usuariosNuevos.close();
        }

        void stringAdminAgain(){
             char cedula[10];
             char clave[15];
             char saldo[30];
             char datosUsuario[57]="";
             char espacio[] = " ";

             usuariosNuevos.open("d://usuariosNew.txt",ios::app);
             cout<<"ingrese cedula: "<<endl;
             cin>>cedula;
             strcat(datosUsuario,cedula);
             //strcat(datosUsuario,espacio);
             cout<<"ingrese clave: "<<endl;
             cin>>clave;
             strcat(datosUsuario,clave);
             strcat(datosUsuario,espacio);
             cout<<"ingrese saldo: "<<endl;
             cin>>saldo;
             strcat(datosUsuario,saldo);

             usuariosNuevos<<datosUsuario<<endl;
             usuariosNuevos.close();
        }





//FUNCIONES VALIDACION

     void validacion(){
        //pide cedula y contraseña
          char cedula[10];
          char clave[15];
          char usuarioValido[25]="";
          char validacion[25]="";
          char espacio[] = " ";

          int i=0;


          ofstream validarUsuario;

          validarUsuario.open("d://usuariosValidacion.txt",ios::out);
          cout<<"ingrese cedula: "<<endl;
          //getline(cin,cedula);
           cin>>cedula;
          strcat(usuarioValido,cedula);
          // strcat(datosUsuario,espacio);
          cout<<"ingrese clave: "<<endl;
          //getline(cin,clave);
          cin>>clave;
          strcat(usuarioValido,clave);
          strcat(usuarioValido,espacio);

          validarUsuario<<usuarioValido<<endl;
          validarUsuario.close();

        //  while(usuarioValido[i]!= ' '){
        //       if (usuarioValido[i]!=)
                // }

          }


