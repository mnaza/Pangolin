//
// Copyright (c) Andrey Mnatsakanov
//

#include "colour.hpp"
#include <pangolin/gl/colour.h>

namespace py_pangolin {

  void bind_colour(pybind11::module& m){
    pybind11::class_<pangolin::Colour> (m, "Colour")
      .def(pybind11::init<>())
      .def(pybind11::init<float, float, float, float>(), pybind11::arg("red"), pybind11::arg("green"), pybind11::arg("blue"), pybind11::arg("alpha")=1.0f)
      //      .def(pybind11::init<float[4]>())
      .def("Get", &pangolin::Colour::Get)
      .def("White", &pangolin::Colour::White)
      .def("Black", &pangolin::Colour::Black)
      .def("Red", &pangolin::Colour::Red)
      .def("Green", &pangolin::Colour::Green)
      .def("Blue", &pangolin::Colour::Blue)
      .def("WithAlpha", &pangolin::Colour::WithAlpha)
      .def("Hsv", &pangolin::Colour::Hsv);//
  }

}  // py_pangolin
