#ifndef _MODES_STREETFIGHTER6MODE_HPP
#define _MODES_STREETFIGHTER6MODE_HPP

#include "core/ControllerMode.hpp"
#include "core/socd.hpp"
#include "core/state.hpp"

class StreetFighter6Mode : public ControllerMode {
  public:
    StreetFighter6Mode(socd::SocdType socd_type);

  private:
    void UpdateDigitalOutputs(InputState &inputs, OutputState &outputs);
    void UpdateAnalogOutputs(InputState &inputs, OutputState &outputs);
};

#endif