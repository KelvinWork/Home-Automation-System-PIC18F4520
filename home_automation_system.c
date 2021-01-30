#include <xc.h>

#pragma config OSC=HS
#pragma config LVP=OFF
#pragma config WDT=OFF

void startLCD(void);
void sendfunction(char);
void sendtext(char);
void speaker(int);
void Blink(void);
void timer(void);
void codeRed(void);
void correct();


#define dataLCD PORTD
#define LCD_E   PORTAbits.RA0
#define LCD_RS  PORTAbits.RA1


#define LB      PORTAbits.RA2
#define S8      PORTAbits.RA3
#define TS5     PORTCbits.RC7

#define L1      PORTAbits.RA5
#define L3      PORTEbits.RE1

#define TouchS  PORTEbits.RE2


#define SL1     PORTAbits.RA4
#define SL2     PORTBbits.RB1

#define SP      PORTEbits.RE0


#define DA     PORTBbits.RB0
#define E      PORTBbits.RB1
#define D      PORTBbits.RB2
#define C      PORTBbits.RB3
#define B      PORTBbits.RB4
#define A      PORTBbits.RB5

char passPosition[] = {0b11000110, 0b11000111,0b11001000,0b11001001};
//* POSITION WHEN USER PRESSED A KEY


char initMess[] 	=  	 "WELCOME";
char second[]   	=  	 "OWNER PRESS A";
char prompt[]         =  	 "ENTER PASSWORD";
char armed[]    	=  	 "System is armed ";
char unarmed[] 	=  	 "System is unarmed";
char access[]         =  	 "Access Granted.";
char red[]      	=   	 "Calls Sent";

char K1[]       	=   "Key 1 was pressed";
char K2[]       	=   "Key 2 was pressed";
char K3[]       	=   "Key 3 was pressed";
char K4[]       	=   "Key 4 was pressed";
char K5[]       	=   "Key 5 was pressed";
char K6[]       	=   "Key 6 was pressed";
char K7[]       	=   "Key 7 was pressed";
char K8[]       	=   "Key 8 was pressed";
char K9[]       	=   "Key 9 was pressed";
char K0[]       	=   "Key 0 was pressed";
char KA[]      	=   "Key A was pressed";
char KB[]      	=   "Key B was pressed";
char KC[]       	=   "Key C was pressed";
char KD[]       	=   "Key D was pressed";
char KE[]       	=   "Key E was pressed";
char KF[]       	=   "Key F was pressed";

char star[]     	= "****";

char pwd[4]    	= {5,3,8,6};
int cPos        	= 0;




unsigned reversed [10]={0b00011000,0b00000000,0b01111000,0b00000011,
          0b00010010,0b00011001,0b01010000,0b01000100,0b00101111,0b00100000};




