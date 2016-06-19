# Old Connected Printer

This bit of code connect a Mannesman Tally MT85 (yes, for 1985!!) to the cloud via Tramontana  and Arduino.

## Wiring the LPT connector to the Arduino pins

|---|--------|--------|----|
| 1 | brown  | STROBE | 37 |
| 2 | red    | D0     | 53 |
| 3 | orange | D1     | 51 |
| 4 | pink   | D2     | 49 |
| 5 | yellow | D3     | 47 |
| 6 | dark green | D4 | 45 |
| 7 | light green | D5 | 43 |
| 8 | blue | D6 | 43 |
| 9 | gray/blue | D7 | 43 |
| 10 | purple | ACK | not connected |
| 11 | gray | BUSY | 35 (after tension reduction) |
| 19 | pink/black | GND | GND |
