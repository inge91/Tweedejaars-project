/**
 * This file has been autogenerated by Aldebaran Module Proxy Writer
 */


#pragma once
#ifndef _LIBNAOQICLIENT_NAOQICLIENT_INTERFACE_ALMOTIONPROXY_INTERFACE_H_
#define _LIBNAOQICLIENT_NAOQICLIENT_INTERFACE_ALMOTIONPROXY_INTERFACE_H_

#include <vector>
#include <naoqiclient/api.h>

namespace AL
{
  /**
   * ALMotionProxy gives acces to all bound methods of the module.
   */
  class NAOQICLIENT_API ALMotionProxyInterface
    {

    public:

      /**
     * Defines the interpolation types available
     */
     enum INTERPOLATION_TYPE {
      INTERPOLATION_LINEAR = 0,
      INTERPOLATION_SMOOTH = 1
    };

      /**
     * Defines the spaces within which cartesian moves can be described
     */
     enum TASK_SPACE {
      SPACE_BODY = 0,
      SPACE_SUPPORT_LEG = 1,
      SPACE_LOCAL = 2,
      SPACE_WORLD = 3,
      SPACE_END = 4
    };

      /**
     * Defines the support mode of the model
     */
    enum SUPPORT_MODE {
      SUPPORT_MODE_LEFT = 0,
      SUPPORT_MODE_DOUBLE_LEFT = 1,
      SUPPORT_MODE_RIGHT = 2,
      SUPPORT_MODE_DOUBLE_RIGHT = 3,
      SUPPORT_MODE_NONE = 4,
    };

    /**
      * Defines the type of balancing to do
      */
    enum BALANCE_MODE {
      BALANCE_MODE_OFF = 0,         // no balancing
      BALANCE_MODE_AUTO = 1,          // auto create com commands
      BALANCE_MODE_COM_CONTROL = 2  // don't auto create com commands
    };

    /**
      *  Defines the axis mask
      */
    enum AXIS_MASK {
      AXIS_MASK_X = 1,
      AXIS_MASK_Y = 2,
      AXIS_MASK_Z = 4,
      AXIS_MASK_WX = 8,
      AXIS_MASK_WY = 16,
      AXIS_MASK_WZ = 32,
      AXIS_MASK_ALL = 63,
      AXIS_MASK_VEL = 7,
      AXIS_MASK_ROT = 56
    };

       /**
        * \brief setAngle : Sets the absolute angle of a joint.
        * \param pJointName The name of the Joint
        * \param pAngle Target angle in radians
        */
       virtual void setAngle ( std::string pJointName, float pAngle )=0;

     /**
        * \brief changeAngle : Changes the angle of a joint relative to the current angle
        * \param pJointName The name of the joint
        * \param pAngleChange The Angle change in radians
        */
       virtual void changeAngle ( std::string pJointName, float pAngleChange )=0;

       /**
        * \brief getAngle : Gets the angle of a joint.
        * \param pJointName The name of the Joint
        * \return value : The Angle of the joint in radians
        */
      virtual  float getAngle ( std::string pJointName )=0;

     /**
        * \brief postGotoAngle : Interpolates the angle of a joint from the current angles to the target.
        * \param pJointName The name of the Joint
        * \param pAngle The target angle of the motor in radians.
        * \param pTime The time of interpolation in seconds.
        * \param pInterpolationType The type of interpolation to do. { LINEAR = 0, SMOOTH = 1 }
        * \return value : The task ID that can be used to stop the task.
        */
       virtual int postGotoAngle ( std::string pJointName, float pAngle, float pTime, int pInterpolationType )=0;

     /**
        * \brief gotoAngle : Interpolates the angle of a joint from the current angles to the target. (Blocking)
        * \param pJointName The name of the Joint
        * \param pAngle The target angle of the motor in radians.
        * \param pTime The time of interpolation in seconds.
        * \param pInterpolationType The type of interpolation to do. { LINEAR = 0, SMOOTH = 1 }
        */
       virtual void gotoAngle ( std::string pJointName, float pAngle, float pTime, int pInterpolationType )=0;

       /**
    * \brief Function to get the difference between the command angle and the sensed angle of a joint
    * \return An angle error in radians
    * \param pJointName The name of the joint
    */
     virtual float getAngleError(std::string pJointName)=0;
     /**
        * \brief setChainAngles : Sets the absolut angles of the joints in the specified chain. The number of angles required depends on the length of the chain.
        * \param pChainName The name of the Chain
        * \param pAngles A vector of target angles in radians
        */
       virtual void setChainAngles ( std::string pChainName, std::vector<float> pAngles )=0;

