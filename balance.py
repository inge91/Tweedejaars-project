from naoqi import ALProxy
import time
import motions

class FootBalance():
    # tweak parameters										best values
	# supLeg = support leg									left = 1, right = 0
	# p = sensitivity										0.002
	# i = Integral sensitivity (not yet used)				1
	# d = derivative sensitivity							1.2
	# s = smooting between previous and current value's		0.8
	# t = threshold when to start balancing					0.004
	def __init__(self, IP, port, supLeg , p, i, d, s, t):
		self.motproxy = ALProxy("ALMotion", IP, port)
		self.memoryProxy = ALProxy("ALMemory", IP, port)
		self.supLeg = supLeg
		if supLeg:
			self.oldFront = (self.memoryProxy.getData("Device/SubDeviceList/LFoot/FSR/FrontLeft/Sensor/Value") + self.memoryProxy.getData("Device/SubDeviceList/LFoot/FSR/FrontRight/Sensor/Value"))
			self.oldBack = (self.memoryProxy.getData("Device/SubDeviceList/LFoot/FSR/RearLeft/Sensor/Value") + self.memoryProxy.getData("Device/SubDeviceList/LFoot/FSR/RearRight/Sensor/Value"))
			self.oldLeft = (self.memoryProxy.getData("Device/SubDeviceList/LFoot/FSR/FrontLeft/Sensor/Value") + self.memoryProxy.getData("Device/SubDeviceList/LFoot/FSR/RearLeft/Sensor/Value"))
			self.oldRight = (self.memoryProxy.getData("Device/SubDeviceList/LFoot/FSR/FrontRight/Sensor/Value") + self.memoryProxy.getData("Device/SubDeviceList/LFoot/FSR/RearRight/Sensor/Value"))
		else:
			self.oldFront = (self.memoryProxy.getData("Device/SubDeviceList/RFoot/FSR/FrontLeft/Sensor/Value") + self.memoryProxy.getData("Device/SubDeviceList/RFoot/FSR/FrontRight/Sensor/Value"))
			self.oldBack = (self.memoryProxy.getData("Device/SubDeviceList/RFoot/FSR/RearLeft/Sensor/Value") + self.memoryProxy.getData("Device/SubDeviceList/RFoot/FSR/RearRight/Sensor/Value"))
			self.oldLeft = (self.memoryProxy.getData("Device/SubDeviceList/RFoot/FSR/FrontLeft/Sensor/Value") + self.memoryProxy.getData("Device/SubDeviceList/RFoot/FSR/RearLeft/Sensor/Value"))
			self.oldRight = (self.memoryProxy.getData("Device/SubDeviceList/RFoot/FSR/FrontRight/Sensor/Value") + self.memoryProxy.getData("Device/SubDeviceList/RFoot/FSR/RearRight/Sensor/Value"))
		self.KpPitchOld = 0
		self.KpRollOld = 0
		self.p = p 
		self.i = i 
		self.d = d		
		self.s = s  
		self.t = t 
		self.previousTime = time.clock()
		
	def balance(self):
	    while 1:
			if self.supLeg:
				Front = (1-self.s) * self.oldFront + self.s * (self.memoryProxy.getData("Device/SubDeviceList/LFoot/FSR/FrontLeft/Sensor/Value") + self.memoryProxy.getData("Device/SubDeviceList/LFoot/FSR/FrontRight/Sensor/Value"))
				Back = (1-self.s) * self.oldBack + self.s * (self.memoryProxy.getData("Device/SubDeviceList/LFoot/FSR/RearLeft/Sensor/Value") + self.memoryProxy.getData("Device/SubDeviceList/LFoot/FSR/RearRight/Sensor/Value"))
				Left = (1-self.s) * self.oldFront + self.s * (self.memoryProxy.getData("Device/SubDeviceList/LFoot/FSR/FrontLeft/Sensor/Value") + self.memoryProxy.getData("Device/SubDeviceList/LFoot/FSR/RearLeft/Sensor/Value"))
				Right = (1-self.s) * self.oldFront + self.s * (self.memoryProxy.getData("Device/SubDeviceList/LFoot/FSR/FrontRight/Sensor/Value") + self.memoryProxy.getData("Device/SubDeviceList/LFoot/FSR/RearRight/Sensor/Value"))
			else:
				Front = (1-self.s) * self.oldFront + self.s * (self.memoryProxy.getData("Device/SubDeviceList/RFoot/FSR/FrontLeft/Sensor/Value") + self.memoryProxy.getData("Device/SubDeviceList/RFoot/FSR/FrontRight/Sensor/Value"))
				Back = (1-self.s) * self.oldBack + self.s * (self.memoryProxy.getData("Device/SubDeviceList/RFoot/FSR/RearLeft/Sensor/Value") + self.memoryProxy.getData("Device/SubDeviceList/RFoot/FSR/RearRight/Sensor/Value"))
				Left = (1-self.s) * self.oldFront + self.s * (self.memoryProxy.getData("Device/SubDeviceList/RFoot/FSR/FrontLeft/Sensor/Value") + self.memoryProxy.getData("Device/SubDeviceList/RFoot/FSR/RearLeft/Sensor/Value"))
				Right = (1-self.s) * self.oldFront + self.s * (self.memoryProxy.getData("Device/SubDeviceList/RFoot/FSR/FrontRight/Sensor/Value") + self.memoryProxy.getData("Device/SubDeviceList/RFoot/FSR/RearRight/Sensor/Value"))
			KpPitch = (Front - Back) * self.p
			KpRoll = (Right - Left) * self.p
			if(not (KpPitch > self.t or KpPitch < -self.t)):
				KpPitch = 0
			if(not (KpRoll > self.t or KpRoll < -self.t)):
				KpRoll = 0
			print "KpPitch: " + str(KpPitch)
			print "KpRoll: " + str(KpRoll)
			Time = time.clock()
			timeTaken = self.previousTime - Time
			self.previousTime = Time
			KdPitch = ((self.KpPitchOld - KpPitch) / timeTaken) * self.d 
			KdRoll = ((self.KpRollOld - KpRoll) / timeTaken) * self.d 				
			self.KpPitchOld = KpPitch
			self.KpRollOld = KpRoll
			AngleoffsetHipPitch = KpPitch + KdPitch
			AngleoffsetHiproll =  KpRoll + KdRoll
			if self.supLeg:		
				try:
					self.motproxy.changeAngles(["LHipRoll","LHipPitch"], [AngleoffsetHiproll,AngleoffsetHipPitch],0.1)
				except:
					try:
						self.motproxy.changeAngles(["LHipRoll","LHipPitch"], [0,AngleoffsetHipPitch],0.2)
					except:
						print "Hiproll out of range"
					try:
						self.motproxy.changeAngles(["LHipRoll","LHipPitch"], [AngleoffsetHiproll,0],0.2)
					except:
						print "Hiproll out of range"
			else:
				try:
					self.motproxy.changeAngles(["RHipRoll","RHipPitch"], [AngleoffsetHiproll,AngleoffsetHipPitch],0.1)
				except:
					try:
						self.motproxy.changeAngles(["RHipRoll","RHipPitch"], [0,AngleoffsetHipPitch],0.2)
					except:
						print "Hiproll out of range"
					try:
						self.motproxy.changeAngles(["RHipRoll","RHipPitch"], [AngleoffsetHiproll,0],0.2)
					except:
						print "Hiproll out of range"				
			print str(self.memoryProxy.getData("Device/SubDeviceList/LFoot/FSR/FrontLeft/Sensor/Value")) + "\t" + str(self.memoryProxy.getData("Device/SubDeviceList/LFoot/FSR/FrontRight/Sensor/Value")) + "  \t  " + str(self.memoryProxy.getData("Device/SubDeviceList/RFoot/FSR/FrontLeft/Sensor/Value")) + "\t" +  str(self.memoryProxy.getData("Device/SubDeviceList/RFoot/FSR/FrontRight/Sensor/Value"))
			print " "
			print str(self.memoryProxy.getData("Device/SubDeviceList/LFoot/FSR/RearLeft/Sensor/Value")) + "\t" + str(self.memoryProxy.getData("Device/SubDeviceList/LFoot/FSR/RearRight/Sensor/Value")) + "  \t  " + str(self.memoryProxy.getData("Device/SubDeviceList/RFoot/FSR/RearLeft/Sensor/Value")) + "\t" + str(self.memoryProxy.getData("Device/SubDeviceList/RFoot/FSR/RearRight/Sensor/Value"))
			print "Angle offsets: " + str(AngleoffsetHiproll) + "   " + str(AngleoffsetHipPitch)
