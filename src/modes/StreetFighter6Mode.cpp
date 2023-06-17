#include "modes/StreetFighter6Mode.hpp"

StreetFighter6Mode::StreetFighter6Mode(socd::SocdType socd_type) : ControllerMode(socd_type) {
    _socd_pair_count = 2;
    _socd_pairs = new socd::SocdPair[_socd_pair_count]{
        socd::SocdPair{&InputState::left, &InputState::right},
        socd::SocdPair{&InputState::down, &InputState::mod_x},
    };
}

void StreetFighter6Mode::UpdateDigitalOutputs(InputState &inputs, OutputState &outputs) {
    // Directions
    outputs.dpadLeft = inputs.left;
    outputs.dpadRight = inputs.right;
    outputs.dpadDown = inputs.down;
    outputs.dpadUp = inputs.mod_x;

    // Menu keys
    outputs.start = inputs.start;
    outputs.rightStickClick = inputs.a; // Steam uses this instead of select by default for select-- unsure why.

    // Right hand bottom row
    outputs.a = inputs.b;
    outputs.b = inputs.x;
    outputs.triggerRDigital = inputs.z;
    outputs.triggerLDigital = inputs.up;

    // Right hand top row
    outputs.x = inputs.r;
    outputs.y = inputs.y;
    outputs.buttonR = inputs.lightshield;
    outputs.buttonL = inputs.midshield;
}

void StreetFighter6Mode::UpdateAnalogOutputs(InputState &inputs, OutputState &outputs) {
    outputs.leftStickX = 128;
    outputs.leftStickY = 128;
    outputs.rightStickX = 128;
    outputs.rightStickY = 128;
    outputs.triggerLAnalog = outputs.triggerLDigital ? 255 : 0;
    outputs.triggerRAnalog = outputs.triggerRDigital ? 255 : 0;
}
