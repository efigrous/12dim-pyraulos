#Πρόγραμμα για επικοινωνία του Ηλεκτρονικού Υπολογιστή με το Arduino μέσω Python
#Code by: Aswinth Raj, Dated: 8-9-2017
#Website: www.circuitdigest.com

import serial # το πακέτο Serial εισάγεται για Σειριακή επικοινωνία ανάμεσα σε Arduino και HY
import time #το πακέτο time απαιτείται για τις συναρτήσεις delay
 
ArduinoSerial = serial.Serial('com6',9600) #Δημιουργία αντικειμένου  Serial port με όνομα arduinoSerialData
time.sleep(2) #Περιμένουμε  2 seconds να εγκατασταθεί η επικονωνία

print ArduinoSerial.readline() #Διάβασε τα σειριακά δεδομένα από το arduino


 
while 1: #Do this forever Για πάντα κάνε τα εξής:


    var = ArduinoSerial.readline()#get input from user Διάβασε τα δεδομένα από το arduino
    print "you entered", int(var) #print the intput for confirmation Τύπωσε τα δεδομένα για επιβεβαίωση
    print (int(var) == 1) #print the intput for confirmation
    print var  #print the intput for confirmation


    
    
    if  (int(var) == 1): #if the value is 1  Αν το arduino εδωσε (μέσω της σειριακής θύρας) στο Python IDLE δεδομένο 1 (δηλ. ο χρήστης πάτησε το διακόπτη) 
        ArduinoSerial.write('1') #send 1
        print ("LED turned ON")
        time.sleep(1)
        
        #το python να εκτελέσει την εντολή του λειτουργικού συστήματος για την εκίννηση του βίντεο apollo11.mp4
        import os
        cmd = '"C:\\Python27\\apollo11.mp4"   --fullscreen   --play-and-exit'
        os.system(cmd)


    if (var == '0'): #if the value is 0  
        ArduinoSerial.write('0') #send 0
        print ("LED turned OFF")
        time.sleep(1)
