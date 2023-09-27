#define STEP 6
#define DIR 5
#define ENABLE 3
bool k=false;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(STEP, OUTPUT);
pinMode (DIR, OUTPUT);
pinMode (ENABLE, OUTPUT);
Serial.println("Iniciando");
}

void loop() {
delay (5000);
if(k){
  k=false;
}
else{
  k=true;
}  
  digitalWrite(ENABLE, LOW);
  for(int j=0; j<18; j++)
  {
    if(k){
      Serial.print("Bajando ");
    }
    else{
      Serial.print("Subiendo ");
    }
    digitalWrite (DIR, k);
    Serial.println(j);
    for(int i = 0; i < 200 ; i++)
    {
      digitalWrite (STEP, HIGH);
      delayMicroseconds (500);
      digitalWrite (STEP, LOW);
      delayMicroseconds(500);
    }
  }
digitalWrite(ENABLE, HIGH);

}
