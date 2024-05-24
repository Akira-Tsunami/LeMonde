/*
 * SoftGLRender
 * @author 	: keith@robot9.me
 *
 */

#pragma once

#include "RenderStates.h"

namespace Monde {

class PipelineStates {
 public:
  explicit PipelineStates(const RenderStates &states)
      : renderStates(states) {}

  virtual ~PipelineStates() = default;

 public:
  RenderStates renderStates;
};

}
