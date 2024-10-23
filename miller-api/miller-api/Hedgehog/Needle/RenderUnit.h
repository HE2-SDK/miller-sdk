#pragma once

namespace hh::needle {
    class RenderUnit : public NeedleRefcountObject {
    public:
        struct Unk1 {
            bool unk1;
            bool isOddFrame; // double buffering
            uint32_t frameCounter;
            csl::math::Matrix44 viewMatrices[2];
            csl::math::Matrix44 projectionMatrices[2];
            uint32_t width1;
            uint32_t height1;
            uint32_t width2;
            uint32_t height2;

            Unk1();
        };

        uint64_t unk1;
        uint64_t unk2;
        SupportFXAll* supportFX;
        intrusive_ptr<CNameIDObject> nameId;
        intrusive_ptr<CNameIDObject> sceneNameId;
        intrusive_ptr<WorldRenderingPipeline> pipeline;
        PipelineInfo* pipelineInfo;
        SupportFX::FxViewport renderUnitViewport;
        intrusive_ptr<SceneParamContainer> sceneParamContainer;
        uint8_t priority;
        bool paramsInitialized;
        bool createSceneParamListeners;
        Unk1 unk14;
        uint32_t cameraId;
        WorldRenderingPipelineExecContext* renderingPipelineExecContext;
        bool renders;
        uint32_t unk18;
        uint32_t flags;

        struct RenderInfo {
            struct JobJointPair {
                rsdx::SJobJoint* startJoint;
                rsdx::SJobJoint* endJoint;
            };

            SupportFX::FxRenderParam renderParam;
            RenderTarget* renderTarget;
            JobJointPair jobJoints;
        };

        RenderUnit(const char* name, SupportFXAll* supportFX, uint8_t priority);
        RenderUnit(const char* name, SupportFXAll* supportFX, uint8_t priority, uint32_t flags);
        ~RenderUnit() {
            if (renderingPipelineExecContext) delete renderingPipelineExecContext;
            if (pipelineInfo) delete pipelineInfo;
        }

        void LoadGlobalParams();
        void SetPipeline(RenderingPipeline* pipeline);
        void SetSceneName(const char* name);
        bool HasHigherPriority(const RenderUnit* other) const;
        SceneContextManager* GetSceneContextManager();

        virtual void PushSceneParamContainer(SupportFX* supportFX);
        virtual void PopSceneParamContainer(SupportFX* supportFX);
        virtual bool IsEnabled(const RenderInfo& renderInfo) { return true; }
        virtual void SetRenderDimensions(const RenderInfo& renderInfo) {}
        virtual void UnkFunc5() {}
        virtual void LoadRenderParams(const RenderInfo& renderInfo);
        virtual void Render();
    };
}
