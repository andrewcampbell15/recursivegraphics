
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

std::string sierpinski_triangle(int degree, int len, std::string &final){
    if(degree == 0){
        return "";
    }

    std::string commands = "";

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < len; j++) {
            final += "F";
        }
        final += "+ +";
        sierpinski_triangle(degree - 1, len / 2, final);
    }

    final += commands;
    return final;
}

int main(){
    std::ofstream of("l-system.txt");

    std::string final, save;
    std::fstream file;

    int lev;
    std::cout << "Enter degree of complexity (between 1-5):" << std::endl;
    std::cin >> lev;
    std::string name = "triangle";
    std::string levv = std::to_string(lev);
    name += levv;
    name += ".txt";
    file.open(name, std::ios_base::out);
    save = sierpinski_triangle(lev, std::pow(2, lev - 1), final);
    std::cout << '\n' << "Process has completed!" << std::endl;
    std::cout << '\n';
    file << save;
    file.close();

}