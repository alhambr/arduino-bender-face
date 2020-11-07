#define M_WIDTH 16             // ширина матрицы
#define M_HEIGHT 16            // высота матрицы

#define ORDER_GRB       // порядок цветов ORDER_GRB / ORDER_RGB / ORDER_BRG
#define COLOR_DEBTH 2   // цветовая глубина: 1, 2, 3 (в байтах)
// на меньшем цветовом разрешении скетч будет занимать в разы меньше места,
// но уменьшится и количество оттенков и уровней яркости!

// ВНИМАНИЕ! define настройки (ORDER_GRB и COLOR_DEBTH) делаются до подключения библиотеки!
#include <microLED.h>
#define LED_PIN 6       // пин ленты

#define NUM_LEDS M_WIDTH * M_HEIGHT
LEDdata leds[NUM_LEDS];  // буфер ленты типа LEDdata

microLED matrix(leds, LED_PIN, M_WIDTH, M_HEIGHT, ZIGZAG, LEFT_BOTTOM, DIR_RIGHT);

void setup() {
  Serial.begin(9600);
  matrix.setBrightness(5);  // яркость (0-255)
  matrix.fill(mRGB(0, 0, 0));
  matrix.show();
  delay(2000);
  initMatrix();
  delay(1000);
  matrix.clear();
}

void loop() {
    drawBenderFace();
    matrix.show();
    delay(1000);
    drawBenderFaceSquinted();
    matrix.show();
    delay(1000);
    drawBenderFaceSquintedLeft();
    matrix.show();
    delay(1000);
    drawBenderFaceSquinted();
    matrix.show();
    delay(1000);
    drawBenderFaceSquintedRight();
    matrix.show();
    delay(1000);
    drawBenderFaceSquinted();
    matrix.show();
    delay(1000);
}


void initMatrix() {
  for (byte y = 0; y < M_HEIGHT; y++) {
    if (y % 2 == 0) {
      for (byte x = 0; x < M_WIDTH; x++) {
        matrix.setPix(x, y, mRGB(random(0, 255), random(0, 255), random(0, 255)));
        matrix.show();
        delay(3);
      }
    } else {
      byte xx = 0;
      for (byte x = 0; x < M_WIDTH; x++) {
        xx = map(x, 0, 15, 15, 0);
        matrix.setPix(xx, y, mRGB(random(0, 255), random(0, 255), random(0, 255)));
        matrix.show();
        delay(3);
      }
    }
  }

//  for(byte y = 5; y <= 10; y++) {
//    matrix.setPix(1, y, mRGB(142, 161, 179));
//    matrix.setPix(2, y, mRGB(142, 161, 179));
//
//    matrix.setPix(4, y, mRGB(142, 161, 179));
//    matrix.setPix(5, y, mRGB(142, 161, 179));
//
//    matrix.setPix(7, y, mRGB(142, 161, 179));
//    matrix.setPix(8, y, mRGB(142, 161, 179));
//
//    matrix.setPix(10, y, mRGB(142, 161, 179));
//    matrix.setPix(11, y, mRGB(142, 161, 179));
//
//    matrix.setPix(13, y, mRGB(142, 161, 179));
//    matrix.setPix(14, y, mRGB(142, 161, 179));
//  }
//  matrix.show();
//  delay(500);
//  for(byte z = 0; z<255;z++) {
//    loading();
//    delay(50);
//  }


 
}

//
//void loading() {
//  // сдвигаем всё вниз
//  for (byte x = 0; x < M_WIDTH; x++) {
//    for (byte y = 0; y < M_HEIGHT - 1; y++) {
//      // красим пиксель цветом верхнего над ним
//      matrix.setPix(x, y, matrix.getColor(x-1, y-1));
//    }
//  }
//  matrix.show();
//}

