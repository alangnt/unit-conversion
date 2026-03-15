#include "convert.h"
#include <string>
#include <vector>

std::string convert(int quantity, double value, std::vector<Quantity>& quantities, bool cgs_to_si) {
  if (quantity <= 0 || quantity > quantities.size()) return "No value";

  double converted_value;
  if (cgs_to_si) converted_value = value / quantities[quantity - 1].conversion_factor;
  else converted_value = value * quantities[quantity - 1].conversion_factor;

  return (std::to_string(converted_value) + " " + (cgs_to_si 
    ? quantities[quantity - 1].si.unit_name : quantities[quantity - 1].cgs.unit_name));
}