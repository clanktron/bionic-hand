# Bionic Hand

Arduino code for a rudimentary bionic hand. This was a fun demo project for my E96 Bionics class.

## System layout

### Button1:

When pressed will trigger the closeHand_partial() function. This closes the index and thumb to grasp a small object.
>uses a force sensor to allow for grabbing delicate items

### Button2:

When pressed will trigger the closeHand_full() function. This closes all fingers to grasp a larger object.
>final position of closed fingers can be adjusted by changing the 'index_full_threshold' and/or 'rem_full_threshold' variables

### Button3:

When pressed will trigger the openHand() function. This returns the hand to its opened 'resting' state.
