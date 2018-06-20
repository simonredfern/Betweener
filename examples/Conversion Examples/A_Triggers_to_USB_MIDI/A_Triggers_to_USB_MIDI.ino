/*This code reads the Betweener Trigger inputs and sends
  corresponding USB MIDI Note On/Off messages.

  Note, this code will only compile if your Arduino IDE
  is set so that "Tools->USB Type->[  ]" is set
  to one of the options that includes "MIDI".

  Example Code by Joseph Kramer - 20 June, 2018
*/


//include the Betweener library
#include <Betweener.h>

//make a Betweener object. anytime you want to talk to the Betweener
//using the library, you will start by using the name "b."
Betweener b;

const int channel = 1;

void setup() {
  //the Betweener begin function is necessary before it will do anything
  b.begin();

}

void loop() {

  //this function reads just the triggers. We could also do readAllInputs().
  b.readTriggers();

  // Check each button for gate HIGH "falling" edge/Note ON
  if (b.trig1.fallingEdge()) {
    usbMIDI.sendNoteOn(60, 127, channel);  // 60 = C4
  }
  if (b.trig2.fallingEdge()) {
    usbMIDI.sendNoteOn(62, 127, channel);  // 62 = D4
  }
  if (b.trig3.fallingEdge()) {
    usbMIDI.sendNoteOn(64, 127, channel);  // 64 = E4
  }
  if (b.trig4.fallingEdge()) {
    usbMIDI.sendNoteOn(65, 127, channel);  // 65 = F4
  }

  // Check each button for gate LOW "rising" edge/Note OFF
  if (b.trig1.risingEdge()) {
    usbMIDI.sendNoteOff(60, 0, channel);  // 60 = C4
  }
  if (b.trig2.risingEdge()) {
    usbMIDI.sendNoteOff(62, 0, channel);  // 62 = D4
  }
  if (b.trig3.risingEdge()) {
    usbMIDI.sendNoteOff(64, 0, channel);  // 64 = E4
  }
  if (b.trig4.risingEdge()) {
    usbMIDI.sendNoteOff(65, 0, channel);  // 65 = F4
  }

   // If a MIDI Controller is not designed to respond to incoming MIDI, it
  // should discard incoming MIDI messages. Othwerwise, the controller will
  // work for a moment and then suddenly stop.
  // http://forum.pjrc.com/threads/24179-Teensy-3-Ableton-Analog-CC-causes-midi-crash
  while (usbMIDI.read()) {
    // ignore incoming messages
  }
}
