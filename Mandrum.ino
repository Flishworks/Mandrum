#include <CapacitiveSensor.h>

/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 */


//pin two is flipper (send pin)
 CapacitiveSensor snare = CapacitiveSensor(2,7);   
 CapacitiveSensor hat = CapacitiveSensor(2,8);        
 CapacitiveSensor crash = CapacitiveSensor(2,9);     
 CapacitiveSensor kick= CapacitiveSensor(2,10);    
 long lastTotalSnare;
 long lastTotalKick;
 long lastTotalCrash;
 long lastTotalHat;
 long i;


void setup()                    
{
   //snare.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   Serial.begin(9600);
}

void loop()                    
{
    i++;
    if (i%1000==0){
      snare.reset_CS_AutoCal();
      hat.reset_CS_AutoCal();
      kick.reset_CS_AutoCal();
      crash.reset_CS_AutoCal();
    }
    //long start = millis();
    long totalSnare =  snare.capacitiveSensor(60);
    long totalHat =  hat.capacitiveSensor(60);
    long totalCrash =  crash.capacitiveSensor(60);
    long totalKick =  kick.capacitiveSensor(60);
    if (totalSnare>(lastTotalSnare+1)*5){
      Serial.print(1);
    }
      if (totalHat>(lastTotalHat+1)*5){
      Serial.print(2);
    }
      if (totalCrash>(lastTotalCrash+1)*5){
      Serial.print(3);
    }
      if (totalKick>(lastTotalKick+1)*5){
      Serial.print(4);
    }
    
//    Serial.print(millis() - start);        // check on performance in milliseconds
//    Serial.print("\t");                    // tab character for debug windown spacing
//
//    Serial.println(totalSnare);
//    Serial.print("\t");
//    Serial.print(totalHat);
//    Serial.print("\t");
//    Serial.print(totalCrash);
//    Serial.print("\t");
//    Serial.print(totalKick);
//    Serial.print("\t");
//
//    Serial.println();
      lastTotalSnare=totalSnare;
      lastTotalKick=totalKick;
      lastTotalCrash=totalCrash;
      lastTotalHat=totalHat;
    delay(5);                             // arbitrary delay to limit data to serial port 
    
}
