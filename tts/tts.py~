from gtts import gTTS 
from pygame import mixer
import time
mixer.init()
while(1):
	x=raw_input("Enter the text you want me to speak :: ")
	tts = gTTS(text=x, lang='en')
	tts.save("hello.mp3")
	mixer.music.load('/home/haresh/Documents/wheelie/tts/hello.mp3')
	mixer.music.play()
