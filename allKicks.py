# Function that calculates all possible retraction points
# Run in UsarSim to find all moves that can be made by the nao
def possiblePositions(stepwidth = 1, size_range = 1000, accuracy = 2):
    """stepwidth is the accurcay with which all possible steps are taken. The
    larger the  stepwidth the smaller the amount of results found. Stepwidth is
    in millimeters. Accuracy is how many decimals are considered when
    comparing coordiantes. Function outputs a list of all possible coordinates"""
    from naoqi import ALProxy
     motions as m
    import time
    mot = ALProxy("ALMotion", "127.0.0.1", 9559)
    # set in normalPose
    m.normalPose()
    (xTorso, yTorso, zTorso) = m.getPosition("Torso", 1, True)

    # TODO make positions relative to the nao
    # do all ranges
    for x in range(-size_range, size_range, stepwidth):
        for y in range(-size_range, size_range, stepwidth):
            for z in range(-size_range, size_range, stepwidth):
                mot.setPosition("RLeg", SPACE_WORLD, (x, y, z), 10, 7)
                time.sleep(3)
                (v, w, u, _, _, _) = mot.getPosition("RLeg", 1, True)
                # in case the same position occurs, write it to file
                x = round(3, x)
                y = round(3, y)
                z = round(3, z)
                v = round(3, v)
                w = round(3, w)
                u = round(3, u)
                if(x == v && y == w && z == u):
                    f = open('possible_positions.txt', 'w')
                    f.write("( " + str(x) + " " + str(y) + " " str(z) + " )" )
                    # TODO also write the angles
                    f.closed
                    # if it is also a balanced position write it to another file
                    if(mot.getCOM("Body", SPACE_WORLD, false) ):
                        f = open('possible_positions_Com.txt', 'w')
                        f.write("( " + str(x - xTorso) + " " + str(y - yTorso) +
                                " " str(z - zTorso) + " )" )
                        # TODO also write the angles
                        f.closed
                m.normalPose()
                    # our own COMfunction to try.
                    #if(# com in support polygon)
                    #    f = open('possible_positions_Com_Ours.txt', 'w')
                    #    f.write("( " + str(x) + " " + str(y) + " " str(z) + " )" )
                    #    f.closed
                


