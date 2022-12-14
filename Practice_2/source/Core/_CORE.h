#include <memory>

namespace CLI
{
	template <typename T>
	using SCOPE = std::unique_ptr<T>;
	template <typename T, typename... Args>
	constexpr SCOPE<T> NEWSCOPE(Args &&...args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template <typename T>
	using REF = std::shared_ptr<T>;
	template <typename T, typename... Args>
	constexpr REF<T> NEWREF(Args &&...args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}

#define CLI_ASSERT(x, ...)                                   \
	{                                                        \
		if (!(x))                                            \
		{                                                    \
			CLI_ERROR("ASSERTION FAILED: {0}", __VA_ARGS__); \
			__debugbreak();                                  \
		}                                                    \
	}