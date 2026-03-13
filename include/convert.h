#pragma once

#include <string>
#include <vector>
#include <utility>

struct UnitSystem {
  std::string unit_name;

  UnitSystem(std::string name) : unit_name(std::move(name)) {}
};

struct Quantity {
  std::string name;
  double conversion_factor;
  UnitSystem cgs;
  UnitSystem si;
  
  Quantity(std::string n, double cf, std::string c, std::string s) 
    : name(n), conversion_factor(cf), cgs(std::move(c)), si(std::move(s)) {}
};

std::string convert(int quantity, double value, std::vector<Quantity>& quantities, bool cgs_to_si);