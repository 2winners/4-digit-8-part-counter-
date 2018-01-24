//segments
int N0 = 6;   // segment selector pin 0
int N1 = 5;   // segment selector pin 1
int N2 = 4;   // segment selector pin 2
int NA = 7;   // activate/ deactivate segment
//digits
int PA = 8;   // activate/ deactivate digit
int P0 = 11;  // Digit selector pin 0
int P1 = 10;  // Digit selector pin 1
int P2 = 9;   // Digit selector pin 2
//other
const int bp1 = 2; const int bp2 = 3; const int bp3 = 12; // button pins
int n = 0;int n1 = 0;int n2 = 0;  // number variables
int x = 0;                        // counter

int button1 = 0; int button2 = 0; int button3 = 0; // button variables
int test = 0;
int TIME1 = millis();
int TIME2;
int del= 0;    // 8   delay stopwatch and chess
int dels = 0;  // 7   delay 
int del2 =500; //     delay general segment timer
int del3 = 100;//     delay startup check 
int mode = 0;  //     mode selector
int start = 0; int pause = 1;  // stopwatch
int updw = 0; long temp = 0; int temp2; // temporary variables
int y = random(1,5); int z = random(9); int c = 0; // demo variables
int u1; int u2;int u3; int u4;int u5; int u6;int u7; int u08; int u9; int u10;int u11; int u12; int u13; int deck = 0;int sum =0; // up down deck of cards
long chess1 = 0; long chess2 = 0; int ch = 0; int chesspause1 = 1; int chesspause2 = 1; // chess variables 
int digi1 = 0; int digi2 = 0; int digi3 = 0; int  digi4 = 0;int digiSelect = 1; int timeSum = 0;  // chess setup 
void setup(){            // ############### void SETUP          ################### Void SETUP       #########################
  pinMode(N1,OUTPUT);
  pinMode(N2,OUTPUT);
  pinMode(N0,OUTPUT);
  pinMode(NA,OUTPUT);
  pinMode(P1,OUTPUT);
  pinMode(P2,OUTPUT);
  pinMode(P0,OUTPUT);
  pinMode(PA,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(bp1,INPUT);
  pinMode(bp2,INPUT);
  pinMode(bp3,INPUT);
  Serial.begin(9600);
  randomSeed(analogRead(0));
}
void loop(){             // ############### void LOOP           ################### void LOOP        #########################
button1 = digitalRead(bp1);  button2 = digitalRead(bp2); button3 = digitalRead(bp3);// ######## Read Buttons  ############## Read Buttons ######

  switch (mode){
    default: startup_check();break;
    case 0: startup_check(); break; 
    case 1: score(); break;
    case 4: demo(); break;
    case 2: stopwatch(); break;
    case 3: updownP(); break;
    case 5: updownT(); break;
    case 6: chesssetup(); break;
    case 7: chess(); break;
    //case 8: eight(); break;
    //case 9: nine(); break;
  }
}

void score(){            // ############### Void Score(1)       ################### void Score       #########################
  del2 = 700;
  if(n1 < 10){           // ###### 0ne digit #### digit 2     ##### ###### 0ne digit #### digit 2     #####
      clearLEDs(); pickDigit(2); pickNumber(n1); delayMicroseconds(del);}
  else{                  // ###### two digit #### digit 1 & 2 ##### ###### two digit #### digit 1 & 2 #####
      clearLEDs(); pickDigit(1); pickNumber(n1/10); delayMicroseconds(del);
      dubbleDot();       //######## dubbe dot ##### 
      clearLEDs(); pickDigit(2); pickNumber(n1-((n1/10)*10)); delayMicroseconds(del);}
  dubbleDot();           // ###### dubbe dot #### 
  if(n2 < 10){           // ###### 0ne digit #### digit 3     ##### ###### 0ne digit #### digit 3     #####
      clearLEDs(); pickDigit(4); pickNumber(n2); delayMicroseconds(del);}
  else{                  // ###### two digit #### digit 3 & 4 ##### ###### two digit #### digit 3 & 4 #####
      clearLEDs(); pickDigit(3); pickNumber(n2/10); delayMicroseconds(del);
      dubbleDot();       //######## dubbe dot ##### 
      clearLEDs(); pickDigit(4); pickNumber(n2-((n2/10)*10)); delayMicroseconds(del);}
  dubbleDot();           // ###### dubbe dot ####
  buttoncheck();         // ###### Read Buttons ####
  del2 = 500; 
}
void demo(){             // ############### Void Demo(4)        ################### Void Demo        #########################
  y = random(1,5); z = random(32); del2 = 11000; 
  buttoncheck();         // ###### Read Buttons ####    
  for (c = 0; c <= 5; c++ ){// ### Run number 5 times #### 
    buttoncheck();       // ###### Read Buttons ####
    clearLEDs(); pickDigit(y); pickNumber(z); delayMicroseconds(del); pickNumber(z); delayMicroseconds(del);
  }
  del2 = 500;  
}
void stopwatch(){        // ############### Void Stopwatch(2)   ################### Void Stopwatch   #########################
  delayMicroseconds(del);  del2 =800;
  if(n<600){                                 //###### time below 60 sec #### 10 =1 sec 100=10sec 1000 1m 40s
    for(x = 0;x<4;x++){  // ###### run numbers X times ####
     del = 60;           // ###### slow down arduino micro sec ####
    clearLEDs();  pickDigit(1);  pickNumber(n/1000);  delayMicroseconds(del);  
    clearLEDs();  pickDigit(2);  pickNumber((n/100)-((n/1000)*10));  delayMicroseconds(del);
    buttoncheck();
    clearLEDs();  pickDigit(3);  deci();  pickNumber((n/10)-((n/100)*10));  delayMicroseconds(del);
    clearLEDs();  pickDigit(4);  pickNumber(n - ((n/10)*10));  delayMicroseconds(del);
    }
  }
  else{                                      //###### time above 60 seconds ####
    for(x = 0;x<4;x++){  // ###### run numbers X times ####
      del = 90;          // ###### slow down arduino micro sec ####
      clearLEDs();  pickDigit(1);  pickNumber((n/10)/600);  delayMicroseconds(del);  
      clearLEDs();  pickDigit(2);  pickNumber(n/600);  delayMicroseconds(del);
      buttoncheck(); dubbleDot(); 
      clearLEDs();  pickDigit(3);  pickNumber((n-((n/600)*600))/100);  delayMicroseconds(del);
      clearLEDs();  pickDigit(4);  pickNumber((n/10)-((n/100)*10));  delayMicroseconds(del);
  }}
  if(pause == 0){ n++;if (n > 9999){ n = 0;}}
  buttoncheck(); del2 = 500; del =0;
}
void updownP(){          // ############### Void Up DownP(3)    ################### Void Up Down     #########################
  buttoncheck();
  if(sum < 10){          // ###### if single digit ####
    clearLEDs(); pickDigit(1); pickNumber(26); delayMicroseconds(del); //###### 26 = P ####
    clearLEDs(); pickDigit(2); pickNumber(sum);delayMicroseconds(del);}
  else{                  // ###### if dubble digit ####
    pickDigit(1); pickNumber(sum/10); delayMicroseconds(del); clearLEDs();
    pickDigit(2); pickNumber(sum -((sum/10)*10)); delayMicroseconds(del);
  }
  buttoncheck();
  if(updw < 10){         // ###### if single digit ####
    clearLEDs(); pickDigit(4); pickNumber(updw); delayMicroseconds(del);}
  else{                  // ###### if dubble digit ####
    pickDigit(3); pickNumber(updw/10); delayMicroseconds(del); clearLEDs();
    pickDigit(4); pickNumber(updw -((updw/10)*10)); delayMicroseconds(del);
  }buttoncheck();
}
void updownT(){          // ############### Void Up DownT(5)    ################### Void Up Down     #########################
   buttoncheck();
  if(sum < 10){          // ###### if single digit ####
    clearLEDs(); pickDigit(1); pickNumber(30); delayMicroseconds(del); //###### 30 = T ####
    clearLEDs(); pickDigit(2); pickNumber(sum);delayMicroseconds(del);}
  else{                  // ###### if dubble digit ####
    pickDigit(1); pickNumber(sum/10); delayMicroseconds(del); clearLEDs();
    pickDigit(2); pickNumber(sum -((sum/10)*10)); delayMicroseconds(del);
  }
  buttoncheck();
  if(updw < 10){        // ###### if single digit ####
    clearLEDs(); pickDigit(4); pickNumber(updw); delayMicroseconds(del);}
  else{                 // ###### if dubble digit ####
    pickDigit(3); pickNumber(updw/10); delayMicroseconds(del); clearLEDs();
    pickDigit(4); pickNumber(updw -((updw/10)*10)); delayMicroseconds(del);
  }buttoncheck();
}
void startup_check(){    // ############### startup check(0)    ################### to check if all blocks light up ##########
  for(x = 1; x < 5; x++){
    pickDigit(x);partA();delay(del3);partB();delay(del3);partC();delay(del3);partD();delay(del3);partE();delay(del3);partF();delay(del3);partG();delay(del3);deci();delay(del3);clearLEDs();
    buttoncheck(); // ######## Read Buttons  ############## Read Buttons ######
  }
/*pickDigit(2);partA();delay(del3);partB();delay(del3);partC();delay(del3);partD();delay(del3);partE();delay(del3);partF();delay(del3);partG();delay(del3);deci();delay(del3);clearLEDs();
buttoncheck(); // ######## Read Buttons  ############## Read Buttons ######
pickDigit(3);partA();delay(del3);partB();delay(del3);partC();delay(del3);partD();delay(del3);partE();delay(del3);partF();delay(del3);partG();delay(del3);deci();delay(del3);clearLEDs();
buttoncheck(); // ######## Read Buttons  ############## Read Buttons ######
pickDigit(4);partA();delay(del3);partB();delay(del3);partC();delay(del3);partD();delay(del3);partE();delay(del3);partF();delay(del3);partG();delay(del3);deci();delay(del3);clearLEDs();
buttoncheck(); // ######## Read Buttons  ############## Read Buttons ###### 
*/
if (start == 0){  start = 1; mode = 1;}
}
void chesssetup(){       // ############### Void chesssetup(6)  ################### Void chesssetup  #########################
  buttoncheck();
  if(temp2 < millis()){if(temp ==0){temp =1;}if(temp == 1){temp =0;}temp2 = millis(); temp2 = temp2+500;}
  if(digiSelect == 1){if(temp==1){delay(12);}else{ clearLEDs();pickDigit(1);pickNumber(digi1);}}  else{ clearLEDs();pickDigit(1);pickNumber(digi1);}
  if(digiSelect == 2){if(temp==1){delay(12);}else{ clearLEDs();pickDigit(2);pickNumber(digi2);}}  else{ clearLEDs();pickDigit(2);pickNumber(digi2);}
  if(digiSelect == 3){if(temp==1){delay(12);}else{ clearLEDs();pickDigit(3);pickNumber(digi3);}}  else{ clearLEDs();pickDigit(3);pickNumber(digi3);}
  if(digiSelect == 4){if(temp==1){delay(12);}else{ clearLEDs();pickDigit(4);pickNumber(digi4);}}  else{ clearLEDs();pickDigit(4);pickNumber(digi4);}
  buttoncheck();
}
void chess(){            // ############### Void Chesstimers(7) ################### Void Chesstimers #########################
  delayMicroseconds(del); del2 =800;
  if (chesspause1 == 1 && chesspause2 == 0){ //###### run player 2 ####
    ch = chess2; pickDigit(3);  deci();delayMicroseconds(del2);pickDigit(4);  deci();delayMicroseconds(del2);
    ch--;chess2 = ch;if (ch <= 0){chesspause1 = 1; chesspause2 =1; pickDigit(4);  deci();}
  }
  if (chesspause1 == 0 && chesspause2 == 1){ //###### run player 1 ####
  ch = chess1; pickDigit(1);  deci();delayMicroseconds(del2);pickDigit(2);  deci();delayMicroseconds(del2);
  ch--;chess1 = ch;if (ch <= 0){chesspause1 = 1; chesspause2 =1; pickDigit(1);  deci();}
}
  if(ch<600){                                //###### time below 60 sec #### 10 =1 sec 100=10sec 1000 1m 40s
    for(x = 0;x<4;x++){  // ###### run number X times ####
      del =45;           // ###### slow down arduino micro sec ####
      clearLEDs();  pickDigit(1);  pickNumber(ch/1000);  delayMicroseconds(del);  delayMicroseconds(dels);
      clearLEDs();  pickDigit(2);  pickNumber((ch/100)-((ch/1000)*10));  delayMicroseconds(del);
      buttoncheck();
      clearLEDs();  pickDigit(3);  deci();  pickNumber((ch/10)-((ch/100)*10));  delayMicroseconds(del);
      clearLEDs();  pickDigit(4);  pickNumber(ch - ((ch/10)*10));  delayMicroseconds(del);
    }}
  else{                                      //###### time above 60 seconds ####
    for(x = 0;x<4;x++){  // ###### run number X times ####
      del = 0;           // ###### slow down arduino micro sec ####
      clearLEDs();  pickDigit(1);  pickNumber((ch/10)/600);  delayMicroseconds(del);  
      dubbleDot();
      clearLEDs();  pickDigit(2);  pickNumber(ch/600);  delayMicroseconds(del);
      buttoncheck(); dubbleDot(); 
      clearLEDs();  pickDigit(3);  pickNumber((ch-((ch/600)*600))/100);  delayMicroseconds(del);
      dubbleDot();
      clearLEDs();  pickDigit(4);  pickNumber((ch/10)-((ch/100)*10));  delayMicroseconds(del);
  }}
  buttoncheck(); del2 = 500; del = 0;
}
void buttoncheck(){      // ############### Void Buttoncheck    ################### Void Buttoncheck #########################
   button1 = digitalRead(bp1);  button2 = digitalRead(bp2);  button3 = digitalRead(bp3);
//#if button1 == 1
  if (button1 == 1){     //######################### Button 1 actv #########################
    if(mode == 1){       //########### score      ###########
    n1 ++;if(n1 > 99){n1=0;} x=0;
    while (button1 == 1){//########### while button is pressed do nothing ####
      delay(100); x++; button1 = digitalRead(bp1); button2 = digitalRead(bp2);
      if (button1 == 1 && button2 == 1){ // ################ Button 1 and 2 Active ##############
         x=0;
         while (button2 == 1){//########### while button is pressed do nothing ####
            x++;
            pickDigit(1);deci();delay(25);pickDigit(2);deci();delay(25);pickDigit(3);deci();delay(25);pickDigit(4);deci();delay(25);clearLEDs();
            button2 = digitalRead(bp2);
         }
         if(x>15){n1 = 0; n2 = 0; }
         if(x<15){n1--;n1--;  } 
      }
    }
    }
    if(mode == 2){       //########### stopwatch  ###########
      if(pause == 0){ pause = 1;}
      else{pause = 0;}
      while(button1 == 1){//########### while button is pressed do nothing ####
        delay(100); button1 = digitalRead(bp1);
       }
    }
    if(mode == 3){       //########### Up DownP   ###########
      deck = 0; u1=u2=u3=u4=u5=u6=u7=u08=u9=u10=u11=u12=u13=sum=0;
      while(button1 == 1){//########### while button is pressed do nothing ####
        clearLEDs();pickDigit(1);pickNumber(26);delay(10);pickNumber(26);delay(10);pickNumber(26);delay(10);pickNumber(26);delay(10);pickNumber(26);delay(10);
        button1 = digitalRead(bp1);
    }}
    if(mode == 5){       //########### Up DownT   ###########
      deck = 0; u1=u2=u3=u4=u5=u6=u7=u10=u11=u12=sum=0;
      while(button1 == 1){//########### while button is pressed do nothing ####
        clearLEDs();pickDigit(1);pickNumber(26);delay(10);pickNumber(26);delay(10);pickNumber(26);delay(10);pickNumber(26);delay(10);pickNumber(26);delay(10);
        button1 = digitalRead(bp1);
    }}
    if(mode == 6){       //########### chesssetup ###########
      switch(digiSelect){
        case 1: digi1++; if(digi1 > 9){ digi1 =0;} break;
        case 2: digi2++; if(digi2 > 9){ digi2 =0;} break;
        case 3: digi3++; if(digi3 > 5){ digi3 =0;} break;
        case 4: digi4++; if(digi4 > 9){ digi4 =0;} break;
      }
      timeSum = (digi1*6000)+(digi2*600)+(digi3*100)+(digi4*10); // ###### sum times in miliseconds ####
      while(button1==1){ //########### while button is pressed do nothing ####
        pickDigit(digiSelect);deci();delay(50);clearLEDs();delay(50);
        button1 = digitalRead(bp1);
      }
    }
    if(mode == 7){       //########### chess      ###########
      chesspause1 = 1; chesspause2 = 0; x=0; // ###### pause player 1 run player 2 ####
      while (button1 == 1){                  // ###### while button is pressed do  ####
        if (button1 ==1 && button2 ==1){     // ###### if button 2 is pressed as well ####
        chesspause1 = 1; chesspause2 = 1;    // ###### Pause both players ####
        x++; }
        pickDigit(1);deci();delay(25);pickDigit(2);deci();delay(25);pickDigit(3);deci();delay(25);pickDigit(4);deci();delay(25);clearLEDs(); button2 = digitalRead(bp2);button1 = digitalRead(bp1);
      }
      if(x >= 15){chess1 = 0; chess2 = 0;}   // ###### if held down for 1.5 sec reset counters ####
   }
  }
//#endif
//#if button2 == 1  
  if (button2 == 1){     //######################### Button 2 actv #########################
    if(mode == 1){       //########### score      ###########
     n2 ++;    if(n2 > 99){n2=0;}
    while (button2 == 1){//###### while button is pressed ####
      delay(100); button1 = digitalRead(bp1); button2 = digitalRead(bp2);
      if (button1 == 1 && button2 == 1){ // ################ Button 1 and 2 Active ##############
         x=0;
         while (button1 == 1){//###### while both buttons are pressed ####
            x++;pickDigit(1);deci();delay(25);pickDigit(2);deci();delay(25);pickDigit(3);deci();delay(25);pickDigit(4);deci();delay(25);clearLEDs();
            button1 = digitalRead(bp1);
         }
         if(x>15){n1 = 0; n2 = 0; }
         if(x<15){n2--;n2--;}
      }
    }
    }
    if(mode == 2){       //########### stopwatch  ###########
      n = 0;
    }
    if(mode == 3){       //########### Up DownP   ###########
      temp = random(1,14);
      if (temp == updw){ temp2 = random(4);  if(temp2 == 3){updw = temp;}else{updw = random(1,14);}}
      else{updw = temp;}
      x=1;
      while(x == 1){
        if(deck < 52){
        switch(updw){    //###### deck counting and checking only 4 of each allowed
          default: break;
          case 1: u1++; if(u1 > 4){temp = random(1,14);       if (temp == updw){ temp2 = random(4);  if(temp2 == 3){updw = temp;}else{updw = random(1,14);}}       else{updw = temp;} u1=4; }else{x=0;};break;
          case 2: u2++; if(u2 > 4){temp = random(1,14);       if (temp == updw){ temp2 = random(4);  if(temp2 == 3){updw = temp;}else{updw = random(1,14);}}       else{updw = temp;} u2=4;}else{x=0;};break;
          case 3: u3++; if(u3 > 4){temp = random(1,14);       if (temp == updw){ temp2 = random(4);  if(temp2 == 3){updw = temp;}else{updw = random(1,14);}}       else{updw = temp;} u3=4;}else{x=0;};break;
          case 4: u4++; if(u4 > 4){temp = random(1,14);       if (temp == updw){ temp2 = random(4);  if(temp2 == 3){updw = temp;}else{updw = random(1,14);}}       else{updw = temp;} u4=4;}else{x=0;};break;
          case 5: u5++; if(u5 > 4){temp = random(1,14);       if (temp == updw){ temp2 = random(4);  if(temp2 == 3){updw = temp;}else{updw = random(1,14);}}       else{updw = temp;} u5=4;}else{x=0;};break;
          case 6: u6++; if(u6 > 4){temp = random(1,14);       if (temp == updw){ temp2 = random(4);  if(temp2 == 3){updw = temp;}else{updw = random(1,14);}}       else{updw = temp;} u6=4;}else{x=0;};break;
          case 7: u7++; if(u7 > 4){temp = random(1,14);       if (temp == updw){ temp2 = random(4);  if(temp2 == 3){updw = temp;}else{updw = random(1,14);}}       else{updw = temp;} u7=4;}else{x=0;};break;
          case 8: u08++; if(u08 > 4){temp = random(1,14);       if (temp == updw){ temp2 = random(4);  if(temp2 == 3){updw = temp;}else{updw = random(1,14);}}       else{updw = temp;}u08=4;}else{x=0;};break;
          case 9: u9++; if(u9 > 4){temp = random(1,14);       if (temp == updw){ temp2 = random(4);  if(temp2 == 3){updw = temp;}else{updw = random(1,14);}}       else{updw = temp;} u9=4;}else{x=0;};break;
          case 10: u10++; if(u10 > 4){temp = random(1,14);       if (temp == updw){ temp2 = random(4);  if(temp2 == 3){updw = temp;}else{updw = random(1,14);}}       else{updw = temp;}u10=4; }else{x=0;};break;
          case 11: u11++; if(u11 > 4){temp = random(1,14);       if (temp == updw){ temp2 = random(4);  if(temp2 == 3){updw = temp;}else{updw = random(1,14);}}       else{updw = temp;}u11=4; }else{x=0;};break;
          case 12: u12++; if(u12 > 4){temp = random(1,14);       if (temp == updw){ temp2 = random(4);  if(temp2 == 3){updw = temp;}else{updw = random(1,14);}}       else{updw = temp;}u12 =4; }else{x=0;};break;
          case 13: u13++; if(u13 > 4){temp = random(1,14);       if (temp == updw){ temp2 = random(4);  if(temp2 == 3){updw = temp;}else{updw = random(1,14);}}       else{updw = temp;}u13=4; }else{x=0;};break;
       }
       }
        else{            //###### deck has run out ####
          deck = 0;u1=u2=u3=u4=u5=u6=u7=u08=u9=u10=u11=u12=u13=sum=0;
          for(x=0;x<15;x++){//###### show P to show new deck ####
          clearLEDs();pickDigit(1);pickNumber(26);delayMicroseconds(del);
          }}
        sum= u1+u2+u3+u4+u5+u6+u7+u08+u9+u10+u11+u12+u13;
     }
     deck++;
     if (sum >= 52){     //###### deck has run out ####
       deck = 0;
       u1=u2=u3=u4=u5=u6=u7=u08=u9=u10=u11=u12=u13=sum=0;
       for(x=0;x<15;x++){//###### show P to show new deck ####
       clearLEDs();pickDigit(1);pickNumber(26);delayMicroseconds(del);
       }
       while(button2 == 1){//###### do nothing while button is pressed ####
         delay(100); button2 = digitalRead(bp2);
       }
    }
    }
    if(mode == 5){       //########### Up DownT   ###########
      temp = random(1,11);
      if (temp == updw){ temp2 = random(4);  if(temp2 == 3){updw = temp;}else{updw = random(1,13);}}
      else{updw = temp;}
      x=1;
      while(x == 1){
        if(deck < 40){
        switch(updw){    //###### deck counting and checking only 4 of each allowed
          default: break;
          case 1: u1++; if(u1 > 4){temp = random(1,11);       if (temp == updw){ temp2 = random(4);  if(temp2 == 3){updw = temp;}else{updw = random(1,11);}}       else{updw = temp;} u1=4;}else{x=0;};break;
          case 2: u2++; if(u2 > 4){temp = random(1,11);       if (temp == updw){ temp2 = random(4);  if(temp2 == 3){updw = temp;}else{updw = random(1,11);}}       else{updw = temp;} u2=4;}else{x=0;};break;
          case 3: u3++; if(u3 > 4){temp = random(1,11);       if (temp == updw){ temp2 = random(4);  if(temp2 == 3){updw = temp;}else{updw = random(1,11);}}       else{updw = temp;} u3=4;}else{x=0;};break;
          case 4: u4++; if(u4 > 4){temp = random(1,11);       if (temp == updw){ temp2 = random(4);  if(temp2 == 3){updw = temp;}else{updw = random(1,11);}}       else{updw = temp;} u4=4;}else{x=0;};break;
          case 5: u5++; if(u5 > 4){temp = random(1,11);       if (temp == updw){ temp2 = random(4);  if(temp2 == 3){updw = temp;}else{updw = random(1,11);}}       else{updw = temp;} u5=4;}else{x=0;};break;
          case 6: u6++; if(u6 > 4){temp = random(1,11);       if (temp == updw){ temp2 = random(4);  if(temp2 == 3){updw = temp;}else{updw = random(1,11);}}       else{updw = temp;} u6=4;}else{x=0;};break;
          case 7: u7++; if(u7 > 4){temp = random(1,11);       if (temp == updw){ temp2 = random(4);  if(temp2 == 3){updw = temp;}else{updw = random(1,11);}}       else{updw = temp;} u7=4;}else{x=0;};break;
          case 8: u10++; if(u10 > 4){temp = random(1,11);     if (temp == updw){ temp2 = random(4);  if(temp2 == 3){updw = 10;}else{updw = random(1,11);}}       else{updw = 10;}u10=4; }else{x=0;};break;
          case 9: u11++; if(u11 > 4){temp = random(1,11);     if (temp == updw){ temp2 = random(4);  if(temp2 == 3){updw = 11;}else{updw = random(1,11);}}       else{updw = 11;}u11=4; }else{x=0;};break;
          case 10: u12++; if(u12 > 4){temp = random(1,11);    if (temp == updw){ temp2 = random(4);  if(temp2 == 3){updw = 12;}else{updw = random(1,11);}}       else{updw = 12;}u12=4; }else{x=0;};break;
//          case 13: u13++; if(u13 > 4){temp = random(1,14);       if (temp == updw){ temp2 = random(4);  if(temp2 == 3){updw = temp;}else{updw = random(1,14);}}       else{updw = temp;}u13=4; }else{x=0;};break;
       }
       }
        else{            //###### deck has run out ####
          deck = 0;u1=u2=u3=u4=u5=u6=u7=u10=u11=u12=sum=0;
          for(x=0;x<15;x++){//###### show T to show new deck ####
          clearLEDs();pickDigit(1);pickNumber(30);delayMicroseconds(del);
          }}
        sum= u1+u2+u3+u4+u5+u6+u7+u10+u11+u12;
     }
     deck++;
     if (sum >= 40){     //###### deck has run out ####
       deck = 0;
       u1=u2=u3=u4=u5=u6=u7=u10=u11=u12=sum=0;
       for(x=0;x<15;x++){//###### show T to show new deck ####
       clearLEDs();pickDigit(1);pickNumber(30);delayMicroseconds(del);
       }
       while(button2 == 1){//###### do nothing while button is pressed ####
         delay(100); button2 = digitalRead(bp2);
       }
    }
    }
    if(mode == 6){       //########### chesssetup ###########
      digiSelect++;      //###### moves the cursor down 1 position ####
      if(digiSelect > 4){digiSelect = 1;}
      while(button2==1){
        pickDigit(digiSelect);deci();delay(25);clearLEDs();delay(50);
        button2 = digitalRead(bp2);
      }
    }
    if(mode == 7){       //########### chess      ###########
      chesspause1 = 0; chesspause2 = 1; x=0;
      while (button2 == 1){ //###### switch to player 1 ####
        if (button1 ==1 && button2 ==1){chesspause1 = 1; chesspause2 = 1; x++; }
        pickDigit(1);deci();delay(25);pickDigit(2);deci();delay(25);pickDigit(3);deci();delay(25);pickDigit(4);deci();delay(25);clearLEDs(); button2 = digitalRead(bp2);button1 = digitalRead(bp1);
      }
      if(x >= 15){chess1 = 0; chess2 = 0;}
    }
 }
    
//#endif
  if (button1 == 1 && button2 == 1){ // ################ Button 1 and 2 Active ##############
    n1 = 0; n2 = 0;    
  }
  if (button3 == 1){ //######################### Button 3 actv #########################
    mode++;if(mode > 7){ mode = 0;}
    while(button3== 1){
      pickDigit(1);pickNumber(mode);delay(10);pickDigit(1);pickNumber(mode);delay(10);pickDigit(1);pickNumber(mode);delay(10);pickDigit(1);pickNumber(mode);delay(10);pickDigit(1);pickNumber(mode);delay(10);
      button3 = digitalRead(bp3);
    }
    if (mode == 7){ if (chess1 == 0 && chess2 == 0){ chess1 = chess2 = ch = timeSum;}}  
  }
}
void pickDigit(int x){   // ############### void pick digit     ################### void pick digit  #########################
  digitalWrite(P0, LOW); digitalWrite(P1, LOW); digitalWrite(P2, LOW);  digitalWrite(PA, HIGH);
  switch(x){ //###################### digit switch ################
    case 1:  digitalWrite(P0, LOW);  digitalWrite(P1, LOW);  digitalWrite(P2, LOW);  digitalWrite(PA, LOW);  break; // 000
    case 2:  digitalWrite(P0, HIGH); digitalWrite(P1, LOW);  digitalWrite(P2, LOW);  digitalWrite(PA, LOW);  break; // 001
    case 3:  digitalWrite(P0, LOW);  digitalWrite(P1, HIGH); digitalWrite(P2, LOW);  digitalWrite(PA, LOW);  break; // 010
    case 4:  digitalWrite(P0, HIGH); digitalWrite(P1, HIGH); digitalWrite(P2, LOW);  digitalWrite(PA, LOW);  break; // 011
    default: digitalWrite(P0, LOW);  digitalWrite(P1, LOW);  digitalWrite(P2, LOW);  digitalWrite(PA, HIGH); break; // XXX
  }
}
void pickNumber(int x){  // ############### void pick Number    ################### void pick number #########################
  switch(x){             // ############## number switch        ###################
    default: zero(); break;
    case 1: one(); break;
    case 2: two(); break;
    case 3: three(); break;
    case 4: four(); break;
    case 5: five(); break;
    case 6: six(); break;
    case 7: seven(); break;
    case 8: eight(); break;
    case 9: nine(); break;
    case 10: emty();break;   //space
    case 11: AAA(); break;
    case 12: eight(); break; // B
    case 13: CCC(); break;
    case 14: DDD(); break;   // d
    case 15: EEE(); break;
    case 16: FFF(); break;
    case 17: GGG(); break;
    case 18: HHH(); break;
    case 19: one(); break;   // i
    case 20: JJJ(); break;  
    case 22: LLL(); break; 
    case 24: NNN(); break;   // n
    case 25: zero();break;   // O
    case 26: PPP(); break;
    case 27: QQQ(); break;   // q
    case 28: RRR(); break;
    case 29: five();break;   // S
    case 30: TTT(); break;   // t
    case 31: UUU(); break;   // U
    case 32: VVV(); break;   // v
  }
}

//####################################### DIGITS #################### DIGITS ###################################
void dubbleDot (){ // shows ":"
    digitalWrite(P0, LOW);  digitalWrite(P1, LOW);  digitalWrite(P2, HIGH);  digitalWrite(PA, LOW);delayMicroseconds(del2);     // 100  
}
void clearLEDs(){  // turn everything off
   digitalWrite(N0, LOW);  digitalWrite(N1, LOW);  digitalWrite(N2, LOW);  digitalWrite(NA, HIGH);  // xxx 
   digitalWrite(P0, HIGH);  digitalWrite(P1, HIGH);  digitalWrite(P2, HIGH);  digitalWrite(PA, HIGH);
   }
void emty(){ //space
   digitalWrite(N0, LOW);  digitalWrite(N1, LOW);  digitalWrite(N2, LOW);  digitalWrite(NA, HIGH); delayMicroseconds(del2);      // 000 A
   }
void zero(){ //ABCDEF
partA();partB();partC();partD();partE();partF();partA();}
void one(){  // BC
partB();partC();partB();partC();partB();partC();partB();}
void two(){  //AB DE G
partA();partB();partD();partE();partG();partA();partB();}
void three(){//ABCD  G
partA();partB();partC();partD();partG();partA();partB();}
void four(){ // BC  FG
partB();partC();partF();partG();partB();partC();partF();}
void five(){ //A CD FG
partA();partC();partD();partF();partG();partA();partC();}
void six(){  //  CDEFG
partC();partD();partE();partF();partG();partC();partD();}
void seven(){//ABC
partA();partB();partC();partA();partB();partC();partA();}
void eight(){//ABCDEFG 
partA();partB();partC();partD();partE();partF();partG();}
void nine(){ //ABC  FG
partA();partB();partC();partF();partG();partA();partB();}
void AAA(){  //ABC EFG    (11)A
partA();partB();partC();partA();partE();partF();partG();}
void CCC(){  //A  DEF     (13)C
partA();partD();partE();partF();partA();partD();partE();}
void DDD(){  // BCDE G   (14)d
partG();partB();partC();partD();partE();partB();partG();}
void EEE(){  //A  DEFG    (15)E
partA();partG();partF();partD();partE();partF();partG();}
void FFF(){  //A   EFG    (16)F
partA();partE();partF();partG();partE();partF();partA();}
void GGG(){  //A  CDEF    (17)G
partA();partF();partC();partD();partE();partF();partA();}
void HHH(){  // BC EFG    (18)H
partB();partC();partE();partF();partG();partB();partC();}
void JJJ(){  // BCD       (20)J
  partB();partC();partD();partB();partC();partD();partB();}
void LLL(){  //   DEF     (22)L
  partD();partE();partF();partD();partE();partF();partD();}
void NNN(){  //  C E G    (24)n
partC();partE();partG();partC();partE();partG();partC();}
void PPP(){  //AB  EFG    (26)P
partA();partB();partG();partA();partE();partF();partG();}
void QQQ(){  //ABC  FG    (27)q
partA();partB();partC();partF();partG();partA();partB();}
void RRR(){  //ABC EFG    (28)R
partA();partB();partC();partA();partE();partF();partG();}
void TTT(){  //   DEFG    (30)t
partD();partE();partF();partD();partE();partF();partG();}
void UUU(){  // BCDEF     (31)U
partF();partB();partC();partD();partE();partF();partB();}
void VVV(){  //  CDE      (32)v
partC();partD();partE();partC();partD();partE();partC();}
//####################################### DIGIT PARTS ################ DIGIT PARTS ################################
void partA(){//LED PART A
  digitalWrite(N0, LOW);  digitalWrite(N1, LOW);  digitalWrite(N2, LOW);  digitalWrite(NA, LOW); delayMicroseconds(del2);}// 000 A
void partB(){//LED PART B
  digitalWrite(N0, HIGH); digitalWrite(N1, LOW);  digitalWrite(N2, LOW);  digitalWrite(NA, LOW); delayMicroseconds(del2);}// 001 B
void partC(){//LED PART C
  digitalWrite(N0, LOW);  digitalWrite(N1, HIGH); digitalWrite(N2, LOW);  digitalWrite(NA, LOW); delayMicroseconds(del2);}// 010 C
void partD(){//LED PART D
  digitalWrite(N0, HIGH); digitalWrite(N1, HIGH); digitalWrite(N2, LOW);  digitalWrite(NA, LOW); delayMicroseconds(del2);}// 011 D
void partE(){//LED PART E
  digitalWrite(N0, LOW);  digitalWrite(N1, LOW);  digitalWrite(N2, HIGH); digitalWrite(NA, LOW); delayMicroseconds(del2);}// 100 E
void partF(){//LED PART F
  digitalWrite(N0, HIGH); digitalWrite(N1, LOW);  digitalWrite(N2, HIGH); digitalWrite(NA, LOW); delayMicroseconds(del2);}// 101 F
void partG(){//LED PART G
  digitalWrite(N0, LOW);  digitalWrite(N1, HIGH); digitalWrite(N2, HIGH); digitalWrite(NA, LOW); delayMicroseconds(del2);}// 110 G
void deci() {//LED PART .
  digitalWrite(N0, HIGH); digitalWrite(N1, HIGH); digitalWrite(N2, HIGH); digitalWrite(NA, LOW); delayMicroseconds(del2);}// 111 .
