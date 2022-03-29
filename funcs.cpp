#include <iostream>
#include "funcs.h"

// add functions here

//shiftChar which is used in the encryption of the Caesar cipher
char shiftChar(char c, int rshift){
    for (int i = 1; i <= rshift; i++){
        if (isalpha(c)){ //check if the character is a letter first
            if (c == 'z' || c == 'Z'){
                if (c == 'z'){
                    c = 'a';
                
                }
                else if (c == 'Z'){
                    c = 'A';
                
                }
            }
            else {
            c = c + 1; //add 1 will shift the current letter to the next in the alphabet (ex: 'a' to 'b' or 'e' to 'f)
            }
        }
        else { // if the character is a white space or other symbols like ! . , it will stay itself since the shift doesn't affect it
            c = c;
        }

    }
    
    return c;

}

std::string encryptCaesar(std::string plaintext, int rshift){
    std::string resultStr = ""; //empty string
    for (int i = 0; i < plaintext.length(); i++){
        char c = plaintext[i];
        char newC = shiftChar(c, rshift);
        resultStr += newC;
    }

    return resultStr;
}

//calculate the distance between 2 vectors (one of the params is the eng lang frequencies)
double distance(double v1[], double v2[], int len){
    //the distance is the square root of the sum of squares differences
    //subtract the values of both arrays at the same index, then square it and add it to the total
    double total = 0;
    for (int i = 0; i < len; i++){
        double square = pow( (v1[i] - v2[i]), 2 ); // pow(a,b) == a^b (we have to put the difference sqaured)
        total += square;
    }    
    double result = sqrt(total);
    return result;
}

//return index of found elent
int indexOfLetter(char letter){
    int upperLetters[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int lowerLetters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    
    int result; //holds the index
    
    for (int i = 0; i < 26; i++){
        if (isupper(letter)){
            if (letter == upperLetters[i]){
                result = i;
            }

        }
        else if (islower(letter)){
            if (letter == lowerLetters[i]){
                result = i;
            }
        }
        
    }

    return result;
    
}

//decode the parameter encrypted_string that has been encrypted using the Caesar cipher
std::string solve(std::string encrypted_string){
    std::string decoded = "";

    // array for the english language frequencies (taken from cs.wellesley.edu)

    // 0.082 is A (where A appears 8.2% of the time), 0.015 is B, ... 0.001 is Z 
    double eng_frequencies[26] = {0.082, 0.015, 0.028, 0.043, 0.127, 0.022, 0.020, 0.061, 0.070, 0.002, 0.008, 0.040, 0.024, 0.068, 0.075, 0.019, 0.001, 0.060, 0.063, 0.091, 0.028, 0.010, 0.024, 0.002, 0.020, 0.001};

    //calc the frequency of each letter in the encrypted_string
    int length = 0;
    double freqCount[26] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    for (int i = 0; i < encrypted_string.length(); i++){
        
        //total up the number of letters, taking into account uppercase and lowercase letters
        char letter = encrypted_string[i];
        if (isalpha(letter)){
            length++; //counts the letters w/o spaces or symbols
            int placement = indexOfLetter(letter);
            //now we found the index of where to place the letter, add 1 into the index of the letter to count that 1 is found
            freqCount[placement] = freqCount[placement] + 1.0; //add 1
        }

    }
    //calculate the frequency now that the array has the number of letters in its correct index
    for (int i = 0; i < 26; i++){
        std::cout << freqCount[i]/length << std::endl;
    }
    


    return decoded;
}

