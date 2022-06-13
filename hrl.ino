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
int left = 0;

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
  delay(1300);
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
  delay(4000);
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
    left = 3;
    fach0_auslagern();
    zur_ausgabe_oben();
    go_back();
    break;
  case 11:
    left = 2;
    fach1_auslagern();
    zur_ausgabe_oben();
    go_back();
    break;
  case 12:
    left = 1;
    fach2_auslagern();
    zur_ausgabe_oben();
    go_back();
    break;
  case 13:
    left = 0;
    fach3_auslagern();
    zur_ausgabe_oben();
    go_back();
    break;
  case 14:
    left = 2;
    fach4_auslagern();
    zur_ausgabe_unten();
    go_back();
    break;
  case 15:
    left = 1;
    fach5_auslagern();
    zur_ausgabe_unten();
    go_back();
    break;
  }
  return left;
}

void fach0_einlagern() // fertig
{
  ftduino.motor_set(Ftduino::M3, Ftduino::LEFT); // arm zieht etwas ein
  delay(5000);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M2, Ftduino::LEFT); // arm fährt komplett hoch
  while (!ftduino.input_get(Ftduino::I2))
    delay(1);
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);
}

void fach0_auslagern() // fertig
{
  ftduino.motor_set(Ftduino::M3, Ftduino::LEFT); // arm zieht etwas ein
  delay(5000);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M2, Ftduino::LEFT); // arm fährt komplett hoch
  while (!ftduino.input_get(Ftduino::I2))
    delay(1);
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M2, Ftduino::RIGHT); // arm fährt etwas runter
  delay(1500);
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);
}

void fach1_einlagern() // fertig
{
  int counter = 0;

  ftduino.motor_set(Ftduino::M3, Ftduino::LEFT); // arm zieht etwas ein
  delay(5000);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt nach links
  while (counter < 1)
  {
    if (ftduino.input_get(Ftduino::I5))
    {
      counter += 1;
      delay(1000);
    }
    delay(1);
  }
  delay(2600);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M2, Ftduino::LEFT); // arm fährt komplett hoch
  while (!ftduino.input_get(Ftduino::I2))
    delay(1);
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);
}

void fach1_auslagern() // fertig
{
  int counter = 0;

  ftduino.motor_set(Ftduino::M3, Ftduino::LEFT); // arm zieht etwas ein
  delay(5000);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt nach links
  while (counter < 1)
  {
    if (ftduino.input_get(Ftduino::I5))
    {
      counter += 1;
      delay(1000);
    }
    delay(1);
  }
  delay(2600);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M2, Ftduino::LEFT); // arm fährt komplett hoch
  while (!ftduino.input_get(Ftduino::I2))
    delay(1);
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M2, Ftduino::RIGHT); // arm fährt etwas runter
  delay(1500);
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);
}

void fach2_einlagern() // fertig
{
  int counter = 0;

  ftduino.motor_set(Ftduino::M3, Ftduino::LEFT); // arm zieht etwas ein
  delay(5000);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt nach links
  while (counter < 2)
  {
    if (ftduino.input_get(Ftduino::I5))
    {
      counter += 1;
      delay(1000);
    }
    delay(1);
  }
  delay(100);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M2, Ftduino::LEFT); // arm fährt komplett hoch
  while (!ftduino.input_get(Ftduino::I2))
    delay(1);
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);
}

void fach2_auslagern() // fertig
{
  int counter = 0;

  ftduino.motor_set(Ftduino::M3, Ftduino::LEFT); // arm zieht etwas ein
  delay(5000);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt nach links
  while (counter < 2)
  {
    if (ftduino.input_get(Ftduino::I5))
    {
      counter += 1;
      delay(1000);
    }
    delay(1);
  }
  delay(100);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M2, Ftduino::LEFT); // arm fährt komplett hoch
  while (!ftduino.input_get(Ftduino::I2))
    delay(1);
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M2, Ftduino::RIGHT); // arm fährt etwas runter
  delay(1500);
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);
}

void fach3_einlagern() // fertig
{
  int counter = 0;

  ftduino.motor_set(Ftduino::M3, Ftduino::LEFT); // arm zieht etwas ein
  delay(5000);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt nach links
  while (counter < 3)
  {
    if (ftduino.input_get(Ftduino::I5))
    {
      counter += 1;
      delay(1000);
    }
    delay(1);
  }
  delay(1650);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M2, Ftduino::LEFT); // arm fährt komplett hoch
  while (!ftduino.input_get(Ftduino::I2))
    delay(1);
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);
}

void fach3_auslagern() // fertig
{
  int counter = 0;

  ftduino.motor_set(Ftduino::M3, Ftduino::LEFT); // arm zieht etwas ein
  delay(5000);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt nach links
  while (counter < 3)
  {
    if (ftduino.input_get(Ftduino::I5))
    {
      counter += 1;
      delay(1000);
    }
    delay(1);
  }
  delay(1650);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M2, Ftduino::LEFT); // arm fährt komplett hoch
  while (!ftduino.input_get(Ftduino::I2))
    delay(1);
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M2, Ftduino::RIGHT); // arm fährt etwas runter
  delay(1500);
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);
}

