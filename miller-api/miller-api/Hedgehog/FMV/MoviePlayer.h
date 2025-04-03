#pragma once

namespace hh::fmv{
    class MoviePlayer : public fnd::ReferencedObject {
    public:
        class MyRenderable : public gfnd::Renderable {
        public:
            MoviePlayer* moviePlayer;

            virtual void* ThreadStart();
            virtual void MyUnkFunc1() {}
            virtual bool MyUnkFunc2() { return true; }
        };

        struct ThreadInfo{
        public:
            int threadHandle;
            void* threadStartFunction;
            MoviePlayer* moviePlayer;
            bool unhandled;
            csl::fnd::IAllocator* allocator;

            ThreadInfo(csl::fnd::IAllocator* allocator);
        };

        struct UnkStr1{
        public:
            float unk0;
            int unk1;
            int unk2;
        };

        MovieRenderObject* movieRenderObj;
        MyRenderable* renderable;
        const char* usmFilePath;
        int64_t qword30;
        ThreadInfo threadInfo;
        UnkStr1 unkStr1[3];
        float secondsRunning;
        int framesRunning;
        int renderPass;
        short renderPriority;
        short flags; //0x128 is paused
        int64_t setupDataUnk3;
        float setupDataUnk4;

        virtual void* UnkFunc0(float deltaTime) {}
        virtual void UnkFunc1() {}
        virtual void UnkFunc1Flag() {}
        virtual void UnkFunc3(char a2) {}
        virtual int SetPause(bool paused) {}
        virtual void UnkFunc5(int a2); //denuvo infested
        virtual void* UnkFunc6(int a2);
        virtual void SetLooping(bool looping);
        virtual void Setup(void* setupData) {}
        virtual int SetFilename(const char* filename);
        virtual void* UnkFunc10(float deltaTime) {}

        MoviePlayer(csl::fnd::IAllocator* allocator);
    };

    class MoviePlayerCri : public MoviePlayer {
    public:
        struct FrameInfo{
        public:
            struct ImageBufferInfo{
            public:
                void* imagePtr;
                int bufferSize;
                int linePitch;
                int lineSize;
                int numLines;
            };

            int framesNum;
            int framesNumPerFile;
            int width;
            int height;
            int displayWidth;
            int displayHeight;
            int framerate;
            int framerateN;
            int framerateD;
            int totalFrames;
            uint64_t time;
            uint64_t timePerFile;
            uint64_t tunit;
            int numConcatenatedMovie;
            int numImages;
            ImageBufferInfo imageInfo[4];
            bool flag;
            int alphaType;
            int refResult;
            void* details;
            int colorConversionType;
            int cntSkippedFrames;
        };

        struct UnkStr2{
        public:
            void* unk0;
            char unk1;
            void* unk2;
            char unk3;
        };

        struct TextureInfo{
        public:
            int width;
            int height;
            char* buffer0;
            char* buffer1;
            size_t linePitch;
            size_t unk4;
        };

        void* criManaPlayer; // criware sdk
        int criManaPlayerStatus;
        FrameInfo::ImageBufferInfo* imageBuffers;
        csl::ut::MoveArray<TextureInfo> textureInfos;
        FrameInfo* frameInfo;
        int* updateFrequency;
        FrameInfo* tempFrameInfo0;
        FrameInfo* tempFrameInfo1;
        bool loadingFrame;
        csl::fnd::IAllocator* unkAllocator1;
        hh::ut::TinyFsm<MoviePlayerCri> fsm;
        char unk10;
        char unk11;
        char unk12;
        char unk13;
        int unk14;
        void* unk16; //somekind of critical section
        int unk17[6];
        char unk18;
        char unk19;
        char unk20;
        char unk21;
        int unk22;
        char unk23;
        bool hasAudio;
        bool isCriManaLoaded; // unsure
        char unk26;
        int unk27;
        int unk28;

        virtual void* UnkFunc0(float deltaTime) override;
        virtual void UnkFunc1() override;
        virtual void UnkFunc1Flag() override;
        virtual void UnkFunc3(char a2) override;
        virtual int SetPause(bool paused) override;
        virtual void UnkFunc5(int a2) override;
        virtual void* UnkFunc6(int a2) override;
        virtual void SetLooping(bool looping) override;
        virtual void Setup(void* setupData) override;
        virtual int SetFilename(const char* filename) override;
        virtual void* UnkFunc10(float deltaTime) override;
        
        MoviePlayerCri(csl::fnd::IAllocator* allocator);
    };
}
