#! /usr/bin/env python2.7

import sys

if len(sys.argv) < 4:
	print "Usage: plot_body hide_labels (True / False) ip_address [LLeg / RLeg]"
	sys.exit(1)

hide_labels = sys.argv[1]
ip_address = sys.argv[2]
leg = sys.argv[3]

from CoM import DebugCoM
com = DebugCoM(ip_address, 9559)
com.get_CoM(leg)

# plot
import plot