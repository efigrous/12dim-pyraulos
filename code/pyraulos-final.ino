

// Include the Servo library
#include <Servo.h> 

// Create a servo object
Servo Servo1;
Servo Servo2;

//Δήλωση μεταβλητών
int  switchState = 0;
int data;

void setup() {
  
  // put your setup code here, to run once:

  // Ορίζουμε το  data rate σε bits per secondο  (baud) για σειριακή μετάδοση δεδομένων από την αντίστοιχη θύρα 
  //για επικοινωνία του Arduino με τον Υπολογιστή. 
  //Χρειαζόμαστε την επικοινωνία Arduino-Ηλεκτρονικό Υπολογιστή, ώστε όταν ο χρήστης πατήσει το κόκκινο κουμπί
  // να δώσει σήμα το Arduino στου ΗΥ να ξεκινήσει το βίντεο της εκτόλευσης του Apollo 11.
  
  Serial.begin(9600); //initialize serial COM at 9600 baudrate
  Serial.println("Hi!, I am Arduino");

   // To pin 2 είναι αυτό που συνδέεται ο διακόπτης και είναι INPUT ώστε το πρόγραμμα να διαβάζει το δυναμικό μέσω της digitalRead(2). 
   // Αν η digitalRead(2) δώσει HIGH έχει πατηθεί ο διακόπτης αλλιώς δεν έχει.
    pinMode(2,INPUT);

    // Σε αυτά τα pins συνδέονται τα LEDs και ρυθμίζονται σε κατάσταση OUTPUT, ώστε να ρυθμίζεται μέσω της digitalWrite() αν το δυναμικό τους είναι HIGH (ανάβει το LED) ή LOW (σβήνει το LED)
    pinMode(3,OUTPUT);
    pinMode(4,OUTPUT);
    pinMode(5,OUTPUT);
    pinMode(6,OUTPUT);
    pinMode(7,OUTPUT);
    pinMode(8,OUTPUT);
    pinMode(9,OUTPUT);
    pinMode(10,OUTPUT);
    pinMode(11,OUTPUT);
    pinMode(12,OUTPUT);


    // Αρχικά όλα το LEDs είναι σβηστά
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);


  // We need to attach the servo to the used pin number
  //αρχικοποίηση για τους servo motors , τους αποσπούμε από τα digital pins
    Servo1.detach();
    Servo2.detach();


}

void loop() {
  // put your main code here, to run repeatedly:

            //Το πρόγραμμα διαβάζει δεδομένα από τη σειριακή θύρα επικοινωνίας του Arduino με τον ΗΥ
            while (Serial.available()){  
            data = Serial.read();
          }

            // Το πρόγραμμα διαβάζει το δυναμικό στο Pin 2 όπου συνδέεται ο διακόπτης
             switchState = digitalRead(2);

             
            if(switchState ==HIGH){   // Αν πατήθηκε ο διακόπτης 
                
                    Serial.println("1"); //Το πρόγραμμα στέλνει το δεδομένο "1" στη σειριακή θύρα επικοινωνίας Arduino - Ηλεκτρονικού Υπολογιστή. 
                                         // Το δεδομένο αυτό θα διαβάσει πρόγραμμα στο κέλυφος  Python IDLE στον Ηλεκτρονικό Υπολογιστή για να ξεκινήσει 
                                         // βίντεο με την αντίστίστροφη μέτρηση των τελευταίων 20sec πριν την εκτόξευση του  apollo11, Ιούλιος 1969.
                    delay(11000);        //Το πρόγραμμα στο Arduino περιμένει 10 sec, όπουν στο ΗΥ παίζει το βίντεο για να συγχρονιστεί με την κατασκευή τα τελευταία 10sec.
                    // To 10o SEC πριν την εκτόξευση ανάβουν όλα τα LEDs
                    digitalWrite(3,HIGH);
                    digitalWrite(4,HIGH);
                    digitalWrite(5,HIGH);
                    digitalWrite(6,HIGH);
                    digitalWrite(7,HIGH);
                    digitalWrite(8,HIGH);
                    digitalWrite(9,HIGH);
                    digitalWrite(10,HIGH);        
                    digitalWrite(11,HIGH);       
                    digitalWrite(12,HIGH);                                                  

                    //Kάθε sec σβήνει και από ένα LED σε συγχρονισμό με το βίντεο: 10, 9, 8,...
                    delay(1000);
                    digitalWrite(3,LOW);
                    delay(1000);
                    digitalWrite(4,LOW);
                    delay(1000);
                    digitalWrite(5,LOW);
                    delay(1000);
                    digitalWrite(6,LOW);      
                    delay(1000);
                    digitalWrite(7,LOW);             
                    delay(1000);
                    digitalWrite(8,LOW);   
                    delay(1000);
                    digitalWrite(9,LOW);      
                    delay(1000);
                    digitalWrite(10,LOW);    
                    delay(1000);
                    digitalWrite(11,LOW);              
                    delay(1000);
                    digitalWrite(12,LOW);                                                                                                                   


                   delay(1000);
                   // Σύνδεση των 2 servo motors στο pin 13
                   Servo1.attach(13);
                   Servo2.attach(13);
                  // Οι servo motors στρέφουν τους βραχίονές τους κατά 90 μοίρες
                  Servo1.write(90);
                  Servo2.write(90);
                  delay(1000);

                  // Αποσύνδεση των servo motors
                   Servo1.detach();
                   Servo2.detach();
            }
}
