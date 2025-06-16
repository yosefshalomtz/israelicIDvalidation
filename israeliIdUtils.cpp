#include <iostream>
#include <string>

unsigned char UTILS_zipTheNumber_SumDigits(unsigned char num) {
	unsigned char sum = 0;
	while(num > 0) {
		sum += num%10;
		num /= 10;
	}
	return sum;
}
bool UTILS_isValidIsraelicId(std::string id) {
	if (id.length() != 9) return false;
	// check if id is number
	for (int i = 0; i < id.length(); i++) if (id[i] < '0' || id[i] > '9') return false;
	// convert 8 chars to numbers for calculate:
	unsigned char idDigits[8];
	for(int i=0;i<8;i++) idDigits[i] = (id[i] - '0');
	// duplicate in the whight
	for(int i = 0;i<8;i++) {idDigits[i] = idDigits[i] * ((i%2)+1);}
	// zip the number. for exemple: 12 => 3
	for (int i = 0; i < 8; i++)
	{
		if(idDigits[i]>9) idDigits[i] = UTILS_zipTheNumber_SumDigits(idDigits[i]);
	}
	// sum all
	unsigned char checkSum = 0;
	for (int i = 0; i < 8; i++) checkSum += idDigits[i];
	
	if((id[8]-'0')!=((10 - (checkSum%10))%10)) return false;

	return true;
}
