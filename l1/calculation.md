The last 4 digits of my student number is 9166. Looking at the manuals for the demultiplexer [74HC139](https://phas.ubc.ca/~kotlicki/Physics_319/74HC139.pdf) and 7-Segment display[DM9368](https://phas.ubc.ca/~kotlicki/Physics_319/DM9368.pdf) we must have the following conditions on the displays.

| Display | A0 | A1 | Strobe | Y0 | Y1 | Y2 | Y3 | LE | D3 | D2 | D1 | D0 | Output |
|---------|----|----|--------|----|----|----|----|----|----|----|----|----|--------|
|    0    | 1  | 1  | 0      | 1  | 1  | 1  | 0  | 0  |  1 | 0  | 0  | 1  | 9      |
|    1    | 0  | 1  | 0      | 1  | 1  | 0  | 1  | 0  |  0 | 0  | 0  | 1  | 1      |
|    2    | 1  | 0  | 0      | 1  | 0  | 1  | 1  | 0  |  0 | 1  | 1  | 0  | 6      |
|    3    | 0  | 0  | 0      | 0  | 1  | 1  | 1  | 0  |  0 | 1  | 1  | 0  | 6      |


outputs: (0000 0000 -> D3 D2 D1 D0 - A1 A0 Strobe)
off
on
reset -> 0000 0 001
9 ->  1001 0 110
set-next -> 1001 0 100
1 ->  0001 0 100
set-next -> 0001 0 101
6 ->  0110 0 010
6 ->  0110 0 000