void main() {

    ADCON1= 0X0F;
    LB=0;
    L1=0;
    L3=0;


    TRISA= 0b11001000;
    TRISB= 0b11111101; //keypad
    TRISC= 0b10000000; //7 segment
    TRISD= 0b00000000; //LCD
    TRISE= 0b11101100;

    int attempt =0;
    int pwdCount =0;
    int Key;
    unsigned correct1=0;
    unsigned char  i;
      startLCD();
      L3=0;
      L1=0;

     sendfunction(0b10000100); //pos
        for (i=0; initMess[i]!=0; i++){
        sendtext(initMess[i]); //welcome

        }
    sendfunction(0b11000001); //pos
        for (i=0; second[i]!=0; i++){
        sendtext(second[i]);  //key in pass
        sendfunction(0b00001100);
        }
    while(1){
     if(DA==1){
         _delay(190000);
         if(D==1 && C==1 && B==0&& A==0){
             sendfunction(0b00000001); //Clr Screen
            sendfunction(0b10000000); //pos

            for (i=0; prompt[i]!=0; i++){
                sendtext(prompt[i]);  //key in pass
                _delay(500);
            }//password prompt

            sendfunction(0b00001111); //blink cursor
            sendfunction(0b11000110); //cursor pos


            // CHECK KEY

            attempt =0;

         while(attempt<3){
             L3=0;
             sendfunction(0b00000001); //Clr Screen
            sendfunction(0b10000000); //pos

            for (i=0; prompt[i]!=0; i++){
                sendtext(prompt[i]);  //key in pass
                _delay(500);
            }//password prompt

            sendfunction(0b00001111); //blink cursor
            sendfunction(0b11000110); //cursor pos

             for( int pwdCount = 0; pwdCount<4;){
                 if (DA==1){
                     _delay(190000);
             if(D==0 && C==0 && B==0&& A==0){       //Key 1
            Key = 1;

        }
        else if(D==0 && C==0 && B==0 && A==1){ //Key 2
            Key = 2;
        }
        else if(D==0 && C==0 && B==1&& A==0){ //Key 3
            Key = 3;
        }
        else if(D==0 && C==1 && B==0&& A==0){  //Key 4
            Key = 4;
        }

        else if(D==0 && C==1 && B==0&& A==1){   //Key 5
            Key = 5;
        }

        else if(D==0 && C==1 && B==1&& A==0){  //Key 6
            Key = 6;
        }

        else if(D==1 && C==0 && B==0&& A==0){  //Key 7
            Key = 7;
        }
        else if(D==1 && C==0 && B==0&& A==1){  //Key 8
            Key = 8;
        }

        else if(D==1 && C==0 && B==1&& A==0){  //Key 9
            Key = 9;
        }
        else if(D==1 && C==1 && B==0&& A==1){  //Key 0
            Key = 0;
        }

        else if(D==1 && C==1 && B==0&& A==0){  //Key A
            Key = 11;
        }

        else if(D==1 && C==1 && B==1&& A==0){  //Key B
            Key = 12;
        }
        else if(D==1&& C==1 && B==1&& A==1){  //Key C
            Key = 13;
        }

        else if(D==1 && C==0 && B==1&& A==1){   //Key D
            Key = 14;
        }

        else if(D==0 && C==1 && B==1&& A==1){ //Key E
            Key = 15;
        }

        else if(D==0 && C==0 && B==1&& A==1){  //Key F
            Key = 16;
        }
         sendfunction(passPosition[pwdCount]);
         sendtext(star[pwdCount]);
       //  sendtext(pwdCount+0x30); //show number on the LCD Only
            if(Key == pwd[pwdCount]){
           pwdCount++;
           correct1 = 1;


        }
            else if(Key != pwd[pwdCount]){
                LB = 0;
                correct1 = 0;

            break;
            }
                 }//DA
            }   // for loop pwdCount


            if (correct1 == 1){
                 sendfunction(0b00000001); //Clr Screen
                sendfunction(0b10000000); //pos
                 for (i=0; access[i]!=0; i++){
                sendtext(access[i]);  //key in pass
                _delay(500);
                 }//password prompt
                L3 = 1;
                for(i=0; i<10; i++){
                _delay(160000);
                }

                correct();
            }
            else {
                attempt++;
                if (attempt==3)
                {
                 codeRed();
                sendfunction(0b00000001); //Clr Screen
                sendfunction(0b10000000); //pos

                for (i=0; red[i]!=0; i++){
                sendtext(red[i]);
                _delay(500);
                }// alert
                     L1 =1;
                    codeRed(); //why it diidnt work?
                }
            }


         }//  while attempt

         }// if key A is pressed
     }// if for DA

    }//while loop
}


     void correct(){
         int i = 0;
       while(1){
     if(TS5 ==1){
                sendfunction(0b00000001); //Clr Screen
                sendfunction(0b10000000); //pos
                 for (i=0; armed[i]!=0; i++){
                sendtext(armed[i]);  //key in pass
                _delay(500);
                 }//armed

        L1 = 1;
        L3 = 0;
        if(TouchS == 0 || S8 ==0){
            sendfunction(0b00000001); //Clr Screen
                sendfunction(0b10000000); //pos

                for (i=0; red[i]!=0; i++){
                sendtext(red[i]);
                _delay(500);
                }// alert

            codeRed();
        }

    }
    //WHEN IT IS ARMED WHEN IT IS ARMED  WHEN IT IS ARMED
   //WHEN IT IS ARMED WHEN IT IS ARMED  WHEN IT IS ARMED




     // ENERGY SAVING ENERGY SAVING ENERGY SAVING
    // ENERGY SAVING ENERGY SAVING ENERGY SAVING
    else if(TS5 ==0){
                 sendfunction(0b00000001); //Clr Screen
                sendfunction(0b10000000); //pos
                 for (i=0; unarmed[i]!=0; i++){
                sendtext(unarmed[i]);  //key in pass
                _delay(500);
                 }//unarmed
        L3 =1;
        L1 =0;
    LB = 1;
     _delay(4000);
    LB =0;
     _delay(10000);

   if(S8 ==0 || TouchS==0){
       LB =1;
       timer();
     LB = 0;
     _delay(100);

   }

    }

     }
     }

 void codeRed(){
     for(int e=0; TS5 != 0; e++){ // when TS 5 is down

        L1 = 1;
        LB = 1;
        SP =~ SP;
        _delay(500);
        L1 =0;
        LB =0;
        SP=~ SP;
        _delay(5000);

    }
 }



void timer(){
      int i =0;
        for(int b=4; b<10; b++){
            SL1 =0;
            SL2 =1;
            PORTC =reversed[b];
            _delay(50000);
          for(int s=0; s<10;s++){
                SL1 = 1;
                SL2 = 0;

                PORTC = reversed[s];
                for(i=0; i<10; i++)
                     _delay(50000);
                 SL1 =0;
                 SL2 =1;
                 PORTC =reversed[b];

                 for(i=0; i<10; i++)
                     _delay(50000);
         }// for loop count
    }// for loop switching seven segment
} //void timer()


void startLCD(){
    sendfunction(0b00111000); //funct set
    sendfunction(0b00001111); // display
    sendfunction(0b00000110); //entry
    sendfunction(0b00000001);  //clr display
    sendfunction(0b00000010);  //return cursor
}

void sendfunction(char x){
    LCD_RS   = 0;
    LCD_E    = 1;
    dataLCD  = x;
    LCD_E    = 0;
    _delay(1000);
}

void sendtext(char x){
    LCD_RS   = 1;
    LCD_E    = 1;
    dataLCD  = x;
    LCD_E    = 0;
    _delay(500);
}
