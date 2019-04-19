#ifndef DECODER_POLAR_FUNCTIONS_H
#define DECODER_POLAR_FUNCTIONS_H

#include <limits>
#include <utility> // pair
#include <mipp.h>
#include <functional>

#include "Tools/Math/utils.h"

#ifndef _MSC_VER
#ifndef __forceinline
#define __forceinline inline __attribute__((always_inline))
#endif
#endif

namespace aff3ct
{
namespace tools
{
// -------------------------------------------------------------------------- special function prototypes for templates

template <typename R>
using proto_i = R (*)(); // special proto: return init value for a specific domain

template <typename R>
using proto_f = R (*)(const R& lambda_a, const R& lambda_b);

template <typename R>
using proto_f_i = mipp::reg (*)(const mipp::reg& lambda_a, const mipp::reg& lambda_b);

template <typename B, typename R>
using proto_g = R (*)(const R& lambda_a, const R& lambda_b, const B& u);

template <typename B, typename R>
using proto_g_i = mipp::reg (*)(const mipp::reg& lambda_a, const mipp::reg& lambda_b, const mipp::reg& u);

template <typename R>
using proto_g0 = R (*)(const R& lambda_a, const R& lambda_b);

template <typename R>
using proto_g0_i = mipp::reg (*)(const mipp::reg& lambda_a, const mipp::reg& lambda_b);

template <typename B, typename R>
using proto_h = B (*)(const R& lambda_a);

template <typename B, typename R>
using proto_h_i = mipp::reg (*)(const mipp::reg& lambda_a);

template <typename R>
using proto_v = R (*)(const R& lambda_a, const R& lambda_b);

template <typename B>
using proto_xo = B (*)(const B& u_a, const B& u_b);

template <typename B>
using proto_xo_i = mipp::reg (*)(const mipp::reg& u_a, const mipp::reg& u_b);

template <typename B, typename R>
using proto_m = R (*)(const B& u_a, const R& lambda_a);

template <typename R>
using proto_s = R (*)(); // special proto: return saturate value for a specific domain

// ------------------------------------------------------------------------------------------- special function headers

template <typename R>
__forceinline R f_LR(const R& lambda_a, const R& lambda_b);

template <typename R>
__forceinline R f_LLR(const R& lambda_a, const R& lambda_b);

template <typename R>
__forceinline R f_LLR_tanh_safe(const R& lambda_a, const R& lambda_b);

template <typename R>
__forceinline mipp::reg f_LLR_i(const mipp::reg& r_lambda_a, const mipp::reg& r_lambda_b);

template <typename B, typename R>
__forceinline R g_LR(const R& lambda_a, const R& lambda_b, const B& u);

template <typename B, typename R>
__forceinline R g_LLR(const R& lambda_a, const R& lambda_b, const B& u);

template <typename B, typename R>
__forceinline mipp::reg g_LLR_i(const mipp::reg& r_lambda_a,
                                const mipp::reg& r_lambda_b,
                                const mipp::reg& r_u);

template <typename R>
__forceinline R g0_LR(const R& lambda_a, const R& lambda_b);

template <typename R>
__forceinline R g0_LLR(const R& lambda_a, const R& lambda_b);

template <typename R>
__forceinline mipp::reg g0_LLR_i(const mipp::reg& r_lambda_a, const mipp::reg& r_lambda_b);

template <typename B, typename R>
__forceinline B h_LR(const R& lambda_a);

template <typename B, typename R>
__forceinline B h_LLR(const R& lambda_a);

template <typename B, typename R>
__forceinline mipp::reg h_LLR_i(const mipp::reg& r_lambda_a);

template <typename R>
__forceinline R v_LR(const R& a, const R& b);

template <typename R>
__forceinline R v_LLR(const R& a, const R& b);

template <typename B>
__forceinline B xo_STD(const B& u_a, const B& u_b);

template <typename B>
__forceinline mipp::reg xo_STD_i(const mipp::reg& r_u_a, const mipp::reg& r_u_b);

template <typename B, typename R>
__forceinline R phi(const R& mu, const R& lambda, const B& u);

__forceinline int compute_depth(int index, int tree_depth);

template <typename B, typename R>
struct Polar_lambdas
{
	static std::map<std::vector<std::vector<bool>>,
	                std::vector<std::function<R(const std::vector<R> &LLRs, const std::vector<B> &bits)>>> functions;
};

template <typename R>
using proto_xor = R (*)(const R& ll, const R& lr);

template <typename R>
using proto_plus = R (*)(const R& ll, const R& lr);

template <typename R>
__forceinline R square_plus(const R& ll, const R& lr);

template <typename R>
__forceinline R plus(const R& ll, const R& lr);

template <typename B, typename R, proto_xor <R> X = square_plus<R>,
                                  proto_plus<R> P = plus<R>>
struct Polar_lambdas_bis
{
public:
	static std::map<std::vector<std::vector<bool>>,
	                std::vector<std::function<R(const std::vector<R> &LLRs, const std::vector<B> &bits)>>> functions;
	static R h(const R &L, const std::vector<B> &u, const std::vector<bool> &m);
};

}
}

#include "decoder_polar_functions.hxx"

#endif /* DECODER_POLAR_FUNCTIONS_H */
