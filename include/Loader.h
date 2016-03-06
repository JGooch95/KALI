#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>

class Loader 
{
public:
	static const std::vector<std::vector<char>> LoadLevel(const std::string FileName);
};