class Multiplier
{
private:
    int num{};

public:
    Multiplier(int n) : num{n} {}

    int operator()(int n) const
    {
        return this->num * n;
    }
};
