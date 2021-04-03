import binascii
from Crypto.Cipher import AES

#Open the file with all the potential keys to iterate through
with open('./keys.txt') as file:
    keys = file.readlines()

#Brute force the key by trying all of them and seeing which ones match
#match the cyphertext we have by encrypting the plaintext with all of
#the keys we came up with in our C program
for key_hex in keys:
    key_hex = key_hex.rstrip()

    #Setup all the necessary items for the AES engine to work on
    iv = binascii.unhexlify('09080706050403020100A2B2C2D2E2F2')
    key = binascii.unhexlify(key_hex)
    plain_text = binascii.unhexlify('255044462d312e350a25d0d4c5d80a34')
    encryption_engine = AES.new(key, AES.MODE_CBC, iv)
    cipher_text = encryption_engine.encrypt(plain_text)

    #Do the actual checking to see if the ciphertext matches our actual
    #ciphertext from the file
    if (cipher_text == binascii.unhexlify('d06bf9d0dab8e8ef880660d2af65aa82')):
        print("key: ", binascii.hexlify(key))
