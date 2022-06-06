#include <FtduinoSimple.h>
#include <AccessNode.h>

RobotikInterConnect *ric;

void setup()
{
  ric = new RobotikInterConnect("hrl");

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX);
  while (!ftduino.input_get(Ftduino::IX))
    delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX);
  while (!ftduino.input_get(Ftduino::IX))
    delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX);
  while (!ftduino.input_get(Ftduino::IX))
    delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);
}
void loop()
{
  ric->send("mfc", "websocket", "OK");
  int result = ric->read_wait().toInt();

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX);
  delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);
  delay(1);

  switch (result)
  {
  case 00:
    fach0_auslagern();
    zur_ausgabe();
    go_back();
    break;
  case 01:
    fach0_einlagern();
    zur_annahme();
    break;
  case 02:
    fach1_auslagern();
    zur_ausgabe();
    go_back();
    break;
  case 03:
    fach1_einlagern();
    zur_annahme();
    break;
  case 04:
    fach2_auslagern();
    zur_ausgabe();
    go_back();
    break;
  case 05:
    fach2_einlagern();
    zur_annahme();
    break;
  case 10:
    fach3_auslagern();
    zur_ausgabe();
    go_back();
    break;
  case 11:
    fach3_einlagern();
    zur_annahme();
    break;
  case 12:
    fach4_auslagern();
    zur_ausgabe();
    go_back();
    break;
  case 13:
    fach4_einlagern();
    zur_annahme();
    break;
  case 14:
    fach5_auslagern();
    zur_ausgabe();
    go_back();
    break;
  case 15:
    fach5_einlagern();
    zur_annahme();
    break;
  }
}

void fach0_einlagern()
{
  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm zieht etwas ein
  delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm fährt komplett hoch
  while (!ftduino.input_get(Ftduino::IX))
    delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);
}

void fach0_auslagern()
{
  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm zieht etwas ein
  delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm fährt komplett hoch
  while (!ftduino.input_get(Ftduino::IX))
    delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm fährt etwas runter
  delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);
}

void fach1_einlagern()
{
  int counter = 0;

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm zieht etwas ein
  delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm fährt nach links
  while (counter < 1)
  {
    if (ftduino.input_get(Ftduino::IX))
      counter++;
    delay(1);
  }
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm fährt komplett hoch
  while (!ftduino.input_get(Ftduino::IX))
    delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);
}

void fach1_auslagern()
{
  int counter = 0;

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm zieht etwas ein
  delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm fährt nach links
  while (counter < 1)
  {
    if (ftduino.input_get(Ftduino::IX))
      counter++;
    delay(1);
  }
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm fährt komplett hoch
  while (!ftduino.input_get(Ftduino::IX))
    delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm fährt etwas runter
  delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);
}

void fach2_einlagern()
{
  int counter = 0;

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm zieht etwas ein
  delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm fährt nach links
  while (counter < 2)
  {
    if (ftduino.input_get(Ftduino::IX))
      counter++;
    delay(1);
  }
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm fährt komplett hoch
  while (!ftduino.input_get(Ftduino::IX))
    delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);
}

void fach2_auslagern()
{
  int counter = 0;

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm zieht etwas ein
  delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm fährt nach links
  while (counter < 2)
  {
    if (ftduino.input_get(Ftduino::IX))
      counter++;
    delay(1);
  }
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm fährt komplett hoch
  while (!ftduino.input_get(Ftduino::IX))
    delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm fährt etwas runter
  delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);
}

void fach3_einlagern()
{
  int counter = 0;

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm zieht etwas ein
  delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm fährt nach links
  while (counter < 3)
  {
    if (ftduino.input_get(Ftduino::IX))
      counter++;
    delay(1);
  }
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm fährt komplett hoch
  while (!ftduino.input_get(Ftduino::IX))
    delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);
}

void fach3_auslagern()
{
  int counter = 0;

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm zieht etwas ein
  delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm fährt nach links
  while (counter < 3)
  {
    if (ftduino.input_get(Ftduino::IX))
      counter++;
    delay(1);
  }
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm fährt komplett hoch
  while (!ftduino.input_get(Ftduino::IX))
    delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm fährt etwas runter
  delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);
}

void fach4_einlagern()
{
  int counter = 0;

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm zieht etwas ein
  delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm fährt nach links
  while (counter < 1)
  {
    if (ftduino.input_get(Ftduino::IX))
      counter++;
    delay(1);
  }
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm fährt komplett runter
  while (!ftduino.input_get(Ftduino::IX))
    delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm fährt etwas hoch
  delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);
}

void fach4_auslagern()
{
  int counter = 0;

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm zieht etwas ein
  delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm fährt nach links
  while (counter < 1)
  {
    if (ftduino.input_get(Ftduino::IX))
      counter++;
    delay(1);
  }
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm fährt komplett runter
  while (!ftduino.input_get(Ftduino::IX))
    delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);
}

void fach5_einlagern()
{
  int counter = 0;

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm zieht etwas ein
  delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm fährt nach links
  while (counter < 2)
  {
    if (ftduino.input_get(Ftduino::IX))
      counter++;
    delay(1);
  }
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm fährt komplett runter
  while (!ftduino.input_get(Ftduino::IX))
    delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm fährt etwas hoch
  delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);
}

void fach5_auslagern()
{
  int counter = 0;

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm zieht etwas ein
  delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm fährt nach links
  while (counter < 2)
  {
    if (ftduino.input_get(Ftduino::IX))
      counter++;
    delay(1);
  }
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm fährt komplett runter
  while (!ftduino.input_get(Ftduino::IX))
    delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);
}

void zur_annahme()
{
  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm fährt komplett aus
  delay(100);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm fährt runter und legt box ab
  delay(100);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm zieht etwas ein
  delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm fährt komplett zurück
  while (!ftduino.input_get(Ftduino::IX))
    delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm fährt komplett runter (zur annahme)
  while (!ftduino.input_get(Ftduino::IX))
    delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm fährt komplett aus (zur annahme)
  while (!ftduino.input_get(Ftduino::IX))
    delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);
}

void zur_ausgabe()
{
  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm fährt komplett aus
  while (!ftduino.input_get(Ftduino::IX))
    delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm fährt hoch und greift box
  delay(100);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm zieht etwas ein
  delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm fährt komplett nach links
  while (!ftduino.input_get(Ftduino::IX))
    delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm fährt komplett hoch
  while (!ftduino.input_get(Ftduino::IX))
    delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm fährt komplett aus
  while (!ftduino.input_get(Ftduino::IX))
    delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm zieht etwas ein
  delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm fährt runter und legt box ab
  delay(100);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);
}

void go_back()
{
  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm zieht etwas ein
  delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm fährt komplett zurück
  while (!ftduino.input_get(Ftduino::IX))
    delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm fährt komplett runter (zur annahme)
  while (!ftduino.input_get(Ftduino::IX))
    delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX); // arm fährt komplett aus (zur annahme)
  while (!ftduino.input_get(Ftduino::IX))
    delay(1);
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);
}