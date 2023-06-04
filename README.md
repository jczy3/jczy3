### Vigenere Cypher Encryption / Decryption Final Project

Authors: Joseph Caraan, Paul Ingram
Date Published: June 3, 2023

Vigenere Cypher Overview:
The Vigenere Cipher is a procedure in which alphabetic text may be encrypted and also decrypted. This procedure utilizes a form of polyalphabetic substitution in which the letters of plain text are transformed into new letters by using a key. Both encryption and decryption in the Vigenere Cipher uses the Vigenere square to perform one or the other. This square consists of the alphabet on the first row and first column. The rest of the square is written by shifting the alphabet cyclically to the left each time the row of the square descends until there are a total of 26 Caesar Ciphers within the square. The certain Caesar Cipher that is used on the Vigenere Square when encrypting or decrypting text depends on the key. 

Encryption Explanation:
To encrypt text, the first letter of the plain text that needs to be encrypted is searched for in the first column of the square. When the row that consists of this letter is found in the first column, the first row of the square is then searched for the first letter of the key. When the column that consists of this letter is found in the first row, both row and column are traversed until the row and column meet. That letter is the encrypted letter for the first letter of plain text. This process is continued for each character of the plain text until the end of the plain text. It is important to note that if the key’s string size is shorter than the plain text’s string size, the keyword is repeated in a circular fashion until it matches the size of the plain text string.

Decryption Explanation:
To decrypt text, the first letter of the keyword is searched for in the first column of the square. When the row that consists of this letter is found in the first column, this row is then searched for the first letter of the encrypted text. The corresponding column letter at this position is the first decrypted letter. This process is repeated until the end of the encrypted text is reached. Once again, if the keyword is shorter than the encrypted text, the keyword is reused in the circular manner until it matches the size of the encrypted text string.

Programming approaches:
An initial programming approach that we came up with was to simulate this description in the program by creating a 2D array which creates the Vigenere square. We then created an encrypt function which would retrieve the row and column indexing on the Vigenere Cypher array by using a for loop that would loop from 0 (i = 0) to the end of the plain text that was to be encrypted (i < inp.size()), converting the character of the plain text at i and the key at j into its ascii values as integers, then subtract these integers by 65 to get the indexing of the row and column on the array. j is then incremented by one, and if the key at j is equal to the null character, j is set to 0. This is so that the key’s characters are repeated in a circular fashion until the end of the for loop. Then, these encrypted letters are added to an empty string until the end of the for loop. For decryption, the same for loop is run such that it iterates from i = 0 to the end of the encrypted text’s string size. The key at j is converted to its corresponding ascii integer and then subtracted by 65 once again to the get row indexing on the Vigenere Cypher array. Once again, j is incremented by one and if the key at j is equal to the null character, j is set equal to 0 to simulate its circular nature when key.size() is less than inp.size(). Now, the encrypted text’s (inp) first letter is searched for within this row. When found, the column’s letter is returned from a search function. The letters of the decrypted text are then added onto an empty string until the for loop ends. Provided below are the encrypt, decrypt, and search functions for this approach. (Note: This is not the finalized code that we used on the project, but simply a previous approach that we made.)

string encrypt(string inp,string key,char ary[][SIZE]){
  string enc = "";
  int charToInt1;
  int charToInt2;
  int j = 0;
  for(int i=0;i<inp.size();i++){
    charToInt1 = int(inp[i])-65;    //getting row indexing on vigenere cypher array using ASCII values
    charToInt2 = int(key[j])-65;    //getting col indexing on vigenere cypher array using ASCII values
    j++;
    if(key[j]=='\0') j = 0;    //if iterator for string key (j) reaches end of string, set j = 0
    enc += ary[charToInt1][charToInt2];
  }
  return enc;
}

string decrypt(string inp,string key,char ary[][SIZE]){
  string dec = "";
  int charToInt1;
  int charToInt2;
  int j = 0;
  for(int i=0;i<inp.size();i++){
    charToInt1 = int(key[j])-65;    //getting row indexing on vigenere cypher array using ASCII values using key[j]
    j++;
    if(key[j]=='\0') j = 0;    //if iterator for string key (j) reaches end of string, set j = 0
    charToInt2 = search(charToInt1,inp[i],ary);    //search row of vigenere cypher array for corresponding inp[i]
    dec+=ary[0][charToInt2];
  }
  return dec;
}

int search(int charToInt1,char c,char ary[][SIZE]){    //function returns column number of decrypted character
  for(int j=0;j<SIZE;j++){
    if(ary[charToInt1][j]==c) return j;
  }
}

However, we came to discover a simpler approach that would decrease time complexity. The creation of the 2D Vigenere Cypher array caused our solution to be O(n^2), however this new approach would only be O(n). In this new approach, the alphabet is 0 indexed. For encryption, it would involve using the same for loop which starts at i = 0 and ends at the end of the input’s size. The row index P_i is retrieved by converting the first character of the plain text into ascii and subtracting 65 to get its indexed value. The same is done to get K_i by converting the first character of the key and subtracting 65. The same if statement is run, checking to see if the key at j is equal to the null character and setting j equal to 0 if true. To encrypt the letter, the following equation is used:  E_i = (P_i + K_i) % 26. Then, the encrypted letter is added to an empty string. This process is repeated until the for loop ends and an encrypted message is generated. Now, for decryption, the same process is utilized, however a different equation is used to get the decrypted letters: D_i = (E_i - K_i + 26) % 26, where D_i is the decrypted letter at i, E_i is the encrypted letter at i, and K_i is the key’s letter at i. The code for this will be provided in the src folder.

Instructions:
To use the program, enter either 1 to encrypt a message or 2 to decrypt a message. For encryption, the program will prompt you to enter text that you wish to encrypt. Then, it will ask for the key you wish to use to encrypt your message. Finally, the program will output your encrypted text. For decryption, the program will prompt you to enter text that you wish to decrypt. Then, it will ask for the key you wish to use to decrypt your message. Finally, the program will output your decrypted text.
Note that you cannot use symbols or spaces for both encryption and decryption, as these are the limitations of using a Vigenere Cypher.
