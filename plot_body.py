#! /usr/bin/env python2.7

import sys
from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
from numpy import matrix

if len(sys.argv) < 4:
	print "Usage: plot_body hide_labels (True / False) ip_address [LLeg / RLeg]"
	sys.exit(1)

hide_labels = sys.argv[1]
ip_address = sys.argv[2]
leg = sys.argv[3]

from CoM import CenterOfMass
com = CenterOfMass(ip_address, 9559, True)
data = com.get_locations_dict(leg)
com_loc = com.get_CoM(leg)

# define a number of chains to plot 
chains = [
		  #left leg
		  ["LAnklePitch", "LKneePitch", "LHipPitch", "LHipRoll",
           "LHipYawPitch", "Torso"],
          # right leg
          ["RAnkleRoll", "RAnklePitch", "RKneePitch", "RHipPitch", "RHipRoll",
           "RHipYawPitch", "Torso"],
          # left arm
          ["LElbowRoll", "LElbowYaw", 
           "LShoulderPitch", "Torso"],
          # right arm
          ["RElbowRoll", "RElbowYaw", "RShoulderRoll",
           "RShoulderPitch", "Torso"],
          # torso/head area
          ["HeadPitch", "HeadYaw", "Torso"]]

# initialisation
fig = plt.figure()
axes = fig.add_subplot(111, projection='3d')

# plot the data for each chain
for chain in chains:
	coords = [matrix(data[key]) for key in chain]
	xs = [coord[0, 0] for coord in coords]
	ys = [coord[1, 0] for coord in coords]
	zs = [coord[2, 0] for coord in coords]
	axes.plot(xs, ys, zs)

# plot the CoM
print com_loc
com_x = com_loc[0, 0]
com_y = com_loc[1, 0]
com_z = com_loc[2, 0]
print 'x', com_x
print 'y', com_y
print 'z', com_z
axes.plot([com_x, com_x + 0.1], [com_y, com_y + 0.1], [com_z, com_z + 0.1])
axes.text(com_x, com_y, com_y, "CoM")

# plot the labels
if not hide_labels:
	visited = []  # ignore already visited locations to reduce clutter
	for key, value in data.iteritems():
		if value in visited:
			continue
		axes.text(value[0][0], value[1][0], value[2][0], key)
		visited.append(value)

# set and label the axes
axes.set_xlim([-20, 500])
axes.set_ylim([-20, 500])
axes.set_zlim([-20, 500])

axes.set_xlabel('X')
axes.set_ylabel('Y')
axes.set_zlabel('Z')

plt.show()
