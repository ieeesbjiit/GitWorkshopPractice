MORSE_CODE_DICT = { 'A':'.-', 'B':'-...', 
                    'C':'-.-.', 'D':'-..', 'E':'.', 
                    'F':'..-.', 'G':'--.', 'H':'....', 
                    'I':'..', 'J':'.---', 'K':'-.-', 
                    'L':'.-..', 'M':'--', 'N':'-.', 
                    'O':'---', 'P':'.--.', 'Q':'--.-', 
                    'R':'.-.', 'S':'...', 'T':'-', 
                    'U':'..-', 'V':'...-', 'W':'.--', 
                    'X':'-..-', 'Y':'-.--', 'Z':'--..', 
                    '1':'.----', '2':'..---', '3':'...--', 
                    '4':'....-', '5':'.....', '6':'-....', 
                    '7':'--...', '8':'---..', '9':'----.', 
                    '0':'-----', ', ':'--..--', '.':'.-.-.-', 
                    '?':'..--..', '/':'-..-.', '-':'-....-', 
                    '(':'-.--.', ')':'-.--.-'} 
        
def encrypt(message):  # eng to morse
    cipher= ' '
    for letter in message:
        if letter !=' ':
            cipher += MORSE_CODE_DICT[letter]+' '
        else:
            cipher +=' '
    return cipher
def decrypt(message): #morse to eng
    message+=' '
    decipher=''
    citext=''
    for letter in message:
        if(letter != ' ' ):
            i=0
            citext+=letter
        else:
            i+=1
            if i==2:
                decipher+=' '
            else:
                decipher+=list(MORSE_CODE_DICT.keys())[list(MORSE_CODE_DICT.values()).index(citext)]
                citext=''
    return decipher

def main():
    print("MORSE TRANSLATOR")
    print("1.Encrypt message")
    print("2.Decrypt message")
    choice=input("Enter you choice ")
    if choice=='1':
        sent=str(input("Enter a string"))
        result=encrypt(sent)
        print('The string in morse code is',result) 
    elif choice=='2':
        dec=str(input("Enter morse code to decrypt"))
        res2=decrypt(dec)
        print('The decrypted message is',res2)
    else:
        print('Enter any one of the choice')
                  

if __name__=='__main__':
    main()
 
