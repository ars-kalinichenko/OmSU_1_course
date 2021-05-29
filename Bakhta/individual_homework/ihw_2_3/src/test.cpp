#include "include/test.h"

#include <string>
#include <fstream>
#include <streambuf>
#include <iostream>


int main()
{
    std::ifstream file("/home/arseny/projects/OmSU_1_course/Bakhta/individual_homework/ihw_2_3/test/1.txt");
    std::string str((std::istreambuf_iterator<char>(file)),
                    std::istreambuf_iterator<char>());

    str.c_str();

    for( unsigned int a = 0; a < sizeof(str)/sizeof(str[0]); a = a + 1 )
    {
        std::cout << str[a] << std::endl;
    }

    return 0;
}