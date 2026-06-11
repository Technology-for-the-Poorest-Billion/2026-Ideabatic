# Technology for the Poorest Billion: Ideabatic – Uniform cooling team
## Kavita Sivaraman
**Working with Kerry Dai & Karen Miyazaki**

## Report Overview
This report provides an overview of the whole project and the key issue of non-uniform cooling within the vaccine cooler. It describes the design and  implementation of the electrical test setup, which was my main individual contribution. In addition, all experimental testing and data analysis was completed collaboratively as a team. Therefore, this report provides a brief summary of the results and findings, but for further detail, refer to the test results document.

## Intro
Vaccines face the logistical challenge of needing to remain within a narrow temperature range  of 2-8°C to remain effective. This presents a challenge for delivering vaccines to remote villages in countries such as Cameroon, where access to reliable electricity is limited. The SMILE project has been developed to address this challenge of maintaining vaccine efficacy for ‘last mile’ vaccine delivery. 

Earlier this year, a thermal test conducted by our partner Kitty on the current SMILE Go prototype showed a significant temperature gradient across the vaccine carousel (as can be seen in the figure below), with compartments at the top of the carousel being hotter than those at the bottom. Given the narrow temperature range within which vaccines must be stored, this non-uniformity limits the cool life and increases the risk of spoilage. 
 


## Project direction
We decided to investigate this non-uniform cooling issue due to the limited understanding of the underlying causes. We initially considered completing a combination of thermal modelling and experimental testing. However, after consulting with our partner, we decided against including thermal modelling within our scope. Some basic modelling has already been completed in previous years’ projects, and developing a more realistic model would require significantly more time, thermal expertise and resources than we had available. As a result, we focused on conducting actual experiments to investigate potential variables that could be contributing to the formation of a temperature gradient. 

In the beginning, we intended to solely investigate the impact of cooler inserts and convection (as can be seen in our original Gantt chart). However, as testing progressed, we identified additional variables that we believed could be influencing the thermal distribution in the cooler. This included heat entering through the access door and the non-uniformity of the contact between the ice bottle contact and the carousel.

Designing Test Setup & Electrical information

Given that our project involved investigating the thermal non-uniformity in the vaccine cooler, it primarily consisted of conducting a series of thermal tests, typically lasting between 6 and 30 hours. I was responsible for designing the test setup, as I had interest in and some previous experience with electronics. I first identified our test system’s requirements, based on the need to compare our results with those obtained by Kitty earlier this year and to allow comparison and therefore evaluation of the effects of the different variables we tested. Kitty’s test had used Bluetooth temperature sensors, with 2 placed in the upper vaccine chambers and 2 in the lower vaccine chambers. She had attempted to use a temperature-controlled chamber, but this had failed midway through her experiment. 

Our system needed to measure the temperatures at multiple locations in the carousel, timestamp the data, store the data and allow the frequency of measurements taken to be adjusted.

We initially planned to use Kitty’s Bluetooth sensors as they had a resolution of 0.1°C and were wireless. However, these could not be located, so I evaluated alternative options based on cost, accuracy, availability, physical size, and circuit requirements and decided on the DS18B20 temperature sensors, which had an accuracy of 0.5°C. The temperature sensors were daisy chained and connected to 5V by a 4.7 kΩ pull-up resistor.

As a result, I developed a test setup using an Arduino connected to 5 temperature sensors, an SD card module for data logging and power source.  My initial plan was to power the Arduino through a PC, which would also allow real-time monitoring through the serial monitor and could therefore provide verification that the test was working correctly at the start, whilst simultaneously storing our data.
I also developed a backup power plan in case we did not have access to Dyson centre computer overnight. This consisted of 6xAA batteries, a barrel jack connector and an RTC module. 
 
Electrical circuit diagram made in Tinkercad circuits


The sensor arrangement consisted of four sensor probes placed within the vaccine carousel (two in upper compartments and two in lower compartments) and one sensor placed out of the cooler for ambient temperature measurement. All sensors were mounted on foam and secured with tape to ensure consistent positioning and comparable height across compartments. The SMILE Go was tested horizontally in a spill tray to mitigate risk from leakage. See the images below to see the test setup.


   
  
