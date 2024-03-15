export module System;

import <vector>;
import <concepts>;
import <cstdint>;

export
{
    namespace ECS
    {

    template <uint32_t T>
    class System
    {
    public:
        ~System() = default;
    protected:
        System();
    private:
        std::array<uint32_t, T> m_arrEntities;
    };

    }
}
