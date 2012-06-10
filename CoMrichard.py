from naoqi import ALProxy
from math import cos, sin
from copy import deepcopy
		
class CenterOfMass():
    #TODO: voor Linker joints y even inverse waarde geven
                # center of mass        x           y        z
    jointCOM = {"RAnkleRoll"      : ( [25.40,  -3.32, -32.41],  0.16175 ),
                "LAnkleRoll"      : ( [25.40,  3.32, -32.41],  0.16175 ),
                "RAnklePitch"     : ( [1.42,   -0.28,  6.38],  0.13892 ),
                "LAnklePitch"     : ( [1.42,   0.28,  6.38],  0.13892 ),
                "RKneePitch"      : ( [4.22,   -2.52, -48.68],  0.25191 ),
                "LKneePitch"      : ( [4.22,   2.52, -48.68],  0.25191 ),
                "RHipPitch"       : ( [1.32,   -2.35, -53.52],  0.39421 ),
                "LHipPitch"       : ( [1.32,   2.35, -53.52],  0.39421 ),
                "RHipRoll"        : ( [-16.49, -0.29, -4.75],  0.13530),
                "LHipRoll"        : ( [-16.49, 0.29, -4.75],  0.13530),
				"RHipYaw"  		  : ( [0,  0,  0 ], 0 ),
				"LHipYaw"  		  : ( [0,  0,  0 ], 0 ),
                "RHipYawPitch"    : ( [-7.66,  12.00,  27.17 ], 0.07117 ),
                "LHipYawPitch"    : ( [-7.66,  -12.00,  27.17 ], 0.07117 ),
                "RElbowRoll"      : ( [65.36,  -0.34, -0.02],  0.18500 ),
                "LElbowRoll"      : ( [65.36,  0.34, -0.02],  0.18500 ),
                "RElbowYaw"       : ( [-25.60,  0.01, -0.19],  0.05971),
                "LElbowYaw"       : ( [-25.60, - 0.01, -0.19],  0.05971),
                "RShoulderRoll"   : ( [18.85,  -5.77,  0.65],  0.12309),
                "LShoulderRoll"   : ( [18.85,  5.77,  0.65],  0.12309),
                "RShoulderPitch"  : ( [-1.78,  24.96,  0.18],  0.06996 ),
                "LShoulderPitch"  : ( [-1.78,  -24.96,  0.18],  0.06996 ),
                "HeadYaw"         : ( [-0.02,  0.17,  -25.56],  0.05930),
                "Torso"           : ( [-4.15,  0.07,   42.58,   1.03948]),
                ######### Misschien niet de juiste versie################
                "HeadPitch"       : ( [1.20,  -0.84,   53.53],  0.52065)}
     

    jointOffsets = {
            ("TorsoToHead")        : [0.0, 0.0, 126.50 ],
            ("HeadToTorso")        : [0.0, 0.0, -126.50 ],
            ("TorsoToLShoulder")   : [0.0, 98.0, 100.00 ],
            ("LShoulderToTorso")   : [0.0, -98.0, -100.00 ],
            ("LShoulderToLElbow" ) : [105.00, 15.00, 0.00],        
            ("LElbowToLShoulder" ) : [-105.00, -15.00, 0.00],        
            ("LElbowToLWrist")     : [55.95, 0, 0 ],
            ("LWristToLElbow")     : [-55.95, 0, 0 ],
			("TorsoToRShoulder")   : [0.0, -98.0, 100.00 ],
			("RShoulderToTorso")   : [0.0, 98.0, -100.00 ],
            ("RShoulderToRElbow" ) : [105.00, -15.00, 0.00],        
            ("RElbowToRShoulder" ) : [-105.00, 15.00, 0.00],        
            ("RElbowToRWrist")     : [55.95, 0, 0 ],
            ("RWristToRElbow")     : [-55.95, 0, 0 ],
            ("TorsoToRHip")        : [0, -50.0, -85.0],
			("TorsoToLHip")        : [0, 50.0, -85.0],
            ("RHipToTorso")        : [0, 50.0, 85.0],
            ("LHipToTorso")        : [0, -50.0, 85.0],
            ("HipToKnee")          : [0.0, 0.0, -100.0],
            ("KneeToHip")          : [0.0, 0.0, 100.0],
            ("KneeToAnkle")        : [0.0, 0.0, -102.9],
            ("AnkleToKnee")        : [0.0, 0.0, 102.9]}
			
    def __init__(self, ip_address, port):
        self.mot = ALProxy("ALMotion", ip_address, port)
			
    def update(self):
		#hardcoded for testing
		supportLeg = "R"
		if supportLeg == "R":
			checkupdown = 1
		else:
			checkupdown = -1

		X = self.mot.getAngles("RAnkleRoll", False)[0] * checkupdown   
		self.RAnkleRoll =   [[1,			0,			0,			0],
						[0,			cos(X),		sin(X),		0],
						[0,			-sin(X),	cos(X),		0],
						[0,			0,			0,			1]]

		X = self.mot.getAngles("RAnklePitch", False)[0] * checkupdown
		self.RAnklePitch =  [[cos(X),	0,			-sin(X),	0],
						[0,			1,			0,			0],
						[sin(X),	0,			cos(X),		0],
						[0,			0,			0,			1]]

		X = self.mot.getAngles("RKneePitch", False)[0] * checkupdown
		self.RKneePitch =   [[cos(X),	0,			-sin(X),	0],
						[0,			1,			0,			0],
						[sin(X),	0,			cos(X),		0],
						[0,			0,			0,			1]]

		X = self.mot.getAngles("RHipPitch", False)[0] * checkupdown	
		self.RHipPitch =    [[cos(X),	0,			-sin(X),	0],
						[0,			1,			0,			0],
						[sin(X),	0,			cos(X),		0],
						[0,			0,			0,			1]]

		X = self.mot.getAngles("RHipRoll", False)[0] * checkupdown
		self.RHipRoll = 	   [[1,			0,			0,			0],
						[0,			cos(X),		-sin(X),	0],
						[0,			sin(X),		cos(X),		0],
						[0,			0,			0,			1]]

		X = self.mot.getAngles("RHipYawPitch", False)[0] * checkupdown		
		self.RHipYaw =      [[cos(X/2),	-sin(X/2),	0,			0],
						[0,			1,			0,			0],
						[sin(X/2),	cos(X/2),	0,			0],
						[0,			0,			0,			1]]

		#X = self.mot.getAngles("RHipYawPitch", False)[0] * checkupdown	
		self.RHipYawPitch = [[cos(X/2),	0,			-sin(X/2),	0],
						[0,			1,			0,			0],
						[sin(X/2),	0,			cos(X/2),	0],
						[0,			0,			0,			1]]
											
		
		#############################################################################################
		
		if supportLeg == "R":
			checkupdown = -1
		else:
			checkupdown = 1
		
		X = self.mot.getAngles("LAnkleRoll", False)[0] * checkupdown   
		self.LAnkleRoll =  [[1,			0,			0,			0],
							[0,			cos(X),		sin(X),		0],
							[0,			-sin(X),	cos(X),		0],
							[0,			0,			0,			1]]

		X = self.mot.getAngles("LAnklePitch", False)[0] * checkupdown
		self.LAnklePitch =  [[cos(X),	0,			-sin(X),	0],
							[0,			1,			0,			0],
							[sin(X),	0,			cos(X),		0],
							[0,			0,			0,			1]]

		X = self.mot.getAngles("LKneePitch", False)[0] * checkupdown
		self.LKneePitch =   [[cos(X),	0,			-sin(X),	0],
							[0,			1,			0,			0],
							[sin(X),	0,			cos(X),		0],
							[0,			0,			0,			1]]

		X = self.mot.getAngles("LHipPitch", False)[0] * checkupdown	
		self.LHipPitch =    [[cos(X),	0,			-sin(X),	0],
							[0,			1,			0,			0],
							[sin(X),	0,			cos(X),		0],
							[0,			0,			0,			1]]

		X = self.mot.getAngles("LHipRoll", False)[0] * checkupdown
		self.LHipRoll = 	[[1,			0,			0,		0],
							[0,			cos(X),		-sin(X),	0],
							[0,			sin(X),		cos(X),		0],
							[0,			0,			0,			1]]

		X = self.mot.getAngles("LHipYawPitch", False)[0] * checkupdown		
		self.LHipYaw =  [[cos(X/2),	-sin(X/2),	0,			0],
						[0,			1,			0,			0],
						[sin(X/2),	cos(X/2),	0,			0],
						[0,			0,			0,			1]]

		self.LHipYawPitch = [[cos(X/2),	0,			-sin(X/2),	0],
							[0,			1,			0,			0],
							[sin(X/2),	0,			cos(X/2),	0],
							[0,			0,			0,			1]]
		
		X = self.mot.getAngles("LHipYawPitch", False)[0]
		self.RShoulderPitch =   [[cos(X),	0,			-sin(X),	0],
								[0,			1,			0,			0],
								[sin(X),	0,			cos(X),		0],
								[0,			0,			0,			1]]
		
		X = self.mot.getAngles("RShoulderRoll", False)[0]
		self.RShoulderRoll = 	[[1,		0,			0,		0],
								[0,			cos(X),		-sin(X),	0],
								[0,			sin(X),		cos(X),		0],
								[0,			0,			0,			1]]
		
		X = self.mot.getAngles("ElbowYaw ", False)[0]
		self.RElbowYaw =      	[[cos(X),	-sin(X),	0,			0],
								[0,			1,			0,			0],
								[sin(X),	cos(X),		0,			0],
								[0,			0,			0,			1]]
								
		X = self.mot.getAngles("RElbowRoll", False)[0]
		self.RElbowRoll = 	   [[1,			0,			0,			0],
								[0,			cos(X),		-sin(X),	0],
								[0,			sin(X),		cos(X),		0],
								[0,			0,			0,			1]]
		
		X = self.mot.getAngles("LShoulderPitch", False)[0]
		self.LShoulderPitch =   [[cos(X),	0,		-sin(X),	0],
								[0,			1,		0,			0],
								[sin(X),	0,		cos(X),		0],
								[0,			0,		0,			1]]
		
		X = self.mot.getAngles("LShoulderRoll", False)[0]
		self.LShoulderRoll = 	[[1,			0,			0,		0],
								[0,			cos(X),		-sin(X),	0],
								[0,			sin(X),		cos(X),		0],
								[0,			0,			0,			1]]
		
		X = self.mot.getAngles("LElbowYaw", False)[0]
		self.LElbowYaw =      	[[cos(X),	-sin(X),	0,			0],
								[0,			1,			0,			0],
								[sin(X),	cos(X),	0,			0],
								[0,			0,			0,			1]]
		
		X = self.mot.getAngles("LElbowRoll", False)[0]
		self.LElbowRoll = 	   [[1,			0,			0,			0],
								[0,			cos(X),		-sin(X),	0],
								[0,			sin(X),		cos(X),		0],
								[0,			0,			0,			1]]
								
		X = self.mot.getAngles("HeadYaw", False)[0]
		self.HeadYaw =      	[[cos(X),	-sin(X),	0,			0],
								[0,			1,			0,			0],
								[sin(X),	cos(X),	0,			0],
								[0,			0,			0,			1]]
								
		X = self.mot.getAngles("HeadPitch", False)[0]
		self.HeadPitch = 		[[cos(X),	0,			-sin(X),	0],
								[0,			1,			0,			0],
								[sin(X),	0,			cos(X),		0],
								[0,			0,			0,			1]]
	
    def CoM(self):
	    self.update()
	    Chains = []
		#if supportLeg = "R":
		# Chains[0] = ["RAnkleRoll","RAnklePitch","RKneePitch","RHipPitch","RHipRoll","RHipYaw","RHipPitch","Torso"]
		# Chains[1] = ["LHipPitch","LHipYaw","LHipRoll","LHipPitch","LKneePitch","LAnklePitch","LAnkleRoll"]
		#elif 
		# Chains[0] = ["LAnkleRoll","LAnklePitch","LKneePitch","LHipPitch","LHipRoll","LHipYaw","LHipPitch","Torso"]
		# Chains[1] = ["RHipPitch","RHipYaw","RHipRoll","RHipPitch","RKneePitch","RAnklePitch","RAnkleRoll"]
		 
		#Chains[2] = ["RShoulderPitch","RShoulderRoll","RElbowYaw","RElbowRoll"]
		#Chains[3] = ["LShoulderPitch","LShoulderRoll","LElbowYaw","LElbowRoll"]
		#Chains[4] = ["HeadYaw", "HeadPitch"]
		
	    Chains.append(["RAnkleRoll","RAnklePitch","AnkleToKnee","RKneePitch","KneeToHip","RHipPitch","RHipRoll","RHipYaw","RHipYawPitch","RHipToTorso"])
	    Chains.append(["TorsoToLHip","LHipYawPitch","LHipYaw","LHipRoll","LHipPitch","HipToKnee","LKneePitch","KneeToAnkle","LAnklePitch","LAnkleRoll"])
	    Chains.append(["TorsoToRShoulder","RShoulderPitch","RShoulderRoll","RShoulderToRElbow","RElbowYaw","RElbowRoll"])
	    Chains.append(["TorsoToLShoulder","LShoulderPitch","LShoulderRoll","LShoulderToLElbow","LElbowYaw","LElbowRoll"])
	    Chains.append(["TorsoToHead","HeadYaw", "HeadPitch"])
		
	    Transform = [[1,0,0,0],
					 [0,1,0,0],
					 [0,0,1,0],
					 [0,0,0,1]]
		
	    JointCOMs = []
	    JointMasses = []
		
	    plot0 = []
	    plot1 = []
	    plot2 = []
	    plot3 = []
	    plot4 = []
		
	    for element in Chains[0]:
		    if element in self.jointCOM:
			    Transform = self.mult(Transform, eval("self." + element))
			    JointCOMs.append(self.mult(Transform, [[self.jointCOM[element][0][0]],[self.jointCOM[element][0][1]],[self.jointCOM[element][0][2]],[1]]))
			    JointMasses.append(self.jointCOM[element][1])
			    print "transform (rotation):"
		    else:
			    Transform[0][3] += self.jointOffsets[element][0]
			    Transform[1][3] += self.jointOffsets[element][1]
			    Transform[2][3] += self.jointOffsets[element][2]
			    print "transform (translate):"		
		    print Transform
		    [[temp1],[temp2],[temp3],[temp4]] = self.mult(Transform, [[0],[0],[0],[1]])
		    plot0.append(temp1)
		    plot0.append(temp2)
		    plot0.append(temp3)
		#Torso has been reached
	    self.NullToTorso = deepcopy(Transform)
	    #Add the torso to the plot
	    [[temp1],[temp2],[temp3],[temp4]] = self.mult(Transform, [[0],[0],[0],[1]])
	    plot1.append(temp1)
	    plot1.append(temp2)
	    plot1.append(temp3)
	    for element in Chains[1]:
		    if element in self.jointCOM:
			    Transform = self.mult(Transform, eval("self." + element))
			    JointCOMs.append(self.mult(Transform, [[self.jointCOM[element][0][0]],[self.jointCOM[element][0][1]],[self.jointCOM[element][0][2]],[1]]))
			    JointMasses.append(self.jointCOM[element][1])
			    print "transform (rotation):"
		    else:
			    Transform[0][3] += self.jointOffsets[element][0]
			    Transform[1][3] += self.jointOffsets[element][1]
			    Transform[2][3] += self.jointOffsets[element][2]
			    print "transform (translate):"		
		    print Transform
		    [[temp1],[temp2],[temp3],[temp4]] = self.mult(Transform, [[0],[0],[0],[1]])
		    plot1.append(temp1)
		    plot1.append(temp2)
		    plot1.append(temp3)
		#back to Torso
	    Transform = deepcopy(self.NullToTorso)
	    #Add the torso to the plot
	    [[temp1],[temp2],[temp3],[temp4]] = self.mult(Transform, [[0],[0],[0],[1]])
	    plot2.append(temp1)
	    plot2.append(temp2)
	    plot2.append(temp3)
	    for element in Chains[2]:
		    if element in self.jointCOM:
			    Transform = self.mult(Transform, eval("self." + element))
			    JointCOMs.append(self.mult(Transform, [[self.jointCOM[element][0][0]],[self.jointCOM[element][0][1]],[self.jointCOM[element][0][2]],[1]]))
			    JointMasses.append(self.jointCOM[element][1])
			    print "transform (rotation):"
		    else:
			    Transform[0][3] += self.jointOffsets[element][0]
			    Transform[1][3] += self.jointOffsets[element][1]
			    Transform[2][3] += self.jointOffsets[element][2]
			    print "transform (translate):"		
		    print Transform
		    [[temp1],[temp2],[temp3],[temp4]] = self.mult(Transform, [[0],[0],[0],[1]])
		    plot2.append(temp1)
		    plot2.append(temp2)
		    plot2.append(temp3)
		#back to Torso
	    Transform = deepcopy(self.NullToTorso)	    
		#Add the torso to the plot
	    [[temp1],[temp2],[temp3],[temp4]] = self.mult(Transform, [[0],[0],[0],[1]])
	    plot3.append(temp1)
	    plot3.append(temp2)
	    plot3.append(temp3)
	    for element in Chains[3]:
		    if element in self.jointCOM:
			    Transform = self.mult(Transform, eval("self." + element))
			    JointCOMs.append(self.mult(Transform, [[self.jointCOM[element][0][0]],[self.jointCOM[element][0][1]],[self.jointCOM[element][0][2]],[1]]))
			    JointMasses.append(self.jointCOM[element][1])
			    print "transform (rotation):"
		    else:
			    Transform[0][3] += self.jointOffsets[element][0]
			    Transform[1][3] += self.jointOffsets[element][1]
			    Transform[2][3] += self.jointOffsets[element][2]
			    print "transform (translate):"		
		    print Transform
		    [[temp1],[temp2],[temp3],[temp4]] = self.mult(Transform, [[0],[0],[0],[1]])
		    plot3.append(temp1)
		    plot3.append(temp2)
		    plot3.append(temp3)
		#back to Torso 
	    Transform = deepcopy(self.NullToTorso)
		#Add the torso to the plot
	    [[temp1],[temp2],[temp3],[temp4]] = self.mult(Transform, [[0],[0],[0],[1]])
	    plot4.append(temp1)
	    plot4.append(temp2)
	    plot4.append(temp3)
	   
	    for element in Chains[4]:
		    if element in self.jointCOM:
			    Transform = self.mult(Transform, eval("self." + element))
			    JointCOMs.append(self.mult(Transform, [[self.jointCOM[element][0][0]],[self.jointCOM[element][0][1]],[self.jointCOM[element][0][2]],[1]]))
			    JointMasses.append(self.jointCOM[element][1])
			    print "transform (rotation):"
		    else:
			    Transform[0][3] += self.jointOffsets[element][0]
			    Transform[1][3] += self.jointOffsets[element][1]
			    Transform[2][3] += self.jointOffsets[element][2]
			    print "transform (translate):"		
		    print Transform
		    [[temp1],[temp2],[temp3],[temp4]] = self.mult(Transform, [[0],[0],[0],[1]])
		    plot4.append(temp1)
		    plot4.append(temp2)
		    plot4.append(temp3)
	    print "JointCOMs: " 
	    print JointCOMs
	    print "masses: "
	    print JointMasses	
	    COM = [0.0,0.0,0.0]
	    plot = []
	    for i in range(len(JointMasses)):
		    COM[0] += JointCOMs[i][0][0] * JointMasses[i]
		    COM[1] += JointCOMs[i][1][0] * JointMasses[i]
		    COM[2] += JointCOMs[i][2][0] * JointMasses[i]
		    plot.append(JointCOMs[i][0][0])
		    plot.append(JointCOMs[i][1][0])
		    plot.append(JointCOMs[i][2][0])				
	    COM = [a/sum(JointMasses) for a in COM]
	    print "plot:"
	    print plot
	    print "plot0:"
	    print plot0
	    print "plot1:"
	    print plot1
	    print "plot2:"
	    print plot2
	    print "plot3:"
	    print plot3
	    print "plot4:"
	    print plot4
	    print "COM:"      
	    return COM
	
    def zero(self,m,n):
		# Create zero matrix
		new_matrix = [[0 for row in range(n)] for col in range(m)]
		return new_matrix
	
    def mult(self,matrix1,matrix2):
		# Matrix multiplication
		if len(matrix1[0]) != len(matrix2):
			# Check matrix dimensions
			print 'Matrices must be m*n and n*p to multiply!'
		else:
			# Multiply if correct dimensions
			new_matrix = self.zero(len(matrix1),len(matrix2[0]))
			for i in range(len(matrix1)):
				for j in range(len(matrix2[0])):
					for k in range(len(matrix2)):
						new_matrix[i][j] += matrix1[i][k]*matrix2[k][j]
			return new_matrix