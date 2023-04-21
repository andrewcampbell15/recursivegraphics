#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

/// Generates the Sierpinski triangle L-system string recursively.
/// \param degree The degree of complexity.
/// \param len The length of the side of the largest triangle.
/// \param final A reference to the final output string.
/// \return The final output string.
std::string sierpinski_triangle(int degree, int len, std::string& final) {
    /// Base case is when degree hits 0; return nothing.
    if (degree == 0) {
        return "";
    }

    /// String for each function call that is added to final string.
    std::string commands = "";

    /// Outer loop loops 3 times for every side of the triangle.
    for (int i = 0; i < 3; i++) {
        /// Inner loop adds "F" to the output string length number of 
times (draws a triangle side).
        for (int j = 0; j < len; j++) {
            final += "F";
        }
        /// Turns the arrow 120 degrees.
        final += "+ +";
        /// Recursion with degree moving towards base case and the length 
divided in half to draw a smaller triangle.
        sierpinski_triangle(degree - 1, len / 2, final);
    }

    final += commands;
    return final;
}

int main() {
    /// Creates output file.
    std::ofstream of("l-system.txt");

    std::string final, save;
    std::fstream file;

    /// Gets level of complexity from user.
    int lev;
    std::cout << "Enter degree of complexity (between 1-5):" << std::endl;
    std::cin >> lev;
    std::string name = "triangle";
    std::string levv = std::to_string(lev);
    name += levv;
    name += ".txt";
    /// Creates file with the output string that can then be inputted into 
the Python display program.
    file.open(name, std::ios_base::out);
    save = sierpinski_triangle(lev, std::pow(2, lev - 1), final);
    std::cout << '\n' << "Process has completed!" << std::endl;
    std::cout << '\n';
    file << save;
    file.close();
}

