# Cat Launcher

A robot that throws a ball across the room for my cat. Built in a single day from parts I already
had — the DC and stepper motors both came out of a dead printer. A stepper drops a ball onto the
launch path, then a DC motor spins a 3D printed hammer up to speed and flings it.

- **Write-up and photos:** https://www.clay-p-mcpherson.com/projects/robotic-cat-toy-launcher/
- **Build video:** https://www.youtube.com/watch?v=yt0IbgSse9E

## What's in here

| | |
|---|---|
| `CAD/` | SolidWorks parts and the `Assy` assembly, with STLs for everything printed |
| `Main/` | The Arduino sketch |

Electronics are a Teensy LC and two L293D drivers on a hand soldered prototyping board, one chip
for the DC motor and one for the stepper. Pin assignments are commented at the top of the sketch
against the L293D pin numbers.

## How it fires

The loop waits five seconds, steps the stepper a quarter turn to release a ball, nudges the DC
motor backwards to set the hammer against its stop, then ramps it to full PWM to launch. After a
second at speed it ramps back down and repeats.

There's no trigger or sensor — it just fires on that timer forever until you unplug it. The step
angle is set by `stpangle`, and the launch power is the ramp rate and the `delay(1000)` in the
middle of the loop.
