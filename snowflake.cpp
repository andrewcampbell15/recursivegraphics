#include <string>
#include <iostream>
#include <fstream>

/**
 * @brief Helper function for generating a snowflake shape.
 *
 * The snowflake is divided into 3 parts, so this function runs the code 3 
times.
 *
 * @param sl The length of each line segment of the snowflake.
 * @param lev The current level of recursion.
 * @param commands The current list of commands for generating the 
snowflake.
 */
void snowHelper(int sl, int lev, std::string &commands);

/**
 * @brief Recursive function for generating a snowflake shape.
 *
 * This function generates a snowflake shape using recursion.
 *
 * @param sl The length of each line segment of the snowflake.
 * @param level The current level of recursion.
 * @param commands The current list of commands for generating the 
snowflake.
 */
void snowflake(int sl, int level, std::string &commands);

void snowHelper(int sl, int lev, std::string &commands){
    /// Snowflake is divided into 3 parts, so we run the code 3 times.
    for(int j = 0; j<3; j++){
        snowflake(256, lev, commands);
        /// At the end of each iteration, turn right.
        commands += "++";
    }
}

void snowflake(int sl, int level, std::string &commands){
    /// Base case: if we've reached the maximum recursion level, draw a 
straight line.
    if(level == 0){
        for(int i = 0; i<sl; i++){
            commands += "F";
        }
        return;
    }
    else{
        /// Call the function 4 more times within a single call.
        snowflake(sl/3, level-1, commands);
        /// Left turns are 60 degrees.
        commands += "-";
        snowflake(sl/3, level-1, commands);
        /// Right turns are 120 degrees.
        commands += "++";
        snowflake(sl/3, level-1, commands);
        commands += "-";
        snowflake(sl/3, level-1, commands);
    }
}

int main(){
    /// Open an output file.
    std::fstream file;
    int lev;
    /// Get complexity from user.
    std::cout << "Enter degree of complexity (between 1-5):" << std::endl;
    std::cin >> lev;
    /// Start name of file.
    std::string name = "snowflake";
    /// Add level of complexity to the txt file's name.
    std::string levv = std::to_string(lev);
    name += levv;
    /// Add the .txt ext.
    name += ".txt";
    file.open(name, std::ios_base::out);
    /// Create string of commands.
    std::string commands = "";
    /// Call snow helper to start the snowflake.
    snowHelper(256, lev, commands);
    /// Tell the user when the process has completed.
    std::cout << '\n' << "Process has completed!" << std::endl;
    std::cout << '\n';
    /// Write the commands to the file.
    file<<commands;
    /// Close the file and end the program.
    file.close();
    return 0;
}

