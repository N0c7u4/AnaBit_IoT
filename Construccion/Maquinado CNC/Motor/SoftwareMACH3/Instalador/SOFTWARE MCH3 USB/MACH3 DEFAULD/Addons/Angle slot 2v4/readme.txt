This wizard is designed to cut those little slots that you place a bolt or pin through that provide a range of adjustment 
for your project.  If you are like me I never take the time to draw such a slot and CAM it. Instead I grab a end mill and 
generally end up with a less than desirable slot.  
                                                                                             ----------------
This wizard only works for horizontal and vertical 90 degree slots.
All values are entered as positive including:
Total depth of cut  
Finish cut depth - amount of stock on the bottom (if the slot is a pocket)  you want to reserve for a finish pass 
- zero if no finish pass is desired
Finish cut width - amount of stock on the slot walls you want to reserve for a finish pass - zero if no finish pass is desired
Maximum depth per pass - generates multiple pass gcode - no single cut depth will exceed the value entered
                                                                                             ----------------
Z tool entry mode - provides two choices. A standard plunge mode which requires a center cutting end mill and
drops the end mill straight into the stock. The ramp mode ramps the cutter to depth, cutting primarily with the side 
of the cutter - slower than plunging (requires extra passes) but generally better finish. Ramp is especially good on lighter
mills as it doesn't stress the setup as much a straight plunge.

Z initial start height - z will rapid to this point before using z feed rate.
Z initial move safe height - safe z height when moving into first cut - hopefully clearing obstructions

All slots are cut with a path down the center and a path outlining the slot.

Typical end mill sizes that will work for a given slot width.
WIDTH		END MILLS
.125			.0625
.25 			.125, .1875
.375			.1875, .25
.5			.25, .3125, .375
If your end mill gets too large or too small the software will complain.