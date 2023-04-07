/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   T3P_Team_Project.ino                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panoma <panoma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 21:06:23 by panoma            #+#    #+#             */
/*   Updated: 2023/04/07 23:37:58 by panoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Setup for This Code Need These Equipment
- Arduino UNO R3
- Motion Sensor Detector Module HC-SR501
- LDR Photoresistor Sensor Module
- Light Strip LED WS2812 5V RGB
-- LCD 20x4 with I2C Interface
Connect each device with these interface
UNO R3  -> Motion Sensor
5V      -> VCC
4       -> OUT
GND     -> GND
UNO R3  -> LDR
5V      -> VCC
GND     -> GND
A5      -> A0
UNO R3  -> Light Strip
5V      -> +5V
G       -> 10
R       -> 9
B       -> 11
*/

// define the pins for the LED strip
#define RED_PIN 9
#define GREEN_PIN 10
#define BLUE_PIN 11

// define function to turn on light each color
// LOW stands for on, HIGH stands for off in this situation
void red() {
  digitalWrite(RED_PIN, LOW);
  digitalWrite(BLUE_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  Serial.println("Red");
}

void blue() {
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(BLUE_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  Serial.println("Blue");
}

void green() {
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(BLUE_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  Serial.println("Green");
}

void white() {
  digitalWrite(RED_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  Serial.println("White");
}

void off() {
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(BLUE_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  Serial.println("Light Off");
}

void setup() {
  
  // initialize the LED pins as outputs
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  
  off();
  // initialize serial communication
  Serial.begin(9600);
  
}

void loop() {
  // get LightValue and MotionValue from LDR and Motion Sensor
  int LightValue = analogRead(A5);
  int MotionValue = digitalRead(4);
  
  // Print LightValue and MotionValue to Serial Monitor
  Serial.print("Light = "); 
  Serial.print(LightValue);
  if (LightValue > 800) {
  Serial.print("\tIT'S DARK NOW"); }
  Serial.print("\tMotion = "); 
  Serial.print(MotionValue);
  
  // Applying logic to turn on/off the light
  // Listen for LightValue at First Priority if It's Dark It's value will be more than 800
  // Then Look for MotionValue, If It will be 1 if motion is detected, It will be 0 if Motion not detected
  // If It's Dark (LightValue > 800) and Motion detected (MotionValue == 1) Turn Light on for 10 second and then off
  // PS. 800 Value is from our experiment and It's vary on the LDR
  if (LightValue > 800) {
    if (MotionValue == 1) {
      Serial.println();
      Serial.println("MOTION DETECTED : TURNING ON LIGHT");
      white();
      delay(10000);
      off();
    }
  }
  Serial.println();
  delay(10);
}
/*
███████╗███████╗    ██╗  ██╗███╗   ███╗██╗████████╗██╗          ██████╗  ██████╗ 
██╔════╝██╔════╝    ██║ ██╔╝████╗ ████║██║╚══██╔══╝██║         ██╔════╝ ██╔════╝ 
█████╗  █████╗      █████╔╝ ██╔████╔██║██║   ██║   ██║         ███████╗ ███████╗ 
██╔══╝  ██╔══╝      ██╔═██╗ ██║╚██╔╝██║██║   ██║   ██║         ██╔═══██╗██╔═══██╗
███████╗███████╗    ██║  ██╗██║ ╚═╝ ██║██║   ██║   ███████╗    ╚██████╔╝╚██████╔╝
╚══════╝╚══════╝    ╚═╝  ╚═╝╚═╝     ╚═╝╚═╝   ╚═╝   ╚══════╝     ╚═════╝  ╚═════╝   
*/