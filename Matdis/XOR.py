# menentukan karakter apa saja yang mungkin ada di pesan
def createpesan():
    pesan = ['.', ',', '!']
    pesanaz = ['a' for i in range(26)]
    pesanAZ = ['A' for i in range(26)]
    pesan09 = ['0' for i in range(10)]
    keyaz = 'a'
    keyAZ = 'A'
    key09 = '0'

    # set pesan menjadi a,b,c......,x,y,z dan A,B,C.....X,Y,Z
    for i in range(25):
        pesanaz[i+1] = chr(ord(pesanaz[i+1])+i+1)
    for i in range(25):
        pesanAZ[i+1] = chr(ord(pesanAZ[i+1])+i+1)
    for i in range(9):
        pesan09[i+1] = chr(ord(pesan09[i+1])+i+1)

    # menyatukan pesan
    for i in (pesan09):
        pesan.append(i)
    for i in (pesanaz):
        pesan.append(i)
    for i in (pesanAZ):
        pesan.append(i)

    return pesan


# XOR hanya dengan beberapa bit saya (misal a-Z saja)
def xorsebagian(pesan):
    hasil = [0 for i in range(256)]
    # XOR dengan alfabet
    for j in range(26):
        # for loop i akan mengXOR pesan dan key dan menambah jumlahnya ke hasil
        for i in range(len(pesan)):
            # jika ingin tidak mengikutsertakan suatu karakter, ubah bagian ini
            if(i >= 0):
                hasil[ord(pesan[i]) ^ ord(keyaz)] += 1
                hasil[ord(pesan[i]) ^ ord(keyAZ)] += 1
        keyaz = chr(ord(keyaz)+1)
        keyAZ = chr(ord(keyAZ)+1)

    # XOR dengan angka
    for j in range(10):
        for i in range(len((pesan))):
            hasil[ord(pesan[i]) ^ ord(key09)] += 1
        key09 = chr(ord(key09)+1)
        # XOR pesan dengan tiitk, koma, tanda seru
    for i in range(65):
        hasil[ord(pesan[i]) ^ ord('.')] += 1
        hasil[ord(pesan[i]) ^ ord(',')] += 1
        hasil[ord(pesan[i]) ^ ord('!')] += 1
    return hasil


# XOR dengan semua bit yang memungkinkan (0-255)
def xorfull(pesan):
    fullkey = chr(0)
    hasil = [0 for i in range(256)]
    for j in range(255):
        for i in range(len(pesan)):
            hasil[ord(pesan[i]) ^ ord(fullkey)] += 1
        fullkey = chr(ord(fullkey)+1)
    return hasil


# main program keseluruhan
pesan = createpesan()
hasil = xorfull(pesan)
macam = 0
total = 0
for i in range(256):
    if(hasil[i] != 0):
        macam += 1
    total += hasil[i]
print('total kombinasi:', total)
print('kombinasi unik :', macam)
print('pesan yang digunakan:')
for i in range(len(pesan)):
    print(pesan[i], end=' ')
    if((i+1) % 32 == 0):
        print('')
print('')
print('hasil:')
for i in range(256):
    print(hasil[i], end=' ')
    if((i+1) % 32 == 0):
        print('')
