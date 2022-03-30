#include <iostream>
#include "funcs.h"
#include <cfloat> // DBL_MAX --> max finite double number 
#include <cmath>

// add functions here

// shiftChar which is used in the encryption of the Caesar cipher
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

// calculate the distance between 2 vectors (one of the params is the eng lang frequencies)
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

// return index of found element in the alphabet
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

// shifts the string 1 character forward (used for the 26 rotations)
std::string shiftString(std::string string){
    std::string newStr = "";
    for (int i = 0; i < string.length(); i++){
        newStr += shiftChar(string[i], 1);
    } 

    return newStr;
}


// decode the parameter encrypted_string that has been encrypted using the Caesar cipher
std::string solve(std::string encrypted_string){
    std::string decoded;
    
    //arrays to later access the rotation
    double allMin[26];
    std::string allEncrypted[26];

    // array for the english language frequencies (taken from cs.wellesley.edu)

    // 0.082 is A (where A appears 8.2% of the time), 0.01492 is B, ... 0.00074 is Z 
    double eng_frequencies[26] = {0.08167, 0.01492, 0.02782, 0.04253, 0.12702, 0.02228, 0.02015, 0.06094, 0.06966, 0.00153, 0.00772, 0.04025, 0.02406, 0.06749, 0.07507, 0.01929, 0.00095, 0.05987, 0.06327, 0.09056, 0.02758, 0.00978, 0.02360, 0.00150, 0.01974, 0.00074};


    // //////26 rotations//////

    double min = DBL_MAX; //the largest double value that a type double can have
    int pos = 0;
    for (int i = 0; i < 26; i++){

        //std::cout << encrypted_string << std::endl;

        //for each rotation: 1. calc freq vec for the rotation 2. calc distance between eng and freq vec

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

            double calc = freqCount[i]/length;
            freqCount[i] = calc;
        }

        //calculate the distance between english and freqCount frequencies
        //double min = DBL_MAX; //the original min --> the largest double value that a type double can have

        double disBetween = distance(eng_frequencies, freqCount, 26);

        //int pos = 0;
        if (disBetween < min){
            min = disBetween;
            
            //add that min to a int array and add the encrypted string into the same index in a string array
            //so later when we have the minimum of all distances we can match up the min index with the encrypted string

            allMin[pos] = min;
            allEncrypted[pos] = encrypted_string;
            pos++; //increase position by 1 so the index moves by one for the next min and string to be added
        }

        encrypted_string = shiftString(encrypted_string); //shifts the entire string by 1 char

    }

    int result;
    //find the index of the min in the array
    for (int i = 0; i < 26; i++){
        
        if (min == allMin[i]){
            result = i;
        }
    }
    
    //access the rotation that has the same index as min
    decoded = allEncrypted[result];
    

    return decoded;
}


// some notes:
// take the encoded string --> calculate the frequency of each letter and add that to an array (letters that are not in the string will have a value of 0.0)
// calculate the distance between the english frequencies an the new array
// save that distance which will be updated with each rotation (thus holding the min)
// shift characters for each rotation by 1 char for each letter and do this for 26 rotations and save the smallest distance for each rotation