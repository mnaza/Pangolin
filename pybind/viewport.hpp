//
// Copyright (c) Andrey Mnatsakanov
//

#ifndef PY_PANGOLIN_VAR_HPP
#define PY_PANGOLIN_VAR_HPP

#include <pybind11/pybind11.h>


namespace py_pangolin{

  void bind_viewport(pybind11::module &m);
  
}  // py_pangolin

#endif //PY_PANGOLIN_VAR_HPP
