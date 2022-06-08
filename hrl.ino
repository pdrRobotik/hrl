#include <FtduinoSimple.h>
#include <AccessNode.h>

RobotikInterConnect *ric;

// M1=links/rechts
// M2=hoch/runter
// M3=vor/zurück
// I1=arm unten
// I2=arm oben
// I3=arm vorne
// I4=arm hinten
// I5=greifer unten
// I6=taster ganz rechts


void setup()
{
  ric = new RobotikInterConnect("hrl");

  ftduino.motor_set(Ftduino::M3, Ftduino::LEFT); // arm komplett einziehen
  while (!ftduino.input_get(Ftduino::I4))
    delay(1);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::RIGHT); // arm komplett nach rechts
  while (!ftduino.input_get(Ftduino::I6))
    delay(1);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M2, Ftduino::RIGHT); // arm komplett nach unten
  while (!ftduino.input_get(Ftduino::I1))
    delay(1);
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M2, Ftduino::LEFT); // arm fährt etwas hoch
  delay(1000);
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT); // arm fährt aus
  delay(10000);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);
}
void loop()
{
  ric->send("mfc", "websocket", "OK");
  int result = ric->read_wait().toInt();

  ftduino.motor_set(Ftduino::M4, Ftduino::LEFT);
  delay(1);
  ftduino.motor_set(Ftduino::M4, Ftduino::OFF);
  delay(1);

  switch (result)
  {
  case 00:
    fach0_einlagern();
    zur_annahme();
    break;
  case 01:
    fach1_einlagern();
    zur_annahme();
    break;
  case 02:
    fach2_einlagern();
    zur_annahme();
    break;
  case 03:
    fach3_einlagern();
    zur_annahme();
    break;
  case 04:
    fach4_einlagern();
    zur_annahme();
    break;
  case 05:
    fach5_einlagern();
    zur_annahme();
    break;
  case 10:
    fach0_auslagern();
    zur_ausgabe();
    go_back();
    break;
  case 11:
    fach1_auslagern();
    zur_ausgabe();
    go_back();
    break;
  case 12:
    fach2_auslagern();
    zur_ausgabe();
    go_back();
    break;
  case 13:
    fach3_auslagern();
    zur_ausgabe();
    go_back();
    break;
  case 14:
    fach4_auslagern();
    zur_ausgabe();
    go_back();
    break;
  case 15:
    fach5_auslagern();
    zur_ausgabe();
    go_back();
    break;
  }
}

void fach0_einlagern()
{
  ftduino.motor_set(Ftduino::M3, Ftduino::LEFT); // arm zieht etwas ein
  delay(5000);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M2, Ftduino::LEFT); // arm fährt komplett hoch
  while (!ftduino.input_get(Ftduino::I2))
    delay(1);
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);
}

void fach0_auslagern()
{
  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm zieht etwas ein
  delay(1);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt komplett hoch
  while (!ftduino.input_get(Ftduino::I1))
    delay(1);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt etwas runter
  delay(1);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);
}

void fach1_einlagern()
{
  int counter = 0;

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm zieht etwas ein
  delay(1);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt nach links
  while (counter < 1)
  {
    if (ftduino.input_get(Ftduino::I1))
      counter++;
    delay(1);
  }
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt komplett hoch
  while (!ftduino.input_get(Ftduino::I1))
    delay(1);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);
}

void fach1_auslagern()
{
  int counter = 0;

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm zieht etwas ein
  delay(1);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt nach links
  while (counter < 1)
  {
    if (ftduino.input_get(Ftduino::I1))
      counter++;
    delay(1);
  }
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt komplett hoch
  while (!ftduino.input_get(Ftduino::I1))
    delay(1);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt etwas runter
  delay(1);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);
}

void fach2_einlagern()
{
  int counter = 0;

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm zieht etwas ein
  delay(1);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt nach links
  while (counter < 2)
  {
    if (ftduino.input_get(Ftduino::I1))
      counter++;
    delay(1);
  }
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt komplett hoch
  while (!ftduino.input_get(Ftduino::I1))
    delay(1);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);
}

