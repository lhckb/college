from pygame import mixer

mixer.init()

def playFirstDo():
    sound = mixer.Sound('./sounds/primeirodo.wav')
    sound.play()
        
def playRe():
    sound = mixer.Sound('./sounds/re.wav')
    sound.play()
        
def playMi():
    sound = mixer.Sound('./sounds/mi.wav')
    sound.play()

def playFa():
    sound = mixer.Sound('./sounds/fa.wav')
    sound.play()

def playSo():
    sound = mixer.Sound('./sounds/sol.wav')
    sound.play()

def playLa():
    sound = mixer.Sound('./sounds/la.wav')
    sound.play()

def playSi():
    sound = mixer.Sound('./sounds/si.wav')
    sound.play()

def playLastDo():
    sound = mixer.Sound('./sounds/ultimodo.wav')
    sound.play()
        