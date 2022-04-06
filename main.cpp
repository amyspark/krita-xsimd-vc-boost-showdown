// SPDX-FileCopyrightText: 2022 L. E. Segovia <amy@amyspark.me>
// SPDX-License-Ref: BSD-3-Clause

#include <iomanip>
#include <xsimd_extra_math.h>
#include <vc_extra_math.h>
#include <boost/math/special_functions/erf.hpp>

#define MAX 10000

#include <locale>

template <class charT, charT sep>
class punct_facet: public std::numpunct<charT> {
protected:
    charT do_decimal_point() const { return sep; }
};

int main()
{
    std::cout.imbue(std::locale(std::cout.getloc(), new punct_facet<char, ','>));
    std::cout << "v;xsimd;xsimd_extra_math;vc_extra_math;boost" << std::endl;

    for (size_t i = 0; i < MAX; i++)
    {
        const float v = (float)i / MAX;

        const auto s = xsimd::batch<float>(v);
        const auto t = xsimd::batch<float>(v);
        const auto u = Vc::float_v(v);

        const auto a = xsimd::erf(s);
        const auto b = XsimdExtraMath::erf(t);
        const auto c = VcExtraMath::erf(u);
        const auto d = boost::math::erf(v);

        std::cout << std::setprecision(6) <<  v << ";" << a.get(0) << ";" << b.get(0) << ";" << c[0] << ";" << d << std::endl;
    }

    return 0;
}
