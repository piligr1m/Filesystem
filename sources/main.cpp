//
//  main.cpp
//  LW4
//
//  Created by Stanislav Martynov on 03/11/2019.
//  Copyright © 2019 Stanislav Martynov. All rights reserved.
//

#include <iostream>
#include <filesystem>
#include "filesystem.hpp"

namespace fs = std::filesystem;

int main(int argc, char *argv[])
{
    if (argc < 2){
        std::cerr << "error" << std::endl;
        return 1;
    }
    try {
        directory parser(argv[1]);
        parser.Check_path();
        parser.print_info();
    }
    catch (const std::exception &ex){
        std::cerr << ex.what() << std::endl;
    }
    catch (...) {
        std::cerr << "unknown exception" << std::endl;
    }

    std::cin.get();
    return 0;
}
