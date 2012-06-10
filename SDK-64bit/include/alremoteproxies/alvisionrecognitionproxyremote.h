// Generated for ALVisionRecognition version 1.12

#ifndef ALVISIONRECOGNITIONPROXYREMOTE_H_
#define ALVISIONRECOGNITIONPROXYREMOTE_H_
#include <alremoteproxies/alvisionrecognitionproxyposthandlerremote.h>

namespace AL
{

/// <summary>ALVisionRecognition is a module which detects and recognizes learned pictures, like pages of a comic books, faces of objects or even locations.
    ///
    /// The learning stage is done using the Choregraphe interface. Follow the steps in the green doc that will explain how to create your own database.
    ///
    /// The output value is written in ALMemory in the PictureDetected variable.
    ///
    /// It contains an array of tags, with the following format: 
    ///
    ///  
    ///
    /// [ [ TimeStampField ] [ Picture_info_0 , Picture _info_1, . . . , Picture_info_N-1 ] ] 
    ///
    ///  
    ///
    /// with as many Picture_info tags as things currently recognized. 
    ///
    /// Picture_info = [[labels_list], matched_keypoints, ratio, [boundary_points]] 
    ///
    /// with labels_list = [label_0, label_1, ..., label_N-1] and label_n belongs to label_n+1 
    ///
    /// and boundary_points = [[x0,y0], [x1,y1], ..., [xN,yN]] 
    ///
    ///  
    ///
    /// - Labels are the names given to the picture (e.g. \"cover/my book\", or \"fridge corner/kitchen/my flat\"). 
    ///
    /// - matched_keypoints corresponds to the number of keypoints retrieved in the current frame. 
    ///
    /// - ratio represents the number of keypoints found for the object in the current frame divided by the number of keypoints found during the learning stage. 
    ///
    /// - boundary_points is a list of points coordinates in angle values representing the reprojection in the current image of the boundaries selected during the learning stage.</summary>
class ALVisionRecognitionProxyRemote : public ALProxyRemote
{
  public:

    /// <summary>
    /// Remote Constructor
    /// </summary>
    /// <param name="pIP"> The IP address used for the connection</param>
    /// <param name="pPort"> The port used for the connection </param>
    ALVisionRecognitionProxyRemote(std::string pIP, int pPort) : ALProxyRemote("ALVisionRecognition", pIP, pPort)
    {
        post.setParent( (ALProxyRemote*)this );
    }

    /// <summary>
    /// Implements thread wrappers around methods
    /// </summary>
    ALVisionRecognitionProxyPostHandlerRemote post;


    /// <summary>
    /// By default the database has the name \"database\" and is on the robot in /home/nao/naoqi/share/naoqi/vision/visionrecognition/current/ folder. This bound method allows to choose both another name and another folder for the database.
    /// </summary>
    /// <param name="databasePath"> Absolute path of the database on the robot, or \"\" to set default path. </param>
    /// <param name="databaseName"> Name of the database (without extension), or \"\" to set default database name. </param>
    /// <returns>  </returns>
    int changeDatabase(const std::string& databasePath, const std::string& databaseName)
    {

        return callRemote<int >("changeDatabase" , databasePath, databaseName);
    }


    /// <summary>
    /// Exits and unregisters the module.
    /// </summary>
    void exit()
    {

        callVoidRemote("exit");
    }


    /// <summary>
    /// Gets the name of the parent broker.
    /// </summary>
    /// <returns> The name of the parent broker. </returns>
    std::string getBrokerName()
    {

        return callRemote<std::string >("getBrokerName");
    }


    /// <summary>
    /// Gets the current period.
    /// </summary>
    /// <returns> Refresh period (in milliseconds). </returns>
    int getCurrentPeriod()
    {

        return callRemote<int >("getCurrentPeriod");
    }


    /// <summary>
    /// Gets the current precision.
    /// </summary>
    /// <returns> Precision of the extractor. </returns>
    float getCurrentPrecision()
    {

        return callRemote<float >("getCurrentPrecision");
    }


    /// <summary>
    /// Retrieves a method's description.
    /// </summary>
    /// <param name="methodName"> The name of the method. </param>
    /// <returns> A structure containing the method's description. </returns>
    AL::ALValue getMethodHelp(const std::string& methodName)
    {

        return callRemote<AL::ALValue >("getMethodHelp" , methodName);
    }


    /// <summary>
    /// Retrieves the module's method list.
    /// </summary>
    /// <returns> An array of method names. </returns>
    std::vector<std::string> getMethodList()
    {

        return callRemote<std::vector<std::string> >("getMethodList");
    }


    /// <summary>
    /// Retrieves the module's description.
    /// </summary>
    /// <returns> A structure describing the module. </returns>
    AL::ALValue getModuleHelp()
    {

        return callRemote<AL::ALValue >("getModuleHelp");
    }


    /// <summary>
    /// Gets the period for a specific subscription.
    /// </summary>
    /// <param name="name"> Name of the module which has subscribed. </param>
    /// <returns> Refresh period (in milliseconds). </returns>
    int getMyPeriod(const std::string& name)
    {

        return callRemote<int >("getMyPeriod" , name);
    }


    /// <summary>
    /// Gets the precision for a specific subscription.
    /// </summary>
    /// <param name="name"> name of the module which has subscribed </param>
    /// <returns> precision of the extractor </returns>
    float getMyPrecision(const std::string& name)
    {

        return callRemote<float >("getMyPrecision" , name);
    }


