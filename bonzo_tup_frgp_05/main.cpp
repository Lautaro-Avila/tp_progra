#include <iostream>
// -- Librerias para numeros random --
#include <cstdlib>
#include <ctime>


// ---------------------------------

using namespace std;

// -------FUNCIONES --------

// -- Pantalla Inicial Opciones --

int PantallaInicio(){

    int opcion;

    cout << "BONZO" << endl;
    cout << "------------------" << endl;
    cout << "1 - Jugar" << endl;
    cout << "2 - Estadísticas" << endl;
    cout << "3 - Créditos" << endl;
    cout << "------------------" << endl;
    cout << "0 - Salir" << endl;
    cout << endl;
    cout << "Opción: ";
    cin >> opcion;
    cout << endl;
    return opcion;
}

// ---------------------------------

// -- Selección Nombres Jugadores --

void ingresoJugadores(string &nombre_jugador_uno, string &nombre_jugador_dos){

    char confirmarNombre ='n';

    do
        {
            cout << "BONZO" << endl;
            cout << "------------------" << endl;
            cout << "Antes de comenzar deben registrar sus nombres: " << endl;
            cout << endl;
            cout << "¿Nombre? ";
            cin >> nombre_jugador_uno;
            cout << endl;
            cout << "¿Nombre? ";
            cin >> nombre_jugador_dos;
            cout << endl;
            cout << "¿Confirmar nombres? (S/N) ";
            cin >> confirmarNombre;
            confirmarNombre = tolower(confirmarNombre);
            cout << endl;
            // agrego cls para limpiar la consola
            system("cls");
        }
        while(confirmarNombre != 's');
            cout << "BONZO" << endl;
            cout << "------------------" << endl;
            cout <<endl;
            cout << "¡QUE COMIENCE EL JUEGO!" << endl;
            cout <<endl;
}

// ---------------------------------

// -- Lanzamiento Dados --

int LanzamientoDado(){
    //para calcular un numero random entre 1 y 6
    srand(time(0));
    int numero = rand() % 6 + 1;
    cout<<endl;
    //cout << numero << endl;
    return numero;
}

// ---------------------------------

// -- DIBUJO DADOS --

void CaraDado(int valor){

switch (valor) {
        case 1:
            cout << "+-----+\n";
            cout << "|     |\n";
            cout << "|  X  |\n";
            cout << "|     |\n";
            cout << "+-----+\n";
            break;
        case 2:
            cout << "+-----+\n";
            cout << "|X    |\n";
            cout << "|     |\n";
            cout << "|    X|\n";
            cout << "+-----+\n";
            break;
        case 3:
            cout << "+-----+\n";
            cout << "|X    |\n";
            cout << "|  X  |\n";
            cout << "|    X|\n";
            cout << "+-----+\n";
            break;
        case 4:
            cout << "+-----+\n";
            cout << "|X   X|\n";
            cout << "|     |\n";
            cout << "|X   X|\n";
            cout << "+-----+\n";
            break;
        case 5:
            cout << "+-----+\n";
            cout << "|X   X|\n";
            cout << "|  X  |\n";
            cout << "|X   X|\n";
            cout << "+-----+\n";
            break;
        case 6:
            cout << "+-----+\n";
            cout << "|X   X|\n";
            cout << "|X   X|\n";
            cout << "|X   X|\n";
            cout << "+-----+\n";
            break;
    }
}

// ---------------------------------

// -- Tirar los Dados Para Inicio Juego --

void QuienArranca(string &j1, string &j2){

    int n1, n2;
   // string jugadorArranque;
    string jugadorSegundo;

    cout << "El jugador " << j1 << " tira el dado!" << endl;
    cout << endl;
    cout << "Si sale un número PAR inicia " << j1 << "!" << endl;
    cout << endl;
    cout << "Si sale un número IMPAR inicia " << j2 << "!" << endl;
    cout << endl;
    cout << "------------------" << endl;
    cout << "Jugador " << j1 << " tire el dado" << endl;
    system("pause");
    n1 = LanzamientoDado();

    system("cls");
    cout << "BONZO" << endl;
    cout << "------------------" << endl;
    cout << endl;
    cout << "Salió en número: " << n1 << endl;
    cout << endl;

    if  (n1%2 == 0){
        cout << "Salió número PAR, empieza el jugador " << j1 << endl;
        system("pause");
    }else{
        cout << "Salió número IMPAR, empieza el jugador " << j2 << endl;

        jugadorSegundo = j1;
        j1= j2;
        j2 = jugadorSegundo;
        system("pause");
    }
}