void drawBender() {
  matrix.fill(mRGB(142, 161, 179));

  for (byte y = 8; y <= 14; y++) {
    for (byte x = 1; x <= 14; x++) {
      matrix.setPix(x, y, mRGB(0, 0, 0));
    }
  }

  matrix.setPix(1, 8, mRGB(142, 161, 179));
  matrix.setPix(1, 14, mRGB(142, 161, 179));
  matrix.setPix(14, 8, mRGB(142, 161, 179));
  matrix.setPix(14, 14, mRGB(142, 161, 179));

matrix.setPix(0, 0, mRGB(0, 0, 0));
matrix.setPix(0, 15, mRGB(0, 0, 0));
matrix.setPix(15, 0, mRGB(0, 0, 0));
matrix.setPix(15, 15, mRGB(0, 0, 0));
  
}

void drawBenderFace() {
  drawBender();

  //левый глаз
  matrix.setPix(2, 10, mRGB(254, 251, 184));
  matrix.setPix(2, 11, mRGB(254, 251, 184));
  matrix.setPix(2, 12, mRGB(254, 251, 184));
  
  matrix.setPix(3, 9, mRGB(254, 251, 184));
  matrix.setPix(3, 10, mRGB(254, 251, 184));
  matrix.setPix(3, 11, mRGB(254, 251, 184));
  matrix.setPix(3, 12, mRGB(254, 251, 184));
  matrix.setPix(3, 13, mRGB(254, 251, 184));
  
  matrix.setPix(4, 9, mRGB(254, 251, 184));
  matrix.setPix(4, 10, mRGB(254, 251, 184));
  matrix.setPix(4, 11, mRGB(0, 0, 0));
  matrix.setPix(4, 12, mRGB(254, 251, 184));
  matrix.setPix(4, 13, mRGB(254, 251, 184));
 
  matrix.setPix(5, 9, mRGB(254, 251, 184));
  matrix.setPix(5, 10, mRGB(254, 251, 184));
  matrix.setPix(5, 11, mRGB(254, 251, 184));
  matrix.setPix(5, 12, mRGB(254, 251, 184));
  matrix.setPix(5, 13, mRGB(254, 251, 184));

  matrix.setPix(6, 10, mRGB(254, 251, 184));
  matrix.setPix(6, 11, mRGB(254, 251, 184));
  matrix.setPix(6, 12, mRGB(254, 251, 184));

  //правый глаз
  matrix.setPix(9, 10, mRGB(254, 251, 184));
  matrix.setPix(9, 11, mRGB(254, 251, 184));
  matrix.setPix(9, 12, mRGB(254, 251, 184));
  
  matrix.setPix(10, 9, mRGB(254, 251, 184));
  matrix.setPix(10, 10, mRGB(254, 251, 184));
  matrix.setPix(10, 11, mRGB(254, 251, 184));
  matrix.setPix(10, 12, mRGB(254, 251, 184));
  matrix.setPix(10, 13, mRGB(254, 251, 184));
  
  matrix.setPix(11, 9, mRGB(254, 251, 184));
  matrix.setPix(11, 10, mRGB(254, 251, 184));
  matrix.setPix(11, 12, mRGB(0, 0, 0));
  matrix.setPix(11, 12, mRGB(254, 251, 184));
  matrix.setPix(11, 13, mRGB(254, 251, 184));
 
  matrix.setPix(12, 9, mRGB(254, 251, 184));
  matrix.setPix(12, 10, mRGB(254, 251, 184));
  matrix.setPix(12, 11, mRGB(254, 251, 184));
  matrix.setPix(12, 12, mRGB(254, 251, 184));
  matrix.setPix(12, 13, mRGB(254, 251, 184));

  matrix.setPix(13, 10, mRGB(254, 251, 184));
  matrix.setPix(13, 11, mRGB(254, 251, 184));
  matrix.setPix(13, 12, mRGB(254, 251, 184));

  drawMouth();
  
}

