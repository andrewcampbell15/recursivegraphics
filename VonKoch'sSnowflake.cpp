#include <string>
#include <iostream>
#include <fstream>
#include <string>

std::string commands = "";

void snowflake(int sl,int level){
    if(level == 0){
        for(int i = 0; i<sl; i++){
            commands += "F";
        }
        return;
    }
    else{
        snowflake(sl/3,level-1);
        commands += "-";

        snowflake(sl/3,level-1);
        commands += "++";

        snowflake(sl/3,level-1);
        commands += "-";

        snowflake(sl/3,level-1);
    }
}


int main(){
    std::fstream file;
    int lev;
    std::cout << "Enter degree of complexity (between 0-5):" << std::endl;
    std::cin >> lev;
    std::string name = "snowflake";
    std::string levv = std::to_string(lev);
    name += levv;
    name += ".txt";
    file.open(name, std::ios_base::out);
    for(int j = 0; j<3; j++){
        snowflake(256,lev);
        commands += "++";
    }
    std::cout << '\n' << "Process has completed!" << std::endl;
    std::cout << '\n';
    file<<commands;
    file.close();
    return 0;
}
