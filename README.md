<h1>About</h1>
This is an implementation in C of the Caesar and Vigenere ciphers.
These ciphers will decrpyt or encrypt alphabetical characters
while numeric and symbols and spaces will be left alone. Case is preserved.
The alphabet is mapped to the numbers 0 to 25, inclusive.
So:
<ul>
    <li>a, A maps to 0 </li>
    <li>b, B maps to 1 </li>
    <li>c, C maps to 2 </li>
    <li> ... </li>
    <li>z, Z maps to 25 </li>
</ul>


<h2> How To Use Caesar </h2>
To use the Caesar cipher type in a command line:
    ./caesar [key] [encrypt/decrypt]
Make sure this key is an integer!

Examples:
./caesar 32 encrypt
plaintext: Meet me in Times Square at 7:00am on ThursdayMorning.
ciphertext: Skkz sk ot Zosky Ywagxk gz 7:00gs ut ZnaxyjgeSuxtotm.

./caesar 16 decrypt
ciphertext: Q Bqddyijuh qbmqoi fqoi xyi turji.
plaintext: A Lannister always pays his debts.


<h2> How To Use Vigenere </h2>
To use the Vigenere cipher type in a command line:
    ./vigenere [key] [encrypt/decrypt]
Make sure this key is a string!

Examples:
./vigenere banana encrypt
plaintext: The night is dark and full of terrors.
ciphertext: Uhr nvgit vs qask nnq fvly os tfreoes.

./vigenere apple decrypt
ciphertext: Eatxinipcc, mn sper Lpewoc.
plaintext: Elementary, my dear Watson.