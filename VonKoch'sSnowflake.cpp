#include <string>
#include <iostream>
#include <fstream>

void snowflake(int sl,int level, std::string &commands); //define function since it will be used in helper function

void snowHelper(int sl, int lev, std::string &commands){
    //snowflake is divided into 3 parts,
    //created a helper function to run the code 3 times
    for(int j = 0; j<3; j++){
        snowflake(256,lev, commands);
        //at the end of each iteration, turn right
        commands += "++";
    }
}

//recursive function
void snowflake(int sl,int level, std::string &commands){
    //base case
    if(level == 0){
        for(int i = 0; i<sl; i++){
            commands += "F";
        }
        return;
    }
    else{
        //call the function 4 more times within a single call
        snowflake(sl/3,level-1, commands);
        //left turns are 60 degrees
        commands += "-";

        snowflake(sl/3,level-1, commands);
        //right turns are 120 degrees
        commands += "++";

        snowflake(sl/3,level-1, commands);
        commands += "-";

        snowflake(sl/3,level-1, commands);
    }
}


int main(){
    //going to create an output file
    std::fstream file;
    int lev;
    //get complexity from user
    std::cout << "Enter degree of complexity (between 1-5):" << std::endl;
    std::cin >> lev;
    //start name of file
    std::string name = "snowflake";
    //add level of complexity to the txt files name
    std::string levv = std::to_string(lev);
    name += levv;
    //add the .txt ext
    name += ".txt";
    file.open(name, std::ios_base::out);
    //create string of commands
    std::string commands = "";
    //call snow helper to start the snowflake
    snowHelper(256, lev, commands);
    //tell user when the process has completed
    std::cout << '\n' << "Process has completed!" << std::endl;
    std::cout << '\n';
    //write the commands to the file
    file<<commands;
    //close the file and end the program
    file.close();
    return 0;
}
