
template <typename T>
struct Display
{
    void operator()(const T &data)
    {
        std::cout << data << " ";
    }
};