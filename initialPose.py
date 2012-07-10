from naoqi import ALProxy

#makes a pose that keeps balance before exercising the kicking motion
def initialPose(kickSide, ip):
    if(kickSide == "RLeg"):
        otherLeg = "L"
        kickLeg = "R"
    else:
        otherLeg = "R"
        kickLeg = "L"
    mot = ALProxy("ALMotion", ip, 9559)
    # Example showing how to set angles, using a fraction of max speed
    names  = ['HeadYaw', 'HeadPitch']
    angles  = [0.6, -0.2]
    fractionMaxSpeed  = 0.2
    proxy.setAngles(names, angles, fractionMaxSpeed)

    



