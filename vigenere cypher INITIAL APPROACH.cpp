#include <iostream>
#define SIZE 26
using namespace std;
string encrypt(string,string,char [][SIZE]);
string decrypt(string,string,char [][SIZE]);
int search(int,char,char [][SIZE]);
int main() {
  char ary[SIZE][SIZE];    //vigenere cypher array
  char x;
  char y = '@';    //ASCII table used
  string choice;    //choice of user
  string plnText;    //plain text to encrypt/decrypt
  string key;    //key used to encrypt/decrypt
  for(int i=0;i<SIZE;i++){
    y++;
    x=y;
    for(int j=0;j<SIZE;j++){
      ary[i][j] = x;
      x++;
      if(x=='[') x = 'A';    //ASCII table used
    }
  }
  cout << "Welcome to the Vigenere Cipher Decryption program by Joseph Caraan and Paul Ingram.\n\n";
  cout << "Enter 1 to encrypt or 2 to decrypt text (with no spaces or symbols): ";
  cin >> choice;
  while(choice != "1" && choice != "2"){
    cout << "ERROR. Please enter either 1 to encrypt to 2 to decrypt: ";
    cin >> choice;
  }
  if(choice == "1"){
    cout << "Enter text that you wish to encrypt: ";
    cin >> plnText;
    cout << "Enter the key that you wish to use to encrypt your text: ";
    cin >> key;
    for(int i=0;i<plnText.size();i++) plnText[i] = toupper(plnText[i]);    //make sure lowercase strings are made uppercase
    for(int i=0;i<key.size();i++) key[i] = toupper(key[i]);    
    cout << "Encrypted text: " << encrypt(plnText,key,ary) << endl;
  }
  else{
    cout << "Enter text that you wish to decrypt: ";
    cin >> plnText;
    cout << "Enter the key that you wish to use to decrypt your text: ";
    cin >> key;
    for(int i=0;i<plnText.size();i++) plnText[i] = toupper(plnText[i]);
    for(int i=0;i<key.size();i++) key[i] = toupper(key[i]);
    cout << "Decrypted text: " << decrypt(plnText,key,ary) << endl;
  }
  return 0;
}
string encrypt(string inp,string key,char ary[][SIZE]){
  string enc = "";
  int charToInt1;
  int charToInt2;
  int j = 0;
  for(int i=0;i<inp.size();i++){
    charToInt1 = int(inp[i])-65;    //getting row indexing on vignere cypher array using ASCII values
    charToInt2 = int(key[j])-65;    //getting col indexing on vignere cypher array using ASCII values
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
    charToInt1 = int(key[j])-65;    //getting row indexing on vignere cypher array using ASCII values using key[j]
    j++;
    if(key[j]=='\0') j = 0;    //if iterator for string key (j) reaches end of string, set j = 0
    charToInt2 = search(charToInt1,inp[i],ary);    //search row of vignere cypher array for corresponding inp[i]
    dec+=ary[0][charToInt2];
  }
  return dec;
}
int search(int charToInt1,char c,char ary[][SIZE]){    //function returns column number of decrypted character
  for(int j=0;j<SIZE;j++){
    if(ary[charToInt1][j]==c) return j;
  }
}