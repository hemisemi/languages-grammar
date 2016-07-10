#pragma once

#include <string>
#include <regex>

inline std::string digraph_name(const std::string & str){
    return std::regex_replace(std::regex_replace(str, std::regex("\\|"), "\\|"), std::regex("&"), "&amp;");
}
