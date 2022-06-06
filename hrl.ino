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

  ric->send("mfc", "websocket", "OK");
  int result = ric->read_wait().toInt();

  switch (result)
  {
  case 00:
    fach0_auslagern();
    break;
  case 01:
    fach0_einlagern();
    break;
  case 02:
    fach1_auslagern();
    break;
  case 03:
    fach1_einlagern();
    break;
  case 04:
    fach2_auslagern();
    break;
  case 05:
    fach2_einlagern();
    break;
  case 10:
    fach3_auslagern();
    break;
  case 11:
    fach3_einlagern();
    break;
  case 12:
    fach4_auslagern();
    break;
  case 13:
    fach4_einlagern();
    break;
  case 14:
    fach5_auslagern();
    break;
  case 15:
    fach5_einlagern();
    break;
  }
}

void fach0_einlagern()
{
}

void fach0_auslagern()
{
}

void fach1_einlagern()
{
}

void fach1_auslagern()
{
}

void fach2_einlagern()
{
}

void fach2_auslagern()
{
}

void fach3_einlagern()
{
}

void fach3_auslagern()
{
}

void fach3_einlagern()
{
  int counter = 0;

  ftduino.motor_set(Ftduino::MX, Ftduino::XXX);
  while (counter < 3)
  {
    if (taster)
      counter++;
    delay(1);
  }
  ftduino.motor_set(Ftduino::MX, Ftduino::OFF);
}

void fach4_auslagern()
{
}

void fach4_einlagern()
{
}

void fach5_auslagern()
{
}

void fach5_einlagern()
{
}
