# Easy Message Encryption
*Encrypt and decrypt private short messages*
________
It's extremely easy application for encypting messages, but it fulfills its function. It's because cryptography is based on ignorance of the encyrption algorithm and private keys. The sender and recipient must use a secure channel to exchange keys (preferably in reality), if they want to correspond safety.

In 'my' cryptosystem, we choose as many as three keys - `x`, `y` and `z`. Number `z` indicates the length of blocks to which the text will be divided. Program use the *Caesar cipher* on these blocks. The odd blocks are shifted by `x` letters and the even ones by `y`. Of course numbers `x` and `y` can be negative, but `z` doesn't.

There are 27 characters available - letters `a-z` and dot `.` for eventually separating sentences. The lack of spaces makes it difficult to break the cipher, because the cryptoanalyst doesn't know the length of the used words.

### Example of encrypting
Set the keys `x=1`, `y=-15`, `z=2`.

Text to encrypt:
```
willanyonerecognizeanencryptedinscription.itisnoteasy
```
Cryptogram:
```
xjxxboj.ofcqdpszj.qmofzoszaefeuztdcuquu.oauejtz.ufmdz
```
The text looks like a cluster of random letters and dots. Such a short text without knowing the keys or algorithm is almost impossible to decipher. But with the publication of a large number of cryptograms, the risk of a statistical attack increases (because we know the statistics of the occurrence of individual letters in many languages). Therefore, I recommend frequent change of keys or establishing with the recipient a key selection schedule, based on the day of the week, on previous keys, etc.

Be careful about *brute force*! If the cryptanalyst knows that you are using the shift cipher in regular blocks, you can use this attack and list all the possibilities of shifting the cryptogram in the available blocks.

Although, number of possible shits is a product of `number of possible length of block` - `53`, `number of possible shift in odd block` - `27`, `number of possible shift in even block` - `27`.

Let's calculate: `53 x 27 x 27 = 38637`. For a determined person it is not a large number at all... and remember that these are just all possibilities. This person can quickly find a meaningful word prefix in the first odd block and search for the original text after it.

That is why this project requires development, perhaps matching other, more non-standard schemes... nevertheless, I think that the program may be useful, especially if we are not attacked by cryptology experts. :)