     /**
        * \brief changeChainAngles : Changes the angles of the joints relative to the current angle in the specified chain. The number of angles required depends on the length of the chain.
        * \param pChainName The name of the Chain
        * \param pAngleChanges A vector of angles changes in radians
        */
       virtual void changeChainAngles ( std::string pChainName, std::vector<float> pAngleChanges )=0;

     /**
        * \brief getChainAngles : Gets the angles of the joints in the specified chain. The number of angles returned depends on the length of the chain.
        * \param pChainName The name of the Chain
        * \return value : A vector of angles in radians, one for each motor in the chain.
        */
     virtual std::vector<float> getChainAngles ( std::string pChainName )=0;

     /**
        * \brief postGotoChainAngles : Interpolates the angles of the joints in the specified chain from the current angles to the target. The number of angles required depends on the length of the chain.
        * \param pChainName The name of the Chain
        * \param pAngles Target angles in radians
        * \param pTime The time of interpolation in seconds.
        * \param pInterpolationType The type of interpolation to do. { INTERPOLATION_LINEAR = 0, INTERPOLATION_SMOOTH = 1}
        * \return value : The task ID that can be used to stop the task.
        */
       virtual int postGotoChainAngles ( std::string pChainName, std::vector<float> pAngles, float pTime, int pInterpolationType )=0;

     /**
        * \brief gotoChainAngles : Interpolates the angles of the joints in the specified chain from the current angles to the target. The number of angles required depends on the length of the chain. (Blocking)
        * \param pChainName The name of the Chain
        * \param pAngles Target angles in radians
        * \param pTime The time of interpolation in seconds.
        * \param pInterpolationType The type of interpolation to do. { INTERPOLATION_LINEAR = 0, INTERPOLATION_SMOOTH = 1 }
        */
       virtual void gotoChainAngles ( std::string pChainName, std::vector<float> pAngles, float pTime, int pInterpolationType )=0;


     /**
    * \brief getChainAngleErrors Function to get the difference between the command angles and the sensed angles for a chain
    * \param pChainName The name of the chain
    * \return A vector of the errors, one for each joint in the chain
    */
     virtual std::vector<float> getChainAngleErrors(std::string pChainName) =0;

     /**
        * \brief setBodyAngles : Sets the absolut angles of all the joints in the body.
        * \param pAngles A vector of angles in radians for all the joints of all the chains
        */
       virtual void setBodyAngles ( std::vector<float> pAngles )=0;

     /**
        * \brief changeBodyAngles : Changes the angles relative to the current angles of all the joints in the body.
        * \param pAngleChanges A vector of angle changes in radians
        */
       virtual void changeBodyAngles ( std::vector<float> pAngleChanges )=0;

       /**
        * \brief getBodyAngles : Gets the angles of all the joints in the body.
        * \return value : A vector of angles in radians, one for each joint.
        */
       virtual std::vector<float> getBodyAngles (  )=0;
     /**
        * \brief getBodyAngleErrors : Gets the errors between the command and sensed angles of all the joints in the body.
        * \return value : A vector of angles errors in radians, one for each joint.
        */
       virtual std::vector<float> getBodyAngleErrors (  )=0;

     /**
        * \brief postGotoBodyAngles : Interpolates the angles of the joints in the body from the current position to the target.
        * \param pAngles The Target angles in radians of all the motors in the chain.
        * \param pTime The time of interpolation in seconds.
        * \param pInterpolationType The type of interpolation to do. { INTERPOLATION_LINEAR = 0, INTERPOLATION_SMOOTH = 1 }
        * \return value : The task ID that can be used to stop the task.
        */
       virtual int postGotoBodyAngles ( std::vector<float> pAngles, float pTime, int pInterpolationType )=0;
     /**
        * \brief gotoBodyAngles : Interpolates the angles of the joints in the body from the current position to the target.
        * \param pAngles The Target angles in radians of all the motors in the chain.
        * \param pTime The time of interpolation in seconds.
        * \param pInterpolationType The type of interpolation to do. { INTERPOLATION_LINEAR = 0, INTERPOLATION_SMOOTH = 1 }
        */
       virtual void gotoBodyAngles (std::vector<float>  pAngles, float pTime, int pInterpolationType )=0;
       /**
        * \brief setJointStiffness : Sets the stiffness of all the joints in the body.
        * \param pJointName The Name of the Joint
        * \param pStiffness The Stiffness between zero and one
        * \param pTime The time of the interpolation in seconds NOTE: The transition is immediate in the model, and interpolated in the DCM
        */
       virtual void setJointStiffness ( std::string pJointName, float pStiffness, float pTime )=0;

