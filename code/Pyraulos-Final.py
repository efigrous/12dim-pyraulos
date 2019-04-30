#��������� ��� ����������� ��� ������������ ���������� �� �� Arduino ���� Python
#Code by: Aswinth Raj, Dated: 8-9-2017
#Website: www.circuitdigest.com

import serial # �� ������ Serial ��������� ��� �������� ����������� ������� �� Arduino ��� HY
import time #�� ������ time ���������� ��� ��� ����������� delay
 
ArduinoSerial = serial.Serial('com6',9600) #���������� ������������  Serial port �� ����� arduinoSerialData
time.sleep(2) #�����������  2 seconds �� ������������ � ����������

print ArduinoSerial.readline() #������� �� �������� �������� ��� �� arduino


 
while 1: #Do this forever ��� ����� ���� �� ����:


    var = ArduinoSerial.readline()#get input from user ������� �� �������� ��� �� arduino
    print "you entered", int(var) #print the intput for confirmation ������ �� �������� ��� �����������
    print (int(var) == 1) #print the intput for confirmation
    print var  #print the intput for confirmation


    
    
    if  (int(var) == 1): #if the value is 1  �� �� arduino ����� (���� ��� ��������� �����) ��� Python IDLE �������� 1 (���. � ������� ������ �� ��������) 
        ArduinoSerial.write('1') #send 1
        print ("LED turned ON")
        time.sleep(1)
        
        #�� python �� ��������� ��� ������ ��� ������������ ���������� ��� ��� �������� ��� ������ apollo11.mp4
        import os
        cmd = '"C:\\Python27\\apollo11.mp4"   --fullscreen   --play-and-exit'
        os.system(cmd)


    if (var == '0'): #if the value is 0  
        ArduinoSerial.write('0') #send 0
        print ("LED turned OFF")
        time.sleep(1)
