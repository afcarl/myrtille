#ifndef STRING_TOOLS_H
#define STRING_TOOLS_H

#include <string>
#include <vector>

std::vector<std::string> split(const std::string &s, const char delim);

std::vector<std::string> split_whitespaces(std::string str);

#endif

