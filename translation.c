//Emmeline Pearson - CF Lab 11/12/2018 
//translated Sovitsky golay and convolution 

//libraries 
#include "softwareSerial.h"


//pin declaration 
int gpio1 = 8; //I/O pins - 2 instead of previous 4 
int gpio2 = 9; 
int txPin = 6; //LCD control


//globals and constants
const int lcddelay = 10; //10 millisecodns 
SoftwareSerial lcd = softwareSerial(0, txPin); 

//----LCD helper methods-------
void lcdPositions(){ 
    lcd.write(0x01); //hex for fist position
    lcd.write(0x09);
    lcd.write(0x0A); 
    delay(lcddelay); 
}
void clearLacd(){ 
    lcd.write(0x01); 
    lcd.write(0x0C); 
    delay(lcddelay); 
}
void backlightOn(){ 
    lcd.write(0x0E); 
    lcd.write(157);//high contrast backlight 
    delay(lacddelay); 
}
void bigFont(){ 
    lcd.write(0x1B); 
    lcd.write(0x69); 
    delay(lcddelay); 
}
void lcdStart(){ 
    clearLcd(); 
    backLightOn(); 
    bigFont(); 
    lcdPosition(); 
}
//---void @ Return--End LCD helper methods-----







//--------Data Collection-----
struct voltReadings;


//---@Return voltReadings contains potentiometer readings








//-------Data Processing----------------

//sgolay filter coefficients = MATLAB: G(:,2)
struct golayKernel{float -0.2000; -0.1000; 0.000; 0.1000; 0.200;}; 

struct first_Ord_Data; 
int i, j; 
int sampleCount = sizeOf(voltReadings); 
int kernelCount = sizeOf(golayKernel); 

//----1d convolution method---- 
for(i = 0; i < sampleCount; i++){ 
    first_Ord_Data[i] = 0; //set to zero before sum (should be default)
    for(j = 0; j < kernelCount; j++){ 
        first_Ord_Data[i] += voltageReadings[i-j] * golayKernel[j]; //convolve: multiply and accumulate 
    }

}

//---@Return concentration value from titration & processing 



//main method? 
