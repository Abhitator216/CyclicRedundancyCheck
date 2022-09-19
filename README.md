# CRC Simulation for Error Detection

Consider two machines a sender and a receiver. Implement CRC Algorithm such that the sender computes error detecting code using CRC and sends the data along with error detecting code to the receiver using socket. Receiver, after ensuring error free frame saves the data.

Your program should meet the following guidelines:
At sender:
- Read input from a file, n characters at a time.
- Convert it into binary(this is m bits of data)
- Using any standard generator polynomial (with degree k), compute error detecting code.
- Send (m+ k) bits to the receiver but before sending (m+k) bits, introduce error randomly as given below.

## Introducing error:

### Following are the steps to introduce error in any frame chosen randomly.

- Generate random number say __r1__. Perform __r1 % 2__. If you get a __0__ do not introduce error and send original __(m+k) bits__. If you get a __1__, introduce error. To decide which bit will be in error, use the following step.

- Generate another random number say __r2__. Perform __r2 % (m+k)__. Outcome of this operation would be a number between __0 and (m+k-1)__. Assume you get a value i as the outcome. Flip the __i th bit of m+k__. Now send it to the receiver.

### At receiver:
- Receive (m+k) bits.
- Determine if it is error free. If yes extract data bits, convert it into character form and save it into output file. Send Ack as OK. If not, send NAK.

### At sender:
- If OK is received, proceed with next n characters. Otherwise if NAK is received, follow step (iv) of the sender above.

Final outcome: Your input and output files should match. Your output should clearly show how many frames were in error and how many retries were done for each frame.