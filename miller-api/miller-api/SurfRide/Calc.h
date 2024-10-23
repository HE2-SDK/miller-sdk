#pragma once

namespace SurfRide {
    template<typename T>
    bool CalcTrackConstant(float time, const KeyLinear<T>* key, unsigned int unk1, T* value);
    template<typename T>
    bool CalcTrackLinear(float time, const KeyLinear<T>* key, unsigned int unk1, T* value);
    template<typename T>
    bool CalcTrackHermite(float time, const KeyHermite<T>* key, unsigned int unk1, T* value);
    template<typename T>
    bool CalcTrackIndividual(float time, const KeyIndividual<T>* key, unsigned int unk1, T* value);
    template<typename T>
    void SearchKey(const T* key, unsigned int keyCount, float time, int* lowerFrame, int* upperFrame);

    bool CalcTrackConstant(float time, const KeyLinear<float>* key, unsigned int unk1, float* value);
    bool CalcTrackConstant(float time, const KeyLinear<double>* key, unsigned int unk1, double* value);
    bool CalcTrackConstant(float time, const KeyLinear<int>* key, unsigned int unk1, int* value);
    bool CalcTrackConstant(float time, const KeyLinear<bool>* key, unsigned int unk1, bool* value);
    bool CalcTrackConstant(float time, const KeyLinear<Color>* key, unsigned int unk1, Color* value);
    bool CalcTrackLinear(float time, const KeyLinear<float>* key, unsigned int unk1, float* value);
    bool CalcTrackLinear(float time, const KeyLinear<double>* key, unsigned int unk1, double* value);
    bool CalcTrackLinear(float time, const KeyLinear<int>* key, unsigned int unk1, int* value);
    bool CalcTrackLinear(float time, const KeyLinear<bool>* key, unsigned int unk1, bool* value);
    bool CalcTrackLinear(float time, const KeyLinear<Color>* key, unsigned int unk1, Color* value);
    bool CalcTrackHermite(float time, const KeyLinear<float>* key, unsigned int unk1, float* value);
    bool CalcTrackHermite(float time, const KeyLinear<double>* key, unsigned int unk1, double* value);
    bool CalcTrackHermite(float time, const KeyLinear<int>* key, unsigned int unk1, int* value);
    bool CalcTrackHermite(float time, const KeyLinear<bool>* key, unsigned int unk1, bool* value);
    bool CalcTrackHermite(float time, const KeyLinear<Color>* key, unsigned int unk1, Color* value);
    bool CalcTrackIndividual(float time, const KeyLinear<float>* key, unsigned int unk1, float* value);
    bool CalcTrackIndividual(float time, const KeyLinear<double>* key, unsigned int unk1, double* value);
    bool CalcTrackIndividual(float time, const KeyLinear<int>* key, unsigned int unk1, int* value);
    bool CalcTrackIndividual(float time, const KeyLinear<bool>* key, unsigned int unk1, bool* value);
    bool CalcTrackIndividual(float time, const KeyLinear<Color>* key, unsigned int unk1, Color* value);
    
    bool CalcTrackConstant(float time, const SRS_TRACK* track, void* value);
    bool CalcTrackLinear(float time, const SRS_TRACK* track, void* value);
    bool CalcTrackHermite(float time, const SRS_TRACK* track, void* value);
    bool CalcTrackIndividual(float time, const SRS_TRACK* track, void* value);

    void SearchKey(const KeyLinear<float>* key, unsigned int keyCount, float time, int* lowerFrame, int* upperFrame);
    void SearchKey(const KeyLinear<double>* key, unsigned int keyCount, float time, int* lowerFrame, int* upperFrame);
    void SearchKey(const KeyLinear<int>* key, unsigned int keyCount, float time, int* lowerFrame, int* upperFrame);
    void SearchKey(const KeyLinear<bool>* key, unsigned int keyCount, float time, int* lowerFrame, int* upperFrame);
    void SearchKey(const KeyLinear<Color>* key, unsigned int keyCount, float time, int* lowerFrame, int* upperFrame);
    void SearchKey(const KeyHermite<float>* key, unsigned int keyCount, float time, int* lowerFrame, int* upperFrame);
    void SearchKey(const KeyHermite<double>* key, unsigned int keyCount, float time, int* lowerFrame, int* upperFrame);
    void SearchKey(const KeyHermite<int>* key, unsigned int keyCount, float time, int* lowerFrame, int* upperFrame);
    void SearchKey(const KeyHermite<bool>* key, unsigned int keyCount, float time, int* lowerFrame, int* upperFrame);
    void SearchKey(const KeyHermite<Color>* key, unsigned int keyCount, float time, int* lowerFrame, int* upperFrame);
    void SearchKey(const KeyIndividual<float>* key, unsigned int keyCount, float time, int* lowerFrame, int* upperFrame);
    void SearchKey(const KeyIndividual<double>* key, unsigned int keyCount, float time, int* lowerFrame, int* upperFrame);
    void SearchKey(const KeyIndividual<int>* key, unsigned int keyCount, float time, int* lowerFrame, int* upperFrame);
    void SearchKey(const KeyIndividual<bool>* key, unsigned int keyCount, float time, int* lowerFrame, int* upperFrame);
    void SearchKey(const KeyIndividual<Color>* key, unsigned int keyCount, float time, int* lowerFrame, int* upperFrame);
}
