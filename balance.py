from naoqi import ALProxy
import time
import os
import pylab
import matplotlib.pyplot as plt

class FootBalance():
    # tweak parameters									best values
	# supLeg = support leg								left = 1, right = 0
	# p = sensitivity									0.0015
	# i = Integral sensitivity (not yet used)			0
	# d = derivative sensitivity						0.0005
	# s = smooting between previous and current value's	0.8
	# tX = threshold on Pitch when to start balancing	2
	# tY = threshold on Roll when to start balancing	2.5
	# plot on/off										on = 1,off = 0
	#
	#  import balance as b 
	#  a = b.FootBalance('wind.local',9559,1,0.0015,0,0.0005,0.8,2,2.5,1)
	#  a.motproxy.setStiffnesses('Body',1)
	#  a.balance()
	#  kill met cntl + c
	#  a.pyPlot()            <- data lists wordt na plotten leeg gemaakt
	def __init__(self, IP, port, supLeg , p, i, d, s, tX,tY, plot):
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
		self.tX = tX
		self.tY = tY
		self.plotX = []
		self.plotY = []
		self.plotT = []
		self.plotTx = []
		self.plotTy = []
		self.plot = plot
		self.previousTimeTaken = 0
		self.smoothedTimetaken = 0
		self.previousErrorX = 0
		self.previousErrorY = 0
		self.previousTime = time.time()
		
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
			
			Time = time.time()
			timeTaken = Time - self.previousTime
			if not(self.smoothedTimetaken == 0 or timeTaken - self.previousTimeTaken < 1):
				self.smoothedTimetaken = 0.9 * self.smoothedTimetaken + 0.1 * timeTaken 
			else:
				self.smoothedTimetaken = timeTaken 
			self.previousTime = Time
					
			
			errorX = (Front - Back)
			errorY = (Right - Left)
			
			KpPitch = errorX * self.p  
			KpRoll = errorY * self.p 	
			
			KdPitch = ((errorX - self.previousErrorX) / self.smoothedTimetaken) * self.d 
			KdRoll = ((errorY  - self.previousErrorY) / self.smoothedTimetaken) * self.d
			
			tX2 = self.tX 
			tY2 = self.tY 
					
			if(not (errorX  > tX2 or errorX  < -tX2)): #error band for X
				KpPitch = 0
				KdPitch = 0
			if(not (errorY   > tY2 or errorY  < -tY2)):  #error band for Y
				KpRoll = 0
				KdRoll = 0

			if timeTaken - self.previousTimeTaken < 2.5: #low-pass filter
				AngleoffsetHipPitch = (KpPitch + KdPitch) * self.smoothedTimetaken
				AngleoffsetHiproll =  (KpRoll + KdRoll)  * self.smoothedTimetaken
			else:
				AngleoffsetHipPitch = 0
				AngleoffsetHiproll =  0
				#just for the plot:
				errorX = 0
				errorY = 0
				tX2 = 0
				tY2 = 0
				
			self.previousTimeTaken = timeTaken
			self.previousErrorX = errorX
			self.previousErrorX = errorY
			
			if self.plot:
				self.plotX.append(errorX)
				self.plotY.append(errorY)
				self.plotT.append(Time)
				self.plotTx.append(tX2)
				self.plotTy.append(tY2)
				
			if self.supLeg:		
				try:
					self.motproxy.changeAngles(["LHipRoll","LHipPitch"], [AngleoffsetHiproll,AngleoffsetHipPitch],0.2)
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
					self.motproxy.changeAngles(["RHipRoll","RHipPitch"], [AngleoffsetHiproll,AngleoffsetHipPitch],0.2)
				except:
					try:
						self.motproxy.changeAngles(["RHipRoll","RHipPitch"], [0,AngleoffsetHipPitch],0.2)
					except:
						print "Hiproll out of range"
					try:
						self.motproxy.changeAngles(["RHipRoll","RHipPitch"], [AngleoffsetHiproll,0],0.2)
					except:
						print "Hiproll out of range"				
	
	def pyPlot(self):
		self.plotT = [e - self.plotT[0] for e in self.plotT]
		self.plotTxMax = self.plotTx
		self.plotTxMin = [e * -1 for e in self.plotTx]
		self.plotTyMax = self.plotTy
		self.plotTyMin = [e * -1 for e in self.plotTy]
		
		fig = plt.figure()
		ax = fig.add_subplot(111)

		values = ax.plot(self.plotT,self.plotX,'-', label = 'measured values')
		tresMax = ax.plot(self.plotT,self.plotTxMax, '-', label = 'max treshold')
		tresMin = ax.plot(self.plotT,self.plotTxMin, '-', label = 'min treshold')
		
		lns = values+tresMax+tresMin
		labs = [l.get_label() for l in lns]
		ax.legend(lns, labs, loc=0, prop={'size':10})
		
		ax.grid()
		ax.set_xlabel("Time in seconds")
		ax.set_ylabel("Error")
		ax.set_title("Plot of the error in x direction")
		
		pylab.show()		
		pylab.savefig('plotX.png')
		
		fig = plt.figure()
		ax = fig.add_subplot(111)

		values = ax.plot(self.plotT,self.plotY,'-', label = 'measured values')
		tresMax = ax.plot(self.plotT,self.plotTyMax, '-', label = 'max treshold')
		tresMin = ax.plot(self.plotT,self.plotTyMin, '-', label = 'min treshold')
		
		lns = values+tresMax+tresMin
		labs = [l.get_label() for l in lns]
		ax.legend(lns, labs, loc=0, prop={'size':10})
		
		ax.grid()
		ax.set_xlabel("Time in seconds")
		ax.set_ylabel("Error")
		ax.set_title("Plot of the error in y direction")
		
		pylab.show()		
		pylab.savefig('plotY.png')
		
		self.plotX = []
		self.plotY = []
		self.plotT = []
		self.plotTx = []
		self.plotTy = []