// ---------------------------------

// -- Información Jugadores --

void InformacionJugadores(string &j1, string &j2, int &ronda, int &totalUno, int &totalDos){

    system("cls");
    cout << "BONZO" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << j1 << ": " << totalUno << " puntos Totales    " << j2 << ": " << totalDos << " puntos Totales" << endl;
    cout << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << " RONDA #" << ronda << endl;
    cout << endl;
    cout << " NÚMERO PROHIBIDO: " << ronda << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << endl;
    cout << endl;
}

// ---------------------------------


// -- Tirada 3 Dados  --

void tiradaTresDados(int tresDados[])  // generación aleatoria de 3 dados
{
    int const DOSDADOS = 3;

    for (int i = 0; i<DOSDADOS; ++i)   // Generar y mostrar 3 números aleatorios del 1 al 10
    {
        int numeroAleatorio = rand() % 6 + 1;
        tresDados[i] = numeroAleatorio;
    }
}

// ---------------------------------

// -- Tirada 2 Dados --

void tiradaDosDados(int dosDados[])  // generación aleatoria de 2 dados
{
    int const DOSDADOS = 2;

    for (int i = 0; i<DOSDADOS; ++i)   // Generar y mostrar 2 números aleatorios del 1 al 10
    {
        int numeroAleatorio = rand() % 6 + 1;
        dosDados[i] = numeroAleatorio;
    }
}

// ---------------------------------


// JUEGO Desarrollo