Each test used this general test setup and then we made changes to the prototype or icepack. Karen researched into cooler insert material and design and both Karen and Kerry were responsible for implementing those changes on the bottle.

I first breadboarded the circuit and ran code to test the individual components before then soldering the circuit as breadboarded circuits are quite temperamental and given that we would be reusing this circuit a lot it made sense to make it more sturdy. After making sure the test equipment worked, I conducted a test equipment experiment to run overnight to check the equipment worked over several hours and to make sure the dyson PC would provide power overnight.

 
Initial breadboarded circuit

 
Soldered circuit


## Code
The code was written by combining code for multiple DS18B20 temperature sensors available on their data sheet and the standard code for printing to an SD card. The libraries you need to download for the temperature sensors are dallasTemperature and OneWire. The libraries needed for reading and writing to the SD card are SPI & SD.  To see the full code, see git pg…


## Assessment of electrical monitoring system

Overall, the electrical temperature monitoring circuit performed very well. It provided reliable temperature data from all 5 sensors to an appropriate level of accuracy in every test.
There was one instance in which, at the start of a test, the code produced an SD card error message when the cooler was moved to the tray. This led me to discover a loose SD card module wire, which required resoldering. Aside from this incident, no further resoldering or circuit modifications were required.

However, I did face significant issues in getting the Arduino to connect to the computer and then in running the code on the Arduino. This occurred because I had initially been using an Arduino clone board found in the Dyson Centre. This board worked sometimes; however, most of the time I just got error messages. I rectified the situation by first changing the Arduino power/data wire, which had no effect, until I changed the actual Arduino Uno to one that was not a clone.


