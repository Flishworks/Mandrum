# to run this:
#\Anaconda3\python.exe C:\Users\avido\Documents\PythonScripts\manDrum\manDrum.py

import serial
import numpy as np
from matplotlib import pyplot as plt
from time import time
import keyboard
import pygame
import os.path, sys
import pygame.mixer, pygame.time

mixer = pygame.mixer
time = pygame.time
mixer.init(frequency=22050, size=-16, channels=16, buffer=512)
ser = serial.Serial('COM6', 9600)

main_dir = os.path.split(os.path.abspath(__file__))[0]
kick = mixer.Sound(main_dir+'/kick.wav')
hat = mixer.Sound(main_dir+'/hat.wav')
snare = mixer.Sound(main_dir+'/snare.wav')
crash = mixer.Sound(main_dir+'/crash.wav')
mario = mixer.Sound(main_dir+'/smb_powerup.wav')


#channelDelay=np.zeros((4))
while not keyboard.is_pressed('space'):
    if ser.in_waiting>0:
        drum = ser.readline()
        drum=str(drum)
        if ("1" in drum):
            mixer.Channel(0).play(snare)
        if ("2" in drum):
            mixer.Channel(1).play(hat)
        if ("3" in drum):
            mixer.Channel(2).play(crash)
        if ("4" in drum):
            mixer.Channel(3).play(kick)
        #if ("5" in drum):
            #mixer.Channel(3).play(mario) #optional 5th pad that plays mario bros powerup noise
        ser.reset_input_buffer()

    time.wait(10)

ser.close()