void DesarrolloDelJuego(string &j1, string &j2)
{
    int tiradaTresDadosVuelta[3];
    int tiradaDosDadosVuelta[2];
    int AcumulaVuelta;
    int dadoProhibido;
    int sumatirada;
    int sumatirada2;
    char seguirTirando;
    bool DosDadosJugadorPrimero = false;
    bool DosDadosJugadorSegundo = false;
    int sumaronda;
    int sumaronda2;
    int acumularPlayerUno=0;
    int acumularPlayerDos=0;
    int acumularTirada = 1;
    int tiradaPlayer1=0;
    int tiradaPlayer2=0;

    for (AcumulaVuelta=1; AcumulaVuelta<=6; AcumulaVuelta++)
    {
        do
        {
            InformacionJugadores(j1, j2, AcumulaVuelta, acumularPlayerUno, acumularPlayerDos);  // aca muestra el tablero
            if(DosDadosJugadorPrimero == true)
            {
                cout << "Ronda " << AcumulaVuelta << endl;
                cout << "Por favor, tire los dados: "  << j1 <<  endl;
                tiradaDosDados(tiradaDosDadosVuelta);
                cout << "Salieron los números" << endl;
                cout << tiradaDosDadosVuelta[0] << endl;
                cout << tiradaDosDadosVuelta[1] << endl;
                dadoProhibido = AcumulaVuelta;
                if (dadoProhibido != tiradaDosDadosVuelta[0] && dadoProhibido != tiradaDosDadosVuelta[1] )
                {
                    sumatirada = tiradaDosDadosVuelta[0] +tiradaDosDadosVuelta[1];
                    sumaronda = sumaronda + sumatirada;
                    cout << "En esta tirada obtuviste: " << sumatirada << " puntos" << endl;
                    cout << endl;
                    cout << "Llevas acumulados en esta ronda: " << sumaronda << " puntos" << endl;
                    cout << endl;
                    cout << "Acumulado sin esta ronda : " << acumularPlayerUno << " puntos" << endl;
                    cout << endl;
                    cout << "Seguis tirando o te plantas? (S/N) " << endl;
                    cin >> seguirTirando;
                    seguirTirando=tolower(seguirTirando);
                    DosDadosJugadorPrimero = false;
                }
                else if((dadoProhibido == tiradaDosDadosVuelta[0] && dadoProhibido != tiradaDosDadosVuelta[1]) //un dado bien
                        ||
                        (dadoProhibido != tiradaDosDadosVuelta[0] && dadoProhibido == tiradaDosDadosVuelta[1]))

                {
                    cout << "Te salió un dado prohibidooo, no sumas puntos ésta ronda!!!!" << endl;
                    sumaronda = 0;
                    cout << endl;
                    cout << "En esta ronda obtuviste: " << sumaronda << " puntos" << endl;
                    cout << endl;
                    cout << "No podes seguir tirando, pasas el turno" << endl;
                    seguirTirando = 'N';
                    system("pause");
                    DosDadosJugadorPrimero = false;
                }

                else if(dadoProhibido == tiradaDosDadosVuelta[0] && dadoProhibido == tiradaDosDadosVuelta[1]) //dos dado bien

                {
                    cout << "Te salieron dos dados prohibidooos, perdiste los puntos de ésta ronda!!!!" << endl;
                    cout << endl;
                    cout << "Y en la próxima ronda vas a tener solo 2 dados!!!!" << endl;
                    DosDadosJugadorPrimero = true;
                    sumaronda = 0;
                    cout << endl;
                    cout << "En esta tirada obtuviste: " << sumaronda << " puntos" << endl;
                    cout << endl;
                    cout << "No podes seguir tirando, pasas el turno" << endl;
                    seguirTirando = 'N';
                    system("pause");

                }
                acumularPlayerUno = acumularPlayerUno + sumaronda;
                cout << "Llevas acumulados en total: " << acumularPlayerUno << " puntos" << endl;
                system("pause");
            }else{
                //cout << "Ronda " << AcumulaVuelta << endl;
                cout << "Por favor, tire los dados: "  << j1 <<  endl;
                tiradaTresDados(tiradaTresDadosVuelta);
                cout << endl;
                cout << "Salieron los números" << endl;
                cout << tiradaTresDadosVuelta[0] << endl;
                cout << tiradaTresDadosVuelta[1] << endl;
                cout << tiradaTresDadosVuelta[2] << endl;

                dadoProhibido = AcumulaVuelta;
                if (dadoProhibido != tiradaTresDadosVuelta[0] && dadoProhibido != tiradaTresDadosVuelta[1] && dadoProhibido != tiradaTresDadosVuelta[2])
                {
                    sumatirada = tiradaTresDadosVuelta[0] +tiradaTresDadosVuelta[1] + tiradaTresDadosVuelta[2] ;
                    sumaronda = sumaronda + sumatirada;
                    cout << "En esta tirada obtuviste: " << sumatirada << " puntos" << endl;
                    cout << endl;
                    cout << "Llevas acumulados en esta ronda: " << sumaronda << " puntos" << endl;
                    cout << endl;
                    cout << "Acumulado sin esta ronda : " << acumularPlayerUno << " puntos" << endl;
                    cout << endl;
                    cout << "Seguis tirando o te plantas? (S/N) " << endl;
                    cin >> seguirTirando;
                    seguirTirando=tolower(seguirTirando);
                }
                else if((dadoProhibido == tiradaTresDadosVuelta[0] && dadoProhibido != tiradaTresDadosVuelta[1] //un dado bien
                         && dadoProhibido != tiradaTresDadosVuelta[2])||
                        (dadoProhibido != tiradaTresDadosVuelta[0] && dadoProhibido == tiradaTresDadosVuelta[1]
                         && dadoProhibido != tiradaTresDadosVuelta[2])||
                        (dadoProhibido != tiradaTresDadosVuelta[0] && dadoProhibido != tiradaTresDadosVuelta[1]
                         && dadoProhibido == tiradaTresDadosVuelta[2]))

                {
                    cout << "Te salió un dado prohibidooo, no sumas puntos ésta ronda!!!!" << endl;
                    sumaronda = 0;
                    cout << endl;
                    cout << "En esta ronda obtuviste: " << sumaronda << " puntos" << endl;
                    cout << endl;
                    cout << "No podes seguir tirando, pasas el turno" << endl;
                    seguirTirando = 'N';
                    system("pause");

                }

                else if((dadoProhibido == tiradaTresDadosVuelta[0] && dadoProhibido == tiradaTresDadosVuelta[1] //dos dado bien
                         && dadoProhibido != tiradaTresDadosVuelta[2])||
                        (dadoProhibido == tiradaTresDadosVuelta[0] && dadoProhibido != tiradaTresDadosVuelta[1]
                         && dadoProhibido == tiradaTresDadosVuelta[2])||
                        (dadoProhibido != tiradaTresDadosVuelta[0] && dadoProhibido == tiradaTresDadosVuelta[1]
                         && dadoProhibido == tiradaTresDadosVuelta[2]))
                {
                    cout << "Te salieron dos dados prohibidooos, perdiste los puntos de ésta ronda!!!!" << endl;
                    cout << endl;
                    cout << "Y en la próxima ronda vas a tener solo 2 dados!!!!" << endl;
                    DosDadosJugadorPrimero = true;
                    sumaronda = 0;
                    cout << endl;
                    cout << "En esta ronda obtuviste: " << sumaronda << " puntos" << endl;
                    cout << endl;
                    cout << "No podes seguir tirando, pasas el turno" << endl;
                    seguirTirando = 'N';
                    system("pause");

                }
                else if (dadoProhibido == tiradaTresDadosVuelta[0] && dadoProhibido == tiradaTresDadosVuelta[1] //dos dado bien
                         && dadoProhibido == tiradaTresDadosVuelta[2])
                {
                    cout << "Te salieron los tres dados iguales al dado prohibido, la quedasssteee!" << endl;
                    cout << endl;
                    cout << "-----------------------------------" << endl;
                    cout << "EL GANADOR ES: " << j2 << endl ;
                    cout << "-----------------------------------" << endl;
                }
            }

            acumularPlayerUno = acumularPlayerUno + sumaronda;
            cout << "Llevas acumulados en total: " << acumularPlayerUno << " puntos" << endl;
            system("pause");
            cout << endl;
            cout << "Le toca el turno a " << j2 << endl;
        }
        while(seguirTirando == 's');

        do
        {
            InformacionJugadores(j1, j2, AcumulaVuelta, acumularPlayerUno, acumularPlayerDos); // muestra siempre el tablero
            if(DosDadosJugadorSegundo == true)
            {
                //cout << "Ronda " << AcumulaVuelta << endl;
                cout << "Por favor, tire los dados: "  << j2 <<  endl;
                tiradaDosDados(tiradaDosDadosVuelta);
                cout << endl;
                cout << "Salieron los números" << endl;
                cout << tiradaDosDadosVuelta[0] << endl;
                cout << tiradaDosDadosVuelta[1] << endl;
                dadoProhibido = AcumulaVuelta;
                if (dadoProhibido != tiradaDosDadosVuelta[0] && dadoProhibido != tiradaDosDadosVuelta[1] )
                {
                    sumatirada2 = tiradaDosDadosVuelta[0] +tiradaDosDadosVuelta[1];
                    sumaronda2 = sumaronda2 + sumatirada2;
                    cout << "En esta tirada obtuviste: " << sumatirada2 << " puntos" << endl;
                    cout << endl;
                    cout << "Llevas acumulados en esta ronda: " << sumaronda2 << " puntos" << endl;
                    cout << endl;
                    cout << "Acumulado sin esta ronda : " << acumularPlayerDos << " puntos" << endl;
                    cout << endl;
                    cout << "Seguis tirando o te plantas? (S/N) " << endl;
                    cin >> seguirTirando;
                    seguirTirando=tolower(seguirTirando);
                    DosDadosJugadorSegundo = false;
                }
                else if((dadoProhibido == tiradaDosDadosVuelta[0] && dadoProhibido != tiradaDosDadosVuelta[1]) //un dado bien
                        ||
                        (dadoProhibido != tiradaDosDadosVuelta[0] && dadoProhibido == tiradaDosDadosVuelta[1]))

                {
                    cout << "Te salió un dado prohibidooo, no sumas puntos ésta ronda!!!!" << endl;
                    sumaronda2 = 0;
                    cout << endl;
                    cout << "En esta ronda obtuviste: " << sumaronda2 << " puntos" << endl;
                    cout << endl;
                    cout << "No podes seguir tirando, pasas el turno" << endl;
                    seguirTirando = 'N';
                    system("pause");
                    DosDadosJugadorSegundo = false;
                }

                else if(dadoProhibido == tiradaDosDadosVuelta[0] && dadoProhibido == tiradaDosDadosVuelta[1]) //dos dado bien

                {
                    cout << "Te salieron dos dados prohibidooos, perdiste los puntos de ésta ronda!!!!" << endl;
                    cout << endl;
                    cout << "Y en la próxima ronda vas a tener solo 2 dados!!!!" << endl;
                    DosDadosJugadorSegundo = true;
                    sumaronda2 = 0;
                    cout << endl;
                    cout << "En esta tirada obtuviste: " << sumaronda2 << " puntos" << endl;
                    cout << endl;
                    cout << "No podes seguir tirando, pasas el turno" << endl;
                    seguirTirando = 'N';
                    system("pause");

                }

                acumularPlayerDos = acumularPlayerDos + sumaronda2;
                cout << "Llevas acumulados en total: " << acumularPlayerDos << " puntos" << endl;
                system("pause");
            }else{
                //cout << "Ronda " << AcumulaVuelta << endl;
                cout << "Por favor, tire los dados: "  << j2 <<  endl;
                tiradaTresDados(tiradaTresDadosVuelta);
                cout << endl;
                cout << "Salieron los números" << endl;
                cout << tiradaTresDadosVuelta[0] << endl;
                cout << tiradaTresDadosVuelta[1] << endl;
                cout << tiradaTresDadosVuelta[2] << endl;
                dadoProhibido = AcumulaVuelta;
                if (dadoProhibido != tiradaTresDadosVuelta[0] && dadoProhibido != tiradaTresDadosVuelta[1] && dadoProhibido != tiradaTresDadosVuelta[2])
                {
                    sumatirada2 = tiradaTresDadosVuelta[0] +tiradaTresDadosVuelta[1] + tiradaTresDadosVuelta[2] ;
                    sumaronda2 = sumaronda2 + sumatirada2;
                    cout << "En esta tirada obtuviste: " << sumatirada2 << " puntos" << endl;
                    cout << endl;
                    cout << "Llevas acumulados en esta ronda: " << sumaronda2 << " puntos" << endl;
                    cout << endl;
                    cout << "Acumulado sin esta ronda : " << acumularPlayerDos << " puntos" << endl;
                    cout << endl;
                    cout << "Seguis tirando o te plantas? (S/N) " << endl;
                    cin >> seguirTirando;
                    seguirTirando=tolower(seguirTirando);
                }
                else if((dadoProhibido == tiradaTresDadosVuelta[0] && dadoProhibido != tiradaTresDadosVuelta[1] //un dado bien
                         && dadoProhibido != tiradaTresDadosVuelta[2])||
                        (dadoProhibido != tiradaTresDadosVuelta[0] && dadoProhibido == tiradaTresDadosVuelta[1]
                         && dadoProhibido != tiradaTresDadosVuelta[2])||
                        (dadoProhibido != tiradaTresDadosVuelta[0] && dadoProhibido != tiradaTresDadosVuelta[1]
                         && dadoProhibido == tiradaTresDadosVuelta[2]))

                {
                    cout << "Te salió un dado prohibidooo, no sumas puntos ésta ronda!!!!" << endl;
                    sumaronda2 = 0;
                    cout << endl;
                    cout << "En esta ronda obtuviste: " << sumaronda2 << " puntos" << endl;
                    cout << endl;
                    cout << "No podes seguir tirando, pasas el turno" << endl;
                    seguirTirando = 'N';
                    system("pause");

                }

                else if((dadoProhibido == tiradaTresDadosVuelta[0] && dadoProhibido == tiradaTresDadosVuelta[1] //dos dado bien
                         && dadoProhibido != tiradaTresDadosVuelta[2])||
                        (dadoProhibido == tiradaTresDadosVuelta[0] && dadoProhibido != tiradaTresDadosVuelta[1]
                         && dadoProhibido == tiradaTresDadosVuelta[2])||
                        (dadoProhibido != tiradaTresDadosVuelta[0] && dadoProhibido == tiradaTresDadosVuelta[1]
                         && dadoProhibido == tiradaTresDadosVuelta[2]))
                {
                    cout << "Te salieron dos dados prohibidooos, perdiste los puntos de ésta ronda!!!!" << endl;
                    cout << endl;
                    cout << "Y en la próxima ronda vas a tener solo 2 dados!!!!" << endl;
                    DosDadosJugadorSegundo = true;
                    sumaronda2 = 0;
                    cout << "En esta ronda obtuviste: " << sumaronda2 << " puntos" << endl;
                    cout << endl;
                    cout << "No podes seguir tirando, pasas el turno" << endl;
                    seguirTirando = 'N';
                    system("pause");

                }
                else if (dadoProhibido == tiradaTresDadosVuelta[0] && dadoProhibido == tiradaTresDadosVuelta[1] //dos dado bien
                         && dadoProhibido == tiradaTresDadosVuelta[2])
                {
                    cout << "Te salieron los tres dados iguales al dado prohibido, la quedasssteee!" << endl;
                    cout << endl;
                    cout << "-----------------------------------" << endl;
                    cout << "EL GANADOR ES: " << j1 << endl;
                    cout << "-----------------------------------" << endl;
                }
            }

            acumularPlayerDos = acumularPlayerDos + sumaronda2;
            cout << "Llevas acumulados en total: " << acumularPlayerDos << " puntos" << endl;
            system("pause");

            cout << "Le toca el turno a " << j1 << endl;
        }
        while(seguirTirando == 's');

    }
    cout << "-----------------------------------" << endl;
    cout << "PARTIDA TERMINADA" << endl;
    cout << "-----------------------------------" << endl;

    if (acumularPlayerUno > acumularPlayerDos)
    {
        cout << "EL GANADOR ES " << j1 <<  " CON " << acumularPlayerUno<< " PUNTOS " << endl;
    }
    else
    {
        cout << "EL GANADOR ES " << j2 << " CON " << acumularPlayerDos << " PUNTOS " << endl;
    }
}
// ---------------------------------

