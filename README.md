
# Moving Car Project System

This project implements an autonomous car control system using the Atmega32 microcontroller. The system controls the car's movement, direction, and LED indicators to create a rectangular path.

## System Testing Video
Watch the system testing video : [System Testing Video](https://drive.google.com/file/d/18ydaOmGCf4X7Lg1qFwADl9SzpGE8zMik/view?usp=sharing)

## Description
1. The car starts initially from 0 speed.
2. Pressing PB1 initiates forward movement after a 1-second delay.
3. The car moves forward for 3 seconds at 50% of its maximum speed to create the longest side of the rectangle.
4. After completing the first longest side, the car stops for 0.5 seconds, rotates 90 degrees to the right, and stops for another 0.5 seconds.
5. The car moves forward at 30% speed for 2 seconds to create the short side of the rectangle.
6. After completing the shortest side, the car stops for 0.5 seconds, rotates 90 degrees to the right, and stops for another 0.5 seconds.
7. Steps 3 to 6 are repeated infinitely until the stop button (PB2) is pressed.
8. PB2 acts as an emergency brake with the highest priority.
9. LED Indicators:
   - LED1: On indicates forward movement on the longest side.
   - LED2: On indicates forward movement on the shortest side.
   - LED3: On indicates a stop.
   - LED4: On indicates a rotation.

## Components Used

- Atmega32 Microcontroller
- Motors and H-Bridge for Car Movement
- Push Buttons (PB1 and PB2) for Control
- LED Indicators (LED1, LED2, LED3, LED4) for Status Display

## Implementation

1. The system initializes with the car at 0 speed.
2. Pressing PB1 starts the car's forward movement after a 1-second delay.
3. The car moves forward for 3 seconds to create the longest side, with LED1 indicating the movement.
4. After completing the side, the car stops, rotates, and stops again, with LED4 indicating the rotation.
5. The car moves forward at 30% speed for 2 seconds to create the short side, with LED2 indicating the movement.
6. Steps 3 to 5 repeat indefinitely until PB2 is pressed, causing an emergency stop and lighting up LED3.

## Usage

1. Clone the repository.
2. Connect the components as described in the circuit diagram.
3. Upload the code to the Atmega32 microcontroller.
4. Power up the system and observe the car's autonomous movement.

## Author

[Ararfa Arafa Abd Elmawgod]

For questions or support, contact [Mail connection](arafa.prog.98@gmail.com).


Happy coding!
