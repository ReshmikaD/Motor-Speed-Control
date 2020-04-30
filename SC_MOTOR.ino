int data = 3;
int motor = 9;

unsigned long prevmillis = 0;
unsigned long duration = 0;
unsigned long newmillis = 0;
unsigned long ttime;
unsigned long tend;
unsigned long tstart;

float p = 100.0;
int speeed;
int rpm;
float preverror;
float error;
int m , f ;
volatile int n = 0;
int q = 1;

void setup()
{
  pinMode(data, INPUT);
  Serial.begin(9600);
  pinMode(motor, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(3), isr , RISING);
  analogWrite(motor, p);
  while (! Serial);
  Serial.println("ENTER RPM");
  Serial.print("RPM");
  Serial.print("   ");
  Serial.print("ERROR");
  Serial.print("  ");
  Serial.print("PWM");
  Serial.print("   ");
  Serial.println("TTIME");
}

void loop()
{


  if (Serial.available())
  { speeed = Serial.parseInt();
    Serial.print("Desired RPM = ");
    Serial.println(speeed);
    tstart = millis();
    m = 1;
    q = 1;
  }

  if ((n == 1) || (q == 1))
  {
    newmillis = millis();
    duration = (newmillis - prevmillis);
    prevmillis = newmillis;
    rpm = ((60000 * 1) / duration);
    n = 0;
    if (rpm > 0 && rpm < 820)
    { Serial.print(rpm);
      Serial.print("    ");

      error = (speeed - rpm);

      if (error < 4 && error > -4)
      { if (m == 1)
        { tend = millis();
          ttime = tend - tstart;
          m = 0; f = 1;
        }
      }

      if (m == 0)
      { //if (error > 4 || error < -4)
        { //if (((preverror - error) > 8) || ((preverror - error) < -8))
          { tend = millis();
            ttime = tend - tstart;
            f = 1;
          }
        }
      }

      if (q == 0)
      {
        p = ((0.25 * error) + p) ;
        if (p > 255) {
          p = 255;
        }
        else if ((p < 35)) {
          p = 35;
        }

        Serial.print(error);
        Serial.print("    ");
        Serial.print(round(p));
        analogWrite(motor, round(p));
        Serial.print("    ");
       // if (f == 1)
        { Serial.print(ttime);
          f = 0;
        }
        preverror = error;
      }
      Serial.println();
    }
  }
  q = 0;
}


void isr() {
  {
    n += 1;
  }
}
