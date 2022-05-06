/*
Module: distance_hcsr04.ino
Function:
        To measure the distance between an object and source using Arduino MEGA board and Ultrasonic sensor HC-SR04
Copyright notice:
        This file copyright (C) 2022 by
        MCCI Corporation
        3520 Krums Corners Road
        Ithaca, NY 14850
        An unpublished work. All rights reserved.
        This file is proprietary information, and may not be disclosed or
        copied without the prior permission of MCCI Corporation.
Author:
        Pranau R, MCCI Corporation   May 2022
*/

#include <HCSR04.h>

HCSR04 hc(11, 12);
int distance;

void setup()
  {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  }

void loop()
  {
  distance = hc.dist();
  Serial.print(distance);
  Serial.println(" cm");

  int count = 0;

  if (distance < 10)
    {
    while (count <= 9)
      {
      digitalWrite(LED_BUILTIN, HIGH);
      delay (450);
      digitalWrite(LED_BUILTIN, LOW);
      delay (150);
      ++count;
      }
    }
  else if (distance > 10 & distance < 30)
    {
    while (count <= 5)
      {
      digitalWrite(LED_BUILTIN, HIGH);
      delay (500);
      digitalWrite(LED_BUILTIN, LOW);
      delay (500);
      ++count;
      }
    }
  else
    {
    while (count <= 2)
      {
      digitalWrite(LED_BUILTIN, HIGH);
      delay (500);
      digitalWrite(LED_BUILTIN, LOW);
      delay (1500);
      ++count;
      }
    }
   delay (4000);
  }
