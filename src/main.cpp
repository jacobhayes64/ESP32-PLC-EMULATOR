#include <Arduino.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

#ifndef LED_BUILTIN
#define LED_BUILTIN 2
#define INPUT_PIN1 34
#define INPUT_PIN2 35
#define INPUT_PIN3 32
#define INPUT_PIN4 33

#define OUTPUT_PIN1 25
#define OUTPUT_PIN2 26
#define OUTPUT_PIN3 27
#define OUTPUT_PIN4 14
int inputPins[4] = {INPUT_PIN1, INPUT_PIN2, INPUT_PIN3, INPUT_PIN4};
int outputPins[4] = {OUTPUT_PIN1, OUTPUT_PIN2, OUTPUT_PIN3, OUTPUT_PIN4};
bool inputState[4];
bool outputState[4];

#endif
void logicsolve(void);
void inputscan(int[]);
void outputscan(int[]);
void test(int,int);

class tag{
  public:
  char name[64];
  char type[4];
  int intValue;
  bool boolValue;
  float floValue;
  double douValue;

};

class rungcontext{
  public:
  bool rungPower;
  int tags[8];
  double nowMs;

};

class XIO {
  public:
  int tagindex;
  bool state;

  bool eval(rungcontext& rung){
    if(this->state==0){
      rung.rungPower = 1;
    }else{rung.rungPower = 0;}
    }
};

// class XIC {
//   public:
//   int tagindex;

//   bool eval(rungcontext *rung){
//     if(this->tag==1){
//       rung->rungPower = 1;
//     }else{rung->rungPower = 0;}
//     }
// };

class OTE {
  public:
  int tag;

  bool eval(rungcontext rung){
  if(rung.rungPower=1){
    this->tag=1;
  }else{this->tag=0;}
    }
};


void setup() {
  rungcontext rung0;
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(INPUT_PIN1, INPUT);
  pinMode(INPUT_PIN2, INPUT);
  pinMode(INPUT_PIN3, INPUT);
  pinMode(INPUT_PIN4, INPUT);

  pinMode(OUTPUT_PIN1, OUTPUT);
  pinMode(OUTPUT_PIN2, OUTPUT);
  pinMode(OUTPUT_PIN3, OUTPUT);
  pinMode(OUTPUT_PIN4, OUTPUT);
  
  vector<tag> tagDB;
  tag T0;
  testPopulateTag(&T0);
  tagDB.push_back(T0);

}

void loop() {
  inputscan(inputPins);
  outputscan(outputPins);
  digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
}

void inputscan(int pins[]){
for(int i=0; i<4; i++){
  if(digitalRead(pins[i])==HIGH){
    inputState[i]=1;
    printf("\nSet Input %d State to HIGH", i);
  }else{
    inputState[i]=0;
    printf("\nSet Input %d State to LOW", i);
  }

}
}


void outputscan(int pins[]){
for(int i=0; i<4; i++){
  if(outputState[i]==1){
    digitalWrite(pins[i], HIGH);
    printf("\nSet Output %d State to HIGH", i);
  }else{
    digitalWrite(pins[i],LOW);
    printf("\nSet Output %d State to LOW", i);
  }

}

}

void testPopulateTag(tag *t){
  strcpy(t->name, "Testing Name");
  strcpy(t->type, "BOOL");
  t->boolValue = 1;



}


