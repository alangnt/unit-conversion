#pragma once

#include <format>
#include <string>
#include <utility>

struct UnitSystem {
  std::string unit_name;

  UnitSystem(std::string name) : unit_name(std::move(name)) {}
};

class Quantity {
private:
  double conversion_factor;
  std::string name;
  UnitSystem cgs;
  UnitSystem si;

public:
  enum class Direction { CGS_TO_SI, SI_TO_CGS };

  Quantity(std::string n, double cf, std::string c, std::string s)
      : name(n), conversion_factor(cf), cgs(std::move(c)), si(std::move(s)) {}

  const std::string& getName() const { return name; }
  const UnitSystem& getCgs() const { return cgs; }
  const UnitSystem& getSi() const { return si; }

  std::string convert(double value, Direction direction) const {
    double converted_value;
    if (direction == Direction::CGS_TO_SI) converted_value = value / conversion_factor;
    else converted_value = value * conversion_factor;

    return (std::format("{:.2f}", converted_value) + " " +
            (direction == Direction::CGS_TO_SI ? si.unit_name : cgs.unit_name));
  }
};