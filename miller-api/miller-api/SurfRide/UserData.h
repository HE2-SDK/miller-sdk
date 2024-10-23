#pragma once

namespace SurfRide {
    struct SRS_DATA {
        enum class Type {
            BOOL,
            INT,
            UINT,
            FLOAT,
            UNK,
            STRING,
        };

        const char* name{};
        Type type{};
        void* value{};
    };

    struct SRS_USERDATA {
        uint32_t count{};
        SRS_DATA* items{};
    };

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