// ---------------------------------


// -- Créditos --

void Creditos()
{
    cout << "BONZO" << endl;
    cout << "-------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Hola! Somos el GRUPO N°1 de la materia Programación I (UTN-FRGP) 2024." << endl;
    cout << endl;
    cout << "Inspirado en el juego de mesa Bunco" << endl;
    cout << endl;
    cout << "-------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "DESARROLLADORES:" << endl;
    cout << endl;
    cout << "Julia" << endl;
    cout << "Charly" << endl;
    cout << "Lautaro" << endl;
    cout << "Diego" << endl;
    cout << endl;
    cout << "Esperamos que lo hayas disfrutado!" << endl;
}

// ---------------------------------

// --Salida del Juego --

void SalidaDelJuego()
{
    cout << "BONZO" << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << endl;
    cout << "Saliste del juego, gracias por usar nuestro desarrollo!" << endl;
    cout << endl;
    cout << "-------------------------------------------------------" << endl;
    // NO se usa return 0; porque el compilador la agrega de forma virtual al usar VOID
}

// ---------------------------------

// ----- PROGRAMA MAIN --------

int main()
{
    srand(static_cast<unsigned int>(time(NULL)));

    //Imprimir los caracteres en español
    setlocale(LC_ALL, "");

    //int tiradaTresDadosVuelta[3];
    //int tiradaDosDadosVuelta[2];
    //int AcumulaVuelta;
    //int dadoProhibido;
    //string quienarranca;
    //char seguirtirando;
    //int sumatirada;
    //int sumatirada2;
    //int menu;
    int eleccion;
    //int acumularPlayerUno=0;
    //int acumularPlayerDos=0;
    //int acumularTirada = 1;
    //int tiradaPlayer1=0;
    //int tiradaPlayer2=0;
    //char confirmaNombre;

    //string nombre1;
    //string nombre2;
    //string jugador1;
    //string jugador2;

    string tirarDeNuevo;
    int dado;
    string tiradaDadoInicio;
    int tiradaDadosVuelta;
    //bool dosDados1 = false;
    //bool dosDados2 = false;
    //int sumaronda;
    //int sumaronda2;

    // -- Variables de los jugadores --
    string jugador_uno;
    string jugador_dos;

    switch(PantallaInicio())
    {
        case 1:
            // se agrega cls para limpiar la consola
            system("cls");

            ingresoJugadores(jugador_uno, jugador_dos);

            QuienArranca(jugador_uno, jugador_dos);

           // InformacionJugadores(jugador_uno, jugador_dos);

            DesarrolloDelJuego(jugador_uno, jugador_dos);

            cout << endl;
            break;
        case 2:
            cout << "BONZO" << endl;
            cout << "---------------------------" << endl;
            cout << "Las estadísticas son: " << endl;
            cout << endl;
            break;
        case 3:
            // agregar cls para limpiar la consola
            system("cls");

            Creditos();

            break;
        case 0:
            // se agrega cls para limpiar la consola
            system("cls");

            SalidaDelJuego();

            break;
        default:
            cout << "Ingresaste mal el número." << endl;
            // se agrega pause para frenar la consola
            system("pause");
            // se agrega cls para limpiar la consola
            system("cls");
            main();
            break;
    }
    return 0;
}