    /// <summary>
    /// Get the list of values updated in ALMemory.
    /// </summary>
    /// <returns> Array of values updated by this extractor in ALMemory </returns>
    std::vector<std::string> getOutputNames()
    {

        return callRemote<std::vector<std::string> >("getOutputNames");
    }


    /// <summary>
    /// Gets the parameters given by the module.
    /// </summary>
    /// <returns> Array of names and parameters of all subscribers. </returns>
    AL::ALValue getSubscribersInfo()
    {

        return callRemote<AL::ALValue >("getSubscribersInfo");
    }


    /// <summary>
    /// Gets the method usage string. This summarise how to use the method.
    /// </summary>
    /// <param name="name"> The name of the method. </param>
    /// <returns> A string that summarises the usage of the method. </returns>
    std::string getUsage(const std::string& name)
    {

        return callRemote<std::string >("getUsage" , name);
    }


    /// <summary>
    /// Returns true if the method is currently running.
    /// </summary>
    /// <param name="id"> The ID of the method that was returned when calling the method using 'post' </param>
    /// <returns> True if the method is currently running </returns>
    bool isRunning(const int& id)
    {

        return callRemote<bool >("isRunning" , id);
    }


    /// <summary>
    /// !!! DEPRECATED !!!
    /// </summary>
    void load()
    {

        callVoidRemote("load");
    }


    /// <summary>
    /// Just a ping. Always returns true
    /// </summary>
    /// <returns> returns true </returns>
    bool ping()
    {

        return callRemote<bool >("ping");
    }


    /// <summary>
    /// protected method
    /// </summary>
    void run()
    {

        callVoidRemote("run");
    }


    /// <summary>
    /// Set vision recognition parameters.
    /// </summary>
    /// <param name="paramName"> Name of the parameter to be changed. Among (\"resolution\",[int]) </param>
    /// <param name="paramValue"> Value(s) of the parameter to be changed. </param>
    void setParam(const std::string& paramName, const AL::ALValue& paramValue)
    {

        callVoidRemote("setParam" , paramName, paramValue);
    }


    /// <summary>
    /// returns true if the method is currently running
    /// </summary>
    /// <param name="id"> the ID of the method to wait for </param>
    void stop(const int& id)
    {

        callVoidRemote("stop" , id);
    }


    /// <summary>
    /// Subscribes to the extractor. This causes the extractor to start writing information to memory using the keys described by getOutputNames(). These can be accessed in memory using ALMemory.getData(\"keyName\"). In many cases you can avoid calling subscribe on the extractor by just calling ALMemory.subscribeToEvent() supplying a callback method. This will automatically subscribe to the extractor for you.
    /// </summary>
    /// <param name="name"> Name of the module which subscribes. </param>
    /// <param name="period"> Refresh period (in milliseconds) if relevant. </param>
    /// <param name="precision"> Precision of the extractor if relevant. </param>
    void subscribe(const std::string& name, const int& period, const float& precision)
    {

        callVoidRemote("subscribe" , name, period, precision);
    }


    /// <summary>
    /// Subscribes to the extractor. This causes the extractor to start writing information to memory using the keys described by getOutputNames(). These can be accessed in memory using ALMemory.getData(\"keyName\"). In many cases you can avoid calling subscribe on the extractor by just calling ALMemory.subscribeToEvent() supplying a callback method. This will automatically subscribe to the extractor for you.
    /// </summary>
    /// <param name="name"> Name of the module which subscribes. </param>
    void subscribe(const std::string& name)
    {

        callVoidRemote("subscribe" , name);
    }


    /// <summary>
    /// Unsubscribes from the extractor.
    /// </summary>
    /// <param name="name"> Name of the module which had subscribed. </param>
    void unsubscribe(const std::string& name)
    {

        callVoidRemote("unsubscribe" , name);
    }


    /// <summary>
    /// Updates the period if relevant.
    /// </summary>
    /// <param name="name"> Name of the module which has subscribed. </param>
    /// <param name="period"> Refresh period (in milliseconds). </param>
    void updatePeriod(const std::string& name, const int& period)
    {

        callVoidRemote("updatePeriod" , name, period);
    }


    /// <summary>
    /// Updates the precision if relevant.
    /// </summary>
    /// <param name="name"> Name of the module which has subscribed. </param>
    /// <param name="precision"> Precision of the extractor. </param>
    void updatePrecision(const std::string& name, const float& precision)
    {

        callVoidRemote("updatePrecision" , name, precision);
    }


    /// <summary>
    /// Returns the version of the module.
    /// </summary>
    /// <returns> A string containing the version of the module. </returns>
    std::string version()
    {

        return callRemote<std::string >("version");
    }


    /// <summary>
    /// Wait for the end of a long running method that was called using 'post'
    /// </summary>
    /// <param name="id"> The ID of the method that was returned when calling the method using 'post' </param>
    /// <param name="timeoutPeriod"> The timeout period in ms. To wait indefinately, use a timeoutPeriod of zero. </param>
    /// <returns> True if the timeout period terminated. False if the method returned. </returns>
    bool wait(const int& id, const int& timeoutPeriod)
    {

        return callRemote<bool >("wait" , id, timeoutPeriod);
    }


};

}
#endif // ALVISIONRECOGNITIONPROXY_H_
