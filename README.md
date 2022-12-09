# Boiler-Rebooter
So, my landlord is in no hurry to fix his old boiler, which requires a reboot 4-6 times a day.
I was tired of getting up at night from the cold, and I wrote this sketch.
Its capabilities:
* Reboots the boiler when the red LED lights up (error, restart required)
* Takes 3 attempts to reboot, after which it starts beeping, calling the user
* Lights up its own red LED when the boiler needs to be restarted
* Using the button, switches the screens with information:
  * 1 screen displays own uptime and 2 reboot numbers:
    * Sft (Soft) - how many times the controller restarted the boiler on its own,
    * Hrd (Hard) - how many times it took a manual reset by disconnecting the boiler from power
  * 2nd screen displays the current brightness value obtained by photoresistor
* Display messages when attempting to reset the boiler and when a manual reset of the boiler is required