     /**
        * \brief setChainStiffness : Function to Set the stiffness of all the motors in the chain
        * \param pChainName The name of the Chain
        * \param pStiffness The Stiffness between zero and one
        * \param pTime The time of the interpolation in seconds. NOTE: The transition is immediate in the model, and interpolated in the DCM
        */
       virtual void setChainStiffness ( std::string pChainName, float pStiffness, float pTime )=0;

     /**
        * \brief setBodyStiffness : Function to Set the stiffness of all the motors in the body
        * \param pStiffness The Stiffness between zero and one
        * \param pTime The time of the interpolation in seconds. NOTE: The transition is immediate in the model, and interpolated in the DCM
        */
       virtual void setBodyStiffness ( float pStiffness, float pTime )=0;
       /**
        * \brief getCom : Gets the position of the Center of Mass relative to the support Leg. Units are meters.
        * \param pSpace The task space
        * \return value : A vector of positions in meters [x, y, z].
        */
       virtual std::vector<float> getCom ( int pSpace )=0;

     /**
        * \brief setCom : Sets the position of the Center of Mass relative to the support Leg. Units are meters.
        * \param pX The x component of the COM position
        * \param pY The y component of the COM position
        * \param pZ The z component of the COM position
        */
       virtual void setCom ( float pX, float pY, float pZ )=0;

       /**
        * \brief changeCom : Changes the position of the Center of Mass relative to the support Leg. Units are meters.
        * \param pXd The x component of the COM change
        * \param pYd The y component of the COM change
        * \param pZd The z component of the COM change
        */
       virtual void changeCom ( float pXd, float pYd, float pZd )=0;

     /**
        * \brief postGotoCom : Moves the position of the Center of Mass over time in absolute frame.
        * \param pX The x component of the COM target
        * \param pY The y component of the COM target
        * \param pZ The z component of the COM target
        * \param pTime The time of the interpolation in seconds
        * \param pInterpolationType The interpolation type : LINEAR  = 0 or SMOOTH = 1(3th order Polynomial)
        * \returns: The TaskID that was assigned to it
        */
       virtual int postGotoCom ( float pX, float pY, float pZ, float pTime, int pInterpolationType )=0;

       /**
        * \brief gotoCom : Moves the position of the Center of Mass over time in absolute frame. (Blocking)
        * \param pX The x component of the COM target
        * \param pY The y component of the COM target
        * \param pZ The z component of the COM target
        * \param pTime The time of the interpolation in seconds
        * \param pInterpolationType The interpolation type { INTERPOLATION_LINEAR = 0, INTERPOLATION_SMOOTH = 1 }
        */
       virtual void gotoCom ( float pX, float pY, float pZ, float pTime, int pInterpolationType )=0;

     /**
        * \brief postGotoTorsoOrientation : Function to rotate the torso over time in absolute frame.
        * \param pX The x component of the torso orientation in radians
        * \param pY The y component of the torso orientation in radians
        * \param pTime The time of the interpolation in seconds
        * \param pInterpolationType The interpolation type { INTERPOLATION_LINEAR = 0, INTERPOLATION_SMOOTH = 1 }
        * \return value : The task ID that can be used to stop the task.
        */
       virtual int postGotoTorsoOrientation ( float pX, float pY, float pTime, int pInterpolationType )=0;

     /**
        * \brief gotoTorsoOrientation : Function to rotate the torso over time in absolute frame. (Blocking)
        * \param pX The x component of the torso orientation in radians
        * \param pY The y component of the torso orientation in radians
        * \param pTime The time of the interpolation in seconds
        * \param pInterpolationType The interpolation type { INTERPOLATION_LINEAR = 0, INTERPOLATION_SMOOTH = 1 }
        */
       virtual void gotoTorsoOrientation ( float pX, float pY, float pTime, int pInterpolationType )=0;

       /**
        * \brief walkStraight : Adds a straight walk pattern that could result in several forwards or backwards footsteps
        * \param pDistance The distance in meters e.g. 0.1f
        * \param pNumSamplesPerStep The number of 20ms cycles per step. e.g. 60
        */
       virtual void walkStraight ( float pDistance, int pNumSamplesPerStep )=0;

     /**
        * \brief walkSideways : Adds a sideways walk pattern that could result in several footsteps
        * \param pDistance The sideways distance in meters e.g. -0.1f
        * \param pNumSamplesPerStep The number of 20ms cycles per step. e.g. 60
        */
       virtual void walkSideways ( float pDistance, int pNumSamplesPerStep )=0;

