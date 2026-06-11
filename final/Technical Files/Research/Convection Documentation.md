General documentation - a more refined description can be found in Kerry's individual report.

# Investigating Convection
A hypothesis regarding the non-uniform cooling is that it is the natural convection of the air within the vaccine chamber that is causing the hot air to rise to the top of the chamber while the cool air that is generated at the top of the chamber falls to the bottom. This leads to a temperature differential that is reflected in the data collected by Kitty and Oliver in their previous experiments, where the chambers near the top of the cooler are warmer than those at the bottom.

![image1](image1.png)

Notice in the data that the non-uniform cooling effect is instantaneous. If the source of the problem were related to the ice distribution within the bottle, perhaps it would be expected that the temperatures initially start out relatively identical, since the ice has not melted enough to have a significantly uneven distribution within the bottle. In this case, once the ice starts to melt, we’d expect the temperatures to differentiate as the water-ice-air ratio evens out (creates more non-uniformity).

However, consider that it is convection that causes the temperatures to be different. The natural convection effect is, on the timescales of the experiment, much faster, as the cooler air generated at the top surface convects to the bottom of the chamber quickly. The transient motion of the air falling is unlikely to occur on the timescale of hours. Thus, we expect a temperature difference between the top and bottom of the chamber as soon as the experiment has started.

![image2](image2.png)

# Method
Experimentally, there are two possible ways to mitigate the temperature gradient caused by natural convection within the vaccine chamber.

## 1. Stop the flow
To stop the flow of air around the chamber, add radial planes that stretch from the inner radius of the vaccine chamber to the outer radius, and extend from the front to the back end. These planes should be as well fitting as can be reasonably constructed, to best resist the flow of hotter air to the top section, and the flow of cooler air to the lower sections. 

Some air gaps will still exist, which will decrease the effectiveness of stopping the convection. However, it may be such that the radial planes are effective enough to create more uniform cooling - something that can be quantified in the test results. 

![image3](image3.png)

From research, if taken to a much smaller scale, this is how insulation works. For example, fibreglass insulation creates a fine web of fibres, which traps air into very small pockets and resists its flowing motion. This convection design essentially makes use of this principle, but on a larger scale. 

## 2. Force the flow
By using a small fan, the air within the vaccine chamber can be forcefully convected and kept more uniform. This would keep all the locations of the vaccine in the same temperature of air, roughly, and eliminate the non-uniform cooling effect, if the temperature difference is truly present in the air (rather than for example a conduction pathway or radiation from the ice pack).

One caveat to this test is that the fan may cause its own heating from the electrical components that run the fan. This effect can be mitigated by running the fan intermittently, which prevents it from overheating. 

![image4](image4.png)

It is critical to note that this test is more solution-oriented than aiming to identify the source of the non-uniform cooling. This is because the fan effectively hides or covers the non-uniform cooling’s source by mixing all the air together, regardless of where the cooler/warmer air has come from. For example, if the asymmetric cooling effect stems from an uneven ice distribution within the ice pack, a forced convection test would still theoretically result in more uniform cooling since the air in the vaccine chamber is forced to mix.

### Fan Issues
The Arduino board is not able to handle the current draw of even very small fans, which require at least 80 mA of current whereas the Arduino itself can supply only a maximum of 40 mA. 

An external power supply would be required to power the fans, possibly connected to a relay which is then controlled by the Arduino. This would mean that the fan can be kept running intermittently to avoid heating the vaccine chamber from the fan’s electrical components. 

However, looking into the case where the use of a fan might be considered in the field, its requirement of a power supply beyond that of the Arduino increases the electrical complexity and thus cost of manufacture of the SMILE Go. Perhaps with the addition of further electrical functionality for the SMILE product, such as the temperature predictor and monitor display project by a 2024 team, a fan could be integrated. Furthermore, the electronic complexity of this system is slightly beyond the project’s scope, with the main focus being using our existing capabilities to investigate the non-uniformity of the cooling to the best of the team’s ability.

An alternate solution that is to be considered is using a usb-powered fan for the convection test. In this case, the fan would be completely isolated from the Arduino and temperature sensor circuit, drawing power from a usb port elsewhere. Usb ports cannot generally be controlled to be turned on or off, so the fan would be running continuously - likely generating heat and affecting the cool-life of the vaccines. However, the heat generated would theoretically be distributed evenly throughout the vaccine chamber due to the forced convection from the fan. This allows the project to still investigate the relative temperatures of the vaccine holder locations, and assess the uniformity of the cooling. 


# Testing
## Radial Planes
This test was conducted with card cutouts which were cut oversize. When inserted into the vaccine chamber, they needed to be pressed down by the walls of the cooler box. This was intentionally done to create a better seal with the walls of the vaccine chamber, which are very hard to reach with any tape or other sealing material once the carousel is inserted. 
Airtight tape was used at the top and bottom of the card cutouts to create a better seal with the edges of the carousel.
A p-shape foam seal was used at one end of the carousel (which had a worse fit than the other end) to give that end better airtight properties. The objective was to resist flow of air over this end of the vaccine cooler and thereby bypass the reason for having the radial planes in place.

### Testing the effectiveness of the radial planes
A test was conducted to see how well the radial planes stops cold air from falling into lower sections of the chamber. Ice cubes were placed in the very top of the vaccine carousel, and temperature readings were taken over time to assess the rate at which the lower sensors would cool, compared to the sensors nearer the top of the chamber (closer to the ice). This was compared to the same experiment but where no planes are present. 
A towel was placed in the central section of the box where the ice pack normally sits. This is to stop any convection currents in that region from cooling the lower section of the vaccine cooler box.
After 100 minutes of testing with the radial planes present and the ice at the top of the carousel, the bottom two sensors did not show a large temperature drop at all, however the top sensors did show a decent drop in temperature. This suggests that the planes are relatively effective at stopping the cold air generated from the ice from falling quickly to the bottom of the chamber.
