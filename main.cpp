/*
Emmy Veselinov
CSCI 135 Cipher Lab w/ Rotations
*/

#include <iostream>
#include <string>

#include "funcs.h"

int main(){
  std::string msg1 = "This is a very important message, alert the captain!";
  std::string cipherMsg1 = encryptCaesar(msg1, 8);
  std::cout << "Encrypted Cipher Text: " << cipherMsg1 << std::endl;
  std::string decode1 = solve(cipherMsg1);
  std::cout << "Decoded Text: " << decode1 << std::endl;
  std::cout << "\n===================================\n";

  std::string msg2 = "The rocket ship launches at 5:01pm. Get ready.";
  std::string cipherMsg2 = encryptCaesar(msg2, 17);
  std::cout << "Encrypted Cipher Text: " << cipherMsg2 << std::endl;
  std::string decode2 = solve(cipherMsg2);
  std::cout << "Decoded Text: " << decode2 << std::endl;
  std::cout << "\n===================================\n";

  std::string msg3 = "Meet me at the corner of Park Avenue";
  std::string cipherMsg3 = encryptCaesar(msg3, 5);
  std::cout << "Encrypted Cipher Text: " << cipherMsg3 << std::endl;
  std::string decode3 = solve(cipherMsg3);
  std::cout << "Decoded Text: " << decode3 << std::endl;
  std::cout << "\n===================================\n";



  return 0;
}