     /**
        * \brief turn : Adds a turn in place walk pattern that could result in several footsteps
        * \param pAngle The angle to turn in radians e.g. 0.5f
        * \param pNumSamplesPerStep The number of 20ms cycles per step. e.g. 60
        */
       virtual void turn ( float pAngle, int pNumSamplesPerStep )=0;

     /**
        * \brief walkArc : Adds a circular walk pattern that could result in several footsteps
        * \param pAngle The angle of the arc of the circle to turn in radians e.g. 0.5f
        * \param pRadius The radius of the circle in meters e.g. 1.5f
        * \param pNumSamplesPerStep The number of 20ms cycles per step. e.g. 60
        */
       virtual void walkArc ( float pAngle, float pRadius, int pNumSamplesPerStep )=0;

     /**
        * \brief endWalk : Clears any Footsteps in the Walk Process and allows it to die
        */
       virtual void endWalk (  )=0;

       /**
        * \brief walkIsActive : Returns true if there is an active walk task.
        * \return value : true if a walk task is active
        */
       virtual bool walkIsActive (  )=0;

       /**
        * \brief waitUntilWalkIsFinished : Waits until the WalkTask is finished
        */
       virtual void waitUntilWalkIsFinished (  )=0;

       /**
        * \brief setWalkConfig : Sets the parameters that will be used next time a WalkTask is created (Use with caution)
        * \param pMaxStepLength The maximum length in meters of a footstep
    * \param pMaxStepHeight The maximum height of a footstep cycloid
    * \param pMaxStepSide The maximum side length in meters of a footstep
    * \param pMaxStepTurn The maximum change in z orientation in radians of a footstep
    * \param pZmpOffsetX The zmp offset in the forwards direction in meters
    * \param pZmpOffsetY  The zmp offset in the sideways direction in meters
        */
       virtual void setWalkConfig ( float pMaxStepLength, float pMaxStepHeight, float pMaxStepSide, float pMaxStepTurn, float pZmpOffsetX, float pZmpOffsetY) =0;


       /**
        * \brief getWalkConfig : Gets the parameters that will be used next time a WalkTask is created
        * \return value : MaxStepLength, MaxStepTurn ,MaxStepHeight, ZmpOffsetX, ZmpOffsetY
        */
       virtual std::vector<float> getWalkConfig (  )=0;

     /**
        * \brief changePosition : Creates a move of an end effector in cartesian space
        * \param pChainName The name of the Chain
        * \param pSpace The task space
        * \param pVelocity A 6D velocity array (pxd,pyd,pzd,pwxd,pwyd,pwzd)
        * \param pAxisMask An axis mask. True for axes that you wish to control
        */
       virtual void changePosition ( std::string pChainName, int pSpace, std::vector<float> pVelocity, int pAxisMask )=0;

     /**
        * \brief setPosition : Moves an end-effector to the given position and orientation
        * \param pChainName The name of the Chain
        * \param pSpace The task space
        * \param pVelocity A 6D position array (px,py,pz,pwx,pwy,pwz)
        * \param pAxisMask An axis mask. True for axes that you wish to control
        */
       virtual void setPosition ( std::string pChainName, int pSpace, std::vector<float> pVelocity, int pAxisMask )=0;

       /**
        * \brief postGotoPosition : Moves an end-effector to the given position and orientation over time.
        * \param pChainName The name of the Chain
        * \param pSpace The task space
        * \param pVelocity A 6D position array (px,py,pz,pwx,pwy,pwz)
        * \param pAxisMask An axis mask. True for axes that you wish to control
        * \param pTime The time of the interpolation in seconds
        * \param pInterpolationType The interpolation type { INTERPOLATION_LINEAR = 0, INTERPOLATION_SMOOTH = 1 }
        */
       virtual void postGotoPosition ( std::string pChainName, int pSpace, std::vector<float> pVelocity, int pAxisMask, float pTime, int pInterpolationType )=0;


     /**
        * \brief gotoPosition : Moves an end-effector to the given position and orientation over time. (Blocking)
        * \param pChainName The name of the Chain
        * \param pSpace The task space
        * \param pVelocity A 6D position array (px,py,pz,pwx,pwy,pwz)
        * \param pAxisMask An axis mask. True for axes that you wish to control
        * \param pTime The time of the interpolation in seconds
        * \param pInterpolationType The interpolation type { INTERPOLATION_LINEAR = 0, INTERPOLATION_SMOOTH = 1 }
        */
       virtual void gotoPosition ( std::string pChainName, int pSpace, std::vector<float> pVelocity, int pAxisMask, float pTime, int pInterpolationType )=0;

