import webbrowser
from pygame import mixer

def openGoodSong():
    webbrowser.open('https://www.youtube.com/watch?v=SBjQ9tuuTJQ&ab_channel=foofightersVEVO', new=2)

def playSound():
    mixer.init()
    mixer.music.load('./sounds/bruh.mp3')
    mixer.music.play()
    