#pragma once

namespace SurfRide {
    class UserData {
        SRS_USERDATA* userData;
    public:
        UserData(SRS_USERDATA* userData);
        int GetIndex(const char* name);

        bool GetBoolValue(int index);
        int GetIntValue(int index);
        unsigned int GetUIntValue(int index);
        float GetFloatValue(int index);
        const char* GetStringValue(int index);
    };
}
