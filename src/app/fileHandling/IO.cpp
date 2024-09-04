#include<iostream>
#include "IO.hpp"
using namespace std ;

//opening the file in read,write and append mode 
IO::IO(const std::string& file_path){
    file_stream.open(file_path, ios::in | ios::out | ios::binary);
    if(!file_stream.is_open()){
        cout << "Error: File not opened" << file_path<<endl;
    }
}

IO::~IO(){
    if(file_stream.is_open()){
        file_stream.close();
    }
}

fstream IO::getFileStream(){
    return move(file_stream);
}