void fach2_auslagern()
{
  int counter = 0;

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm zieht etwas ein
  delay(1);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt nach links
  while (counter < 2)
  {
    if (ftduino.input_get(Ftduino::I1))
      counter++;
    delay(1);
  }
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt komplett hoch
  while (!ftduino.input_get(Ftduino::I1))
    delay(1);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt etwas runter
  delay(1);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);
}

void fach3_einlagern()
{
  int counter = 0;

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm zieht etwas ein
  delay(1);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt nach links
  while (counter < 3)
  {
    if (ftduino.input_get(Ftduino::I1))
      counter++;
    delay(1);
  }
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt komplett hoch
  while (!ftduino.input_get(Ftduino::I1))
    delay(1);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);
}

void fach3_auslagern()
{
  int counter = 0;

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm zieht etwas ein
  delay(1);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt nach links
  while (counter < 3)
  {
    if (ftduino.input_get(Ftduino::I1))
      counter++;
    delay(1);
  }
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt komplett hoch
  while (!ftduino.input_get(Ftduino::I1))
    delay(1);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt etwas runter
  delay(1);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);
}

void fach4_einlagern()
{
  int counter = 0;

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm zieht etwas ein
  delay(1);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt nach links
  while (counter < 1)
  {
    if (ftduino.input_get(Ftduino::I1))
      counter++;
    delay(1);
  }
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt komplett runter
  while (!ftduino.input_get(Ftduino::I1))
    delay(1);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt etwas hoch
  delay(1);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);
}

void fach4_auslagern()
{
  int counter = 0;

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm zieht etwas ein
  delay(1);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt nach links
  while (counter < 1)
  {
    if (ftduino.input_get(Ftduino::I1))
      counter++;
    delay(1);
  }
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt komplett runter
  while (!ftduino.input_get(Ftduino::I1))
    delay(1);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);
}

void fach5_einlagern()
{
  int counter = 0;

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm zieht etwas ein
  delay(1);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt nach links
  while (counter < 2)
  {
    if (ftduino.input_get(Ftduino::I1))
      counter++;
    delay(1);
  }
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt komplett runter
  while (!ftduino.input_get(Ftduino::I1))
    delay(1);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt etwas hoch
  delay(1);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);
}

void fach5_auslagern()
{
  int counter = 0;

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm zieht etwas ein
  delay(1);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt nach links
  while (counter < 2)
  {
    if (ftduino.input_get(Ftduino::I1))
      counter++;
    delay(1);
  }
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt komplett runter
  while (!ftduino.input_get(Ftduino::I1))
    delay(1);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);
}

void zur_annahme()
{
  ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT); // arm fährt komplett aus
  while (!ftduino.input_get(Ftduino::I5))
    delay(1);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M2, Ftduino::RIGHT); // arm fährt runter und legt box ab
  delay(2100);
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M3, Ftduino::LEFT); // arm fährt komplett ein
  while (!ftduino.input_get(Ftduino::I4))
    delay(1);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::RIGHT); // arm fährt komplett zurück
  while (!ftduino.input_get(Ftduino::I6))
    delay(1);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M2, Ftduino::RIGHT); // arm fährt komplett runter
  while (!ftduino.input_get(Ftduino::I1))
    delay(1);
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M2, Ftduino::LEFT); // arm fährt etwas hoch
  delay(1000);
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT); // arm fährt aus (zur annahme)
  delay(10000);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);
}

void zur_ausgabe()
{
  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt komplett aus
  while (!ftduino.input_get(Ftduino::I1))
    delay(1);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt hoch und greift box
  delay(100);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm zieht etwas ein
  delay(1);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt komplett nach links
  while (!ftduino.input_get(Ftduino::I1))
    delay(1);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt komplett hoch
  while (!ftduino.input_get(Ftduino::I1))
    delay(1);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt komplett aus
  while (!ftduino.input_get(Ftduino::I1))
    delay(1);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm zieht etwas ein
  delay(1);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt runter und legt box ab
  delay(100);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);
}

void go_back()
{
  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt komplett ein
  while (!ftduino.input_get(Ftduino::I1))
    delay(1);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt komplett zurück
  while (!ftduino.input_get(Ftduino::I1))
    delay(1);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt komplett runter (zur annahme)
  while (!ftduino.input_get(Ftduino::I1))
    delay(1);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt aus (zur annahme)
  delay(1);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);
}