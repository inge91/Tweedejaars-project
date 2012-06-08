from naoqi import ALProxy
from math import cos, sin
		
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
            ("Torso", "HeadYaw")                : [0.0, 0.0, 126.50 ],
            ("HeadYaw", "Torso")                : [0.0, 0.0, -126.50 ],
            ("HeadYaw","HeadPitch")             : [0.0, 0.0, 0.0 ],
            ("HeadPitch","HeadYaw")             : [0.0, 0.0, 0.0 ],
            ("Torso", "LShoulderPitch")         : [0.0, 98.0, 100.00 ],
            ("LShoulderPitch", "Torso")         : [0.0, 98.0, -100.00 ],
            ("LShoulderPitch", "LShoulderRoll") : [0.0, 0.0, 0.0],
            ("LShoulderRoll", "LShoulderPitch") : [0.0, 0.0, 0.0],
            ("LShoulderRoll", "LElbowYaw" )     : [105.00, 15.00, 0.00],        
            ("LElbowYaw", "LShoulderRoll" )     : [105.00, 15.00, 0.00],        
            ("LElbowYaw", "LElbowRoll")         : [0, 0, 0],
            ("LElbowRoll", "LElbowYaw")         : [0, 0, 0],
            ("LElbowRoll", "LWristYaw")         : [55.95, 0, 0 ],
            ("LWristYaw", "LElbowRoll")         : [55.95, 0, 0 ],
            ("Torso", "LHipYawPitch")           : [0, 50.0, -85.0],
            ("LHipYawPitch", "Torso")           : [0, 50.0, 85.0],
            ("LHipYawPitch", "LHipRoll")        : [0.0 , 0.0, 0.0],
            ("LHipRoll", "LHipYawPitch")        : [0.0 , 0.0, 0.0],
            ("LHipRoll", "LHipPitch")           : [0.0, 0.0, 0.0],
            ("LHipPitch", "LHipRoll")           : [0.0, 0.0, 0.0],
            ("LHipPitch", "LKneePitch")         : [0.0, 0.0, -100.0],
            ("LKneePitch", "LHipPitch")         : [0.0, 0.0, 100.0],
            ("LKneePitch","LAnklePitch")        : [0.0, 0.0, -102.9],
            ("LAnklePitch","LKneePitch")        : [0.0, 0.0, 102.9],
            ("LAnklePitch", "LAnkleRoll")       : [0.0, 0.0, 0.0],
            ("LAnkleRoll", "LAnklePitch")       : [0.0, 0.0, 0.0],
            ("Torso", "RShoulderPitch")         : [0.0, -98.0, 100.00 ],
            ("RShoulderPitch", "Torso")         : [0.0, -98.0, -100.00 ],
            ("RShoulderPitch", "RShoulderRoll") : [0.0, 0.0, 0.0],
            ("RShoulderRoll", "RShoulderPitch") : [0.0, 0.0, 0.0],
            ("RShoulderRoll", "RElbowYaw" )     : [105.00, -15.00, 0.00],        
            ("RElbowYaw", "RShoulderRoll" )     : [105.00, -15.00, 0.00],        
            ("RElbowYaw", "RElbowRoll")         : [0, 0, 0],
            ("RElbowRoll", "RElbowYaw")         : [0, 0, 0],
            ("RElbowRoll", "RWristYaw")         : [55.95, 0, 0 ],
            ("RWristYaw", "RElbowRoll")         : [55.95, 0, 0 ],
            ("Torso", "RHipYawPitch")           : [0, -50.0, -85.0],
            ("RHipYawPitch", "Torso")           : [0, -50.0, 85.0],
            ("RHipYawPitch", "RHipRoll")        : [0.0 , 0.0, 0.0],
            ("RHipRoll", "RHipYawPitch")        : [0.0 , 0.0, 0.0],
            ("RHipRoll", "RHipPitch")           : [0.0, 0.0, 0.0],
            ("RHipPitch", "RHipRoll")           : [0.0, 0.0, 0.0],
            ("RHipPitch", "RKneePitch")         : [0.0, 0.0, -100.0],
            ("RKneePitch", "RHipPitch")         : [0.0, 0.0, 100.0],
            ("RKneePitch","RAnklePitch")        : [0.0, 0.0, -102.9],
            ("RAnklePitch","RKneePitch")        : [0.0, 0.0, 102.9],
            ("RAnklePitch", "RAnkleRoll")       : [0.0, 0.0, 0.0],
            ("RAnkleRoll", "RAnklePitch")       : [0.0, 0.0, 0.0]}
			
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
		global RAnkleRoll    
		RAnkleRoll =   [[1,			0,			0,			0],
						[0,			cos(X),		sin(X),		0],
						[0,			-sin(X),	cos(X),		0],
						[0,			0,			0,			1]]

		X = self.mot.getAngles("RAnklePitch", False)[0] * checkupdown
		global RAnklePitch	
		RAnklePitch =  [[cos(X),	0,			-sin(X),	0],
						[0,			1,			0,			0],
						[sin(X),	0,			cos(X),		102.90 * checkupdown],
						[0,			0,			0,			1]]

		X = self.mot.getAngles("RKneePitch", False)[0] * checkupdown
		global RKneePitch
		RKneePitch =   [[cos(X),	0,			-sin(X),	0],
						[0,			1,			0,			0],
						[sin(X),	0,			cos(X),		100 * checkupdown],
						[0,			0,			0,			1]]

		X = self.mot.getAngles("RHipPitch", False)[0] * checkupdown	
		global RHipPitch	
		RHipPitch =    [[cos(X),	0,			-sin(X),	0],
						[0,			1,			0,			0],
						[sin(X),	0,			cos(X),		0],
						[0,			0,			0,			1]]

		X = self.mot.getAngles("RHipRoll", False)[0] * checkupdown
		global RHipRoll	
		RHipRoll = 	   [[1,			0,			0,			0],
						[0,			cos(X),		-sin(X),	0],
						[0,			sin(X),		cos(X),		0],
						[0,			0,			0,			1]]

		X = self.mot.getAngles("RHipYawPitch", False)[0] * checkupdown		
		global RHipYaw	
		RHipYaw =      [[cos(X/2),	-sin(X/2),	0,			0],
						[0,			1,			0,			0],
						[sin(X/2),	cos(X/2),	0,			0],
						[0,			0,			0,			1]]

		X = self.mot.getAngles("RHipYawPitch", False)[0] * checkupdown	
		global RHipYawPitch	
		RHipYawPitch = [[cos(X/2),	0,			-sin(X/2),	0],
						[0,			1,			0,			0],
						[sin(X/2),	0,			cos(X/2),	0],
						[0,			0,			0,			1]]
							
		global Torso					
		Torso =	   	   [[1,			0,			0,			0],
						[0,			1,			0,			-50 * checkupdown],
						[0,			0,			1,			85 * checkupdown],
						[0,			0,			0,			1]]
						

	# returns the center of mass of a given part
    def get_CoM(self):
	    update(self)
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
		
	    Chains.append(["RAnkleRoll","RAnklePitch","RKneePitch","RHipPitch"])

	    Transform = [[1,0,0,0],
					 [0,1,0,0],
					 [0,0,1,0],
					 [0,0,0,1]]
		
	    JointCOMs = []
	    JointMasses = []

	    for element in Chains[0]:
		    transform = mult(transform, eval(element))		
		    JointCOMs.append(mult(transform, [[jointCOM[element][0][0]],[jointCOM[element][0][1]],[jointCOM[element][0][2]],[1]]))
		    JointMasses.append(jointCOM[element][1])
	    transformToTorso = transform
	    print JointCOMs[:]
	    print JointMasses[:]	
	    COM = [0,0,0]
	    for i in range(range(len(JointMasses))):
		    COM[0] += JointCOMs[i][0] * JointMasses[i]
		    COM[1] += JointCOMs[i][1] * JointMasses[i]
		    COM[2] += JointCOMs[i][2] * JointMasses[i]
	    COM = COM/sum(JointMasses)
	    print COM
		
    def mult(self,matrix1,matrix2):
		# Matrix multiplication
		if len(matrix1[0]) != len(matrix2):
			# Check matrix dimensions
			print 'Matrices must be m*n and n*p to multiply!'
		else:
			# Multiply if correct dimensions
			new_matrix = zero(len(matrix1),len(matrix2[0]))
			for i in range(len(matrix1)):
				for j in range(len(matrix2[0])):
					for k in range(len(matrix2)):
						new_matrix[i][j] += matrix1[i][k]*matrix2[k][j]
			return new_matrix