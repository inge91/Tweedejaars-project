from naoqi import ALProxy


IP = "127.0.0.1"  # Put here the IP address of your NAOqi
PORT = 9559

#________________________________
# Get Proxy on ALVideoDevice
#________________________________

try:
  camProxy = ALProxy("ALVideoDevice", IP, PORT)
except Exception,e:
  print "Error when creating vision proxy:"
  print str(e)
  exit(1)

pRange = [0,10000]
pLoop = True
pReplayMode = 0
pStreamNumber = 0

try:
  camProxy.setVideo("/home/nao/myVideo.arv", pRange, pLoop, pReplayMode, pStreamNumber)
except Exception,e:
  print "setVideo Failed"

print 'end of script'

