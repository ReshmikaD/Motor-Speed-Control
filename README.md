# CLOSED LOOP SPEED CONTROL OF DC MOTOR
This is a design of a closed loop speed control system for a 12V DC motor using Arduino. This setup makes the motor spin at a desired rpm and does not allow any load to affect it.

# TERMINOLOGY:
# Module 1: To calculate the rpm of a dc motor.
Revolutions per minute 
Tachometer

𝒅𝒖𝒓𝒂𝒕𝒊𝒐𝒏 = 𝒄𝒖𝒓𝒓𝒆𝒏𝒕 𝒕𝒊𝒎𝒆 − 𝒑𝒓𝒆𝒗𝒊𝒐𝒖𝒔 𝒕𝒊𝒎𝒆
𝒕 = 𝟔𝟎  × 𝟏𝟎𝟎𝟎𝒎𝒔 = 𝟏 𝒎𝒊𝒏𝒖𝒕𝒆
𝒄𝒖𝒓𝒓𝒆𝒏𝒕 𝒓𝒑𝒎 = 𝒅𝒖𝒓𝒂𝒕𝒊𝒐𝒏
where,
𝒄𝒖𝒓𝒓𝒆𝒏𝒕 𝒕𝒊𝒎𝒆 − 𝒑𝒓𝒆𝒗𝒊𝒐𝒖𝒔 𝒕𝒊𝒎𝒆 is time between simultaneous detection of the shaft by the infrared sensor.
𝒕 is the time in seconds as Arduino assigns time in milliseconds. Rpm is hence calculated by the above formula.

# Module 2: To make the dc motor run at a desired speed.
Desired rpm
Closed loop negative feedback control system
Pulse width modulation (PWM)
Proportional Controller
 
𝒆𝒓𝒓𝒐𝒓 = 𝒄𝒖𝒓𝒓𝒆𝒏𝒕 𝒓𝒑𝒎 − 𝒅𝒆𝒔𝒊𝒓𝒆𝒅 𝒓𝒑𝒎
𝒄𝒐𝒓𝒓𝒆𝒄𝒕𝒊𝒗𝒆 𝒑𝒘𝒎 = 𝒆𝒓𝒓𝒐𝒓 × 𝑲𝒑
𝒑𝒘𝒎 = 𝒄𝒐𝒓𝒓𝒆𝒄𝒕𝒊𝒗𝒆 𝒑𝒘𝒎 + 𝒑𝒘𝒎
where Kp is the proportionality gain.

Permissible error
𝒓𝒑𝒎(𝒎𝒂𝒙)
𝒑𝒘𝒎(𝒎𝒂𝒙)

# Module 3:
Load stabilization




The Report.pdf file contains all the observations and inference of the project.