(I have compiled all this information into a document called ‘Electrical’ which is also accessible through the Git website and is in an appropriate handover format

## Tests 
For our investigation, our team conducted a series of tests to narrow down the causes of the non-uniformity. We conducted:
-	2x Control tests – tests run to compare against our following test results allowing analysis of the changed variable
-	Door oriented downwards – cooler orientation was flipped such that door was on bottom. The door is a potential area where heat could be entering as it is poorly sealed.
-	Cooler insert test – 3D printed PLA insert in the shape of a cross inserted to split the ice into chambers
-	Top Contact test – raised the icepack off the bottom of the bottle chamber so that the ice was now in contact with the top.
-	Vertical – solution based test. Oriented the cooler upright.
-	Convection test (as well as additional tests to assess our setup) – inserted radial baffles
-	Fan test – solution based test. Attached 2 fans to carousel to force air around.
-	Combination tests – both top contact and convection tested

At the beginning of every test, I made sure the code uploaded correctly and checked that the temperature sensors were being read as well as that the data was being correctly stored to the SD card.
During the test, every so often, I would look at the serial monitor to monitor the test.
At the end of every test, I then read the txt file from the SD card and compiled it into a graph which could then be analysed by myself, Kerry and Karen.

## Insert tests
Karen was responsible for researching, designing and then 3D printing cooler inserts for us to test in the ice pack bottle. Kerry (and Karen) were responsible for inserting the insert and attempting to make it watertight using hot glue. The inserts were 3D printed in PLA, as this was the main print material we had easy access to. However, research was conducted into other materials and sealants to be used, as hot glueing, whilst fine for prototyping, is not suitable for manufacturing.
Ice pack inserts were an idea our partners were keen for us to look into. The idea behind an insert is that normally, as the ice melts, the cold water would sink to the bottom of the bottle, the ice would float in the middle and then the air would accumulate at the top of the bottle. This could therefore be a factor contributing to the non-uniform cooling. By putting an insert into the ice bottle, this would keep some of the ice and cold water in the top of the icepack bottle when it laid horizontally.
 
Diagram made by Karen

## Convection tests
From our tests, it became apparent that cold air was accumulating at the bottom of the carousel while hot air was rising, resulting in the observed temperature gradient. Given that the data showed this gradient forming very quickly, it seemed unlikely to be caused solely by the geometry of the ice melting (the issue targeted by inserts), and we suspected natural convection might be responsible. Kerry researched this idea, and we decided to conduct a test using tightly fitting radial inserts to seal off the individual chambers of the carousel. This would prevent or at least slow down (since not properly airtight) the movement of hot air upwards and the cold air downwards. The results showed a slight reduction in the temperature gradient, but not as much as expected. As a result, I proposed conducting a further test to evaluate the effectiveness of our convection setup. This was done by placing a small bag of ice in the top compartment, both with and without the radial convection setup, to observe how quickly cold air would sink to the bottom of the carousel. Our results did show that the setup had an effect on the convection. However, because a much smaller amount of ice was used, the rate of temperature decrease was significantly lower than in a normal test, so it could not provide an accurate sense of the timescale if using the central icepack instead.
 

## Assessment of Tests
Given the nature of the tests and our ability to control certain variables, there were certain things about our setup that were not ideal and may have affected the validity of our results.
Ambient temperature not being controlled: All our testing was conducted in the Dyson centre rather than a temperature controlled environment. The temperature within Dyson was not constant but stayed within a few degrees in a 24hr cycle. This was already a significant improvement on Kitty’s test which had a temperature range of 18 – 28 °C as the temperature chamber she had initially been using to test the device at 28°C stopped working. However, our testing did show that the ambient temperature significantly effected the cooler’s internal temperatures, leading to rises and drops as per the ambient.
Prototype condition: The prototype SMILE Go we were testing on had been drop tested during last year’s project. As a result, some of the rivets were starting to become loose and the door hinge did not correctly fit into its slot. These factors could have affected the insulation and sealing of the cooler. We tried to account for these factors, where we thought it might lead to particular hotspots like the door, which we tested by monitoring the cooler upside down with the door on the bottom instead.

## Feasibility of using a fan
The fan test was a more solution-oriented test rather than investigative. It did not necessarily narrow down what was causing the non-uniformity, but showed that forced convection stopped the temperature gradient. 
This is not the ideal solution because the cooler is currently passive. Therefore, using an active system which requires electricity like the fan concept is not ideal. However, adding an electronic component is not without precedent, as past projects have developed electrical monitoring add-on packages.  Therefore, an active solution could be feasible. The fans we used in the experiment were 25x25x10mm DC 5v brushless fans. These fans were incredibly small and had a max operation of 3400rpm with an air flow capacity of 0.027 Cubic metres Per Minute.
Electrical details: 5V, 0.02A, 0.1W
This is actually a very low power fan, so it would not be unrealistic to power this for the necessary 24hrs.
For 24hrs, the energy required by the fan: E = P x t = 0.1 x 24 = 2.4 Wh
So for 2 fans this would be 4.8 Wh of stored energy.

Potential power sources include:
-	4xAA batteries: provide ~6V, ~2500 mAh, 15Wh
o	An alternative to reduce the number of batteries is to use just 1 or 2 AA batteries as they can provide sufficient current and power to the fans, but a boost converted would be required to raise the voltage to 5V.
-	A 18650 Lithium ion cell: ~3.6V, 1500 – 3500 mAh
o	This would also require a boost converter to provide 5V
These are both cheap, readily accessible potential power sources that can easily last a full journey. They would experience loss of performance in high temperatures but it should not be an issue
-	Solar cell: 
o	The solar cell would need to be connected to a rechargeable battery which could then drive the fans. This circuit could have losses of up to 20% so 5.76Wh required.
o	A 1-2W solar cell should be able to charge the necessary batteries with a few hours of sunlight.


## Test results and discussion 
Our group’s main technical output was our thermal monitoring tests and the results we obtained. This testing and the results analysis was completed by our whole team and cannot be distinguished. As a result, to avoid repetition in each of our individual reports, please see the markdown page called ‘Test results & analysis’ for our test results.

## Further testing & potential design changes
Based on our tests, the most important design changes to make to the current prototype are improving the insulation. This is critical given that in every test our temperature sensors showed that the top compartments were above the required 8 degrees. The current prototype uses spray foam and is very unevenly distributed. 
 
Looking at our control tests done at different ambient temperatures and the resulting temperatures the compartments stabilised at, also suggests improving the insulation would help keep the vaccines below 8 degrees and would likely reduce the temperature difference. This insulation could be manipulated to reduce the temperature gradient by adding more or better insulation to the top. This asymmetric insulation concept is employed successfully by the original SMILE. Other alternatives could include adding an additional icepack to the top of the cooler, by the door.
Additionally, almost all of our tests showed the bottom compartments going well below 2°C into the freezing range which is not acceptable for vaccines. This suggests changes need to be made to the carousel design such that the 3D print is thicker or other insulation is added in some other way. Adding fins all the way around the interior of the central chamber so that the ice pack bottle isn’t in the direct contact with the walls, could prevent this freezing and would also solve the non-uniform contact issue.
Both solution-oriented tests we conducted showed great promise. The forced convection test with the fans successfully brought the compartments to within the range and led to almost uniform conditions across the carousel. Based on my feasibility calculations above, it would not be too difficult to implement if active solutions were to be considered. The other solution based test was the vertical orientation test. This showed only a 1°C difference between compartment locations at the bottom and top of the icepack (see sensor 2 & 4 in the figure below). However, this test was only conducted for 5.5hrs and the ice pack does not extend to the top of the carousel, so the temperature measured there (sensor 1) was several degrees warmer. It would be worthwhile testing this same setup with a taller icepack and over a longer duration, as this could be a very simple solution if it continued to show such promising results.
 


## Reflections
This project gave me the opportunity to engage with technical areas such as electronics, practical testing, and data analysis. It was also a valuable opportunity to work in a team, figuring out the most effective way to collaborate, divide the workload and manage our limited time effectively. 
One important lesson I learned was the need to be adaptable. This became apparent at the outset, when our electronic component procurement took longer than expected, delaying our testing schedule. However, we continued to adapt throughout our project, as we modified the tests we conducted and therefore the schedule in response to new ideas and theories we thought of as the project developed.
One aspect that differed from my expectations was that I expected to find one factor which would not show any or very little asymmetry i.e. find a dominant cause. As a result, some tests were run for shorter periods than would have been ideal so that we could get through more tests because we thought a few hours was enough to determine if that was the dominant cause. However, given that the results suggest the asymmetry is most likely due to a combination of factors, it would have been beneficial to have longer tests, as the temperature gradient did vary slightly with time.
An additional area that I would have been interested in exploring was ice pack composition. Given our interest in cooler inserts to look at how changes in the ice geometry over time affect the uniformity, it would also have been interesting to look at how changing the composition of the icepack (e.g. adding salt, or starch, could affect the freezing point and therefore state of the icepack. However, our partner was very keen to only have water in the icepack to make it as fail-proof and easily manufacturable as possible, so given this and the limited time, it was not an avenue we decided to explore. 

## Conclusion
This project investigated potential causes for the temperature asymmetry observed within the SMILE Go vaccine cooler, where the top compartments remained warmer than the bottom ones. We designed a built a temperature monitoring system and then conducted thermal tests on the cooler, looking at convection, potential hotspot areas like the door, ice distribution and ice pack contact. 
Our results showed that the temperature gradient forms very quickly and whilst we tested several hypotheses, the gradient still persisted. Some of our changes did lead to slight reductions in the asymmetry, which suggests the gradient may not occur by one dominant mechanism but by multiple. The door was found not to be a significant cause of the gradient, whilst the ice pack insert, improved top contact and convection tests showed some slight improvements. The cooler insert showed the most promise, appearing to reduce the difference by 2°C. Furthermore, forcing air using fans was the only change that reduced the gradient to essentially zero. 

Going forward, we would recommend conducting further tests to validate and further expand on our findings. Experiments should be repeated to identify any anomalies and ideally, tests should be conducted in a controlled environment. Additionally, it could be vital to look at whether the temperature in a vaccine vial in a compartment is at the same temperature as the compartment.
Based on our findings, the insulation needs to be improved in order to get the compartments into the acceptable temperature range. This improved insulation could reduce the asymmetry. Additionally, active low-power systems like the fan are viable and should be considered as a potential solution.

Overall, the project assessed various potential causes of the temperature gradient seen across the vaccine carousel, but it did not identify a primary cause. However, it has provided an initial look into the problem from which further investigation should be continued.

## AI use statement: AI was used to check for grammatical errors
