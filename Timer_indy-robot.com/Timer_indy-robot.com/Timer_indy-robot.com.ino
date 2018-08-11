#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

unsigned long laptime = 0;
unsigned long starttime = 0;
boolean Trigger = true;

const int buttonPin = 2;

void setup() {  
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  
  clear_wait();                  
                          
  pinMode(buttonPin,INPUT_PULLUP);
  digitalWrite(13, HIGH);
}

void loop() {
    if(digitalRead(buttonPin)==0)
      {
          laptime = millis() - starttime;
          starttime = millis();
      
          if(Trigger == true)
            {
            clear_start();
            }
          if(Trigger != true)
            {
            print_time(); 
            }
      Trigger = false;  
      delay(500);
      }      
}

void clear_wait()
{
  display.clearDisplay();
  display.setTextSize(1);       
  display.setTextColor(WHITE);   
  display.setCursor(46,0);       
  display.print(" Timer ");
  display.setCursor(29,15);       
  display.print(" indy-robot ");
  display.setTextSize(3); 
  display.setCursor(30,30);       
  display.print("wait");
  display.setTextSize(1); 
  display.setCursor(50,55);       
  display.print(" sec ");
  display.display();  
  delay(500);
}

void clear_start()
{
  display.clearDisplay();
  display.setTextSize(1);       
  display.setTextColor(WHITE);   
  display.setCursor(46,0);       
  display.print(" Timer ");
  display.setCursor(29,15);       
  display.print(" indy-robot ");
  display.setTextSize(3); 
  display.setCursor(25,30);       
  display.print("Start");
  display.setTextSize(1); 
  display.setCursor(50,55);       
  display.print(" sec ");
  display.display();  
}

void print_time()
{
  display.clearDisplay();
  display.setTextSize(1);       
  display.setTextColor(WHITE);   
  display.setCursor(46,0);       
  display.print(" Timer ");
  display.setCursor(29,15);       
  display.print(" indy-robot ");
  display.setTextSize(3); 
  display.setCursor(0,30);       
  display.print(laptime/1000);
  display.print('.');
  display.print(laptime%1000);
  display.setTextSize(1); 
  display.setCursor(50,55);       
  display.print(" sec ");
  display.display();  
}


