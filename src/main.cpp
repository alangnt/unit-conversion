#include "convert.h"
#include <iostream>
#include <vector>

// SI to CGS - CGS to SI

double input_user_value() {
  double value;

  while (true) {
    std::cout << "Enter a value: ";
    std::cin >> value;
    if (value > 0) {
      break;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Your answer should be over 0, try again." << std::endl;
  }

  return value;
}

int input_user_choice(int choicesSize) {
  int choice;

  while (true) {
    std::cout << "Enter a value (1-" << choicesSize << "): ";
    std::cin >> choice;
    // if max, checks if > min and <= max otherwies only checks if > min
    if (choice > 0 && choice <= choicesSize) {
      break;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Your answer should be 1-" << choicesSize << ", try again." << std::endl;
    std::cout << "Enter a value: ";
  }

  return choice;
}

int main() {
  std::vector<Quantity> quantities;
  quantities.emplace_back("Length",       1e2,  "cm", "m");         // Length (l)
  quantities.emplace_back("Mass",         1e3,  "g", "kg");         // Mass (m)
  quantities.emplace_back("Time",         1,    "s", "s");          // Time (t)
  quantities.emplace_back("Force",        1e5,  "dyn", "N");        // Force (F)
  quantities.emplace_back("Energy, Work", 1e7,  "Erg", "J");        // Energy, Work (E, A)
  quantities.emplace_back("Power",        1e7,  "Erg/s", "W");      // Power (P)
  quantities.emplace_back("Pressure",     10,   "dyn/cm^2", "Pa");  // Pressure (p)

  while (true) {
    std::cout << "Select what type of conversion:" << std::endl;
    std::cout << "1. CGS -> SI" << std::endl;
    std::cout << "2. SI -> CGS" << std::endl;

    int system = input_user_choice(2);

    std::cout << "Select what do you want to convert:" << std::endl;
    for (int i = 0; i < quantities.size(); i++) {
      std::cout << i + 1 << ". " << quantities[i].getName() 
        << std::format(" ({})", 
          (system == 1 ? quantities[i].getCgs().unit_name + " -> " + quantities[i].getSi().unit_name 
            : quantities[i].getSi().unit_name + " -> " + quantities[i].getCgs().unit_name)) << std::endl;
    }

    int quantity = input_user_choice(quantities.size());

    double value = input_user_value();

    std::string converted_value;

    if (system == 1) {
      converted_value = quantities[quantity - 1].convert(value, Quantity::Direction::CGS_TO_SI);
    } else {
      converted_value = quantities[quantity - 1].convert(value, Quantity::Direction::SI_TO_CGS);
    }
    std::cout << "Converted value: " << converted_value << std::endl;

    char start_again;
    while (true) {
      std::cout << "Would you like to convert another value ? (y/n): ";
      std::cin >> start_again;

      if (start_again == 'y' || start_again == 'n') {
        break;
      }
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      std::cout << "Your answer should be y or n, try again." << std::endl;
      std::cout << "Enter a value: ";
    }

    if (start_again == 'n') break;
  }
  return 0;
}