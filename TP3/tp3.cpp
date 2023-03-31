#include <iostream>
#include <string>
#include<vector>
#include <cstdlib>
#include <ctime>
#include <array>

using namespace std;

//TP3P1
void stringAT(string example){
    for(unsigned int i=0; i<example.length(); i++)
        cout<<example.at(i)<<" ";
}

void stringINDEX(string example){
    for(unsigned int i=0; i<example.length(); i++)
        cout<<example[i]<<" ";
}

void stringITERATOR(string example){
    for(auto i=example.begin(); i!=example.end(); i++)
        cout<<*i<<" ";
}

void stringEACH(string example){
    for(char letter:example)
        cout<<letter<<" ";
}

//TP3P2

string palindromePyramid(const string& str){

    string pyramid;  // Pirámide a construir
    int len = str.length();  // Longitud de la cadena de entrada

    // Para cada posible centro de palíndromo en la cadena
    for (int center = 0; center < len; center++) {
        int left = center, right = center;

        // Expandir a izquierda y derecha mientras siga siendo un palíndromo
        while (left >= 0 && right < len && str[left] == str[right]) {
            // Extraer el palíndromo y agregarlo a la pirámide con el formato adecuado
            string palindrome = str.substr(left, right - left + 1);
            pyramid.append(palindrome);
            if (right < len - 1) {
                pyramid.append(" ");  // Espacio entre palíndromos en la misma fila
            }
            left--;
            right++;
        }

        // Agregar una nueva línea al final de cada fila (excepto la última)
        if (center < len - 1) {
            pyramid.append("\n");
        }
    }

    return pyramid;

}

//TP3P3

string replaceAll(const string &str, const string &from, const string &to){
    size_t startPos=0;
    string newStr=str;

    while((startPos=newStr.find(from, startPos))!=string::npos){
        newStr.replace(startPos, from.length(), to);
        startPos+=to.length();
    }

    return newStr;

}

//TP3P4
vector<unsigned int> create(unsigned int N, unsigned int from, unsigned int to){
    srand(time(0));

    vector<unsigned int> vec(N);
    unsigned int range = to-from+1;

    for(auto &i:vec){
        i=rand() % range + from;
    }

    return vec;
}

/*void print(vector<unsigned int> v, format f){
    size_t N=v.size();
switch (f)
{
case FMT_LIST:
     for (size_t i=0; i<N ; i++)
    {
        cout<<v[i]<<endl;
    }
    break;
case FMT_LINE:
for (size_t i=0; i<N ; i++)
    {
        cout<<v[i]<< " " ;
    }
    break;
}
*/
void sort(vector<unsigned int> &v){
    unsigned int temp;

    for(unsigned int i=0; i<v.size(); i++){
        for(unsigned int j=0; j<v.size()-1; j++){
            if(v[j]>v[j+1]){
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }
}

vector<unsigned int> insert(vector<unsigned int> v1, vector<unsigned int> v2,
unsigned int pos){
    vector<unsigned int> v3;

    // Insertamos los elementos de v1 hasta la posición pos en v3
    v3.insert(v3.end(), v1.begin(), v1.begin() + pos);
    // Insertamos los elementos de v2 en v3
    v3.insert(v3.end(), v2.begin(), v2.end());
    // Insertamos los elementos restantes de v1 en v3
    v3.insert(v3.end(), v1.begin() + pos, v1.end());
    return v3;
}

void print_frequency(vector<unsigned int> v){
    unsigned int cont=1, i, j, aux;

    for(i=1; i<v.size(); i++){
        if(v[i]==v[i-1]){
            cont++;
        }else{
            cout<<"El numero "<<v[i-1]<<" se repite "<<cont<<" veces"<<endl;
            cont=1;
        }
    }

    cout << "El numero " << v.back() << " se repite " << cont << " veces" <<endl;

}

//TP3P5

int main(int, char **){


    return 0;
}
