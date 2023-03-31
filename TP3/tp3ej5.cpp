#include <iostream>
#include <fstream>
#include <array>

using namespace std;

// Definición de la estructura rgb
struct rgb {
    uint8_t r, g, b;
};

// Tamaño de la matriz
const int TAM = 100;

// Función para generar un archivo .ppm con la matriz y la cruz
void dibujar(array<array<rgb,TAM>,TAM> image, string filename) {
    const int dimx = image.size();
    const int dimy = image[0].size();

    // Apertura del archivo de salida
    ofstream outfile(filename, ofstream::binary);
    outfile << "P6\n" << dimx << " "<< dimy << "\n255\n";

    // Matriz de colores
    array<rgb,5> colores = {{
        { 0x94, 0x00, 0xD3 },  // Deep Purple
        { 0x4B, 0x00, 0x82 },  // Indigo
        { 0xFF, 0xBF, 0x00 },  // Amber
        { 0x54, 0x64, 0x6E },  // Blue Gray
        { 0x8B, 0xC3, 0x4A }   // Light Green
    }};

    // Generación de la matriz de colores y la cruz
    for (int y = 0; y < dimy; y++) {
        for (int x = 0; x < dimx; x++) {
            int i = x % 5;
            if (x == 49 || y == 49) {
                // La coordenada (49,49) es el centro del archivo, se dibuja la cruz
                image[x][y] = { 0xFF, 0xFF, 0xFF };
            } else {
                // Se genera la matriz de colores
                image[x][y] = colores[i];
            }
        }
    }

    // Escritura de los datos en el archivo de salida
    for (int y = 0; y < dimy; y++) {
        for (int x = 0; x < dimx; x++) {
            rgb c = image[x][y];
            outfile << char(c.r) << char(c.g) << char(c.b);
        }
    }

    // Cierre del archivo de salida
    outfile.close();
}

int main() {
    // Creación de la matriz de colores
    array<array<rgb,TAM>,TAM> image;

    // Generación del archivo .ppm con la matriz de colores y la cruz
    dibujar(image, "imagen.ppm");

    return 0;
}
