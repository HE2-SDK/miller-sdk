#pragma once

namespace app::game {
    class GameCondition {
    public:
        class Listener {
        public:
            virtual ~Listener() = default;
        };
    };
}
