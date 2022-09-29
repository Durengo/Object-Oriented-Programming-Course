#pragma once

#include <string>

// INPUT STREAM
int GIBI();
int GIBI(int min, int max);
double GIBD();
std::string GIBS();
std::string GIBS_NW();
int Get_Input_Yes_Or_No();
bool validateName(const std::string &name);
bool isLetters(const std::string_view &text);
bool isNumbers(const std::string_view &text);
bool oneCapital(const std::string &text);