#ifndef SOLUTION_H_
#define SOLUTION_H_

#include <cstdint>

#include "Image.h"
#include "FunctionTracer.h"

namespace Solution {
    void compute([[maybe_unused]]std::vector<PackedImage> &images);

    void compute([[maybe_unused]]std::vector<StrideImage> &images);
};

#endif /* SOLUTION_H_ */
