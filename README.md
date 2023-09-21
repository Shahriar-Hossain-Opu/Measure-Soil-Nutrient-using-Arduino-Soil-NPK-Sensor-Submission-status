# Measure-Soil-Nutrient-using-Arduino-Soil-NPK-Sensor-Submission-status

 
Bangabandhu Sheikh Mujibur Rahman Digital University, Bangladesh
Faculty of Cyber Physical System
Dept. of Internet of Things and Robotics Engineering (IRE)
Course Title: Real life in IoT Lab         
Course Code: IOT 4316
Lab Report-08
 
Submitted to-
Teacher name: Nurjahan Nipa
Designation: Lecturer
Department: IRE

   



                        Submitted by-
Md. Shahriar Hossain Apu (1901036)
Date of Submission: 21-09-2023
Task: Measure Soil Nutrient using Arduino & Soil NPK Sensor Submission status
Introduction:
Soil NPK Sensor
The soil NPK sensor is suitable for detecting the content of nitrogen, phosphorus, and potassium in the soil. It helps in determining the fertility of the soil thereby facilitating the systematic assessment of the soil condition. The sensor can be buried in the soil for a long time. It has a High-quality probe, rust resistance, electrolytic resistance, salt & alkali corrosion resistance, to ensure the long-term operation of the probe part. Therefore, it is suitable for all kinds of soil. It is suitable for the detection of alkaline soil, acid soil, substrate soil, seedling bed soil & coconut bran soil.
The sensor doesn’t require any chemical reagent. Since it has High measurement accuracy, fast response speed, and good interchangeability, it can be used with any microcontroller. You cannot use the sensor directly with the microcontroller as it has a Modbus Communication port. Hence you need any Modbus Module like RS485/MAX485 and connect the sensor to the microcontroller.
The sensor operates on 9-24V & power consumption is very low. While talking about the accuracy of the sensor, it is up to within 2%. The nitrogen, phosphorous & potassium measuring resolution is up to 1mg/kg (mg/l).
Specifications
1.	Power: 9V-24V
2.	Measuring Range: 0-1999 mg/kg (mg/l)
3.	Operating Temperature: 5-45 °C
4.	Resolution: 1mg/kg
5.	Precision: ±2% F.S.
6.	Output Signal: RS485
7.	Baud Rate: 2400/4800/9600
8.	Protection Class: IP68
MAX13487 TTL to RS-485 Interface Module
The MAX13487 TTL to RS-485 Interface Module allows us to use the RS-485 differential signaling for robust long-distance serial communications up to 1200 meters or in electrically noisy environments and is commonly used in industrial environments. It supports upto 2.5MBit/Sec data rates, but as distance goes up, the maximum data rate that can be supported comes down. 
 

The data starts out as a typical TTL level serial as far as the microcontroller is concerned while the RS-485 module takes care of converting the electrical signals between TTL and the differential signaling used by RS-485. A significant benefit of RS-485 is that it supports multiple devices (up to 32) on the same cable, commonly referred to as ‘multi-drop’.

Specifications
1. Use MAX485 Interface chip
2. Uses differential signaling for noise immunity
3. Distances up to 1200 meters
4. Speeds up to 2.5Mbit/Sec
5. Multi-drop supports up to 32 devices on same bus
6. Red power LED
7. 5V operation






Circuit Diagram:
 
Fig: Circuit diagram 
1. Nitrogen: {0x01,0x03, 0x00, 0x1e, 0x00, 0x01, 0xe4, 0x0c}
The inquiry frame for getting Soil Nitrogen Value is:
 
2. Phosphorous:{0x01,0x03, 0x00, 0x1f, 0x00, 0x01, 0xb5, 0xcc}
The inquiry frame for getting Soil Phosphorous Value is:
 


3. Potassium:{0x01,0x03, 0x00, 0x20, 0x00, 0x01, 0x85, 0xc0}
The inquiry frame for getting Soil Potassium Value is:
 


Operational view: 
 
Fig: Operational view 

Conclusion:
Once the sensor becomes stable, one can dip the sensor in the soil to get the NPK Reading. The volume of Nitrogen, Phosphorous & Potassium which are the Ammonium content in the soil will be displayed as mg/Kg.

–End of the Report–
