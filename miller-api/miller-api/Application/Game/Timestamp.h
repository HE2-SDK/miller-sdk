#pragma once

namespace app::game {
    struct Timestamp {
        int days{};
        int hours{};
        int minutes{};
        float seconds{};

        Timestamp();
        Timestamp(int days, int hours, int minutes, float seconds) : days{ days }, hours{ hours }, minutes{ minutes }, seconds{ seconds } {}
        void Add(const Timestamp& other);
        void Add(int days, int hours, int minutes, float seconds);
        bool HaveMinutesPassedSince(const Timestamp& timestamp, int minutes) const;
        bool operator==(const Timestamp& other) const;
        float GetTimeOfDayInSeconds() const;
        float GetTimeOfDayInHours() const;
        bool operator>=(const Timestamp& other) const;
        bool IsTimeOfDayStrictlyLater(const Timestamp& other) const;
        bool IsTimeOfDayBetween(const Timestamp& lowerBound, const Timestamp& upperBound) const;
        bool operator<(const Timestamp& other) const;
        bool operator<=(const Timestamp& other) const;
        void Normalize();
        void Set(const Timestamp& other);
        void Set(int days, int hours, int minutes, float seconds);
        void SetTimeOfDayInHours(float hours);
    };
}
