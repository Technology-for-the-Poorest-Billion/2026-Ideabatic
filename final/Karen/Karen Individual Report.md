# Technology for the poorest billion

# SMILE GO Project - Uniform Cooling Solutions

Karen Miyazaki | 10 June 2026

## Project Team:

Karen Miyazaki, Kerry Dai, Kavita Sivaraman

## In collaboration with:

Kitty Liao, Oliver Griffiths

# My Contribution

This report documents my contribution to the SMILE GO project, which investigated the causes of non-uniform cooling within the vaccine carrier and explored potential methods to reduce temperature gradients. My primary responsibility was the design, manufacture and evaluation of bottle inserts for the central ice pack. As a team, we all contributed to experimental setup, test execution and analysis throughout the project. Ideas for tests were discussed as a team and set up together upon reaching an agreement.

# Project Overview

The SMILE GO is the scaled down version of the SMILE vaccine cooler created by Kitty Liao’s company, Ideabatic, which helps deliver vaccines to remote and low-resource areas. The cooler is designed to be an affordable and portable solution, making it more suitable where access to reliable refrigeration and healthcare infrastructure is limited such as in Cameroon. The vaccine cooler is required to stay in a 2-8 degree temperature range to maintain the cold-chain. If the vaccines go below 2 degrees, there is a risk of the vaccines freezing and likewise if the vaccines go above 8 degrees, there is a risk of the vaccines denaturing.

However, it was observed that the upper chambers inside the cooler were much hotter than the lower chambers so we aimed to identify the causes of non-uniform cooling within the vaccine cooler and propose mitigation strategies for this. This investigation is crucial to ensure that all vaccines safely remain in range to ensure the vaccines remain effective for a longer period of time. Vaccine wastage can also be reduced, making healthcare delivery more reliable and sustainable in these rural areas. Throughout this project, we collected valuable thermal data that can be used to inform future design improvements.

# Prototyping set-up

## Insert Development

Upon discussion with Kitty, we hypothesized that the ice pack cools unevenly because of the large internal air gap at the top of the ice bottle during melting. Since air has a significantly lower thermal conductivity and heat capacity than water, heat transfer from the upper sections of the bottle to the remaining ice was expected to be less effective, leading to higher temperatures in the upper vaccine compartments.

I designed the inserts to divide the bottle into multiple chambers while maintaining a simple geometry that could be manufactured using FDM 3D printing. I generated multiple insert designs and evaluated them before a final design was selected. The design process focused on balancing thermal performance with practical manufacturing constraints. The insert needed to fit through the bottle opening, maintain sufficient internal volume for the ice pack, and be manufacturable using the available 3D printing facilities. A few packaging methods were considered such as snap-fit inserts, slotted structures or single print structures. These ideas are presented below:

![Insert design concepts](images/insert_concepts.png)

The first design was selected due to its simplicity and reliability. In this set-up, the two planes have slots that physically interlock, allowing the print to be done as two flat planes instead of a thin 3D part. Two planes were sufficient to demonstrate results, while remaining practical to insert into the bottle. As shown in the diagram below, the larger air gap gets segmented into four chambers, so the upper chamber has less insulation from the air in this set up than without the inserts.

![Bottle chamber segmentation diagram](images/bottle_segmentation.png)

![Top view of segmented bottle](images/top_view_segmentation.png)

![Bottle assembly photograph](images/bottle_assembly.jpg)

However, this design relies on the 3D print being flexible enough to push through the neck of the bottle. Therefore, an initial prototype was produced to verify fit and assembly within the bottle. The inserts were manufactured using PLA through 3D printing. Printing parameters of 100% outer walls and 15% infill provided adequate stiffness while retaining a small degree of flexibility during assembly. This is shown below:

![Initial prototype insert](images/prototype_insert.jpg)

Early testing demonstrated that attaching the insert directly to the bottle lid was impractical due to difficulties associated with the screw closure mechanism. As a result, the design was modified to incorporate a separate printed top section. Two further iterations were completed to refine the dimensions and ensure reliable closure of the bottle. The final design successfully allowed the bottle lid to close while maintaining the required internal geometry.

Throughout the design process, several practical limitations of this prototyped design became apparent, particularly regarding print porosity and sealing.

## Assembly

A significant challenge encountered was producing a watertight and airtight seal within the bottle. Hot glue was selected as a low-cost and readily available sealing method for prototype testing. Kerry was responsible for hot gluing the insert into the bottle and additional hot glue was applied around the interfaces to minimise leakage. I assisted with this process at times.

Following assembly, the bottle underwent a freeze-thaw cycle prior to experimental testing. The insert and adhesive joints remained structurally sound throughout this process and the final assembly was found to be almost perfectly watertight and airtight.

## Materials research

Throughout the design process, Kerry and I analysed the materials used in this test. Several limitations of 3D printing became apparent, particularly regarding print porosity. Moisture permeation was observed through some printed components caused by microscopic voids and gaps between extrusion lines. This was more significant in the earlier prototype, which was printed using a lower-precision printer. Later prototypes were produced using a higher-quality Bambu Lab printer with 100% top and bottom densities and 15% infill. This improved print consistency, reduced visible porosity, and still retained enough flexibility for the insert to be pushed through the bottle neck during assembly. Over time, this may still pose as a concern.

PLA was suitable for rapid prototyping because it was cheap, quick to manufacture, readily available in the Dyson Centre, and allowed complex geometries to be produced easily. However, it is not ideal for long-term use in the SMILE GO cooler. The material PLA itself can absorb moisture over time and may undergo hydrolytic degradation in water. Repeated freezing and thawing may also cause the absorbed water within the print to expand and contract, potentially opening cracks or weakening the interfaces between printed layers. For the short duration of our prototype testing, these limitations were acceptable, but they would be problematic for a cooler intended to last for several years.

Sealing the inserts inside the bottle also presented practical difficulties...
