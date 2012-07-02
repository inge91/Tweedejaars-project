# Function that calculates all possible retraction points
# Run in UsarSim to find all moves that can be made by the nao
def possiblePositions(stepwidth = 1, size_range = 1000):
    """stepwidth is the accurcay with which all possible steps are taken. The
    larger the  stepwidth the smaller the amount of results found. Stepwidth is
    in millimeter. Function outputs a list of all possible coordinates"""
    from naoqi import ALProxy
    import motions as m
    import time
    mot = ALProxy("ALMotion", ip, 9559)
    # set in normalPose
    m.normalpose()
    # do all ranges
    for x in range(-size_range, size_range, stepwidth):
        for y in range(-size_range, size_range, stepwidth):
            for z in range(-size_range, size_range, stepwidth):
                mot.setPosition("RLeg", SPACE_WORLD, (x, y, z), 10, 7)
                time.sleep(3)
                (v, w, u, _, _, _) = mot.getPosition("RLeg", SPACE_WORLD, True)
                # in case the same position occurs, write it to file
                if(x == v && y == w && z == u):
                    f = open('possible_positions.txt', 'w')
                    f.write("( " + str(x) + " " + str(y) + " " str(z) + " )" )
                    # TODO also write the angles
                    f.closed
                    # if it is also a balanced position write it to another file
                    if(mot.getCOM("Body", SPACE_WORLD, false) ):
                        f = open('possible_positions_Com.txt', 'w')
                        f.write("( " + str(x) + " " + str(y) + " " str(z) + " )" )
                        # TODO also write the angles
                        f.closed
                    # our own COMfunction to try.
                    #if(# com in support polygon)
                    #    f = open('possible_positions_Com_Ours.txt', 'w')
                    #    f.write("( " + str(x) + " " + str(y) + " " str(z) + " )" )
                    #    f.closed
                


