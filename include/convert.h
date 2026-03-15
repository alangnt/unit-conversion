#pragma once

#include <format>
#include <string>
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

  std::string convert(double value, bool cgs_to_si) {
    double converted_value;
    if (cgs_to_si) converted_value = value / conversion_factor;
    else converted_value = value * conversion_factor;

    return (std::format("{:.2f}", converted_value) + " " + 
      (cgs_to_si ? si.unit_name : cgs.unit_name));
  }
};