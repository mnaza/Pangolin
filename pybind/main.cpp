//
// Copyright (c) Andrey Mnatsakanov
//

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>


#include "var.hpp"
#include "viewport.hpp"
#include "view.hpp"
#include "window.hpp"
#include "display.hpp"
#include "params.hpp"
#include "opengl_render_state.hpp"
#include "attach.hpp"
#include "handler.hpp"
#include "gl.hpp"
#include "gl_draw.hpp"
#include "widget.hpp"
#include "pixel_format.hpp"
#include "image.hpp"
#include "datalog.hpp"
#include "plotter.hpp"
#include "colour.hpp"


PYBIND11_MODULE(pypangolin, m) {
  m.doc() = "pybind11 example plugin"; // optional module docstring

  py_pangolin::bind_var(m);
  py_pangolin::bind_viewport(m);
  py_pangolin::bind_view(m);
  py_pangolin::bind_window(m);
  py_pangolin::bind_display(m);
  py_pangolin::bind_params(m);
  py_pangolin::bind_opengl_render_state(m);
  py_pangolin::bind_attach(m);
  py_pangolin::bind_colour(m);
  py_pangolin::bind_datalog(m); 
  py_pangolin::bind_plotter(m); 
  py_pangolin::bind_handler(m);
  py_pangolin::bind_gl(m);
  py_pangolin::bind_gl_draw(m);
  py_pangolin::bind_widget(m);
  py_pangolin::bind_pixel_format(m);
  py_pangolin::bind_image<unsigned char>(m, "Image"); 
}