     /**
        * \brief killAll : Kills all tasks.
        */
       virtual void killAll ( void )=0;

       /**
        * \brief killTask : Kills a task.
        * \param pTaskID The TaskID of the task you want to kill. The TaskID is returned from any action which takes time.
        * \return value : False if the task could not be found
        */
       virtual bool killTask ( int pTaskID )=0;

       /**
        * \brief getBodyLimits : Gets the minAngle, maxAngle, and maxChangePerCycle for all the joints in the body.
        * \return value : An ALValue array of ALValue arrays containing the minAngle, maxAngle, and maxChangePerCycle for all the joints in the body.
        */
      // virtual ALValue getBodyLimits (  )=0;

     /**
        * \brief setBalanceMode : Sets the balance mode which can be used to change the way nao responds to commands while keeping balance.
        * \param pBalanceMode The balance mode {BALANCE_MODE_OFF = 0, BALANCE_MODE_AUTO = 1, BALANCE_MODE_COM_CONTROL = 2}
        */
       virtual void setBalanceMode ( int pBalanceMode )=0;

       /**
        * \brief getBalanceMode : Gets the balance mode which can be used to change the way nao responds to commands while keeping balance.
        * \return value : The balance mode {BALANCE_MODE_OFF = 0, BALANCE_MODE_AUTO = 1, BALANCE_MODE_COM_CONTROL = 2}
        */
       virtual int getBalanceMode (  )=0;

       /**
        * \brief setSupportMode : Sets the support mode. TODO ck task or sample?
        * \param pSupportMode  The support mode. { SUPPORT_MODE_LEFT = 0, SUPPORT_MODE_DOUBLE_LEFT = 1, SUPPORT_MODE_RIGHT = 2, SUPPORT_MODE_DOUBLE_RIGHT = 3}
        */
       virtual void setSupportMode ( int pSupportMode )=0;

       /**
        * \brief getSupportMode : Gets the support mode.
        * \return value : The balance mode { SUPPORT_MODE_LEFT = 0, SUPPORT_MODE_DOUBLE_LEFT = 1, SUPPORT_MODE_RIGHT = 2, SUPPORT_MODE_DOUBLE_RIGHT = 3}
        */
       virtual int getSupportMode (  )=0;

       /**
        * \brief getForwardTransform : Gets the forward Homogenous Transform of a Chain relative to the SPACE_BODY
        * \param pChainName The name of the Chain
        * \param pSpace The task space {SPACE_BODY = 0, SPACE_SUPPORT_LEG = 1 }
        * \return value : A vector of 16 floats corresponding to the values of the matrix, line by line.
        */
       virtual std::vector<float> getForwardTransform ( std::string pChainName, int pSpace )=0;

       /**
        * \brief getPosition : Gets the Position of a Chain relative to the TASK_SPACE
        * \param pChainName The name of the Chain
        * \param pSpace The task space {SPACE_BODY = 0, SPACE_SUPPORT_LEG = 1 }
        * \return value : A vector containing the Position6D. (x, y, z, wx, wy, wz )
        */
       virtual std::vector<float> getPosition ( std::string pChainName, int pSpace )=0;


       /**
      * \brief setAutoBalancerPidParams : Sets the PID parameters for torso rotation and com
    * \param pRotP The proportional factor for rotation
    * \param pRotD The derivative factor for rotation
    * \param pRotLimit The limit for rotation changes
    * \param pComP The proportional factor for com
    * \param pComD The derivative factor for com
    * \param pComLimit The limit for com changes
    */
       virtual void setAutoBalancerPidParams ( float pRotP, float pRotD, float pRotLimit, float pComP, float pComD, float pComLimit)=0;


     /**
      * \brief getSupportPolygon : Gets a vector of the outer points of the support polygon
    * \return value: A vector of outer points x1,y1,...xn,yn in meters relative to SPACE_SUPPORT_LEG
    */
     virtual std::vector<float> getSupportPolygon (  )=0;

     /**
      * \brief getSupportPolygonCenter : Gets the center of the support polygon
    * \return value: A vector containing centerX and centerY in meters relative to SPACE_SUPPORT_LEG
    */
     virtual std::vector<float> getSupportPolygonCenter (  )=0;

   };
};

#endif  // _LIBNAOQICLIENT_NAOQICLIENT_INTERFACE_ALMOTIONPROXY_INTERFACE_H_
