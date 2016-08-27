#define PULLB 2
#define MARKB 3
#define PULLMARKB 4
#define PULL 5
#define MARK 6
#define LAMPEPULL 7
#define LAMPEMARK 8
#define ONOFFB 9
#define n 3000
#define i 150

void setup() {
  pinMode(PULL, OUTPUT);
  pinMode(MARK, OUTPUT);
  pinMode(LAMPEMARK, OUTPUT);
  pinMode(LAMPEPULL, OUTPUT);

  pinMode(PULLB, INPUT_PULLUP);
  pinMode(MARKB, INPUT_PULLUP);
  pinMode(PULLMARKB, INPUT_PULLUP);
  pinMode(ONOFFB, INPUT_PULLUP);

  digitalWrite(LAMPEPULL, HIGH);
  digitalWrite(LAMPEMARK, HIGH);
  digitalWrite(MARK, HIGH);
  digitalWrite(PULL, HIGH);


}
void loop() {
  if ( ( digitalRead(MARKB) == HIGH && digitalRead(PULLMARKB) == HIGH && digitalRead(PULLB) == HIGH) || (digitalRead(MARKB) == LOW && digitalRead(PULLMARKB) == LOW && digitalRead(PULLB) == LOW) )
  {
    digitalWrite(LAMPEPULL, HIGH);
    digitalWrite(LAMPEMARK, HIGH);
    digitalWrite(MARK, HIGH);
    digitalWrite(PULL, HIGH);
  }
  else
  {
    if ( digitalRead(ONOFFB) == LOW )
    {
      if (digitalRead(MARKB) == LOW && digitalRead(PULLMARKB) == LOW && digitalRead(PULLB) == HIGH )
      {
        digitalWrite(LAMPEPULL, LOW);
        delay(random(n));
        digitalWrite(LAMPEPULL, HIGH);
        digitalWrite(PULL, LOW);
        delay(i);
        digitalWrite(PULL, HIGH);
      } else
      {
        digitalWrite(LAMPEPULL, HIGH);
        digitalWrite(LAMPEMARK, HIGH);
        digitalWrite(MARK, HIGH);
        digitalWrite(PULL, HIGH);
      }
      if ( digitalRead(PULLB) == LOW  && digitalRead(PULLMARKB) == LOW  && digitalRead(MARKB) == HIGH)
      {
        digitalWrite(LAMPEMARK, LOW);
        delay(random(n));
        digitalWrite(LAMPEMARK, HIGH);
        digitalWrite(MARK, LOW);
        delay(i);
        digitalWrite(MARK, HIGH);
      }
      else
      {
        digitalWrite(LAMPEPULL, HIGH);
        digitalWrite(LAMPEMARK, HIGH);
        digitalWrite(MARK, HIGH);
        digitalWrite(PULL, HIGH);
      }
      if (digitalRead(PULLB) == LOW  && digitalRead(MARKB) == LOW && digitalRead(PULLMARKB) == HIGH )
      {
        digitalWrite(LAMPEPULL, LOW);
        digitalWrite(LAMPEMARK, LOW);
        delay(random(n));
        digitalWrite(LAMPEPULL, HIGH);
        digitalWrite(LAMPEMARK, HIGH);
        digitalWrite(MARK, LOW);
        digitalWrite(PULL, LOW);
        delay(i);
        digitalWrite(MARK, HIGH);
        digitalWrite(PULL, HIGH);
      }
      else
      {
        digitalWrite(LAMPEPULL, HIGH);
        digitalWrite(LAMPEMARK, HIGH);
        digitalWrite(MARK, HIGH);
        digitalWrite(PULL, HIGH);
      }
    }


    if ( digitalRead(ONOFFB) == HIGH )
    {
      if (  digitalRead(MARKB) == LOW && digitalRead(PULLMARKB) == LOW && digitalRead(PULLB) == HIGH )
      {
        digitalWrite(PULL, LOW);
        delay(i);
        digitalWrite(PULL, HIGH);
      }
      else
      {
        digitalWrite(LAMPEPULL, HIGH);
        digitalWrite(LAMPEMARK, HIGH);
        digitalWrite(MARK, HIGH);
        digitalWrite(PULL, HIGH);
      }
      if ( digitalRead(PULLB) == LOW  && digitalRead(PULLMARKB) == LOW  && digitalRead(MARKB) == HIGH)
      {
        digitalWrite(MARK, LOW);
        delay(i);
        digitalWrite(MARK, HIGH);
      }
      else
      {
        digitalWrite(LAMPEPULL, HIGH);
        digitalWrite(LAMPEMARK, HIGH);
        digitalWrite(MARK, HIGH);
        digitalWrite(PULL, HIGH);
      }
      if ( digitalRead(PULLB) == LOW  && digitalRead(MARKB) == LOW && digitalRead(PULLMARKB) == HIGH  )
      {
        digitalWrite(PULL, LOW);
        digitalWrite(MARK, LOW);
        delay(i);
        digitalWrite(PULL, HIGH);
        digitalWrite(MARK, HIGH);
      }
      else
      {
        digitalWrite(LAMPEPULL, HIGH);
        digitalWrite(LAMPEMARK, HIGH);
        digitalWrite(MARK, HIGH);
        digitalWrite(PULL, HIGH);
      }
    }
  }
}

