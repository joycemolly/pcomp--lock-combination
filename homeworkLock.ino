int ledWrong = 7;
int ledRight= 3;
int ledReset =4;


int button1 = 13;  
int button2 = 12;
int button3 = 11;
int button4 = 10;


int ResetLightState = 0; 

int button1StatePrevious = 0; 
int button1StateCurrent = 0; 

int button2StatePrevious = 0; 
int button2StateCurrent = 0; 

int button3StatePrevious = 0; 
int button3StateCurrent = 0; 

int button4StatePrevious = 0; 
int button4StateCurrent = 0; 


int pressedAmount =0;
int val =0;





void setup() {
  Serial.begin(9600);
  pinMode(ledReset,OUTPUT);
  pinMode(ledRight,OUTPUT);
  pinMode(ledRight,OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);


}

void loop() {
  button1StateCurrent = digitalRead(button1);
  button2StateCurrent = digitalRead(button2);
  button3StateCurrent = digitalRead(button3);
  button4StateCurrent = digitalRead(button4);
  Serial.println(val);

  
  
  if(button1StatePrevious!=button1StateCurrent){
    if(button1StateCurrent == HIGH){
      pressedAmount +=1; 
      if(val == 0){
            val = 1; 
      }
    }
    
  }
  button1StatePrevious = button1StateCurrent;

  if(button2StatePrevious!=button2StateCurrent){
    if(button2StateCurrent == HIGH){
      pressedAmount +=1; 
      if(val == 1){
            val =2; 
      }
    }
    
  }
  button2StatePrevious = button2StateCurrent;

  if(button3StatePrevious!=button3StateCurrent){
    if(button3StateCurrent == HIGH){
      pressedAmount +=1; 
      if(val == 2){
            val =3; 
      }
    }
    
  }
  button3StatePrevious = button3StateCurrent;

  if(button4StatePrevious!=button4StateCurrent){
    if(button4StateCurrent == HIGH){
      pressedAmount +=1; 
      if(val == 3){
            val =4; 
      }
    }
    
  }
  button4StatePrevious = button4StateCurrent;

  if(pressedAmount <4 ){
       digitalWrite(ledRight,LOW);
       digitalWrite(ledWrong,LOW);
       digitalWrite(ledReset,HIGH);
    
  }
  
 //led: 
  
  if(pressedAmount >3){
    if(val ==4){
       digitalWrite(ledRight,HIGH);
       digitalWrite(ledWrong,LOW);
       digitalWrite(ledReset,LOW);
       delay(5000);


       digitalWrite(ledRight,LOW);
       digitalWrite(ledWrong,LOW);
       digitalWrite(ledReset,HIGH);
       pressedAmount =0;
       val = 0;

    }
    else{
       val = 0;
       pressedAmount =0; 
       digitalWrite(ledWrong,HIGH);
       digitalWrite(ledRight,LOW);
       digitalWrite(ledReset,LOW);
       delay(5000);

       digitalWrite(ledRight,LOW);
       digitalWrite(ledWrong,LOW);
       digitalWrite(ledReset,HIGH);
  

    }
  }

}
