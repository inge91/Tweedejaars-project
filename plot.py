from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
from numpy import matrix

# initialisation
fig = plt.figure()
axes = fig.add_subplot(111, projection='3d')

# read the data
with open('debug_com.txt', 'r') as f:
	data = f.read()

data = eval(data)

# define a number of chains to plot 
chains = [
		  #left leg
		  ["LAnklePitch", "LKneePitch", "LHipPitch", "LHipRoll",
           "LHipYawPitch", "Torso"],
          # right leg
          ["RAnkleRoll", "RAnklePitch", "RKneePitch", "RHipPitch", "RHipRoll",
           "RHipYawPitch", "Torso"],
          # left arm
          ["LElbowRoll", "LElbowYaw", "LShoulderRoll",
           "LShoulderPitch", "Torso"],
          # right arm
          ["RElbowRoll", "RElbowYaw", "RShoulderRoll",
           "RShoulderPitch", "Torso"],
          # torso/head area
          ["HeadPitch", "HeadYaw", "Torso"]]

# plot the data for each chain
for chain in chains:
	coords = [matrix(data[key]) for key in chain]
	xs = [coord[0, 0] for coord in coords]
	ys = [coord[1, 0] for coord in coords]
	zs = [coord[2, 0] for coord in coords]
	print xs
	print ys
	print zs
	axes.plot(xs, ys, zs)

# plot the labels
visited = []  # ignore already visited locations to reduce clutter
for key, value in data.iteritems():
	if value in visited:
		continue
	axes.text(value[0][0], value[1][0], value[2][0], key)
	visited.append(value)

axes.set_xlabel('X')
axes.set_ylabel('Y')
axes.set_zlabel('Z')

plt.show()