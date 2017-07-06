//
//  ofxHyperdeck.h
//  ofxHyperdeck
//
//  Created by Fred on 25/09/14.
//
//
#include "ofMain.h"
#include "ofxNetwork.h"


class ofxHyperdeck{
     
public:
     
     void setup( string ip);
     
     void play();
     
     bool getRemote();
     
     void setOverride(bool _overRide);
     void setRemote(bool _remote);
     void exit();
     void togglePreview(bool _preview);
     void playWithSpeed(int speed);
     void playWithLoop();
     void playSingleClip();
     void record();
     void recordWithName(string name);
     void stop();
     void goToClip(int clipId);
     void goToClipStart();
     void goToClipEnd();
     void goToTimecode(string timecode);
     void nudgeTimecodeForwards(string timecode);
     void nudgeTimecodeBack(string timecode);
     vector<string > getClips();
     void setVideoInputType(string inputType);
     void setAudioInputType(string inputType);
     void selectSlot(int slot);
     void setFileFormat(string format);
     bool checkConnection();
     bool _connected;
     void reconnect();
     void updateTransportInfo();
     string _ip;
     
     
     ofxTCPClient hyperdeck;
     
     vector <string> storeText;
    struct TransportInfo
    {
        string status;
        int speed;
        int slotId;
        int clipId;
        bool bSingleClip;
        string timecode;
        string displayTimecode;
        string videoFormat;
        bool bLoop;
        uint64_t updatedFrame = 0;
        float updatedTime = 0;
    } transportInfo;

};
