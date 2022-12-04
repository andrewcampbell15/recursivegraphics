#include <iostream>
#include <fstream>
#include <string>

void curve (int n, std::string &move ,int degree);

int main (){
     //going to create an output file
    std::fstream file;
    int lev;
    //get complexity from user
    std::cout << "Enter degree of complexity (between 1-5):" << std::endl;
    std::cin >> lev;
    //start name of file
    std::string name = "hil_curve";
    //add level of complexity to the txt files name
    std::string levv = std::to_string(lev);
    name += levv;
    //add the .txt ext
    name += ".txt";
    file.open(name, std::ios_base::out);
    //create string of commands
    std::string commands = "";
    //call curve to start the hilbert curve
    curve(lev, commands, 90);
    //tell user when the process has completed
    std::cout << '\n' << "Process has completed!" << std::endl;
    std::cout << '\n';
    //write the commands to the file
    file<<commands;
    //close the file and end the program
    file.close();
    return 0;
}

void curve (int n, std::string &move, int degree){
    if (n <= 0){
        return;
    }
        if (degree == 90){
            move+= "+";
        }
        else {
            move += "+++";
        }
        curve(n-1, move, -degree);
        move += "F"; // forward
        if (degree == 90){
            move+= "-";
        }
        else {
            move += "---";
        }
        curve(n-1, move, degree);
        move+="F"; // forward
        curve(n-1, move, degree);
        if (degree == 90){
            move+= "-";
        }
        else {
            move += "---";
        }
        move+="F"; // forward
        curve(n-1, move, -degree);
        if (degree == 90){
            move+= "+";
        }
        else {
            move += "+++";
        }
}
