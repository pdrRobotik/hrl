#include <FtduinoSimple.h>
#include <AccessNode.h>

RobotikInterConnect* ric;
int counter = 0;

void setup() {
  ric = new RobotikInterConnect("greifarm");

    ftduino.motor_set(Ftduino::M1, Ftduino::RIGHT);
    while (!ftduino.input_get(Ftduino::I2)) delay(1);
    ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

    ftduino.motor_set(Ftduino::M2, Ftduino::LEFT);
    while (!ftduino.input_get(Ftduino::I6)) delay(1);
    ftduino.motor_set(Ftduino::M2, Ftduino::OFF);

    ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT);
    while (!ftduino.input_get(Ftduino::I7)) delay(1);
    ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

    ftduino.output_set(Ftduino::O8, Ftduino::OFF);
}
void loop() {
  ftduino.motor_set(Ftduino::M1, Ftduino::RIGHT);
    while (!ftduino.input_get(Ftduino::I2)) delay(1);
    ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

    ftduino.motor_set(Ftduino::M2, Ftduino::LEFT);
    while (!ftduino.input_get(Ftduino::I6)) delay(1);
    ftduino.motor_set(Ftduino::M2, Ftduino::OFF);

    ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT);
    while (!ftduino.input_get(Ftduino::I7)) delay(1);
    ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  ric->send("mfc","websocket","OK");
  int result = ric->read_wait().toInt();
    
    ftduino.output_set(Ftduino::O8, Ftduino::HI);

    
    if (result == "r") {
      ftduino.motor_set(Ftduino::M2, Ftduino::RIGHT);
      delay(12300);
      ftduino.motor_set(Ftduino::M2, Ftduino::OFF);
    } else if (result == "g") {
      ftduino.motor_set(Ftduino::M2, Ftduino::RIGHT);
      delay(6500);
      ftduino.motor_set(Ftduino::M2, Ftduino::OFF);
    } else if (result == "b") {
      ftduino.motor_set(Ftduino::M2, Ftduino::RIGHT);
      delay(800);
      ftduino.motor_set(Ftduino::M2, Ftduino::OFF);
    }
    
    //Arm runte
    ftduino.motor_set(Ftduino::M1, Ftduino::LEFT);
    while (!ftduino.input_get(Ftduino::I1)) delay(1);
    ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

    //Pneumatik an (greifen)
    ftduino.output_set(Ftduino::O7, Ftduino::HI);
    delay(1000);

    //Arm hoch
    ftduino.motor_set(Ftduino::M1, Ftduino::RIGHT);
    while (!ftduino.input_get(Ftduino::I2)) delay(1);

    //Arm einziehen
    ftduino.motor_set(Ftduino::M2, Ftduino::LEFT);
    while (!ftduino.input_get(Ftduino::I6)) delay(1);
    ftduino.motor_set(Ftduino::M2, Ftduino::OFF);
    
    //drehen
    ftduino.motor_set(Ftduino::M3, Ftduino::LEFT);
    while (!ftduino.input_get(Ftduino::I3)) delay(1);
    ftduino.motor_set(Ftduino::M3, Ftduino::OFF);


    //Arm runter
    ftduino.motor_set(Ftduino::M1, Ftduino::LEFT);
    delay(3500);
    ftduino.motor_set(Ftduino::M1, Ftduino::OFF);

    ric->send("mfc","websocket","NEXT");
    ric->read_wait();

    //Pneumatik aus (loslassen)
    ftduino.output_set(Ftduino::O7, Ftduino::OFF);
    ftduino.output_set(Ftduino::O8, Ftduino::OFF);

    delay(3000);

    //Arm hoch
    ftduino.motor_set(Ftduino::M1, Ftduino::RIGHT);
    while (!ftduino.input_get(Ftduino::I2)) delay(1);
    ftduino.motor_set(Ftduino::M1, Ftduino::OFF);


    //zurück (drehen)
    ftduino.motor_set(Ftduino::M3, Ftduino::RIGHT);
    while (!ftduino.input_get(Ftduino::I7)) delay(1);
    ftduino.motor_set(Ftduino::M3, Ftduino::OFF);

  delay(1);
}

void fach0_einlagern() {
  

}

void fach0_ausgabe() {

}

void fach1_einlagern() {
  

}

void fach1_ausgabe() {

}

void fach2_einlagern() {
  

}

void fach2_ausgabe() {

}

void fach3_einlagern() {
  

}

void fach3_ausgabe() {

}

void fach3_einlagern() {
  

}

void fach4_ausgabe() {

}

void fach4_einlagern() {
  

}

void fach0_ausgabe() {

}



