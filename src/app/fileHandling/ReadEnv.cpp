#include <iostream>
#include<string>
#include<fstream>
#include "IO.hpp"
#include<sstream>
using namespace std;


class ReadEnv{
    public:
        string getenv(){
            string env_path = ".env";  // Path to the .env file
            IO io(env_path);    // Create an IO object      
            fstream f_stream = io.getFileStream();   // Get the file stream
            stringstream buffer; // Create a string stream buffer to read the file
            buffer << f_stream.rdbuf(); // Read the file
            string content = buffer.str(); // Get the content of the file
            return content;
        }    
};