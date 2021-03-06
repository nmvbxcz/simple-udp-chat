#include "cipher.h"
#include <ctype.h>

std::string cipher::encrypt(std::string _inputStr, int _offset) {
	std::string reversedStr = "";

	char aLetter = 'a', zLetter = 'z';
	bool isLetter;
	for (size_t i = 0; i < _inputStr.size(); i++){
		isLetter = false;
		char currChar = _inputStr[i];
		if (islower(currChar)){
			aLetter = 'a';
			zLetter = 'z';
			isLetter = true;
		} else if (isupper(currChar)){
			aLetter = 'A';
			zLetter = 'Z';
			isLetter = true;
		}
		if (isLetter){
			currChar = currChar + _offset;
			currChar = bound(currChar, aLetter, zLetter);
		}
		reversedStr += currChar;
	}

	return reversedStr;
}

std::string cipher::decrypt(std::string _inputStr, int _offset) {
	return encrypt(_inputStr, -_offset);
}

char cipher::bound(char _charToCheck, char _left, char _right){
	if (_charToCheck > _right){
		_charToCheck = _left + (_charToCheck - _right) - 1;
	} else if (_charToCheck < _left){
		_charToCheck = _right - (_left - _charToCheck) + 1;
	}
	return _charToCheck;
}
