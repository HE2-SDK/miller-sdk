#pragma once

namespace Cyan::Elements{
    class Particle : public Element {
    public:
        virtual void Process(float deltaTime, Cyan::Element* unk) override;
        virtual void UpdateChildren(float deltaTime) override;
        virtual void Update(float deltaTime, Cyan::Element* unk) override;
        virtual void PrepareRender(Graphics::Renderer* renderer, Graphics::EffectObject* effectObject) override;
        virtual int GetHistoricalStripeBufferSize() const override;
        virtual void InitParameter() override;

        void InitDirection(System::Random* random);
        void InitScale(System::Random* random);
        void CalcField(float time, csl::math::Vector3* unk0, csl::math::Vector3* unk1);
        void CalcFieldVortex(FieldArgs* args, csl::math::Vector3& out);
        void CalcFieldSpin(FieldArgs* args, csl::math::Vector3& out);
        void CalcFieldSpin2(FieldArgs* args, csl::math::Vector3& out);
        void CalcFieldRandom(FieldArgs* args, const csl::math::Vector3& spreadVector, const csl::math::Vector3& spreadVectorNorm, const csl::math::Matrix34& emissionMatrix, bool unk0);
        void Rotation2VecY(const csl::math::Vector3& rotation, csl::math::Vector3* out);
        void CalcDirectional(Element* element, unsigned int unkParam1, unsigned int unkParam2);

        Particle(Emitter* emitter, const Resource::ElementParam* element, const EmitParam* emitParam);
    };  
}
