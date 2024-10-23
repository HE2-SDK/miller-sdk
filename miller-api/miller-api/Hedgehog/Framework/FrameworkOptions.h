#pragma once

namespace hh::fw {
    struct FrameworkOptions {
        struct GraphicsOptions {
            uint64_t qword0;
            uint32_t unkResX;
            uint32_t unkResY;
            uint32_t resX;
            uint32_t resY;
            uint32_t renderResX;
            uint32_t renderResY;
            uint64_t qword20;
            uint64_t qword28;
            uint64_t qword30;
            uint8_t byte38;
        };

        const char* title;
        uint8_t byte8;
        uint32_t dwordC;
        uint32_t dword10;
        uint16_t word14;
        csl::ut::VariableString launcherApp;
        csl::ut::VariableString hostIp;
        const char* imageDirectory;
        const char* qword40;
        uint8_t byte48;
        const char* qword50;
        const char* iniFilePath;
        const char* debugFontPackfilePath;
        const char* shadersPackfileName;
        uint64_t qword70;
        uint64_t qword78;
        uint64_t qword80;
        uint32_t dword88;
        uint64_t qword90;
        uint64_t bts;
        bool disableDialog;
        bool disableBts;
        bool enableSDK;
        uint32_t inputPort;
        bool enableStdOut;
        csl::ut::VariableString userInfo;
        csl::ut::VariableString windowLayout;
        csl::ut::VariableString screenSetting;
        GraphicsOptions graphicsOptions;
        uint32_t dword120;
        uint32_t dword124;
        uint64_t optionsParser;

        FrameworkOptions();
        void Parse(int argc, const char* const* argv);
    };
}
