//
//  filesystem.hpp
//  LW4
//
//  Created by Stanislav Martynov on 03/11/2019.
//  Copyright © 2019 Stanislav Martynov. All rights reserved.
//

#ifndef filesystem_hpp
#define filesystem_hpp

#include <stdio.h>
#include <filesystem>
#include <iostream>
#include <exception>
#include <string>
#include <map>
#include <vector>

namespace fs = std::filesystem;

class directory
{
public:
    explicit directory(std::string path);
    void Check_path();
    void print_info();
private:
    void type_path(fs::path value);
    std::pair<std::string, std::string> brockers_parse(std::string &fn);
    void add_brocker(std::string &brocker, std::string &account, std::string date);
    std::string get_brocker_name(fs::path &dir);
    fs::path my_path;
    std::map<std::string, std::map<std::string, std::vector<std::string>>> m_brockers;
};

#endif /* filesystem_hpp */
