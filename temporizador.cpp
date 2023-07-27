#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

// Función para mostrar el tiempo formateado
void mostrarTiempo(int horas, int minutos, int segundos) {
    cout << "\r";
    cout << "Tiempo restante: ";
    cout << (horas < 10 ? "0" : "") << horas << ":";
    cout << (minutos < 10 ? "0" : "") << minutos << ":";
    cout << (segundos < 10 ? "0" : "") << segundos;
    cout << flush;
}

int main() {
    int horas, minutos, segundos;

    // Solicitar los datos de tiempo al usuario
    cout << "Ingrese las horas: ";
    cin >> horas;
    cout << "Ingrese los minutos: ";
    cin >> minutos;
    cout << "Ingrese los segundos: ";
    cin >> segundos;

    // Mostrar el tiempo inicial
    mostrarTiempo(horas, minutos, segundos);

    // Convertir las horas, minutos y segundos a segundos totales
    int tiempoTotal = horas * 3600 + minutos * 60 + segundos;

    // Ciclo para contar hacia adelante
    while (tiempoTotal > 0) {
        // Restar 1 segundo al tiempo total
        tiempoTotal--;

        // Calcular las nuevas horas, minutos y segundos
        horas = tiempoTotal / 3600;
        minutos = (tiempoTotal % 3600) / 60;
        segundos = (tiempoTotal % 3600) % 60;

        // Mostrar el tiempo actualizado
        mostrarTiempo(horas, minutos, segundos);

        // Esperar 1 segundo antes de actualizar el cronómetro
        this_thread::sleep_for(chrono::seconds(1));
    }

    // Mostrar el tiempo finalizado
    cout << "\n\n¡Tiempo finalizado!" << endl;

    return 0;
}
