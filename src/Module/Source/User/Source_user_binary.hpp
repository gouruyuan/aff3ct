#ifndef SOURCE_USER_BINARY_HPP_
#define SOURCE_USER_BINARY_HPP_

#include <string>
#include <vector>

#include "Module/Source/Source.hpp"

namespace aff3ct
{
namespace module
{
template <typename B>
class Source_user_binary : public Source<B>
{
private:
	std::vector<std::vector<B>> source;
	int src_counter;

public:
	Source_user_binary(const int K, std::string filename, const int n_frames = 1);
	virtual ~Source_user_binary() = default;

protected:
	void _generate(B *U_K, const int frame_id);
};
}
}

#endif /* SOURCE_USER_BINARY_HPP_ */