void drawBenderFaceSquinted() {
  drawBender();

  //левый глаз
  matrix.setPix(2, 10, mRGB(254, 251, 184));
  matrix.setPix(2, 11, mRGB(254, 251, 184));
  matrix.setPix(2, 12, mRGB(254, 251, 184));
  

  matrix.setPix(3, 10, mRGB(254, 251, 184));
  matrix.setPix(3, 11, mRGB(254, 251, 184));
  matrix.setPix(3, 12, mRGB(254, 251, 184));
  
  matrix.setPix(4, 10, mRGB(254, 251, 184));
  matrix.setPix(4, 12, mRGB(0, 0, 0));
  matrix.setPix(4, 12, mRGB(254, 251, 184));
 
  matrix.setPix(5, 10, mRGB(254, 251, 184));
  matrix.setPix(5, 11, mRGB(254, 251, 184));
  matrix.setPix(5, 12, mRGB(254, 251, 184));

  matrix.setPix(6, 10, mRGB(254, 251, 184));
  matrix.setPix(6, 11, mRGB(254, 251, 184));
  matrix.setPix(6, 12, mRGB(254, 251, 184));

  //правый глаз
  matrix.setPix(9, 10, mRGB(254, 251, 184));
  matrix.setPix(9, 11, mRGB(254, 251, 184));
  matrix.setPix(9, 12, mRGB(254, 251, 184));
  
  matrix.setPix(10, 10, mRGB(254, 251, 184));
  matrix.setPix(10, 11, mRGB(254, 251, 184));
  matrix.setPix(10, 12, mRGB(254, 251, 184));
  
  matrix.setPix(11, 10, mRGB(254, 251, 184));
  matrix.setPix(11, 11, mRGB(0, 0, 0));
  matrix.setPix(11, 12, mRGB(254, 251, 184));
 
  matrix.setPix(12, 10, mRGB(254, 251, 184));
  matrix.setPix(12, 11, mRGB(254, 251, 184));
  matrix.setPix(12, 12, mRGB(254, 251, 184));
 
  matrix.setPix(13, 10, mRGB(254, 251, 184));
  matrix.setPix(13, 11, mRGB(254, 251, 184));
  matrix.setPix(13, 12, mRGB(254, 251, 184));

  drawMouth();
  
}

void drawBenderFaceSquintedLeft() {
  drawBender();

  matrix.setPix(1, 8, mRGB(142, 161, 179));
  matrix.setPix(1, 14, mRGB(142, 161, 179));
  matrix.setPix(14, 8, mRGB(142, 161, 179));
  matrix.setPix(14, 14, mRGB(142, 161, 179));

  //левый глаз
  matrix.setPix(2, 10, mRGB(254, 251, 184));
  matrix.setPix(2, 11, mRGB(254, 251, 184));
  matrix.setPix(2, 12, mRGB(254, 251, 184));
  

  matrix.setPix(3, 10, mRGB(254, 251, 184));
  matrix.setPix(3, 11, mRGB(0, 0, 0));
  matrix.setPix(3, 12, mRGB(254, 251, 184));
  
  matrix.setPix(4, 10, mRGB(254, 251, 184));
  matrix.setPix(4, 11, mRGB(254, 251, 184));
  matrix.setPix(4, 12, mRGB(254, 251, 184));
 
  matrix.setPix(5, 10, mRGB(254, 251, 184));
  matrix.setPix(5, 11, mRGB(254, 251, 184));
  matrix.setPix(5, 12, mRGB(254, 251, 184));

  matrix.setPix(6, 10, mRGB(254, 251, 184));
  matrix.setPix(6, 11, mRGB(254, 251, 184));
  matrix.setPix(6, 12, mRGB(254, 251, 184));

  //правый глаз
  matrix.setPix(9, 10, mRGB(254, 251, 184));
  matrix.setPix(9, 11, mRGB(254, 251, 184));
  matrix.setPix(9, 12, mRGB(254, 251, 184));
  
  matrix.setPix(10, 10, mRGB(254, 251, 184));
  matrix.setPix(10, 11, mRGB(0, 0, 0));
  matrix.setPix(10, 12, mRGB(254, 251, 184));
  
  matrix.setPix(11, 10, mRGB(254, 251, 184));
  matrix.setPix(11, 11, mRGB(254, 251, 184));
  matrix.setPix(11, 12, mRGB(254, 251, 184));
 
  matrix.setPix(12, 10, mRGB(254, 251, 184));
  matrix.setPix(12, 11, mRGB(254, 251, 184));
  matrix.setPix(12, 12, mRGB(254, 251, 184));
 
  matrix.setPix(13, 10, mRGB(254, 251, 184));
  matrix.setPix(13, 11, mRGB(254, 251, 184));
  matrix.setPix(13, 12, mRGB(254, 251, 184));

  drawMouth();
  
}

