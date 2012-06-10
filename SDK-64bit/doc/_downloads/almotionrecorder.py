IP   = "127.0.0.1"
PORT = 9559
import time
from naoqi import ALProxy
mvrec = ALProxy("ALMotionRecorder",IP,PORT)
mvrec.post.startPeriodicRecording(["HeadPitch", "HeadYaw"], 0, True, 0.100, [], [])
time.sleep(4)
move = mvrec.stopAndGetRecording()
print move