void fach4_einlagern() // nicht fertig
{
  int counter = 0;

  ftduino.motor_set(Ftduino::M3, Ftduino::LEFT); // arm zieht etwas ein
  delay(5000);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt nach links
  while (counter < 1)
  {
    if (ftduino.input_get(Ftduino::I5))
    {
      counter += 1;
      delay(1000);
    }
    delay(1);
  }
  delay(2600);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

}

void fach4_auslagern() // nicht fertig
{
  int counter = 0;

  ftduino.motor_set(Ftduino::M3, Ftduino::LEFT); // arm zieht etwas ein
  delay(5000);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt nach links
  while (counter < 1)
  {
    if (ftduino.input_get(Ftduino::I5))
    {
      counter += 1;
      delay(1000);
    }
    delay(1);
  }
  delay(2600);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M2, Ftduino::RIGHT); // arm fährt etwas runter
  delay(2000);
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);
}

void fach5_einlagern() // nicht fertig
{
  int counter = 0;

  ftduino.motor_set(Ftduino::M3, Ftduino::LEFT); // arm zieht etwas ein
  delay(5000);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt nach links
  while (counter < 2)
  {
    if (ftduino.input_get(Ftduino::I5))
    {
      counter += 1;
      delay(1000);
    }
    delay(1);
  }
  delay(100);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

}

void fach5_auslagern() // nicht fertig
{
  int counter = 0;

  ftduino.motor_set(Ftduino::M3, Ftduino::LEFT); // arm zieht etwas ein
  delay(5000);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt nach links
  while (counter < 2)
  {
    if (ftduino.input_get(Ftduino::I5))
    {
      counter += 1;
      delay(1000);
    }
    delay(1);
  }
  delay(100);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M2, Ftduino::RIGHT); // arm fährt etwas runter
  delay(2000);
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);
}

void zur_annahme() // fertig
{
  ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT); // arm fährt komplett aus
  while (!ftduino.input_get(Ftduino::I3))
    delay(1);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M2, Ftduino::RIGHT); // arm fährt runter und legt box ab
  delay(1700);
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

void zur_ausgabe_oben() // fertig
{
  int counter = 0;

  ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT); // arm fährt komplett aus
  while (!ftduino.input_get(Ftduino::I3))
    delay(1);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M2, Ftduino::LEFT); // arm fährt komplett hoch
  while (!ftduino.input_get(Ftduino::I2))
    delay(1);
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M3, Ftduino::LEFT); // arm zieht etwas ein
  delay(7000);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  if (left != 0)
  {
    ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt nach links
    while (counter < left)
    {
      if (ftduino.input_get(Ftduino::I5))
      {
        counter += 1;
        delay(1000);
      }
      delay(1);
    }
    delay(1650);
    ftduino.motor_set(Ftduino::M1, Ftduino::OFF);
  }

  ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT); // arm fährt etwas aus
  delay(2000);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M2, Ftduino::RIGHT); // arm fährt komplett runter und legt box ab
  while (!ftduino.input_get(Ftduino::I1))
    delay(1);
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);

  left = 0;
}

void zur_ausgabe_unten() // fertig
{
  int counter = 0;

  ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT); // arm fährt komplett aus
  while (!ftduino.input_get(Ftduino::I3))
    delay(1);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M2, Ftduino::LEFT); // arm fähr etwas hoch und greift box
  delay(2000);
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M3, Ftduino::LEFT); // arm zieht etwas ein
  delay(7000);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M2, Ftduino::LEFT); // arm fährt komplett hoch
  while (!ftduino.input_get(Ftduino::I2))
    delay(1);
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);

  if (left != 0)
  {
    ftduino.motor_set(Ftduino::M1, Ftduino::LEFT); // arm fährt nach links
    while (counter < left)
    {
      if (ftduino.input_get(Ftduino::I5))
      {
        counter += 1;
        delay(1000);
      }
      delay(1);
    }
    delay(1650);
    ftduino.motor_set(Ftduino::M1, Ftduino::OFF);
  }

  ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT); // arm fährt etwas aus
  delay(2000);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M2, Ftduino::RIGHT); // arm fährt komplett runter und legt box ab
  while (!ftduino.input_get(Ftduino::I1))
    delay(1);
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);

  left = 0;
}

void go_back() // fertig
{
  ftduino.motor_set(Ftduino::M3, Ftduino::LEFT); // arm komplett einziehen
  while (!ftduino.input_get(Ftduino::I4))
    delay(1);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M1, Ftduino::RIGHT); // arm komplett nach rechts
  while (!ftduino.input_get(Ftduino::I6))
    delay(1);
  ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M2, Ftduino::RIGHT); // arm fährt komplett runter
  while (!ftduino.input_get(Ftduino::I1))
    delay(1);
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M2, Ftduino::LEFT); // arm fährt etwas hoch
  delay(1300);
  ftduino.motor_set(Ftduino::M2, Ftduino::OFF);

  ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT); // arm fährt aus (zur annahme)
  delay(10000);
  ftduino.motor_set(Ftduino::M3, Ftduino::OFF);
}