void drawBenderFaceSquintedRight() {
  drawBender();

  //левый глаз
  matrix.setPix(2, 10, mRGB(254, 251, 184));
  matrix.setPix(2, 11, mRGB(254, 251, 184));
  matrix.setPix(2, 12, mRGB(254, 251, 184));
  

  matrix.setPix(3, 10, mRGB(254, 251, 184));
  matrix.setPix(3, 11, mRGB(254, 251, 184));
  matrix.setPix(3, 12, mRGB(254, 251, 184));
  
  matrix.setPix(4, 10, mRGB(254, 251, 184));
  matrix.setPix(4, 11, mRGB(254, 251, 184));
  matrix.setPix(4, 12, mRGB(254, 251, 184));
 
  matrix.setPix(5, 10, mRGB(254, 251, 184));
  matrix.setPix(5, 11, mRGB(0, 0, 0));
  matrix.setPix(5, 12, mRGB(254, 251, 184));

  matrix.setPix(6, 10, mRGB(254, 251, 184));
  matrix.setPix(6, 11, mRGB(254, 251, 184));
  matrix.setPix(6, 12, mRGB(254, 251, 184));

  //правый глаз
  matrix.setPix(9, 10, mRGB(254, 251, 184));
  matrix.setPix(9, 11, mRGB(254, 251, 184));
  matrix.setPix(9, 12, mRGB(254, 251, 184));
  
  matrix.setPix(10, 10, mRGB(254, 251, 184));
  matrix.setPix(10, 11, mRGB(254, 251, 184));
  matrix.setPix(10, 12, mRGB(254, 251, 184));
  
  matrix.setPix(11, 10, mRGB(254, 251, 184));
  matrix.setPix(11, 11, mRGB(254, 251, 184));
  matrix.setPix(11, 12, mRGB(254, 251, 184));
 
  matrix.setPix(12, 10, mRGB(254, 251, 184));
  matrix.setPix(12, 11, mRGB(0, 0, 0));
  matrix.setPix(12, 12, mRGB(254, 251, 184));
 
  matrix.setPix(13, 10, mRGB(254, 251, 184));
  matrix.setPix(13, 11, mRGB(254, 251, 184));
  matrix.setPix(13, 12, mRGB(254, 251, 184));

  drawMouth();
  
}

void drawMouth() {

  for (byte y = 1; y <= 6; y++) {
    for (byte x = 2; x <= 13; x++) {
      matrix.setPix(x, y, mRGB(0, 0, 0));
    }
  }
  
  for (byte y = 2; y <= 5; y++) {
    for (byte x = 3; x <= 12; x++) {
      matrix.setPix(x, y, mRGB(254, 251, 184));
    }
  }
  matrix.setPix(2, 6, mRGB(142, 161, 179));
  matrix.setPix(2, 1, mRGB(142, 161, 179));
  matrix.setPix(13, 1, mRGB(142, 161, 179));
  matrix.setPix(13, 6, mRGB(142, 161, 179));

  matrix.setPix(3, 2, mRGB(0, 0, 0));
  matrix.setPix(3, 5, mRGB(0, 0, 0));
  matrix.setPix(12, 2, mRGB(0, 0, 0));
  matrix.setPix(12, 5, mRGB(0, 0, 0));
  
}
