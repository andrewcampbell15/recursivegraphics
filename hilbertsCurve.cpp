#include <iostream>
#include <fstream>
#include <string>

/**
 * @brief Recursively generates the Hilbert curve of a given degree.
 * @param n Degree of the curve.
 * @param move A string that stores the final commands for the curve.
 * @param degree The current direction of the curve.
 */
void curve(int n, std::string &move, int degree);

int main() {
    /// Going to create an output file
    std::fstream file;
    int lev;
    /// Get complexity from user
    std::cout << "Enter degree of complexity (between 1-5):" << std::endl;
    std::cin >> lev;
    /// Start name of file
    std::string name = "hil_curve";
    /// Add level of complexity to the txt files name
    std::string levv = std::to_string(lev);
    name += levv;
    /// Add the .txt extension
    name += ".txt";
    file.open(name, std::ios_base::out);
    /// Create string of commands
    std::string commands = "";
    /// Call curve to start the Hilbert curve
    curve(lev, commands, 90);
    /// Tell user when the process has completed
    std::cout << '\n' << "Process has completed!" << std::endl;
    std::cout << '\n';
    /// Write the commands to the file
    file << commands;
    /// Close the file and end the program
    file.close();
    return 0;
}

void curve(int n, std::string &move, int degree) {
    if (n <= 0) {
        return;
    }
    /// This check determines if the cursor should be turned 90 degrees or 
270
    if (degree == 90) {
        move += "+"; /// Turn 90 degrees to the right
    } else {
        move += "+++"; /// Turn 270 degrees to the right
    }
    curve(n - 1, move, -degree);
    move += "F"; /// Forward
    if (degree == 90) {
        move += "-"; /// Turn 90 degrees to the left
    } else {
        move += "---"; /// Turn 270 degrees to the left
    }
    curve(n - 1, move, degree);
    move += "F"; /// Forward
    curve(n - 1, move, degree);
    if (degree == 90) {
        move += "-";
    } else {
        move += "---";
    }
    move += "F"; /// Forward
    curve(n - 1, move, -degree);
    if (degree == 90) {
        move += "+";
    } else {
        move += "+++";
    }
}

